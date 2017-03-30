// -*- C++ -*-
//
// Package:    MuAnalyzer
// Class:      MuAnalyzer
// 
/**\class MuAnalyzer MuAnalyzer.cc MuonAnalyzer/MuAnalyzer/src/MuAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Nairit Sur,,,
//         Created:  Thu Jun 25 22:17:25 CEST 2015
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TH1.h"
#include "TLorentzVector.h" 
#include <vector>
#include "TMath.h"

#include "DataFormats/PatCandidates/interface/PATObject.h"
//#include "PhysicsTools/PatExamples/plugins/MuonAnalyzer.h" //new
#include "DataFormats/PatCandidates/interface/Muon.h"  // new


const double muon_mass = 0.10565837; //pdg mass
const double pion_mass = 0.13957018; //pdg mass
const double kaon_mass = 0.493667;
const double Jpsi_mass = 3.096916;
const double psi2S_mass = 3.686093;

//
// class declaration
//

class MuAnalyzer : public edm::EDAnalyzer {
   public:
      explicit MuAnalyzer(const edm::ParameterSet&);
      ~MuAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

      // ----------member data ---------------------------

  TH1D *trackpt;
  TH1D *tracketa;
  TH1D *trackphi;
  TH1D *trackcharge;

  TH1D *mupt;
  TH1D *mueta;
  TH1D *muphi;
  TH1D *mucharge;
  TH1D *mumumass;


};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
MuAnalyzer::MuAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed

  edm::Service<TFileService> fs;
  trackpt = fs->make<TH1D>("track_pt" , "Track p_{T}" , 10000 , 0 , 1000 );
  tracketa = fs->make<TH1D>("track_eta" , "Track #eta" , 100 , -5.0 , 5.0);
  trackphi = fs->make<TH1D>("track_phi" , "Track #phi" , 50 , -3.15 , 3.15);
  trackcharge = fs->make<TH1D>("track_charge" , "Track Charge" , 10 , -1.5 , 1.5);

  mupt = fs->make<TH1D>("mu_pt" , "mu p_{T}" , 10000 , 0 , 1000 );
  mueta = fs->make<TH1D>("mu_eta" , "mu #eta" , 100 , -5.0 , 5.0);
  muphi = fs->make<TH1D>("mu_phi" , "mu #phi" , 50 , -3.15 , 3.15);
  mucharge = fs->make<TH1D>("mu_charge" , "mu Charge" , 10 , -1.5 , 1.5);
  mumumass = fs->make<TH1D>("mumumass" , "MuMu Mass" , 1000 , 0 , 10);
}


MuAnalyzer::~MuAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
MuAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;
   using std::vector;
   using namespace pat;

//vector<TLorentzVector> *Mu4Mom_vect;
//TLorentzVector Mu4Mom;
//vector<double> *MuCharge;

//vector<TLorentzVector> *Trk4Mom;
//vector<double> *TrkCharge;

//Handle<reco::TrackCollection> tracks;
//iEvent.getByLabel("generalTracks", tracks); 
//LogInfo("Demo") << "number of tracks "<<tracks->size();
//demohisto->Fill(tracks->size());


/*
for( reco::TrackCollection::const_iterator t = tracks->begin(); t != tracks->end(); ++ t ) {

double pt = t->pt(), eta = t->eta(), phi = t->phi() , charge = t->charge();
  trackpt->Fill( pt );
  tracketa->Fill( eta );
  trackphi->Fill( phi );
  trackcharge->Fill( charge );
}
*/


//Handle<reco::MuonCollection> muons;
//iEvent.getByLabel("muons",muons);

   Handle<std::vector<pat::Muon> > muons;
   iEvent.getByLabel("selectedPatMuons", muons);


LogInfo("Demo") << "number of muons "<<muons->size();

//for( reco::MuonCollection::const_iterator mu = muons->begin(); mu != muons->end(); ++ mu ) { // muon loop
for(vector<pat::Muon>::const_iterator mu=muons->begin(); mu != muons->end(); ++mu){ // muon 1 loop
double mu_pt = mu->pt(), mu_eta = mu->eta(), mu_phi = mu->phi() , mu_charge = mu->charge();
  mupt->Fill( mu_pt );
  mueta->Fill( mu_eta );
  muphi->Fill( mu_phi );
  mucharge->Fill( mu_charge );
	
	for(vector<pat::Muon>::const_iterator mu2=muons->begin(); mu2 != muons->end(); ++mu2 ){ // muon 2 loop
		if( mu2==mu ) continue;
		if( (*mu).pt()>1.5 && (*mu2).pt()>1.5 && fabs( (*mu).eta())< 2.2 && fabs( (*mu2).eta())< 2.2) { // pt, eta cond
		if(!( mu->charge()*mu2->charge()<0 ))   continue;
		double MuMuMass = (mu->p4()+mu2->p4()).mass(); 
		mumumass->Fill(MuMuMass);
	} // pt eta cond
	} //muon 2 loop
cout << "muonpt "<<mu_pt<<endl;



/*
if (    muons->size()>1 
//    && (muons->isTrackerMuon() || muons->isGlobalMuon()) 
    && mu_pt>3.3 ) 
{
Mu4Mom.SetPtEtaPhiM(mu_pt,mu_eta,mu_phi,muon_mass);
Mu4Mom_vect->push_back(Mu4Mom);
MuCharge->push_back(mu_charge);
}

*/

} // muon 1 loop


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
MuAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
MuAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void 
MuAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
MuAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
MuAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
MuAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MuAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MuAnalyzer);
