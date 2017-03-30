// -*- C++ -*-
//
// Package:    MuMuPiKPAT
// Class:      MuMuPiKPAT
// 
/**\class MuMuPiKPAT MuMuPiKPAT.cc myAnalyzers/MuMuPiKPAT/src/MuMuPiKPAT.cc
 
   Description: <one line class summary>
   Make rootTuple for JPsiPiPi reconstruction
 
   Implementation:
   <Notes on implementation>
*/
//
// Original Author:  Keith Ulmer   keith.ulmer@colorado.edu
//
//


// system include files
#include <memory>

// user include files
#include "../interface/MuMuPiKPAT.h"
#include "../interface/VertexReProducer.h"
//#include "DataFormats/Candidate/interface/OverlapChecker.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CommonTools/Statistics/interface/ChiSquaredProbability.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GtFdlWord.h"
#include "FWCore/Common/interface/TriggerNames.h"

#include "DataFormats/Candidate/interface/VertexCompositeCandidate.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
//#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"

#include "RecoVertex/KinematicFitPrimitives/interface/MultiTrackKinematicConstraint.h"
#include "RecoVertex/KinematicFit/interface/KinematicConstrainedVertexFitter.h"
#include "RecoVertex/AdaptiveVertexFit/interface/AdaptiveVertexFitter.h"
#include "RecoVertex/KinematicFit/interface/TwoTrackMassKinematicConstraint.h"

#include "RecoVertex/VertexTools/interface/VertexDistanceXY.h"

#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "MagneticField/Engine/interface/MagneticField.h"
#include "TrackingTools/PatternTools/interface/TwoTrackMinimumDistance.h"
#include "TrackingTools/IPTools/interface/IPTools.h"

//#include "TrackingTools/Records/interface/TrackingComponentsRecord.h"

#include "DataFormats/Common/interface/RefToBase.h"
#include "DataFormats/Candidate/interface/ShallowCloneCandidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Candidate/interface/CandMatchMap.h"
#include "DataFormats/Math/interface/Error.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/Math/interface/Vector3D.h"

#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/PatCandidates/interface/GenericParticle.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/TrackReco/interface/DeDxData.h"

//for 53x 
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "TFile.h"
#include "TTree.h"
#include "TVector3.h"

#include <vector>
#include <utility>

#include "TMath.h"
#include "Math/VectorUtil.h"


//
// constants, enums and typedefs
//

typedef math::Error<3>::type CovarianceMatrix;

const ParticleMass muon_mass = 0.10565837; //pdg mass
const ParticleMass pion_mass = 0.13957018; //pdg mass
const ParticleMass kaon_mass = 0.493667;
ParticleMass Jpsi_mass = 3.096916;
ParticleMass psi2S_mass = 3.686093;

//Setting insignificant mass sigma to avoid singularities in the covariance matrix.
float small_sigma = muon_mass*1.e-6;				

//
// static data member definitions
//

//
// constructors and destructor
//
MuMuPiKPAT::MuMuPiKPAT(const edm::ParameterSet& iConfig) :
  hlTriggerResults_(iConfig.getUntrackedParameter<edm::InputTag>("HLTriggerResults",edm::InputTag("TriggerResults::HLT")) ),
  inputGEN_(iConfig.getUntrackedParameter<edm::InputTag>("inputGEN",edm::InputTag("genParticles"))),
  vtxSample(iConfig.getUntrackedParameter<std::string>("VtxSample",std::string("offlinePrimaryVertices"))), 
  ///// li lascio ma ineffettivi
  doMC(iConfig.getUntrackedParameter<bool>("DoMonteCarloTree", false)),
  MCParticle( iConfig.getUntrackedParameter<int>("MonteCarloParticleId", 20443) ), //20443 X, 100443 Psi(2S), 9120443 X from B
  ////////
  doMuMuMassConst( iConfig.getUntrackedParameter<bool>("DoMuMuMassConstraint", true) ),

  skipJPsi(iConfig.getUntrackedParameter<bool>("SkipJPsi", false)),
  skipPsi2S(iConfig.getUntrackedParameter<bool>("SkipPsi2S", false)),

  MuMinPixHits(iConfig.getUntrackedParameter<int>("MinNumMuPixHits", 0)),
  MuMinSiHits(iConfig.getUntrackedParameter<int>("MinNumMuSiHits", 0)),
  MuMaxNormChi(iConfig.getUntrackedParameter<double>("MaxMuNormChi2", 1000)),
  MuMaxD0(iConfig.getUntrackedParameter<double>("MaxMuD0", 1000)),

  TrMinSiHits(iConfig.getUntrackedParameter<int>("MinNumTrSiHits", 0)),
  TrMinPt(iConfig.getUntrackedParameter<double>("MinTrPt", 0)),
  TrMaxNormChi2(iConfig.getUntrackedParameter<double>("MaxTrChi2NDF", 10)),

  TriggersForMatching_(iConfig.getUntrackedParameter<std::vector<std::string> >("TriggersForMatching")),
  FiltersForMatching_(iConfig.getUntrackedParameter<std::vector<std::string> >("FiltersForMatching")),
  resolveAmbiguity_(iConfig.getUntrackedParameter<bool>("resolvePileUpAmbiguity",true)),
  addMuMulessPrimaryVertex_(iConfig.getUntrackedParameter<bool>("addMuMulessPrimaryVertex", true)),

  JPsiMaxMass(iConfig.getUntrackedParameter<double>("MaxJPsiMass", 3.2)),
  JPsiMinMass(iConfig.getUntrackedParameter<double>("MinJPsiMass", 2.7)),
  PsiPrimeMinMass(iConfig.getUntrackedParameter<double>("MinPsiPrimeMass", 3.)),
  PsiPrimeMaxMass(iConfig.getUntrackedParameter<double>("MaxPsiPrimeMass", 4.)),

  MuMuTrackMaxDR(iConfig.getUntrackedParameter<double>("MaxMuMuTrackDR", 1)),
  // B0
  B0TrackMaxDR(iConfig.getUntrackedParameter<double>("MaxB0CandTrackDR", 1.1)),
  UseB0DR(iConfig.getUntrackedParameter<bool>("UseB0DR", false)),
  MuMuPiKMinMass(iConfig.getUntrackedParameter<double>("MinMuMuPiKMass", 0)),
  MuMuPiKMaxMass(iConfig.getUntrackedParameter<double>("MaxMuMuPiKMass", 10)),
  addB0lessPrimaryVertex_(iConfig.getUntrackedParameter<bool>("addB0lessPrimaryVertex",true)),

  Debug_(iConfig.getUntrackedParameter<bool>("Debug_Output",false)),
  DeDxEstimator_(iConfig.getUntrackedParameter<std::string>("DeDxEstimator",std::string("dedxHarmonic2"))),
  m_dEdxDiscrimTag(iConfig.getUntrackedParameter<std::string>("DeDxDiscriminator",std::string("dedxHarmonic2"))),
  m_dEdxDiscrimTag_kaon(iConfig.getUntrackedParameter<std::string>("DeDxDiscriminator",std::string("dedxHarmonic2Kaon"))),

  Z_One_Tree_(0),

  runNum(0), evtNum(0), lumiNum(0),

  trigRes(0), trigNames(0), L1TT(0), MatchTriggerNames(0), 

  nMu(0), nMuMu(0), nB0(0),
  priVtx_X(0), priVtx_Y(0), priVtx_Z(0), priVtx_XE(0), priVtx_YE(0), priVtx_ZE(0), priVtx_NormChi2(0), priVtx_Chi2(0), priVtx_CL(0), priVtx_tracks(0),  

  // indices
  mu1Idx(0), mu2Idx(0), MuMuType(0),
  // B0
  B0_MuMuIdx(0), B0_piIdx(0), B0_kIdx(0),   

  // generic muons
  muPx(0), muPy(0), muPz(0),
  muPhits(0), muShits(0), muLayersTr(0), muLayersPix(0),  
  muD0(0),  muD0E(0), muDz(0), muChi2(0), muNDF(0),
  mufHits(0), muFirstBarrel(0), muFirstEndCap(0),
  muDzVtx(0), muDxyVtx(0), muDzVtxErr(0), muKey(0),
  //muNDF(0), muGlNDF(0),muPhits(0), muShits(0), muGlMuHits(0), muType(0), muQual(0), 
  muGlMuHits(0), muGlChi2(0), muGlNDF(0), muGlMatchedStation(0), 
  muGlDzVtx(0), muGlDxyVtx(0), 
  muType(0), muQual(0), muTrack(0), muCharge(0),

  // generic tracks
  trNotRef(0), trRef(0),
  //
  trPx(0), trPy(0), trPz(0), trE(0),
  trNDF(0), trPhits(0), trShits(0), trChi2(0),

  trD0(0), trD0E(0), trCharge(0),
  trfHits(0), trFirstBarrel(0), trFirstEndCap(0),
  trDzVtx(0), trDxyVtx(0),
  trQualityHighPurity(0), trQualityTight(0),

  tr_nsigdedx(0), tr_dedx(0), tr_dedxMass(0), tr_theo(0), tr_sigma(0),
  // by hits
  tr_dedx_byHits(0), tr_dedxErr_byHits(0), tr_saturMeas_byHits(0), tr_Meas_byHits(0),

  // MuMu
  MuMuMass(0), MuMuPx(0), MuMuPy(0), MuMuPz(0),
  MuMuVtx_CL(0), MuMuVtx_Chi2(0), 
  MuMuDecayVtx_X(0), MuMuDecayVtx_Y(0), MuMuDecayVtx_Z(0),
  MuMuDecayVtx_XE(0), MuMuDecayVtx_YE(0), MuMuDecayVtx_ZE(0),
  MuMuMuonTrigMatch(0),
  // muons after Psi' fit
  mu1_MuMu_Px(0), mu1_MuMu_Py(0), mu1_MuMu_Pz(0), mu1_MuMu_Chi2(0), mu1_MuMu_NDF(0),
  mu2_MuMu_Px(0), mu2_MuMu_Py(0), mu2_MuMu_Pz(0), mu2_MuMu_Chi2(0), mu2_MuMu_NDF(0),
  // Primary Vertex with "MuMu correction"
  PriVtxMuMuCorr_X(0), PriVtxMuMuCorr_Y(0), PriVtxMuMuCorr_Z(0), PriVtxMuMuCorr_EX(0), PriVtxMuMuCorr_EY(0), PriVtxMuMuCorr_EZ(0),
  PriVtxMuMuCorr_Chi2(0), PriVtxMuMuCorr_CL(0), PriVtxMuMuCorr_tracks(0),

  // B0  
  b0Mass(0), b0Vtx_CL(0), b0Vtx_Chi2(0),
  b0Px(0), b0Py(0), b0Pz(0), b0PxE(0), b0PyE(0), b0PzE(0), 
  b0DecayVtx_X(0), b0DecayVtx_Y(0), b0DecayVtx_Z(0), b0DecayVtx_XE(0), b0DecayVtx_YE(0), b0DecayVtx_ZE(0),
  // Muons and pions/tracks after B0 Cand fit
  mu1Px_MuMuPiK(0), mu1Py_MuMuPiK(0), mu1Pz_MuMuPiK(0), mu1E_MuMuPiK(0),
  mu2Px_MuMuPiK(0), mu2Py_MuMuPiK(0), mu2Pz_MuMuPiK(0), mu2E_MuMuPiK(0),
  piPx_MuMuPiK(0), piPy_MuMuPiK(0), piPz_MuMuPiK(0), piE_MuMuPiK(0),
  pion_nsigdedx(0), pion_dedx(0), pion_dedxMass(0), pion_theo(0), pion_sigma(0), 
  pion_dedx_byHits(0), pion_dedxErr_byHits(0), pion_saturMeas_byHits(0), pion_Meas_byHits(0), 
  kPx_MuMuPiK(0), kPy_MuMuPiK(0), kPz_MuMuPiK(0), kE_MuMuPiK(0), 
  kaon_nsigdedx(0), kaon_dedx(0), kaon_dedxMass(0), kaon_theo(0), kaon_sigma(0), 
  kaon_dedx_byHits(0), kaon_dedxErr_byHits(0), kaon_saturMeas_byHits(0), kaon_Meas_byHits(0), 
  // Primary Vertex with largest B0_cos(alpha)
  PriVtx_B0CosAlpha_X(0), PriVtx_B0CosAlpha_Y(0), PriVtx_B0CosAlpha_Z(0), PriVtx_B0CosAlpha_EX(0), PriVtx_B0CosAlpha_EY(0), PriVtx_B0CosAlpha_EZ(0),
  PriVtx_B0CosAlpha_Chi2(0), PriVtx_B0CosAlpha_CL(0), PriVtx_B0CosAlpha_tracks(0),
  // Primary Vertex with "B0 correction"
  PriVtxB0Corr_X(0), PriVtxB0Corr_Y(0), PriVtxB0Corr_Z(0), PriVtxB0Corr_EX(0), PriVtxB0Corr_EY(0), PriVtxB0Corr_EZ(0),
  PriVtxB0Corr_Chi2(0), PriVtxB0Corr_CL(0), PriVtxB0Corr_tracks(0),

  b0LxyPV(0), b0CosAlphaPV(0), b0CTauPV(0), b0CTauPVE(0), 
  b0LxyPVCosAlpha(0), b0CosAlphaPVCosAlpha(0), b0CTauPVCosAlpha(0), b0CTauPVCosAlphaE(0),
  b0LxyPVX(0), b0CosAlphaPVX(0), b0CTauPVX(0), b0CTauPVXE(0),
  b0LxyBS(0), b0CosAlphaBS(0), b0CTauBS(0), b0CTauBSE(0),
  b0CTauPVX_3D(0), b0CTauPVX_3D_err(0),

  PiPiMass_err(0)

{
  //string DoubleMu0 = "HLT_DoubleMu0"; 
  //TriggersForMatching.push_back(DoubleMu0);
  //string DoubleMu0_Quark = "HLT_DoubleMuO_Quarkonium_V1";
  //TriggersForMatching.push_back(DoubleMu0_Quark);

  //now do what ever initialization is needed
  MuMuMinMass = JPsiMinMass;
  MuMuMaxMass = PsiPrimeMaxMass;

}


MuMuPiKPAT::~MuMuPiKPAT()
{
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
	
}


//
// member functions
//

// ------------ method called to for each event  ------------
void MuMuPiKPAT::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{	
  // get event content information
	
  runNum = iEvent.id().run();
  evtNum = iEvent.id().event();
  lumiNum = iEvent.id().luminosityBlock();
  bool hasRequestedTrigger = false;
  ESHandle<MagneticField> bFieldHandle;
  iSetup.get<IdealMagneticFieldRecord>().get(bFieldHandle);
	
  // first get HLT results
  map<string,int> HLTPreScaleMap;

  edm::Handle<edm::TriggerResults> hltresults;
  try {
    iEvent.getByLabel(hlTriggerResults_, hltresults);
  }
  catch ( ... ) {
    cout << "Couldn't get handle on HLT Trigger!" << endl;
  }
  if (!hltresults.isValid()) {
    cout << "No Trigger Results!" << endl;
  } 
  else {
    int ntrigs = hltresults->size();
    if (ntrigs==0){
      cout << "No trigger name given in TriggerResults of the input " << endl;
    } 
		
    // get hold of trigger names - based on TriggerResults object!
    edm::TriggerNames triggerNames_;
    //     triggerNames_.init(*hltresults); 
    triggerNames_ = iEvent.triggerNames(*hltresults);
	
    int ntriggers = TriggersForMatching_.size();
    for (int MatchTrig = 0; MatchTrig<ntriggers; MatchTrig++){
      MatchingTriggerResult[MatchTrig]= 0;
    }

    for (int itrig = 0; itrig < ntrigs; itrig++) {
      string trigName = triggerNames_.triggerName(itrig);
      int hltflag = (*hltresults)[itrig].accept();
      if (hltflag) cout << trigName << " " <<hltflag <<endl;
      trigRes->push_back(hltflag);
      trigNames->push_back(trigName);
      
      int ntriggers = TriggersForMatching_.size();
      for (int MatchTrig = 0; MatchTrig < ntriggers; MatchTrig++) {
	if (TriggersForMatching_[MatchTrig] == triggerNames_.triggerName(itrig)){
	  MatchingTriggerResult[MatchTrig] = hltflag;
	  if (hltflag==1) hasRequestedTrigger = true;
	  break;
	}
      }
    }
    //int ntriggers = TriggersForMatching_.size();
    for (int MatchTrig = 0; MatchTrig<ntriggers; MatchTrig++){
      //      cout << TriggersForMatching_[MatchTrig]<<endl;
      MatchTriggerNames->push_back(TriggersForMatching_[MatchTrig]);
    }
    
    //
    // Get HLT map : triggername associated with its prescale, saved only for accepted trigger
    //
    for (unsigned int i=0; i<triggerNames_.size(); i++){
      if ( hltresults->accept(i) ) { //  save trigger info only for accepted paths
	// get the prescale from the HLTConfiguration, initialized at beginRun
	int prescale = hltConfig_.prescaleValue(iEvent,iSetup,triggerNames_.triggerNames().at(i));
	//std::cout<<" HLT===> "<<triggerNames_.triggerNames().at(i)<<" prescale ="<<prescale<<std::endl;
	HLTPreScaleMap[triggerNames_.triggerNames().at(i)] = prescale;
      }
    }
    HLTTrig = &HLTPreScaleMap; // store in the branch

  } // end valid trigger

	
  // get L1 trigger info
	
  edm::ESHandle<L1GtTriggerMenu> menuRcd;
  iSetup.get<L1GtTriggerMenuRcd>().get(menuRcd) ;

  //const L1GtTriggerMenu* menu = menuRcd.product();
	
  edm::Handle< L1GlobalTriggerReadoutRecord > gtRecord;
  iEvent.getByLabel( edm::InputTag("gtDigis"), gtRecord);
  const DecisionWord dWord = gtRecord->decisionWord();  
	
  const TechnicalTriggerWord ttWord = gtRecord->technicalTriggerWord();
  for(unsigned int l1i = 0; l1i != ttWord.size(); ++l1i){
    L1TT->push_back(ttWord.at(l1i));
  }
	
  Vertex thePrimaryVtx, theBeamSpotVtx;
  math::XYZPoint RefVtx;
	
  reco::BeamSpot beamSpot;
  edm::Handle<reco::BeamSpot> beamSpotHandle;
  iEvent.getByLabel("offlineBeamSpot", beamSpotHandle);
  if ( beamSpotHandle.isValid() ) {
    beamSpot = *beamSpotHandle; 
    theBeamSpotVtx = Vertex(beamSpot.position(), beamSpot.covariance3D());
  }
  else cout << "No beam spot available from EventSetup" << endl;
	
	
  Handle<VertexCollection> recVtxs;
  iEvent.getByLabel(vtxSample, recVtxs);
  unsigned int nVtxTrks = 0;
  if ( recVtxs->begin() != recVtxs->end() ) {
    if (addMuMulessPrimaryVertex_ || addB0lessPrimaryVertex_ || resolveAmbiguity_) { 
      thePrimaryVtx = Vertex(*(recVtxs->begin()));
    }
    else {
      for ( reco::VertexCollection::const_iterator vtx = recVtxs->begin(); vtx != recVtxs->end(); ++vtx) {
	if (nVtxTrks < vtx->tracksSize() ) {
	  nVtxTrks = vtx->tracksSize();
	  thePrimaryVtx = Vertex(*vtx);
	}				
      }
    }
  }
  else {
    thePrimaryVtx = Vertex(beamSpot.position(), beamSpot.covariance3D());
  }
	
  edm::ESHandle<TransientTrackBuilder> theTTBuilder;
  iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder",theTTBuilder);
  KalmanVertexFitter vtxFitter(true);

  RefVtx = thePrimaryVtx.position(); //reference primary vertex choosen	
	
  priVtx_X = (thePrimaryVtx.position().x()) ;
  priVtx_Y = (thePrimaryVtx.position().y()) ;
  priVtx_Z = (thePrimaryVtx.position().z()) ;
  priVtx_XE = (thePrimaryVtx.xError()) ;	
  priVtx_YE = (thePrimaryVtx.yError()) ;
  priVtx_ZE = (thePrimaryVtx.zError()) ;
  priVtx_NormChi2 = (thePrimaryVtx.normalizedChi2()) ;
  priVtx_Chi2 = thePrimaryVtx.chi2() ;
  priVtx_CL = ChiSquaredProbability( (double)(thePrimaryVtx.chi2()), (double)(thePrimaryVtx.ndof())) ;
  priVtx_tracks = thePrimaryVtx.tracksSize() ;
	
  //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // try reconstruction without fitting modules
  //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  Handle< vector<pat::GenericParticle> > thePATTrackHandle;
  iEvent.getByLabel("cleanPatTrackCands", thePATTrackHandle);
  Handle< vector<pat::GenericParticle> > theKaonRefittedPATTrackHandle;
  iEvent.getByLabel("cleanPatTrackKaonCands", theKaonRefittedPATTrackHandle);
  for ( vector<pat::GenericParticle>::const_iterator TrackNotRefitted = thePATTrackHandle->begin(); TrackNotRefitted != thePATTrackHandle->end(); ++TrackNotRefitted ) {
    for ( vector<pat::GenericParticle>::const_iterator TrackRefitted = theKaonRefittedPATTrackHandle->begin(); TrackRefitted != theKaonRefittedPATTrackHandle->end(); ++TrackRefitted ) {
      if ( TrackNotRefitted->track().key() == TrackRefitted->track().key() ) {
	trNotRef->push_back( TrackNotRefitted->p() ) ;
	trRef->push_back( TrackRefitted->p() ) ;
	break ;
      }
    }
    break ;
  }

  Handle< vector<pat::Muon> > thePATMuonHandle;
  iEvent.getByLabel("patMuonsWithTrigger", thePATMuonHandle);

  Handle<reco::DeDxDataValueMap> elossCollection;
  energyLoss = 0;
  iexception_dedx = 0;
  try {
    //iEvent.getByLabel("dedxHarmonic2", elossCollection);
    iEvent.getByLabel(DeDxEstimator_, elossCollection);
    energyLoss = elossCollection.product();
  } catch ( cms::Exception& ex ) {
    if (evtNum < 100) edm::LogError("Analyzer") <<"Warning can't get collection with label: elossCollection";
    iexception_dedx = 1;
  }

  // dE/dx hits
  Handle<edm::ValueMap<reco::DeDxData> > dEdxTrackHandle;
  try {
    iEvent.getByLabel(m_dEdxDiscrimTag, dEdxTrackHandle);
    dEdxTrack = *dEdxTrackHandle.product();
  } catch ( cms::Exception& ex ) {
    if (evtNum < 100) edm::LogError("Analyzer") <<"Warning can't get collection with label: dEdxTrackHandle";
    iexception_dedx = 1;
  }

  Handle<edm::ValueMap<reco::DeDxData> > dEdxTrackHandle_Kaon;
  try {
    iEvent.getByLabel(m_dEdxDiscrimTag_kaon, dEdxTrackHandle_Kaon);
    dEdxTrack_Kaon = *dEdxTrackHandle_Kaon.product();
  } catch ( cms::Exception& ex ) {
    if (evtNum < 100) edm::LogError("Analyzer") <<"Warning can't get collection with label: dEdxTrackHandle_Kaon";
    iexception_dedx = 1;
  }

	
  bool isEventWithInvalidMu = false;
	
  if (Debug_) {
    cout << "starting event with " << thePATTrackHandle->size() << " tracks, and " << thePATMuonHandle->size() << " muons" << endl;
  }
  if ((thePATMuonHandle->size()) * (thePATTrackHandle->size()) > 20000) {
    cout << "Too many Muons: " << thePATMuonHandle->size() << " and Tracks " << thePATTrackHandle->size() << endl;
  }
  //
  else //if (thePATMuonHandle->size() >= 2) {
    if (thePATMuonHandle->size() >= 2  && hasRequestedTrigger) {
      if (Debug_) cout <<"============================  evt: " <<evtNum <<" Accept event with 2 mu and TRIGGER ==============================================" <<endl;
      
      //filling track tree

      for ( vector<pat::GenericParticle>::const_iterator iTr = thePATTrackHandle->begin(); iTr != thePATTrackHandle->end(); ++iTr ) {

	pat::GenericParticle tr = *iTr;
	trPx->push_back(tr.px());
	trPy->push_back(tr.py());
	trPz->push_back(tr.pz());
	trE->push_back(tr.energy());
	
	trPhits->push_back(tr.track()->hitPattern().numberOfValidPixelHits());
	trShits->push_back(tr.track()->hitPattern().numberOfValidStripHits());
	trChi2->push_back(tr.track()->chi2());
	trNDF->push_back(tr.track()->ndof());
	
	trD0->push_back(tr.track()->d0());
	trD0E->push_back(tr.track()->d0Error());
	trCharge->push_back(tr.charge());
	
	float hits = (1.0*tr.track()->found() )/ (tr.track()->found()+ tr.track()->lost() + tr.track()->trackerExpectedHitsInner().numberOfHits() + tr.track()->trackerExpectedHitsOuter().numberOfHits());
	trfHits->push_back(hits);
	trFirstBarrel->push_back(tr.track()->hitPattern().hasValidHitInFirstPixelBarrel());
	trFirstEndCap->push_back(tr.track()->hitPattern().hasValidHitInFirstPixelEndcap());
	trDzVtx->push_back(tr.track()->dz(RefVtx));
	trDxyVtx->push_back(tr.track()->dxy(RefVtx));
	
	double theo = 0., sigma = 0. ;
	tr_nsigdedx->push_back(nsigmaofdedx(tr.track(),theo,sigma));
	tr_dedx->push_back(getEnergyLoss(tr.track()));
	tr_dedxMass->push_back(GetMass(tr.track()));
	tr_theo->push_back(theo);
	tr_sigma->push_back(sigma);
	// dE/dx hits
	tr_dedx_byHits->push_back( (dEdxTrack)[tr.track()].dEdx() );
	tr_dedxErr_byHits->push_back( (dEdxTrack)[tr.track()].dEdxError() );
	tr_saturMeas_byHits->push_back( (dEdxTrack)[tr.track()].numberOfSaturatedMeasurements() );
	tr_Meas_byHits->push_back( (dEdxTrack)[tr.track()].numberOfMeasurements() );
	
	//  Track quality:            
	//// loose=0, tight=1, highPurity=2, confirmed=3, goodIterative=4, looseSetWithPV=5, highPuritySetWithPV=6
	bool ishighPurity = tr.track()->quality(reco::TrackBase::highPurity);
	trQualityHighPurity->push_back(ishighPurity);
	trQualityTight->push_back(tr.track()->quality(reco::TrackBase::tight));
      }
      
      //get MuMu cands
      for ( std::vector<pat::Muon>::const_iterator Muon1 = thePATMuonHandle->begin(); Muon1 != thePATMuonHandle->end(); ++Muon1 ) {

	// push back all muon information
	++nMu;
	const reco::Muon* rmu1 = dynamic_cast<const reco::Muon * >(Muon1->originalObject());
	muPx->push_back(rmu1->px());
	muPy->push_back(rmu1->py());
	muPz->push_back(rmu1->pz());
	muCharge->push_back(rmu1->charge());
	
	if (rmu1->track().isNull()) { // rmu->track() returns innerTrack();
	  //	 cout << "no track for " << std::distance(thePATMuonHandle->begin(), Muon1) << " filling defaults" << endl;
	  ///AF
	  muD0->push_back(0);
	  muDz->push_back(0);
	  muChi2->push_back(0);
	  muNDF->push_back(-1);
	  muPhits->push_back(0);
	  muShits->push_back(0);

	  muLayersTr->push_back(0);
	  muLayersPix->push_back(0);
	  muDzVtx->push_back(0);
	  muDxyVtx->push_back(0);
	  mufHits->push_back(0);
	  muFirstBarrel->push_back(0);
	  muFirstEndCap->push_back(0);
	  muD0E->push_back(0);
	  muDzVtxErr->push_back(0);
	  muKey->push_back(0);
	  
	  muGlChi2->push_back(0); 
	  muGlNDF->push_back(-1);
	  muGlMuHits->push_back(0);
	  muGlMatchedStation->push_back(0);
	  muGlDzVtx->push_back(0);
	  muGlDxyVtx->push_back(0);
	  
	  if (Debug_) cout <<"evt:" <<evtNum << "no track for PAT muon " <<std::distance(thePATMuonHandle->begin(), Muon1) <<" skipping muon... should skip event instead" <<endl;
	  isEventWithInvalidMu = true;
	  continue;
	}
	else {
	  muD0->push_back(rmu1->track()->d0());
	  muDz->push_back(rmu1->track()->dz());
	  muChi2->push_back(rmu1->track()->chi2());
	  muNDF->push_back(rmu1->track()->ndof());
	  muPhits->push_back(rmu1->track()->hitPattern().numberOfValidPixelHits());
	  muShits->push_back(rmu1->track()->hitPattern().numberOfValidStripHits());

	  if (Debug_) cout <<"evt:" <<evtNum <<" trackerLayersWithMeasurement=" <<rmu1->track()->hitPattern().trackerLayersWithMeasurement() <<endl;
	  if ( !(rmu1->track()->hitPattern().trackerLayersWithMeasurement()) ) { 
	    isEventWithInvalidMu = true;
	    if (Debug_) cout <<"evt:" <<evtNum <<" problem with trackerLayersWithMeasurement" <<endl;
	    continue ;
	  }
	  if ( !(rmu1->track()->hitPattern().pixelLayersWithMeasurement()) ) {
	    isEventWithInvalidMu = true;
	    continue ;
	  }
	  muLayersTr->push_back(rmu1->track()->hitPattern().trackerLayersWithMeasurement());
	  muLayersPix->push_back(rmu1->track()->hitPattern().pixelLayersWithMeasurement());	
	  muDzVtx->push_back(rmu1->track()->dz(RefVtx));
	  muDxyVtx->push_back(rmu1->track()->dxy(RefVtx));
	  mufHits->push_back((1.0*rmu1->track()->found())/ (rmu1->track()->found()+ rmu1->track()->lost() + rmu1->track()->trackerExpectedHitsInner().numberOfHits() + rmu1->track()->trackerExpectedHitsOuter().numberOfHits() ) );
	  if (Debug_) cout <<"mu found " <<rmu1->track()->found() <<" fHits=" <<(1.0*rmu1->track()->found())/ (rmu1->track()->found()+ rmu1->track()->lost() + rmu1->track()->trackerExpectedHitsInner().numberOfHits() + rmu1->track()->trackerExpectedHitsOuter().numberOfHits() ) <<endl;
	  muFirstBarrel->push_back(rmu1->track()->hitPattern().hasValidHitInFirstPixelBarrel());
	  muFirstEndCap->push_back(rmu1->track()->hitPattern().hasValidHitInFirstPixelEndcap());
	  muD0E->push_back(rmu1->track()->d0Error());
	  muDzVtxErr->push_back(rmu1->track()->dzError());
	  muKey->push_back(rmu1->track().key());
	}
	
	if (rmu1->globalTrack().isNull()) { 
	  muGlMuHits->push_back(0);
	  muGlChi2->push_back(0);
	  muGlNDF->push_back(-1);
	  muGlMatchedStation->push_back(0);
	  muGlDzVtx->push_back(-1);
	  muGlDxyVtx->push_back(-1);
	}
	else {
	  muGlMuHits->push_back(rmu1->globalTrack()->hitPattern().numberOfValidMuonHits());
	  muGlChi2->push_back(rmu1->globalTrack()->chi2());
	  muGlNDF->push_back(rmu1->globalTrack()->ndof());
	  muGlMatchedStation->push_back(rmu1->numberOfMatchedStations());
	  muGlDzVtx->push_back(rmu1->globalTrack()->dz(RefVtx));
	  muGlDxyVtx->push_back(rmu1->globalTrack()->dxy(RefVtx));
	}
	//
	muType->push_back(rmu1->type());
	int qm = 0;
	for (int qi=1; qi!= 24; ++qi) {
	  if (muon::isGoodMuon(*rmu1, muon::SelectionType(qi)))
	    qm += 1<<qi;
	}
	muQual->push_back(qm);
	muTrack->push_back(-1);// not implemented yet
	
	//check for muon1
	TrackRef muTrack1 = Muon1->track();
	if ( muTrack1.isNull() )
	  continue;      
	// cuts on muon1
	if (rmu1->track()->hitPattern().numberOfValidPixelHits() < MuMinPixHits
	    || rmu1->track()->hitPattern().numberOfValidStripHits() < MuMinSiHits
	    || rmu1->track()->chi2()/rmu1->track()->ndof() > MuMaxNormChi
	    || fabs(rmu1->track()->dxy(RefVtx)) > MuMaxD0) {
	  continue ;
	}
			
	//next check for muon2
	for ( std::vector<pat::Muon>::const_iterator Muon2 = Muon1+1;
	      Muon2 != thePATMuonHandle->end(); ++Muon2) {
	  //checks for muon2
	  if(Muon2->charge() * Muon1->charge() > 0)
	    continue ;
	  //
	  const reco::Muon* rmu2 = dynamic_cast<const reco::Muon *>(Muon2->originalObject()) ;	 
	  if (muon::overlap(*rmu1, *rmu2) )
	    continue ;	
	  //
	  TrackRef muTrack2 = Muon2->track() ;
	  if ( muTrack2.isNull() )
	    continue ;	
	  // cuts on muon2
	  if (rmu2->track()->hitPattern().numberOfValidPixelHits() < MuMinPixHits
	      || rmu2->track()->hitPattern().numberOfValidStripHits() < MuMinSiHits
	      || rmu2->track()->chi2()/rmu1->track()->ndof() > MuMaxNormChi
	      || fabs(rmu2->track()->dxy(RefVtx)) > MuMaxD0) {
	    continue ;
	  }

	  //Get the MuMu information				
	  TransientTrack muon1TT( muTrack1, &(*bFieldHandle) );
	  TransientTrack muon2TT( muTrack2, &(*bFieldHandle) );
				
	  KinematicParticleFactoryFromTransientTrack pFactory;
				
	  //initial chi2 and ndf before kinematic fits.
	  float chi = 0., ndf = 0. ;

	  vector<RefCountedKinematicParticle> muons;
	  muons.push_back( pFactory.particle( muon1TT, muon_mass, chi, ndf, small_sigma));
	  muons.push_back( pFactory.particle( muon2TT, muon_mass, chi, ndf, small_sigma));
				
	  KinematicParticleVertexFitter MuMuFitter;   
	  RefCountedKinematicTree MuMuVertexFitTree;
	  MuMuVertexFitTree = MuMuFitter.fit(muons); 
	  if (!MuMuVertexFitTree->isValid())
	    continue ; 
	
	  MuMuVertexFitTree->movePointerToTheTop();				
	  RefCountedKinematicParticle MuMuCand_fromFit = MuMuVertexFitTree->currentParticle();
	  RefCountedKinematicVertex MuMuCand_vertex_fromFit = MuMuVertexFitTree->currentDecayVertex();
				
	  MuMuVertexFitTree->movePointerToTheFirstChild();
	  RefCountedKinematicParticle Mu1Cand_fromFit = MuMuVertexFitTree->currentParticle(); // cambia i nomi togliendo MC o mettendo noMC!!!! 
	  MuMuVertexFitTree->movePointerToTheNextChild();
	  RefCountedKinematicParticle Mu2Cand_fromFit = MuMuVertexFitTree->currentParticle();
				
	  KinematicParameters Mu1Cand_KP = Mu1Cand_fromFit->currentState().kinematicParameters();
	  KinematicParameters Mu2Cand_KP = Mu2Cand_fromFit->currentState().kinematicParameters();
				
	  //Fill the MuMu vectors
	  if (MuMuCand_fromFit->currentState().mass() < MuMuMinMass  ||  MuMuCand_fromFit->currentState().mass() > MuMuMaxMass) // check
	    continue ;
 
	  MuMuMass->push_back( MuMuCand_fromFit->currentState().mass() );
				
	  MuMuDecayVtx_X->push_back( MuMuCand_vertex_fromFit->position().x() );
	  MuMuDecayVtx_Y->push_back( MuMuCand_vertex_fromFit->position().y() );
	  MuMuDecayVtx_Z->push_back( MuMuCand_vertex_fromFit->position().z() );
				
	  MuMuDecayVtx_XE->push_back( sqrt( MuMuCand_vertex_fromFit->error().cxx()) );
	  MuMuDecayVtx_YE->push_back( sqrt( MuMuCand_vertex_fromFit->error().cyy()) );
	  MuMuDecayVtx_ZE->push_back( sqrt( MuMuCand_vertex_fromFit->error().czz()) );
	  MuMuVtx_CL->push_back( ChiSquaredProbability((double)( MuMuCand_vertex_fromFit->chiSquared()),(double)( MuMuCand_vertex_fromFit->degreesOfFreedom())) );
	  MuMuVtx_Chi2->push_back( MuMuCand_vertex_fromFit->chiSquared() ) ;

	  MuMuPx->push_back( Mu1Cand_KP.momentum().x() + Mu2Cand_KP.momentum().x() );
	  MuMuPy->push_back( Mu1Cand_KP.momentum().y() + Mu2Cand_KP.momentum().y() );
	  MuMuPz->push_back( Mu1Cand_KP.momentum().z() + Mu2Cand_KP.momentum().z() );

	  mu1Idx->push_back(std::distance(thePATMuonHandle->begin(), Muon1)); 
	  mu2Idx->push_back(std::distance(thePATMuonHandle->begin(), Muon2));
				
	  mu1_MuMu_Px->push_back( Mu1Cand_KP.momentum().x());
	  mu1_MuMu_Py->push_back( Mu1Cand_KP.momentum().y());
	  mu1_MuMu_Pz->push_back( Mu1Cand_KP.momentum().z());
	  mu1_MuMu_Chi2->push_back( Mu1Cand_fromFit->chiSquared());
	  mu1_MuMu_NDF->push_back( Mu1Cand_fromFit->degreesOfFreedom());

	  mu2_MuMu_Px->push_back( Mu2Cand_KP.momentum().x());
	  mu2_MuMu_Py->push_back( Mu2Cand_KP.momentum().y());
	  mu2_MuMu_Pz->push_back( Mu2Cand_KP.momentum().z());
	  mu2_MuMu_Chi2->push_back( Mu2Cand_fromFit->chiSquared());
	  mu2_MuMu_NDF->push_back( Mu2Cand_fromFit->degreesOfFreedom());


	  Int_t dimuonType = 0;   //0 nothing,  1 J/psi  , 2 psi(2S)   
	  if ( MuMuCand_fromFit->currentState().mass() > JPsiMinMass  &&  MuMuCand_fromFit->currentState().mass() < JPsiMaxMass ) {
	    dimuonType = 1 ;
	  } else if ( MuMuCand_fromFit->currentState().mass() > PsiPrimeMinMass  &&  MuMuCand_fromFit->currentState().mass() < PsiPrimeMaxMass ) {
	    dimuonType = 2 ;
	  }
	  //cout <<dimuonType <<endl;

	  if (Debug_) cout <<"evt:" <<evtNum <<" MuMu with diMuonType = " <<dimuonType <<endl;

	  MuMuType->push_back(dimuonType);
	

	  int ntriggers = TriggersForMatching_.size();
	  for (int MatchTrig = 0; MatchTrig < ntriggers; MatchTrig++) {

	    //cout << "result " << MatchingTriggerResult[MatchTrig] << " " << TriggersForMatching_[MatchTrig] <<endl;
	    if ( MatchingTriggerResult[MatchTrig]!=0 ) {
	      const pat::TriggerObjectStandAloneCollection mu1HLTMatches = Muon1->triggerObjectMatchesByFilter( FiltersForMatching_[MatchTrig] );
	      const pat::TriggerObjectStandAloneCollection mu2HLTMatches = Muon2->triggerObjectMatchesByFilter( FiltersForMatching_[MatchTrig] );
	      bool pass1 = mu1HLTMatches.size() > 0;
	      bool pass2 = mu2HLTMatches.size() > 0;
	   
	      if ((pass1) && (pass2)) {
		MuMuMuonTrigMatch->push_back(true);
		if (Debug_) cout <<"Matched MuMu" <<endl ;
	      } else
		MuMuMuonTrigMatch->push_back(false);
	    }
	    else
	      MuMuMuonTrigMatch->push_back(false);
	  }
	  
	  // vertex without matched muons 
	  vector<TransientVertex> pvs ;
	  //
	  
	  if (addMuMulessPrimaryVertex_)
	    {
	      VertexReProducer revertex(recVtxs, iEvent);
	      Handle<TrackCollection> pvtracks;   
	      iEvent.getByLabel(revertex.inputTracks(),   pvtracks);
	      Handle<BeamSpot>        pvbeamspot;
	      iEvent.getByLabel(revertex.inputBeamSpot(), pvbeamspot);
	      //
	      if ( pvbeamspot.isValid() < 0 ) 
		continue ; 
	      if (pvbeamspot.id() != beamSpotHandle.id()) {
		edm::LogWarning("Inconsistency") << "The BeamSpot used for PV reco is not the same used in this analyzer.";
	      }
	      //
	      const reco::Muon *rmu_1 = dynamic_cast<const reco::Muon*>( Muon1->originalObject() ) ;
	      const reco::Muon *rmu_2 = dynamic_cast<const reco::Muon*>( Muon2->originalObject() ) ;
	      //
	      if (rmu_1 != 0  &&  rmu_2 != 0  &&  rmu_1->track().id() == pvtracks.id()  &&  rmu_2->track().id() == pvtracks.id() ) { 
		TrackCollection MuMuLess;
		MuMuLess.reserve(pvtracks->size());
		for (size_t i = 0, n = pvtracks->size(); i < n; ++i) {
		  if (i == rmu_1->track().key()) continue;
		  if (i == rmu_2->track().key()) continue;
		  //
		  MuMuLess.push_back((*pvtracks)[i]);
		}
		cout <<pvbeamspot.isValid() <<endl ;
		pvs = revertex.makeVertices(MuMuLess, *pvbeamspot, iSetup) ;
		//
		if (!pvs.empty()) {
		  Vertex MuMuLessPV = Vertex(pvs.front());
		  thePrimaryVtx = MuMuLessPV;
		}
	      }
	    }
	  
	  //							
	  PriVtxMuMuCorr_X->push_back( thePrimaryVtx.position().x() ) ;
	  PriVtxMuMuCorr_Y->push_back( thePrimaryVtx.position().y() ) ; 
	  PriVtxMuMuCorr_Z->push_back( thePrimaryVtx.position().z() ) ;
	  PriVtxMuMuCorr_EX->push_back( thePrimaryVtx.xError() ) ;
	  PriVtxMuMuCorr_EY->push_back( thePrimaryVtx.yError() ) ;
	  PriVtxMuMuCorr_EZ->push_back( thePrimaryVtx.zError() ) ;
	  PriVtxMuMuCorr_CL->push_back( ChiSquaredProbability( (double)(thePrimaryVtx.chi2()), (double)(thePrimaryVtx.ndof())) ) ;
	  PriVtxMuMuCorr_Chi2->push_back( thePrimaryVtx.chi2() ) ;
	  PriVtxMuMuCorr_tracks->push_back( thePrimaryVtx.tracksSize() ) ;

	  
	  ++nMuMu;
	  muons.clear();
	  //////////////////////////////////////////////////////////////////////

	  if (dimuonType == 0) 
	    continue ;
	  	
	  if (Debug_) cout <<"evt:"<<evtNum<< " is Invalid Muon ?  " <<isEventWithInvalidMu << endl;
	  /*
	    if (isEventWithInvalidMu ) { 
	    if (Debug_) cout <<"evt:"<<evtNum<< "invalid muon ... skip event" << endl;
	    continue;
	    }
	  */
	  if ( skipJPsi  &&  (dimuonType == 1) ) // skip J/psi events
	    continue ;           
	  if ( skipPsi2S  &&  (dimuonType == 2) ) // skip Psi(2S) events
	    continue ;           

		
	  if (thePATTrackHandle->size() < 2)
	    continue ;	
	  /////// cuts on MuMu mass window
	  if (MuMuMass->at(nMuMu-1) < MuMuMinMass  ||  MuMuMass->at(nMuMu-1) > MuMuMaxMass)
	    continue ;
	
	  // next check tracks for pion
	  //
	  for ( vector<pat::GenericParticle>::const_iterator Track1 = thePATTrackHandle->begin(); Track1 != thePATTrackHandle->end(); ++Track1 ) {
					
	    //check track doesn't overlap with the MuMu candidate tracks
	    if (Track1->track().key() == rmu1->track().key()  ||  Track1->track().key() == rmu2->track().key())
	      continue;
	    
	    // cuts on charged tracks	
	    if (( Track1->track()->chi2()/Track1->track()->ndof() > TrMaxNormChi2 )  ||  Track1->pt() < TrMinPt)
	      continue ;

	    //next check tracks for kaon
	    //for ( vector<pat::GenericParticle>::const_iterator Track2 = Track1+1; Track2 != thePATTrackHandle->end(); ++Track2 )
	    for ( vector<pat::GenericParticle>::const_iterator Track2 = theKaonRefittedPATTrackHandle->begin(); Track2 != theKaonRefittedPATTrackHandle->end(); ++Track2 )
	      {
		//check that this second track doesn't overlap with the the first track candidate
		if (Track2->track().key() == Track1->track().key())
		  continue ;	      
		//check track doesn't overlap with the MuMu candidate tracks
		if (Track2->track().key() == rmu1->track().key()  ||  Track2->track().key() == rmu2->track().key())
		  continue ;	      

		if (Track1->charge() * Track2->charge() > 0)
		  continue ;
	      		
		///// cuts on charged tracks	
		if ((Track2->track()->chi2() / Track2->track()->ndof() > TrMaxNormChi2)  ||  Track2->pt() < TrMinPt)
		  continue;	      
		
		// cuts on tracks' delta R								
		math::XYZTLorentzVector MuMu = (rmu1->p4() + rmu2->p4()); 
		math::XYZTLorentzVector b0 = (rmu1->p4() + rmu2->p4() + Track1->p4() + Track2->p4()); 
		//
		float MuMuPiDR = sqrt( pow(MuMu.eta() - Track1->p4().eta(),2) + pow(MuMu.phi() - Track1->p4().phi(), 2) );
		float MuMuKDR = sqrt( pow(MuMu.eta() - Track2->p4().eta(),2) + pow(MuMu.phi() - Track2->p4().phi(), 2) );
		
		float b0PiDR = sqrt( pow(b0.eta() - Track1->p4().eta(),2) + pow(b0.phi() - Track1->p4().phi(), 2));
		float b0KDR = sqrt( pow(b0.eta() - Track2->p4().eta(),2) + pow(b0.phi() - Track2->p4().phi(), 2));

		
		// B0
		if (UseB0DR) {
		  if (b0PiDR > B0TrackMaxDR  ||  b0KDR > B0TrackMaxDR)
		    continue ; // B0TrackMaxDR = 2
		} else {
		  if (MuMuPiDR > MuMuTrackMaxDR  ||  MuMuKDR > MuMuTrackMaxDR)
		    continue ; // MuMuTrackMaxDR = 3.5
		}
		
		////////// cuts on MuMu+pi+k mass window
		if ((Track1->p4() + Track2->p4() + MuMu).M() > MuMuPiKMaxMass  ||  (Track1->p4() + Track2->p4() + MuMu).M() < MuMuPiKMinMass)
		  continue ;
		
		// having two oppositely charged muons, and two oppositely charged tracks: try to vertex them
		TransientTrack pionTT( Track1->track(), &(*bFieldHandle) ); 
		TransientTrack kaonTT( Track2->track(), &(*bFieldHandle) );
		
		TransientTrack kaonTT_notRefit ;
		Bool_t notRefittedPartner = false ;
		for ( vector<pat::GenericParticle>::const_iterator Track2_notRefit = thePATTrackHandle->begin(); Track2_notRefit != thePATTrackHandle->end(); ++Track2_notRefit )
		  if ( Track2_notRefit->track().key() == Track2->track().key() ) {
		    notRefittedPartner = true ;
		    kaonTT_notRefit = TransientTrack( Track2_notRefit->track(), &(*bFieldHandle) ) ;
		    break ;
		  }
			      
		// Do mass constraint for MuMu cand and do mass constrained vertex fit
		vector<RefCountedKinematicParticle> b0Daughters;
		b0Daughters.push_back(pFactory.particle( muon1TT, muon_mass, chi, ndf, small_sigma));
		b0Daughters.push_back(pFactory.particle( muon2TT, muon_mass, chi, ndf, small_sigma));
		b0Daughters.push_back(pFactory.particle( pionTT, pion_mass, chi, ndf, small_sigma));
		b0Daughters.push_back(pFactory.particle( kaonTT, kaon_mass, chi, ndf, small_sigma));
		
		RefCountedKinematicTree B0VertexFitTree, B0VertexFitTree_noKrefit ;
		KinematicConstrainedVertexFitter B0Fitter ;
		
		if (doMuMuMassConst) { // MassConst = 'MC' in the following
		  //MultiTrackKinematicConstraint *MuMu = new  TwoTrackMassKinematicConstraint(psi2S_mass);
		  MultiTrackKinematicConstraint *MuMu = 0;
		  if (dimuonType == 1) { // constrain to JPsi mass
		    MuMu = new TwoTrackMassKinematicConstraint(Jpsi_mass);
		  } else if (dimuonType == 2) { // constrain to Psi(2S) mass
		    MuMu = new TwoTrackMassKinematicConstraint(psi2S_mass);
		  } // already asked for: if (dimuonType == 0) continue ;
		  
		  B0VertexFitTree = B0Fitter.fit( b0Daughters, MuMu );
		  if (notRefittedPartner) { // use not refitted kaons
		    b0Daughters.pop_back() ;
		    b0Daughters.push_back(pFactory.particle( kaonTT_notRefit, kaon_mass, chi, ndf, small_sigma));
		    B0VertexFitTree_noKrefit = B0Fitter.fit( b0Daughters, MuMu );
		  }
		} 
		else {
		  B0VertexFitTree = B0Fitter.fit( b0Daughters );
		  if (notRefittedPartner) { // use not refitted kaons
		  b0Daughters.pop_back() ;
		  b0Daughters.push_back(pFactory.particle( kaonTT_notRefit, kaon_mass, chi, ndf, small_sigma));
		  B0VertexFitTree_noKrefit = B0Fitter.fit( b0Daughters );
		  }
		}
		
		if ( !B0VertexFitTree->isValid() )
		  if (Debug_) cout <<"B0VertexFitTree is NOT valid!" <<endl ;
		if ( notRefittedPartner  &&  !B0VertexFitTree_noKrefit->isValid() )
		  if (Debug_) cout <<"B0VertexFitTree_noKrefit is NOT valid!" <<endl ;
		
		if ( !B0VertexFitTree->isValid() )
		  //if ( !B0VertexFitTree->isValid() || !B0VertexFitTree_noKrefit->isValid() )
		  continue ;	      
		B0VertexFitTree->movePointerToTheTop();
		RefCountedKinematicParticle B0Cand_fromMCFit = B0VertexFitTree->currentParticle();
		//B0VertexFitTree_noKrefit->movePointerToTheTop();
		//RefCountedKinematicParticle B0Cand_noKrefit_fromMCFit = B0VertexFitTree_noKrefit->currentParticle();

		RefCountedKinematicVertex B0Cand_vertex_fromMCFit = B0VertexFitTree->currentDecayVertex();	      
		//
		if ( !B0Cand_vertex_fromMCFit->vertexIsValid() )
		  continue ;
		
		if ( B0Cand_vertex_fromMCFit->chiSquared() < 0  ||  B0Cand_vertex_fromMCFit->chiSquared() > 10000 )
		  continue ;
	    
		if ( B0Cand_fromMCFit->currentState().mass() > 100 )
		  continue ;
		
		double b0VtxProb = ChiSquaredProbability((double)(B0Cand_vertex_fromMCFit->chiSquared()), (double)(B0Cand_vertex_fromMCFit->degreesOfFreedom()));
		if ( b0VtxProb < 0.005 ) // check
		  continue ; 

		// fill B0 candidate variables now
		//if (Debug_) cout <<"B0 mass with refitted Kaon = " <<B0Cand_fromMCFit->currentState().mass() <<endl ;
		//if (Debug_) cout <<"B0 mass with NOT refitted Kaon = " <<B0Cand_noKrefit_fromMCFit->currentState().mass() <<endl ;
		b0Mass->push_back( B0Cand_fromMCFit->currentState().mass()) ;
		b0Px->push_back( B0Cand_fromMCFit->currentState().globalMomentum().x()) ;
		b0Py->push_back( B0Cand_fromMCFit->currentState().globalMomentum().y()) ;
		b0Pz->push_back( B0Cand_fromMCFit->currentState().globalMomentum().z()) ;			
		b0PxE->push_back( sqrt( B0Cand_fromMCFit->currentState().kinematicParametersError().matrix()(3,3) ) ) ;
		b0PyE->push_back( sqrt( B0Cand_fromMCFit->currentState().kinematicParametersError().matrix()(4,4) ) ) ;
		b0PzE->push_back( sqrt( B0Cand_fromMCFit->currentState().kinematicParametersError().matrix()(5,5) ) ) ;			
		b0Vtx_CL->push_back( ChiSquaredProbability((double)(B0Cand_vertex_fromMCFit->chiSquared()), (double)(B0Cand_vertex_fromMCFit->degreesOfFreedom())) );
		b0Vtx_Chi2->push_back( B0Cand_vertex_fromMCFit->chiSquared() ) ;

		b0DecayVtx_X->push_back((*B0Cand_vertex_fromMCFit).position().x());
		b0DecayVtx_Y->push_back((*B0Cand_vertex_fromMCFit).position().y());
		b0DecayVtx_Z->push_back((*B0Cand_vertex_fromMCFit).position().z());
		b0DecayVtx_XE->push_back(sqrt((*B0Cand_vertex_fromMCFit).error().cxx()));
		b0DecayVtx_YE->push_back(sqrt((*B0Cand_vertex_fromMCFit).error().cyy()));
		b0DecayVtx_ZE->push_back(sqrt((*B0Cand_vertex_fromMCFit).error().czz()));
						
		B0VertexFitTree->movePointerToTheFirstChild(); 
		RefCountedKinematicParticle mu1_MuMuPiK = B0VertexFitTree->currentParticle();
		B0VertexFitTree->movePointerToTheNextChild();
		RefCountedKinematicParticle mu2_MuMuPiK = B0VertexFitTree->currentParticle();
		B0VertexFitTree->movePointerToTheNextChild();
		RefCountedKinematicParticle pi_MuMuPiK = B0VertexFitTree->currentParticle();
		B0VertexFitTree->movePointerToTheNextChild();
		RefCountedKinematicParticle k_MuMuPiK = B0VertexFitTree->currentParticle();
		// muon1			
		mu1Px_MuMuPiK->push_back( mu1_MuMuPiK->currentState().globalMomentum().x() );
		mu1Py_MuMuPiK->push_back( mu1_MuMuPiK->currentState().globalMomentum().y() );
		mu1Pz_MuMuPiK->push_back( mu1_MuMuPiK->currentState().globalMomentum().z() );
		mu1E_MuMuPiK->push_back( mu1_MuMuPiK->currentState().kinematicParameters().energy() );
		// muon2
		mu2Px_MuMuPiK->push_back( mu2_MuMuPiK->currentState().globalMomentum().x() );
		mu2Py_MuMuPiK->push_back( mu2_MuMuPiK->currentState().globalMomentum().y() );
		mu2Pz_MuMuPiK->push_back( mu2_MuMuPiK->currentState().globalMomentum().z() );
		mu2E_MuMuPiK->push_back( mu2_MuMuPiK->currentState().kinematicParameters().energy() );
		// pion
		piPx_MuMuPiK->push_back( pi_MuMuPiK->currentState().globalMomentum().x() );
		piPy_MuMuPiK->push_back( pi_MuMuPiK->currentState().globalMomentum().y() );
		piPz_MuMuPiK->push_back( pi_MuMuPiK->currentState().globalMomentum().z() );
		piE_MuMuPiK->push_back( pi_MuMuPiK->currentState().kinematicParameters().energy() );
		// dE/dx	
		Double_t theo = 0., sigma = 0. ;
		pion_nsigdedx->push_back(nsigmaofdedx(Track1->track(),theo,sigma));
		pion_dedx->push_back(getEnergyLoss(Track1->track()));
		pion_dedxMass->push_back(GetMass(Track1->track()));
		pion_theo->push_back(theo);
		pion_sigma->push_back(sigma);
		// dE/dx hits
		pion_dedx_byHits->push_back( (dEdxTrack)[Track1->track()].dEdx() );
		pion_dedxErr_byHits->push_back( (dEdxTrack)[Track1->track()].dEdxError() );
		pion_saturMeas_byHits->push_back( (dEdxTrack)[Track1->track()].numberOfSaturatedMeasurements() );
		pion_Meas_byHits->push_back( (dEdxTrack)[Track1->track()].numberOfMeasurements() );
		// kaon
		kPx_MuMuPiK->push_back( k_MuMuPiK->currentState().globalMomentum().x() );
		kPy_MuMuPiK->push_back( k_MuMuPiK->currentState().globalMomentum().y() );
		kPz_MuMuPiK->push_back( k_MuMuPiK->currentState().globalMomentum().z() );
		kE_MuMuPiK->push_back( k_MuMuPiK->currentState().kinematicParameters().energy() );
		// dE/dx	
		/*theo = 0.; sigma = 0. ;
		kaon_nsigdedx->push_back(nsigmaofdedx(Track2->track(),theo,sigma));
		kaon_dedx->push_back(getEnergyLoss(Track2->track()));
		kaon_dedxMass->push_back(GetMass(Track2->track()));
		kaon_theo->push_back(theo);
		kaon_sigma->push_back(sigma);*/
		// dE/dx hits
		kaon_dedx_byHits->push_back( (dEdxTrack_Kaon)[Track2->track()].dEdx() );
		kaon_dedxErr_byHits->push_back( (dEdxTrack_Kaon)[Track2->track()].dEdxError() );
		kaon_saturMeas_byHits->push_back( (dEdxTrack_Kaon)[Track2->track()].numberOfSaturatedMeasurements() );
		kaon_Meas_byHits->push_back( (dEdxTrack_Kaon)[Track2->track()].numberOfMeasurements() );

		///////////////////////////////////						
													
		vector<TransientVertex> B0_pvs ;  
		if (addB0lessPrimaryVertex_) 
		  {
		    VertexReProducer revertex(recVtxs, iEvent);
		    Handle<TrackCollection> pvtracks;   
		    iEvent.getByLabel(revertex.inputTracks(),   pvtracks);
		    Handle<BeamSpot>        pvbeamspot;
		    iEvent.getByLabel(revertex.inputBeamSpot(), pvbeamspot);
		    //
		    if (pvbeamspot.id() != beamSpotHandle.id() ) 
		      edm::LogWarning("Inconsistency") << "The BeamSpot used for PV reco is not the same used in this analyzer.";
		    //
		    const reco::Muon *B0rmu_1 = dynamic_cast<const reco::Muon *>(Muon1->originalObject());
		    const reco::Muon *B0rmu_2 = dynamic_cast<const reco::Muon *>(Muon2->originalObject());
		    //
		    if (B0rmu_1 != 0  &&  B0rmu_2 != 0  &&  B0rmu_1->track().id() == pvtracks.id()  &&  B0rmu_2->track().id() == pvtracks.id() 
			&&  Track1->track().id() == pvtracks.id()  &&  Track2->track().id() ==  pvtracks.id()) { 
		      TrackCollection B0Less;
		      B0Less.reserve(pvtracks->size());
		      for (size_t i = 0, n = pvtracks->size(); i < n; ++i) {
			if (i == B0rmu_1->track().key()) continue;
			if (i == B0rmu_2->track().key()) continue;
			if (i == Track1->track().key()) continue;
			if (i == Track2->track().key()) continue;
			B0Less.push_back((*pvtracks)[i]);
		      }
		      B0_pvs = revertex.makeVertices(B0Less, *pvbeamspot, iSetup) ;
		      if (!B0_pvs.empty()) {
			Vertex B0LessPV = Vertex(B0_pvs.front());
			thePrimaryVtx = B0LessPV;
		      }
		    }
		  }
		

		TVector3 B0_vtx((*B0Cand_vertex_fromMCFit).position().x(), (*B0Cand_vertex_fromMCFit).position().y(), 0) ;			
		TVector3 B0_pperp(B0Cand_fromMCFit->currentState().globalMomentum().x(), B0Cand_fromMCFit->currentState().globalMomentum().y(), 0);
		TVector3 B0_pvtx ;
		TVector3 B0_vdiff ;

		// Find the PV with the largest B0_cos(alpha)
		Vertex theCosAlphaV = thePrimaryVtx ; // first declaration here
		float maxCosAlpha = -1. ;
		//
		for (VertexCollection::const_iterator itv = recVtxs->begin(), itvend = recVtxs->end(); itv != itvend; ++itv) {
		  B0_pvtx.SetXYZ(itv->position().x(), itv->position().y(), 0) ;	
		  B0_vdiff = B0_vtx - B0_pvtx ;
		  float cosAlpha_temp = B0_vdiff.Dot(B0_pperp) / (B0_vdiff.Perp()*B0_pperp.Perp()) ;
		  
		  if ( cosAlpha_temp > maxCosAlpha ) {
		    maxCosAlpha = cosAlpha_temp ;    
		    //thePrimaryVtx = Vertex(*itv);
		    //theCosAlphaV = thePrimaryVtx;
		    theCosAlphaV = Vertex(*itv) ;
		  }
		}
		//							
		PriVtx_B0CosAlpha_X->push_back( theCosAlphaV.position().x() ) ;
		PriVtx_B0CosAlpha_Y->push_back( theCosAlphaV.position().y() ) ;
		PriVtx_B0CosAlpha_Z->push_back( theCosAlphaV.position().z() ) ;
		PriVtx_B0CosAlpha_EX->push_back( theCosAlphaV.xError() ) ;
		PriVtx_B0CosAlpha_EY->push_back( theCosAlphaV.yError() ) ;
		PriVtx_B0CosAlpha_EZ->push_back( theCosAlphaV.zError() ) ;
		PriVtx_B0CosAlpha_CL->push_back( ChiSquaredProbability((double)(theCosAlphaV.chi2()), (double)(theCosAlphaV.ndof())) ) ;
		PriVtx_B0CosAlpha_Chi2->push_back( theCosAlphaV.chi2() ) ;
		PriVtx_B0CosAlpha_tracks->push_back( theCosAlphaV.tracksSize() ) ;

		
		Vertex theOtherV = thePrimaryVtx; 
		//			
		if (resolveAmbiguity_) {
		  float minDz = 999999. ;
		  if (!addB0lessPrimaryVertex_) {
		    for (VertexCollection::const_iterator itv = recVtxs->begin(), itvend = recVtxs->end(); itv != itvend; ++itv)
		      {
			float deltaZ = fabs((*B0Cand_vertex_fromMCFit).position().z() - itv->position().z()) ;
			if ( deltaZ < minDz ) {
			  minDz = deltaZ;    
			  thePrimaryVtx = Vertex(*itv);
			  theOtherV = thePrimaryVtx;
			}
		      }
		  } else {
		    for (vector<TransientVertex>::iterator itv2 = B0_pvs.begin(), itvend2 = B0_pvs.end(); itv2 != itvend2; ++itv2)
		      {
			float deltaZ = fabs((*B0Cand_vertex_fromMCFit).position().z() - itv2->position().z()) ;
			if ( deltaZ < minDz ) {
			  minDz = deltaZ;    
			  Vertex B0LessPV = Vertex(*itv2); 
			  thePrimaryVtx = B0LessPV;
			  theOtherV = B0LessPV;
			}
		      }
		  }
		} 
	    
	
		Vertex TheOtherVertex3D = thePrimaryVtx; 
		//cout<<" choose PV ="<<endl;
		if (resolveAmbiguity_) {
		  float minDz = 999999.;
		  //float minDzTrack = 999999.;
		  if (!addB0lessPrimaryVertex_) {
		    for (VertexCollection::const_iterator itv = recVtxs->begin(), itvend = recVtxs->end(); itv != itvend; ++itv) {
		      float deltaZ = fabs((*B0Cand_vertex_fromMCFit).position().z() - itv->position().z()) ;
		      if ( deltaZ < minDz ) {
			minDz = deltaZ;    
			TheOtherVertex3D = Vertex(*itv);
		      }
		    }
		  } else {
		    for (vector<TransientVertex>::iterator itv2 = B0_pvs.begin(), itvend2 = B0_pvs.end(); itv2 != itvend2; ++itv2) {
		      VertexDistance3D a3d;
		      float deltaZ   = a3d.distance(Vertex(*itv2), Vertex(*B0Cand_vertex_fromMCFit)).value();
		      if ( deltaZ < minDz ) {
			minDz = deltaZ;    
			Vertex XLessPV = Vertex(*itv2); 
			TheOtherVertex3D = XLessPV;
			//cout<<" z(X) - z(vtx) min="<<minDz<<endl; 
		      }
		      
		    }
		  }
		} 
		
		//					
		PriVtxB0Corr_X->push_back( thePrimaryVtx.position().x() ) ;
		PriVtxB0Corr_Y->push_back( thePrimaryVtx.position().y() ) ;
		PriVtxB0Corr_Z->push_back( thePrimaryVtx.position().z() ) ; 
		PriVtxB0Corr_EX->push_back( thePrimaryVtx.xError() ) ;
		PriVtxB0Corr_EY->push_back( thePrimaryVtx.yError() ) ;
		PriVtxB0Corr_EZ->push_back( thePrimaryVtx.zError() ) ;
		PriVtxB0Corr_CL->push_back( ChiSquaredProbability( (double)(thePrimaryVtx.chi2()), (double)(thePrimaryVtx.ndof())) );
		PriVtxB0Corr_Chi2->push_back( thePrimaryVtx.chi2() ) ;
		PriVtxB0Corr_tracks->push_back( thePrimaryVtx.tracksSize() ) ;
		//			
		///////////////////////////////////////////////////////////////////////////////
						
						
		VertexDistanceXY B0_vdistXY;
												
		AlgebraicVector B0_vpperp(3);
		B0_vpperp[0] = B0_pperp.x(); B0_vpperp[1] = B0_pperp.y(); B0_vpperp[2] = 0.;
		AlgebraicVector3 B0_v3pperp ;
		B0_v3pperp[0] = B0_pperp.x(); B0_v3pperp[1] = B0_pperp.y(); B0_v3pperp[2] = 0.;

		// Lifetime PV
		B0_pvtx.SetXYZ(thePrimaryVtx.position().x(), thePrimaryVtx.position().y(), 0) ;
		B0_vdiff = B0_vtx - B0_pvtx ;
		double B0_cosAlpha = B0_vdiff.Dot(B0_pperp) / (B0_vdiff.Perp()*B0_pperp.Perp()) ;
		Measurement1D B0_distXY = B0_vdistXY.distance(Vertex(*B0Cand_vertex_fromMCFit), Vertex(thePrimaryVtx));
		double B0_ctauPV = B0_distXY.value() * B0_cosAlpha * B0Cand_fromMCFit->currentState().mass() / B0_pperp.Perp();
						
		GlobalError B0_v1e = (Vertex(*B0Cand_vertex_fromMCFit)).error();
		GlobalError B0_v2e = thePrimaryVtx.error();
		//AlgebraicSymMatrix B0_vXYe = B0_v1e.matrix() + B0_v2e.matrix() ;
		AlgebraicSymMatrix33 B0_vXYe = B0_v1e.matrix() + B0_v2e.matrix() ;
		//double ctauErrPV = sqrt(B0_vXYe.similarity(B0_vpperp)) * B0Cand_fromMCFit->currentState().mass() / (B0_pperp.Perp2()) ;
		double ctauErrPV = sqrt(ROOT::Math::Similarity(B0_v3pperp,B0_vXYe)) * B0Cand_fromMCFit->currentState().mass() / (B0_pperp.Perp2()) ;
		float lxyPV = B0_vdiff.Dot(B0_pperp)/B0_pperp.Mag();
						
		b0CosAlphaPV->push_back(B0_cosAlpha);
		b0CTauPV->push_back(B0_ctauPV);
		b0CTauPVE->push_back(ctauErrPV);
		b0LxyPV->push_back(lxyPV);
					
		
		// Lifetime wrt PV with largest B0_cos(alpha) candidate 
		B0_pvtx.SetXYZ(theCosAlphaV.position().x(), theCosAlphaV.position().y(), 0) ;	
		B0_vdiff = B0_vtx - B0_pvtx ;
		B0_cosAlpha =  maxCosAlpha ;
		B0_distXY = B0_vdistXY.distance( Vertex(*B0Cand_vertex_fromMCFit), Vertex(theCosAlphaV) ) ;
		double B0_ctauPVCosAlpha = B0_distXY.value() * B0_cosAlpha * B0Cand_fromMCFit->currentState().mass() / B0_pperp.Perp();
		
		GlobalError B0_v1eCosAlpha = (Vertex(*B0Cand_vertex_fromMCFit)).error();
		GlobalError B0_v2eCosAlpha = theCosAlphaV.error();
		AlgebraicSymMatrix33 B0_vXYeCosAlpha = B0_v1eCosAlpha.matrix() + B0_v2eCosAlpha.matrix();
		//double B0_ctauErrPVCosAlpha = sqrt(B0_vXYeCosAlpha.similarity(B0_vpperp))*B0Cand_fromMCFit->currentState().mass()/(B0_pperp.Perp2());
		double B0_ctauErrPVCosAlpha = sqrt(ROOT::Math::Similarity(B0_v3pperp,B0_vXYeCosAlpha)) * B0Cand_fromMCFit->currentState().mass() / (B0_pperp.Perp2());
		float B0_lxyPVCosAlpha = B0_vdiff.Dot(B0_pperp) / B0_pperp.Mag() ;
		
		b0CosAlphaPVCosAlpha->push_back( B0_cosAlpha ) ;
		b0CTauPVCosAlpha->push_back( B0_ctauPVCosAlpha ) ;
		b0CTauPVCosAlphaE->push_back( B0_ctauErrPVCosAlpha ) ;
		b0LxyPVCosAlpha->push_back( B0_lxyPVCosAlpha ) ;


		// Lifetime wrt PV with smaller longitudinal X impact parameter 
		B0_pvtx.SetXYZ(theOtherV.position().x(), theOtherV.position().y(), 0);
		B0_vdiff = B0_vtx - B0_pvtx;
		B0_cosAlpha = B0_vdiff.Dot(B0_pperp) / (B0_vdiff.Perp()*B0_pperp.Perp());
		B0_distXY = B0_vdistXY.distance(Vertex(*B0Cand_vertex_fromMCFit), Vertex(theOtherV));
		double B0_ctauPVX = B0_distXY.value() * B0_cosAlpha * B0Cand_fromMCFit->currentState().mass() / B0_pperp.Perp();
		GlobalError B0_v1eX = (Vertex(*B0Cand_vertex_fromMCFit)).error();
		GlobalError B0_v2eX = theOtherV.error();
		AlgebraicSymMatrix33 B0_vXYeX = B0_v1eX.matrix() + B0_v2eX.matrix();
		//double ctauErrPVX = sqrt(B0_vXYeX.similarity(B0_vpperp))*B0Cand_fromMCFit->currentState().mass()/(B0_pperp.Perp2());
		double ctauErrPVX = sqrt(ROOT::Math::Similarity(B0_v3pperp,B0_vXYeX)) * B0Cand_fromMCFit->currentState().mass() / (B0_pperp.Perp2());
		float lxyPVX = B0_vdiff.Dot(B0_pperp) / B0_pperp.Mag() ;
	    
		b0CosAlphaPVX->push_back(B0_cosAlpha);
		b0CTauPVX->push_back(B0_ctauPVX);
		b0CTauPVXE->push_back(ctauErrPVX);
		b0LxyPVX->push_back(lxyPVX);
	    

		VertexDistance3D a3d; 
		float Dist3DPV     = a3d.distance(TheOtherVertex3D, Vertex(*B0Cand_vertex_fromMCFit)).value() ;
		float Dist3DPV_err = a3d.distance(TheOtherVertex3D, Vertex(*B0Cand_vertex_fromMCFit)).error() ;
		b0CTauPVX_3D->push_back(Dist3DPV);
		b0CTauPVX_3D_err->push_back(Dist3DPV_err);
		//cout << Dist3DPV << " " << Dist3DPV_err << endl; 


		//Lifetime BS
		B0_pvtx.SetXYZ(theBeamSpotVtx.position().x(), theBeamSpotVtx.position().y(), 0);
		B0_vdiff = B0_vtx - B0_pvtx;
		B0_cosAlpha = B0_vdiff.Dot(B0_pperp)/(B0_vdiff.Perp()*B0_pperp.Perp());
		B0_distXY = B0_vdistXY.distance(Vertex(*B0Cand_vertex_fromMCFit), Vertex(theBeamSpotVtx));
		double ctauBS = B0_distXY.value()*B0_cosAlpha*B0Cand_fromMCFit->currentState().mass()/B0_pperp.Perp();
		GlobalError B0_v1eB = (Vertex(*B0Cand_vertex_fromMCFit)).error();
		GlobalError B0_v2eB = theBeamSpotVtx.error();
		//AlgebraicSymMatrix B0_vXYeB = B0_v1eB.matrix() + B0_v2eB.matrix();
		AlgebraicSymMatrix33 B0_vXYeB = B0_v1eB.matrix() + B0_v2eB.matrix();
		//double ctauErrBS = sqrt(B0_vXYeB.similarity(B0_vpperp))*B0Cand_fromMCFit->currentState().mass()/(B0_pperp.Perp2());
		double ctauErrBS = sqrt(ROOT::Math::Similarity(B0_v3pperp,B0_vXYeB)) * B0Cand_fromMCFit->currentState().mass()/(B0_pperp.Perp2());
		float lxyBS = B0_vdiff.Dot(B0_pperp)/B0_pperp.Mag();
						
		b0CosAlphaBS->push_back(B0_cosAlpha);
		b0CTauBS->push_back(ctauBS);
		b0CTauBSE->push_back(ctauErrBS);
		b0LxyBS->push_back(lxyBS);

		B0_MuMuIdx->push_back(nMuMu-1);
		B0_piIdx->push_back(std::distance(thePATTrackHandle->begin(), Track1));
		//B0_kIdx->push_back(std::distance(thePATTrackHandle->begin(), Track2));
		B0_kIdx->push_back(std::distance(theKaonRefittedPATTrackHandle->begin(), Track2));
		
		nB0++;
						
		b0Daughters.clear();
	      }// 2nd loop over track (look for k)
	  }// 1st loop over track (look for pi)
	  
	}// 2nd loop over muons (look for mu-)
      }//first loop over muons (look for mu+)
    }//if two muons
	
  // AT THE END OF THE EVENT fill the tree and clear the vectors
  // ===========================================================
	
  if (nMuMu > 0)
    Z_One_Tree_->Fill() ;
  //
  //
  // trigger stuff
  trigRes->clear(); trigNames->clear(); L1TT->clear(); MatchTriggerNames->clear(); 
  //
  // event numbers
  runNum = 0; evtNum = 0; lumiNum = 0;
  //
  // counters
  nMu = 0; nMuMu = 0; nB0 = 0; 
  //
  // indices
  mu1Idx->clear(); mu2Idx->clear();
  // B0
  B0_MuMuIdx->clear(); B0_piIdx->clear(); B0_kIdx->clear();
  //
  // Primary Vertex	
  priVtx_X = 0; priVtx_Y = 0; priVtx_Z = 0 ; 
  priVtx_XE = 0; priVtx_YE = 0; priVtx_ZE = 0 ; 
  priVtx_NormChi2 = 0; priVtx_Chi2 = 0; priVtx_CL = 0, priVtx_tracks = 0 ;
  //
  // MuMu cand
  MuMuMass->clear(); MuMuVtx_CL->clear(); MuMuVtx_Chi2->clear(); 
  MuMuPx->clear(); MuMuPy->clear(); MuMuPz->clear();
  MuMuDecayVtx_X->clear(); MuMuDecayVtx_Y->clear(); MuMuDecayVtx_Z->clear();
  MuMuDecayVtx_XE->clear(); MuMuDecayVtx_YE->clear(); MuMuDecayVtx_ZE->clear();
  MuMuMuonTrigMatch->clear();
  //
  // muons from MuMu fit
  mu1_MuMu_Px->clear(); mu1_MuMu_Py->clear(); mu1_MuMu_Pz->clear(); mu1_MuMu_Chi2->clear(); mu1_MuMu_NDF->clear();
  mu2_MuMu_Px->clear(); mu2_MuMu_Py->clear(); mu2_MuMu_Pz->clear(); mu2_MuMu_Chi2->clear(); mu2_MuMu_NDF->clear();
  MuMuType->clear();
  // Primary Vertex with "MuMu correction"
  PriVtxMuMuCorr_X->clear(); PriVtxMuMuCorr_Y->clear(); PriVtxMuMuCorr_Z->clear(); 
  PriVtxMuMuCorr_EX->clear(); PriVtxMuMuCorr_EY->clear(); PriVtxMuMuCorr_EZ->clear();  
  PriVtxMuMuCorr_Chi2->clear(); PriVtxMuMuCorr_CL->clear(); PriVtxMuMuCorr_tracks->clear();
  //
  // B0 cand	
  b0Mass->clear(); b0Vtx_CL->clear(); b0Vtx_Chi2->clear(); 
  b0Px->clear(); b0Py->clear(); b0Pz->clear(); 
  b0PxE->clear(); b0PyE->clear(); b0PzE->clear();
  b0DecayVtx_X->clear(); b0DecayVtx_Y->clear(); b0DecayVtx_Z->clear(); 
  b0DecayVtx_XE->clear(); b0DecayVtx_YE->clear(); b0DecayVtx_ZE->clear(); 
  // muons and tracks after B0 Cand fit
  mu1Px_MuMuPiK->clear(); mu1Py_MuMuPiK->clear(); mu1Pz_MuMuPiK->clear(); mu1E_MuMuPiK->clear();
  mu2Px_MuMuPiK->clear(); mu2Py_MuMuPiK->clear(); mu2Pz_MuMuPiK->clear(); mu2E_MuMuPiK->clear();
  piPx_MuMuPiK->clear(); piPy_MuMuPiK->clear(); piPz_MuMuPiK->clear(); piE_MuMuPiK->clear();
  pion_nsigdedx->clear(); pion_dedx->clear(); pion_dedxMass->clear(); pion_theo->clear(); pion_sigma->clear();
  pion_dedx_byHits->clear(); pion_dedxErr_byHits->clear(); pion_saturMeas_byHits->clear(); pion_Meas_byHits->clear();
  kPx_MuMuPiK->clear(); kPy_MuMuPiK->clear(); kPz_MuMuPiK->clear(); kE_MuMuPiK->clear();
  kaon_nsigdedx->clear(); kaon_dedx->clear(); kaon_dedxMass->clear(); kaon_theo->clear(); kaon_sigma->clear();
  kaon_dedx_byHits->clear(); kaon_dedxErr_byHits->clear(); kaon_saturMeas_byHits->clear(); kaon_Meas_byHits->clear();
  // Primary Vertex with largest B0_cos(alpha)
  PriVtx_B0CosAlpha_X->clear(); PriVtx_B0CosAlpha_Y->clear(); PriVtx_B0CosAlpha_Z->clear(); 
  PriVtx_B0CosAlpha_EX->clear(); PriVtx_B0CosAlpha_EY->clear(); PriVtx_B0CosAlpha_EZ->clear();  
  PriVtx_B0CosAlpha_Chi2->clear(); PriVtx_B0CosAlpha_CL->clear(); PriVtx_B0CosAlpha_tracks->clear();
  // Primary Vertex with "B0 correction"
  PriVtxB0Corr_X->clear(); PriVtxB0Corr_Y->clear(); PriVtxB0Corr_Z->clear(); 
  PriVtxB0Corr_EX->clear(); PriVtxB0Corr_EY->clear(); PriVtxB0Corr_EZ->clear();  
  PriVtxB0Corr_Chi2->clear(); PriVtxB0Corr_CL->clear(); PriVtxB0Corr_tracks->clear();
  //
  // B0 lifetime
  b0LxyPV->clear(); b0CosAlphaPV->clear(); b0CTauPV->clear(); b0CTauPVE->clear(); 
  b0LxyPVCosAlpha->clear(); b0CosAlphaPVCosAlpha->clear(); b0CTauPVCosAlpha->clear(); b0CTauPVCosAlphaE->clear();
  b0LxyPVX->clear(); b0CosAlphaPVX->clear(); b0CTauPVX->clear(); b0CTauPVXE->clear();
  b0LxyBS->clear(); b0CosAlphaBS->clear(); b0CTauBS->clear(); b0CTauBSE->clear();
  b0CTauPVX_3D->clear(); b0CTauPVX_3D_err->clear();
  //
  muPx->clear(); muPy->clear(); muPz->clear(); 
  muD0->clear(); muDz->clear(); muChi2->clear(); muGlChi2->clear();
  mufHits->clear(); muFirstBarrel->clear(); muFirstEndCap->clear(); muD0E->clear() ;  muDzVtxErr->clear() ; muKey->clear() ;
  muDzVtx->clear(); muDxyVtx->clear(); muGlMatchedStation->clear(); muGlDzVtx->clear(); muGlDxyVtx->clear(); 
  muNDF->clear(); muGlNDF->clear(); muPhits->clear(); muShits->clear(); muGlMuHits->clear(); muType->clear(); 
  muQual->clear(); muTrack->clear(); muCharge->clear();
  //
  // tracks
  trNotRef->clear(); trRef->clear();
  //
  trPx->clear(); trPy->clear(); trPz->clear(); trE->clear();	
  trNDF->clear(); trPhits->clear(); trShits->clear(); trChi2->clear();
  trD0->clear(); trD0E->clear(); trCharge->clear();
  trQualityHighPurity->clear(); trQualityTight->clear();
  trfHits->clear(); trFirstBarrel->clear(); trFirstEndCap->clear();
  trDzVtx->clear(); trDxyVtx->clear();
  tr_nsigdedx->clear(); tr_dedx->clear(); tr_dedxMass->clear(); tr_theo->clear(); tr_sigma->clear();
  tr_dedx_byHits->clear(); tr_dedxErr_byHits->clear(); tr_saturMeas_byHits->clear(); tr_Meas_byHits->clear();
  //

}// analyze


// ------------ method called once each job just before starting event loop  ------------
void MuMuPiKPAT::beginRun(edm::Run const & iRun, edm::EventSetup const& iSetup){
  //   bool changed = true;
  //   proccessName_="HLT";
  //   hltConfig_.init(iRun,iSetup,proccessName_,changed);
}


void MuMuPiKPAT::beginJob()
{
  edm::Service<TFileService> fs;
	
  Z_One_Tree_ = fs->make<TTree>("Z_data", "Z(4430) Data");

  Z_One_Tree_->Branch("TrigRes", &trigRes);
  Z_One_Tree_->Branch("TrigNames", &trigNames);
  Z_One_Tree_->Branch("MatchTriggerNames", &MatchTriggerNames);
  Z_One_Tree_->Branch("L1TrigRes", &L1TT);
  //
  Z_One_Tree_->Branch("evtNum",&evtNum,"evtNum/i");
  Z_One_Tree_->Branch("runNum",&runNum,"runNum/i");
  Z_One_Tree_->Branch("lumiNum", &lumiNum, "lumiNum/i");
  //
  Z_One_Tree_->Branch("priVtx_X",&priVtx_X, "priVtx_X/f");
  Z_One_Tree_->Branch("priVtx_Y",&priVtx_Y, "priVtx_Y/f");
  Z_One_Tree_->Branch("priVtx_Z",&priVtx_Z, "priVtx_Z/f");
  Z_One_Tree_->Branch("priVtx_XE",&priVtx_XE, "priVtx_XE/f");
  Z_One_Tree_->Branch("priVtx_YE",&priVtx_YE, "priVtx_YE/f");
  Z_One_Tree_->Branch("priVtx_ZE",&priVtx_ZE, "priVtx_ZE/f");
  Z_One_Tree_->Branch("priVtx_NormChi2",&priVtx_NormChi2, "priVtx_NormChi2/f");
  Z_One_Tree_->Branch("priVtx_Chi2",&priVtx_Chi2, "priVtx_Chi2/f");
  Z_One_Tree_->Branch("priVtx_CL",&priVtx_CL, "priVtx_CL/f");
  Z_One_Tree_->Branch("priVtx_tracks", &priVtx_tracks, "priVtx_tracks/i");
  //
  Z_One_Tree_->Branch("nMu", &nMu, "nMu/i");
  Z_One_Tree_->Branch("muPx",&muPx);
  Z_One_Tree_->Branch("muPy",&muPy);
  Z_One_Tree_->Branch("muPz",&muPz);
  Z_One_Tree_->Branch("muD0",&muD0);
  Z_One_Tree_->Branch("muDz",&muDz);
  Z_One_Tree_->Branch("muChi2",&muChi2);
  Z_One_Tree_->Branch("muNDF",&muNDF);
  Z_One_Tree_->Branch("muPhits",&muPhits);
  Z_One_Tree_->Branch("muShits",&muShits);

  Z_One_Tree_->Branch("muLayersTr",&muLayersTr);
  Z_One_Tree_->Branch("muLayersPix",&muLayersPix);
    
  Z_One_Tree_->Branch("muD0E",&muD0E);
  Z_One_Tree_->Branch("muDzVtxErr",&muDzVtxErr);
  Z_One_Tree_->Branch("muKey",&muKey);
    
  Z_One_Tree_->Branch("muGlMuHits",&muGlMuHits);
  Z_One_Tree_->Branch("muGlChi2",&muGlChi2);
  Z_One_Tree_->Branch("muGlNDF",&muGlNDF);
  Z_One_Tree_->Branch("muGlMatchedStation",&muGlMatchedStation);
  Z_One_Tree_->Branch("muGlDzVtx", &muGlDzVtx);
  Z_One_Tree_->Branch("muGlDxyVtx", &muGlDxyVtx);

  Z_One_Tree_->Branch("muType",&muType);
  Z_One_Tree_->Branch("muQual",&muQual);
  Z_One_Tree_->Branch("muTrack",&muTrack);
  Z_One_Tree_->Branch("muCharge", &muCharge);
  //
  Z_One_Tree_->Branch("mufHits", &mufHits);
  Z_One_Tree_->Branch("muFirstBarrel", &muFirstBarrel);
  Z_One_Tree_->Branch("muFirstEndCap", &muFirstEndCap);
  Z_One_Tree_->Branch("muDzVtx", &muDzVtx);
  Z_One_Tree_->Branch("muDxyVtx", &muDxyVtx);
  //
  Z_One_Tree_->Branch("trNotRef", &trNotRef);
  Z_One_Tree_->Branch("trRef", &trRef);
  //
  Z_One_Tree_->Branch("trackPx", &trPx);
  Z_One_Tree_->Branch("trackPy", &trPy);
  Z_One_Tree_->Branch("trackPz", &trPz);
  Z_One_Tree_->Branch("trackEnergy", &trE);
  Z_One_Tree_->Branch("trackNDF", &trNDF);
  Z_One_Tree_->Branch("trackPhits", &trPhits);
  Z_One_Tree_->Branch("trackShits", &trShits);
  Z_One_Tree_->Branch("trackChi2", &trChi2);
  Z_One_Tree_->Branch("trackD0", &trD0);
  Z_One_Tree_->Branch("trackD0Err", &trD0E);
  Z_One_Tree_->Branch("trackCharge", &trCharge);
  Z_One_Tree_->Branch("TrackHighPurity", &trQualityHighPurity);
  Z_One_Tree_->Branch("TrackTight", &trQualityTight);
  Z_One_Tree_->Branch("trackfHits", &trfHits);
  Z_One_Tree_->Branch("trackFirstBarrel", &trFirstBarrel);
  Z_One_Tree_->Branch("trackFirstEndCap", &trFirstEndCap);
  Z_One_Tree_->Branch("trackDzVtx", &trDzVtx);
  Z_One_Tree_->Branch("trackDxyVtx", &trDxyVtx);
  //
  Z_One_Tree_->Branch("tr_nsigdedx", &tr_nsigdedx);
  Z_One_Tree_->Branch("tr_dedx", &tr_dedx);
  Z_One_Tree_->Branch("tr_dedxMass", &tr_dedxMass);
  Z_One_Tree_->Branch("tr_theo", &tr_theo);
  Z_One_Tree_->Branch("tr_sigma", &tr_sigma);
  // by hits
  Z_One_Tree_->Branch("tr_dedx_byHits", &tr_dedx_byHits );
  Z_One_Tree_->Branch("tr_dedxErr_byHits", &tr_dedxErr_byHits );
  Z_One_Tree_->Branch("tr_saturMeas_byHits", &tr_saturMeas_byHits );
  Z_One_Tree_->Branch("tr_Meas_byHits", &tr_Meas_byHits );
  // MuMu cand
  Z_One_Tree_->Branch("nMuMu",&nMuMu,"nMuMu/i");
  Z_One_Tree_->Branch("MuMuMass",&MuMuMass);
  Z_One_Tree_->Branch("MuMuPx",&MuMuPx);
  Z_One_Tree_->Branch("MuMuPy",&MuMuPy);
  Z_One_Tree_->Branch("MuMuPz",&MuMuPz);
  Z_One_Tree_->Branch("MuMuVtx_CL",&MuMuVtx_CL);
  Z_One_Tree_->Branch("MuMuVtx_Chi2",&MuMuVtx_Chi2);

  Z_One_Tree_->Branch("MuMuDecayVtx_X",&MuMuDecayVtx_X);
  Z_One_Tree_->Branch("MuMuDecayVtx_Y",&MuMuDecayVtx_Y);
  Z_One_Tree_->Branch("MuMuDecayVtx_Z",&MuMuDecayVtx_Z);
  Z_One_Tree_->Branch("MuMuDecayVtx_XE",&MuMuDecayVtx_XE);
  Z_One_Tree_->Branch("MuMuDecayVtx_YE",&MuMuDecayVtx_YE);
  Z_One_Tree_->Branch("MuMuDecayVtx_ZE",&MuMuDecayVtx_ZE);
  // muons from psi' fit
  Z_One_Tree_->Branch("mu1Idx",&mu1Idx);
  Z_One_Tree_->Branch("mu2Idx",&mu2Idx);
  Z_One_Tree_->Branch("mu1Px_MuMu",&mu1_MuMu_Px);
  Z_One_Tree_->Branch("mu1Py_MuMu",&mu1_MuMu_Py);
  Z_One_Tree_->Branch("mu1Pz_MuMu",&mu1_MuMu_Pz);
  Z_One_Tree_->Branch("mu1Chi_MuMu2",&mu1_MuMu_Chi2);
  Z_One_Tree_->Branch("mu1NDF_MuMu",&mu1_MuMu_NDF);
  Z_One_Tree_->Branch("mu2Px_MuMu",&mu2_MuMu_Px);
  Z_One_Tree_->Branch("mu2Py_MuMu",&mu2_MuMu_Py);
  Z_One_Tree_->Branch("mu2Pz_MuMu",&mu2_MuMu_Pz);
  Z_One_Tree_->Branch("mu2Chi2_MuMu",&mu2_MuMu_Chi2);
  Z_One_Tree_->Branch("mu2NDF_MuMu",&mu2_MuMu_NDF);
  Z_One_Tree_->Branch("MuMuType",&MuMuType);
  Z_One_Tree_->Branch("MuMuMuonTrigMatch",&MuMuMuonTrigMatch);
  //
  Z_One_Tree_->Branch("PriVtxMuMuCorr_X",&PriVtxMuMuCorr_X);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_Y",&PriVtxMuMuCorr_Y);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_Z",&PriVtxMuMuCorr_Z);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_EX",&PriVtxMuMuCorr_EX);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_EY",&PriVtxMuMuCorr_EY);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_EZ",&PriVtxMuMuCorr_EZ);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_Chi2",&PriVtxMuMuCorr_Chi2);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_CL",&PriVtxMuMuCorr_CL);
  Z_One_Tree_->Branch("PriVtxMuMuCorr_tracks",&PriVtxMuMuCorr_tracks);
  // B0 cand
  Z_One_Tree_->Branch("nB0",&nB0,"nB0/i");
  Z_One_Tree_->Branch("B0Mass",&b0Mass);
  Z_One_Tree_->Branch("B0Px",&b0Px);
  Z_One_Tree_->Branch("B0Py",&b0Py);
  Z_One_Tree_->Branch("B0Pz",&b0Pz);
  Z_One_Tree_->Branch("B0PxE",&b0PxE);
  Z_One_Tree_->Branch("B0PyE",&b0PyE);
  Z_One_Tree_->Branch("B0PzE",&b0PzE);
  Z_One_Tree_->Branch("B0Vtx_CL",&b0Vtx_CL);
  Z_One_Tree_->Branch("B0Vtx_Chi2",&b0Vtx_Chi2);

  Z_One_Tree_->Branch("B0DecayVtx_X",&b0DecayVtx_X);
  Z_One_Tree_->Branch("B0DecayVtx_Y",&b0DecayVtx_Y);
  Z_One_Tree_->Branch("B0DecayVtx_Z",&b0DecayVtx_Z);
  Z_One_Tree_->Branch("B0DecayVtx_XE",&b0DecayVtx_XE);
  Z_One_Tree_->Branch("B0DecayVtx_YE",&b0DecayVtx_YE);
  Z_One_Tree_->Branch("B0DecayVtx_ZE",&b0DecayVtx_ZE);
  //
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_X",&PriVtx_B0CosAlpha_X);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_Y",&PriVtx_B0CosAlpha_Y);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_Z",&PriVtx_B0CosAlpha_Z);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_EX",&PriVtx_B0CosAlpha_EX);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_EY",&PriVtx_B0CosAlpha_EY);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_EZ",&PriVtx_B0CosAlpha_EZ);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_Chi2",&PriVtx_B0CosAlpha_Chi2);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_CL",&PriVtx_B0CosAlpha_CL);
  Z_One_Tree_->Branch("PriVtx_B0CosAlpha_tracks",&PriVtx_B0CosAlpha_tracks);
  //	
  Z_One_Tree_->Branch("PriVtxB0Corr_X",&PriVtxB0Corr_X);
  Z_One_Tree_->Branch("PriVtxB0Corr_Y",&PriVtxB0Corr_Y);
  Z_One_Tree_->Branch("PriVtxB0Corr_Z",&PriVtxB0Corr_Z);
  Z_One_Tree_->Branch("PriVtxB0Corr_EX",&PriVtxB0Corr_EX);
  Z_One_Tree_->Branch("PriVtxB0Corr_EY",&PriVtxB0Corr_EY);
  Z_One_Tree_->Branch("PriVtxB0Corr_EZ",&PriVtxB0Corr_EZ);
  Z_One_Tree_->Branch("PriVtxB0Corr_Chi2",&PriVtxB0Corr_Chi2);
  Z_One_Tree_->Branch("PriVtxB0Corr_CL",&PriVtxB0Corr_CL);
  Z_One_Tree_->Branch("PriVtxB0Corr_tracks",&PriVtxB0Corr_tracks);
  //
  Z_One_Tree_->Branch("B0LxyPV", &b0LxyPV);
  Z_One_Tree_->Branch("B0CosAlphaPV", &b0CosAlphaPV);
  Z_One_Tree_->Branch("B0CTauPV", &b0CTauPV);
  Z_One_Tree_->Branch("B0CTauPVE", &b0CTauPVE);
  Z_One_Tree_->Branch("B0LxyPVCosAlpha", &b0LxyPVCosAlpha);
  Z_One_Tree_->Branch("B0CosAlphaPVCosAlpha", &b0CosAlphaPVCosAlpha);
  Z_One_Tree_->Branch("B0CTauPVCosAlpha", &b0CTauPVCosAlpha);
  Z_One_Tree_->Branch("B0CTauPVCosAlphaE", &b0CTauPVCosAlphaE);
  Z_One_Tree_->Branch("B0LxyPVX", &b0LxyPVX);
  Z_One_Tree_->Branch("B0CosAlphaPVX", &b0CosAlphaPVX);
  Z_One_Tree_->Branch("B0CTauPVX", &b0CTauPVX);
  Z_One_Tree_->Branch("B0CTauPVXE", &b0CTauPVXE);
  Z_One_Tree_->Branch("B0LxyBS", &b0LxyBS);
  Z_One_Tree_->Branch("B0CosAlphaBS", &b0CosAlphaBS);
  Z_One_Tree_->Branch("B0CTauBS", &b0CTauBS);
  Z_One_Tree_->Branch("B0CTauBSE", &b0CTauBSE);
  Z_One_Tree_->Branch("B0CTauPVX_3D", &b0CTauPVX_3D);
  Z_One_Tree_->Branch("B0CTauPVX_3D_err", &b0CTauPVX_3D_err);
  //
  Z_One_Tree_->Branch("B0MuMuIdx", &B0_MuMuIdx);
  Z_One_Tree_->Branch("B0PionIdx", &B0_piIdx);
  Z_One_Tree_->Branch("B0KaonIdx", &B0_kIdx);
  //
  Z_One_Tree_->Branch("PiPiMass_err",& PiPiMass_err);
  //
  Z_One_Tree_->Branch("Muon1Px_MuMuPiK", &mu1Px_MuMuPiK);
  Z_One_Tree_->Branch("Muon1Py_MuMuPiK", &mu1Py_MuMuPiK);
  Z_One_Tree_->Branch("Muon1Pz_MuMuPiK", &mu1Pz_MuMuPiK);
  Z_One_Tree_->Branch("Muon1E_MuMuPiK", &mu1E_MuMuPiK);
  //
  Z_One_Tree_->Branch("Muon2Px_MuMuPiK", &mu2Px_MuMuPiK);
  Z_One_Tree_->Branch("Muon2Py_MuMuPiK", &mu2Py_MuMuPiK);
  Z_One_Tree_->Branch("Muon2Pz_MuMuPiK", &mu2Pz_MuMuPiK);
  Z_One_Tree_->Branch("Muon2E_MuMuPiK", &mu2E_MuMuPiK);
  //
  Z_One_Tree_->Branch("PionPx_MuMuPiK", &piPx_MuMuPiK);
  Z_One_Tree_->Branch("PionPy_MuMuPiK", &piPy_MuMuPiK);
  Z_One_Tree_->Branch("PionPz_MuMuPiK", &piPz_MuMuPiK);
  Z_One_Tree_->Branch("PionE_MuMuPiK", &piE_MuMuPiK);
  Z_One_Tree_->Branch("pion_nsigdedx", &pion_nsigdedx);
  Z_One_Tree_->Branch("pion_dedx", &pion_dedx);
  Z_One_Tree_->Branch("pion_dedxMass", &pion_dedxMass);
  Z_One_Tree_->Branch("pion_theo", &pion_theo);
  Z_One_Tree_->Branch("pion_sigma", &pion_sigma);
  Z_One_Tree_->Branch("pion_dedx_byHits", &pion_dedx_byHits);
  Z_One_Tree_->Branch("pion_dedxErr_byHits", &pion_dedxErr_byHits);
  Z_One_Tree_->Branch("pion_saturMeas_byHits", &pion_saturMeas_byHits);
  Z_One_Tree_->Branch("pion_Meas_byHits", &pion_Meas_byHits);
  //
  Z_One_Tree_->Branch("KaonPx_MuMuPiK", &kPx_MuMuPiK);
  Z_One_Tree_->Branch("KaonPy_MuMuPiK", &kPy_MuMuPiK);
  Z_One_Tree_->Branch("KaonPz_MuMuPiK", &kPz_MuMuPiK);
  Z_One_Tree_->Branch("KaonE_MuMuPiK", &kE_MuMuPiK);
  Z_One_Tree_->Branch("kaon_nsigdedx", &kaon_nsigdedx);
  Z_One_Tree_->Branch("kaon_dedx", &kaon_dedx);
  Z_One_Tree_->Branch("kaon_dedxMass", &kaon_dedxMass);
  Z_One_Tree_->Branch("kaon_theo", &kaon_theo);
  Z_One_Tree_->Branch("kaon_sigma", &kaon_sigma);
  Z_One_Tree_->Branch("kaon_dedx_byHits", &kaon_dedx_byHits);
  Z_One_Tree_->Branch("kaon_dedxErr_byHits", &kaon_dedxErr_byHits);
  Z_One_Tree_->Branch("kaon_saturMeas_byHits", &kaon_saturMeas_byHits);
  Z_One_Tree_->Branch("kaon_Meas_byHits", &kaon_Meas_byHits);

  //

}// begin Job

// ------------ method called once each job just after ending the event loop  ------------
void 
MuMuPiKPAT::endJob() {
  Z_One_Tree_->GetDirectory()->cd();
  Z_One_Tree_->Write();
}//endjob

double MuMuPiKPAT::getSigmaOfLogdEdx(double logde)
{
  return 0.3;
}

float MuMuPiKPAT::getEnergyLoss(const reco::TrackRef & track)
{
  if (iexception_dedx==1) return 9999.;
  //   const DeDxDataValueMap & eloss = *energyLoss;
  const reco::DeDxDataValueMap & eloss = *energyLoss;
  return eloss[track].dEdx();
}

double MuMuPiKPAT::nsigmaofdedx(const reco::TrackRef & track, double & theo, double & sigma)
{  
	
  //   ch = (track->charge() > 0 ? 0 : 1);
    
  // no usable dE/dx if p > 2
	
  double nsigma = 99 ;
  if (iexception_dedx==1) return nsigma ;
	
  //   if(track->p() > 2) return nsigma;
	
  double m  = 0.13957; 
  double bg = track->p() / m;
	
  theo = getLogdEdx(bg);
	
  // !!!!!!
  int nhitr = track->numberOfValidHits();
	
  double meas = log(getEnergyLoss(track));
  sigma = getSigmaOfLogdEdx(theo) * pow(nhitr,-0.65);
  //   double errdedxTrk = eloss[trk1Ref].dEdxError();
  if (sigma>0)
    nsigma = (meas-theo) / sigma ;
  return nsigma;
}


double MuMuPiKPAT::getLogdEdx(double bg)
{
  const double a =  3.25 ;
  const double b =  0.288;
  const double c = -0.852;
	
  double beta = bg/sqrt(bg*bg + 1);
  double dedx = log( a/(beta*beta) + b * log(bg) + c );
	
  return dedx;
	
}


double MuMuPiKPAT::GetMass(const reco::TrackRef & track){
  double P = track->p();
  double C = 2.625;
  double K = 2.495;
  double I = getEnergyLoss(track);
  return sqrt((I-C)/K)*P;
}



//define this as a plug-in
DEFINE_FWK_MODULE(MuMuPiKPAT);

// rsync -vut --existing src/MuMuPiKPAT.cc cristella@cmssusy.ba.infn.it:/cmshome/cristella/work/Z_analysis/exclusive/clean_14ott/CMSSW_5_3_7_patch5/src/UserCode/MuMuPiKPAT/src/MuMuPiKPAT.cc

