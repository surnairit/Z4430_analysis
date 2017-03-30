#define BkgAnalysis_cxx
// The class definition in BkgAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("BkgAnalysis.C")
// Root > T->Process("BkgAnalysis.C","some options")
// Root > T->Process("BkgAnalysis.C+")
//

#include "BkgAnalysis.h"
#include <TH2.h>
#include <TStyle.h>

#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TSystem.h>
#include <TTree.h>
#include <TBranch.h>
#include <TCint.h>
#include <TRandom.h>
#include <TMath.h>
#include <TDirectory.h>
#include "TEnv.h"
#include <TH1.h>
#include <TF1.h>
#include <TString.h>
#include <TProof.h>
#include <TProofOutputFile.h>
#include "TLorentzVector.h"
#include "TPoint.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


void BkgAnalysis::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void BkgAnalysis::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

//    OutFile = new TProofOutputFile( "Bkg_B0ToPsiMuMu_2Mu.root" );
//    OutFile = new TProofOutputFile( "Bkg_BsToPsiMuMu_0001.root" );
   OutFile = new TProofOutputFile( "Bkg_BpToPsiMuMu_0001.root" );
//   OutFile = new TProofOutputFile( "Bkg_LambdaBToPsiMuMu.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls_jpsi_eta.root" );
    
   fOut = OutFile->OpenFile("RECREATE");

   if ( !(fOut = OutFile->OpenFile("RECREATE")) )
    {
      Warning("SlaveBegin", "problems opening file: %s/%s",
              OutFile->GetDir(), OutFile->GetFileName());
    }

    h_nB0                   = new TH1F("h_nB0","h_nB0",10,0,10);
    hMuMuMass               = new TH1F("hMuMuMass","hMuMuMass",140,2.6,4.0);
    hJpsiPiMass             = new TH1F("hJpsiPiMass","hJpsiPiMass",1000,0,10);
    hKPiMass                = new TH1F("hKPiMass","hKPiMass",1000,0,10);
    hPiPiMass               = new TH1F("hPiPiMass","hPiPiMass",1000,0,10);
    hKKMass                 = new TH1F("hKKMass","hKKMass",1000,0,10);
    hKPiMass_noBs           = new TH1F("hKPiMass_noBs","hKPiMass_noBs",1000,0,10);
    
    hJpsiPiMass_peak        = new TH1F("hJpsiPiMass_peak","hJpsiPiMass_peak",1000,0,10);
    hKPiMass_peak           = new TH1F("hKPiMass_peak","hKPiMass_peak",1000,0,10);
    hPiPiMass_peak          = new TH1F("hPiPiMass_peak","hPiPiMass_peak",1000,0,10);
    hKKMass_peak            = new TH1F("hKKMass_peak","hKKMass_peak",1000,0,10);
    
    hJpsiPiMass_sb          = new TH1F("hJpsiPiMass_sb","hJpsiPiMass_sb",1000,0,10);
    hKPiMass_sb             = new TH1F("hKPiMass_sb","hKPiMass_sb",1000,0,10);
    hPiPiMass_sb            = new TH1F("hPiPiMass_sb","hPiPiMass_sb",1000,0,10);
    hKKMass_sb              = new TH1F("hKKMass_sb","hKKMass_sb",1000,0,10);
    
    hjpsiKPiMassBaseSelAlt  = new TH1F("hjpsiKPiMassBaseSelAlt"," MuMuKPiMass after basic selection",100, 4.8, 5.8);
    hjpsiKKMassBaseSelAlt   = new TH1F("hjpsiKKMassBaseSelAlt"," MuMuKKMass after basic selection",100, 4.8, 5.8);
    hjpsiPiPiMassBaseSelAlt = new TH1F("hjpsiPiPiMassBaseSelAlt"," MuMuPiPiMass after basic selection",100, 4.8, 5.8);
    hjpsiPhiToKKMass        = new TH1F("hjpsiPhiToKKMass"," Jpsi Phi (-> KK) Mass after basic selection",100, 4.8, 5.8);
//    hjpsiKPiMassSelAlt		= new TH1F("hjpsiKPiMassSelAlt","hmjpsiKPiMassSel ALTERNATIVE", 100, 4.8, 5.8);
    hjpsiKPiMassNoPhi 		= new TH1F("hjpsiKPiMassNoPhi","hjpsiKPiMass No Phi to KK ", 100, 4.8, 5.8);
//    hjpsiKPiMassNoPhiNoBs 	= new TH1F("hjpsiKPiMassNoPhiNoBs","hjpsiKPiMass No Phi to KK && no Bs ", 100, 4.8, 5.8);

    hDalitz_peak            = new TH2F("hDalitz_peak","hDalitz_peak",600,0,6,1700,9,26);
    hDalitz_sideband        = new TH2F("hDalitz_sideband","hDalitz_sideband",600,0,6,1700,9,26);
    
    hChi2byNDF              = new TH1F("hChi2byNDF","hChi2byNDF",100,0,10);
    hmuShits                = new TH1F("hmuShits","hmuShits",50,0,50);
    hmuPhits                = new TH1F("hmuPhits","hmuPhits",15,0,15);
    hmuDz                   = new TH1F("hmuDz","hmuDz",3000,0,30);
    hmuDxy                  = new TH1F("hmuDxy","hmuDxy",1000,0,10);
    hB0Vtx_CL               = new TH1F("hB0Vtx_CL","hB0Vtx_CL",1000,0,1.0);
   
    hB0CosAlphaPV       	= new TH1F("hB0CosAlphaPV","hB0CosAlphaPV",1000 ,0.0 ,0.999);
    hB0CtauPV_by_E      	= new TH1F("hB0CtauPV_by_E","hB0CtauPV_by_E",500 ,0 ,50);
    hMuMuVtx_CL         	= new TH1F("hMuMuVtx_CL","hMuMuVtx_CL",1000 ,0 ,0.1);
    htrack_fromB0_Pt		= new TH1F("htrack_fromB0_Pt","htrack_fromB0_Pt",1000 ,0.0 ,100);
    htrack_fromB0_Eta		= new TH1F("htrack_fromB0_Eta","htrack_fromB0_Eta",100,-5.0,5.0);
    hB0Pt               	= new TH1F("hB0Pt","hB0Pt",1000 ,0 ,100);
    hjpsi_fromB0_Pt         = new TH1F("hjpsi_fromB0_Pt","hjpsi_fromB0_Pt",1000 ,0 ,100);
    hjpsi_track_deltaR		= new TH1F("hjpsi_track_deltaR","hjpsi_track_deltaR",100 ,0 ,10);
    htrackChi2byNDF         = new TH1F("htrackChi2byNDF","htrackChi2byNDF",100 ,0 ,10);
    htrackShits         	= new TH1F("htrackShits","htrackShits",50 ,0 ,50);
    htrackPhits         	= new TH1F("htrackPhits","htrackPhits",15 ,0 ,15);


}

Bool_t BkgAnalysis::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either BkgAnalysis::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

  GetEntry(entry);

  for (Int_t myMuMuIdx = 0; myMuMuIdx < abs(nMuMu); myMuMuIdx++) {
    hMuMuMass->Fill((*MuMuMass)[myMuMuIdx]) ;
	}

  int muonQual[] = {1,3,4,12};
    
    h_nB0->Fill(nB0);
    int numB0 = 0;
    
    Float_t B0MassAlt=0;
    double JpsiPiMass=0;
    double KPiMass=0;
    double theta_Jpsi=0;
    double theta_Kstar=0;
    double phi=0;
    
    
    double B0_Pt = 0;
    double pion_fromB0_Pt = 0;
    double kaon_fromB0_Pt = 0;
    double jpsi_fromB0_Pt = 0;
    double pion_from_B0_Eta = 0;
    double kaon_from_B0_Eta = 0;

    
    TLorentzVector mu1_p4, mu2_p4;
    TLorentzVector muP_p4, muM_p4;
    TLorentzVector jpsip4;
    TLorentzVector pip4, pip4_exchanged;
    TLorentzVector kp4, kp4_exchanged;
    TLorentzVector Pip4_orig, Kp4_orig;
    TLorentzVector B0p4, B0p4_KPiExchanged, Bsp4_JpsiKK, JpsiPiPip4;
    TLorentzVector Zcandp4;

  if ( nB0>0 ) { //b0 requirement
//  if ( nB0 == 1 ) { //b0 requirement

  for (Int_t myB0Idx = 0; myB0Idx < abs(nB0); myB0Idx++)

    {  // b0 loop
  Int_t pi_orig_Index = (*B0PionIdx)[myB0Idx] ;
  Int_t ka_orig_Index = (*B0KaonIdx)[myB0Idx] ;
  Int_t jpsi_index = (*B0MuMuIdx)[myB0Idx];
  Int_t mu1_fromB0_index = (*mu1Idx)[jpsi_index];
  Int_t mu2_fromB0_index = (*mu2Idx)[jpsi_index];
        
        int mu1Charge = (*muCharge)[mu1_fromB0_index];
        int mu2Charge = (*muCharge)[mu2_fromB0_index];
        
  Int_t muP_fromB0_index;
  Int_t muM_fromB0_index;

        if ((*muCharge)[mu1_fromB0_index]>0.0 && (*muCharge)[mu2_fromB0_index]<0.0){
            muP_fromB0_index = (*mu1Idx)[jpsi_index];
            muM_fromB0_index = (*mu2Idx)[jpsi_index];
        }
 
        if ((*muCharge)[mu1_fromB0_index]<0.0 && (*muCharge)[mu2_fromB0_index]>0.0){
            muP_fromB0_index = (*mu2Idx)[jpsi_index];
            muM_fromB0_index = (*mu1Idx)[jpsi_index];
        }
        
//        TLorentzVector mu1_p4, mu2_p4;
//        TLorentzVector muP_p4, muM_p4;


  Float_t mu1E = 0., mu2E = 0.;
  mu1E = sqrt( pow((*muPx)[mu1_fromB0_index],2) + pow((*muPy)[mu1_fromB0_index],2) + pow((*muPz)[mu1_fromB0_index],2) + pow(muon_mass,2) );
  mu2E = sqrt( pow((*muPx)[mu2_fromB0_index],2) + pow((*muPy)[mu2_fromB0_index],2) + pow((*muPz)[mu2_fromB0_index],2) + pow(muon_mass,2) );
  mu1_p4.SetPxPyPzE( (*muPx)[mu1_fromB0_index], (*muPy)[mu1_fromB0_index], (*muPz)[mu1_fromB0_index], mu1E);
  mu2_p4.SetPxPyPzE( (*muPx)[mu2_fromB0_index], (*muPy)[mu2_fromB0_index], (*muPz)[mu2_fromB0_index], mu2E);

 
        
        Float_t muPE = 0., muME = 0.;
        muPE = sqrt( pow((*muPx)[muP_fromB0_index],2) + pow((*muPy)[muP_fromB0_index],2) + pow((*muPz)[muP_fromB0_index],2) + pow(muon_mass,2) );
        mu2E = sqrt( pow((*muPx)[muM_fromB0_index],2) + pow((*muPy)[muM_fromB0_index],2) + pow((*muPz)[muM_fromB0_index],2) + pow(muon_mass,2) );
        muP_p4.SetPxPyPzE( (*muPx)[muP_fromB0_index], (*muPy)[muP_fromB0_index], (*muPz)[muP_fromB0_index], muPE);
        muM_p4.SetPxPyPzE( (*muPx)[muM_fromB0_index], (*muPy)[muM_fromB0_index], (*muPz)[muM_fromB0_index], muME);
      

//  TLorentzVector jpsip4;
  Float_t jpsi_E = 0.;
  jpsi_E = sqrt( pow((*MuMuPx)[jpsi_index],2) + pow((*MuMuPy)[jpsi_index], 2) + pow((*MuMuPz)[jpsi_index], 2) + pow((*MuMuMass)[jpsi_index], 2) ) ;
  jpsip4.SetPxPyPzE( (*MuMuPx)[jpsi_index], (*MuMuPy)[jpsi_index], (*MuMuPz)[jpsi_index], jpsi_E) ;




//  TLorentzVector pip4, pip4_exchanged;
  pip4.SetPxPyPzE( (*PionPx_MuMuPiK)[myB0Idx], (*PionPy_MuMuPiK)[myB0Idx], (*PionPz_MuMuPiK)[myB0Idx], (*PionE_MuMuPiK)[myB0Idx]) ; 

//  Float_t P_E = 0.;
//  P_E = sqrt( pow((*trackPx)[pi_orig_Index], 2) + pow((*trackPy)[pi_orig_Index], 2) + pow((*trackPz)[pi_orig_Index], 2) + pow(kaonCh_mass, 2) ) ; // kaon mass to pion track
//  pip4_exchanged.SetPxPyPzE( (*trackPx)[pi_orig_Index], (*trackPy)[pi_orig_Index], (*trackPz)[pi_orig_Index], P_E) ; // kaon mass to pion track




//  TLorentzVector kp4, kp4_exchanged;
  kp4.SetPxPyPzE( (*KaonPx_MuMuPiK)[myB0Idx], (*KaonPy_MuMuPiK)[myB0Idx], (*KaonPz_MuMuPiK)[myB0Idx], (*KaonE_MuMuPiK)[myB0Idx]) ;

     
//  TLorentzVector Pip4_orig, Kp4_orig;
  Pip4_orig.SetPxPyPzE( (*trackPx)[pi_orig_Index], (*trackPy)[pi_orig_Index], (*trackPz)[pi_orig_Index], (*trackEnergy)[pi_orig_Index]) ; // original
  float pionCharge = (*trackCharge)[pi_orig_Index];

  Float_t K_E = 0.;
  K_E = sqrt( pow((*trackPx)[ka_orig_Index], 2) + pow((*trackPy)[ka_orig_Index], 2) + pow((*trackPz)[ka_orig_Index], 2) + pow(kaonCh_mass, 2) ) ; // original
  Kp4_orig.SetPxPyPzE( (*trackPx)[ka_orig_Index], (*trackPy)[ka_orig_Index], (*trackPz)[ka_orig_Index], K_E) ; // original
  float kaonCharge = (*trackCharge)[ka_orig_Index];
        
        
  pip4_exchanged.SetVectM(pip4.Vect(), kaonCh_mass) ;
  kp4_exchanged.SetVectM(kp4.Vect(), pionCh_mass) ;

//  TLorentzVector B0p4, B0p4_KPiExchanged, Bsp4_JpsiKK, JpsiPiPip4;
  B0p4 = jpsip4+pip4+kp4;
  Bsp4_JpsiKK = jpsip4+kp4+pip4_exchanged;
  JpsiPiPip4 = jpsip4+pip4+kp4_exchanged;
        


//  Float_t
        B0MassAlt = (jpsip4+pip4+kp4).Mag() - jpsip4.M() + jpsi_mass;
  Float_t BsMassAlt = (jpsip4+kp4+pip4_exchanged).Mag() - jpsip4.M() + jpsi_mass;
  Float_t JpsiPiPiMass = (jpsip4+pip4+kp4_exchanged).Mag()- jpsip4.M() + jpsi_mass;
        
        B0_Pt = B0p4.Pt();
        pion_fromB0_Pt = pip4.Pt();
        kaon_fromB0_Pt = kp4.Pt();
        jpsi_fromB0_Pt = jpsip4.Pt();
	    pion_from_B0_Eta = pip4.Eta();
        kaon_from_B0_Eta = kp4.Eta();

       // double
        JpsiPiMass = (jpsip4+pip4).Mag();
       // double
        KPiMass = (pip4+kp4).Mag();


//    hjpsiKPiMassBaseSelAlt->Fill( B0MassAlt );

  B0p4_KPiExchanged = jpsip4 + pip4_exchanged + kp4_exchanged;
        
        

//  hjpsifromBMass->Fill((*MuMuMass)[(*B0MuMuIdx)[myB0Idx]]);
//  int jpsiId = (*B0MuMuIdx)[myB0Idx];


  Bool_t newsoftID = false;
  Bool_t baselineB0Sel = false;


   hChi2byNDF->Fill(((*muChi2)[mu1_fromB0_index]/(*muNDF)[mu1_fromB0_index]));
   hmuShits->Fill((*muShits)[mu1_fromB0_index]);
   hmuPhits->Fill((*muPhits)[mu1_fromB0_index]);
   hmuDz->Fill(fabs((*muDzVtx)[mu1_fromB0_index]));
   hmuDxy->Fill(fabs((*muDxyVtx)[mu1_fromB0_index]));

   hChi2byNDF->Fill(((*muChi2)[mu2_fromB0_index]/(*muNDF)[mu2_fromB0_index]));
   hmuShits->Fill((*muShits)[mu2_fromB0_index]);
   hmuPhits->Fill((*muPhits)[mu2_fromB0_index]);
   hmuDz->Fill(fabs((*muDzVtx)[mu2_fromB0_index]));
   hmuDxy->Fill(fabs((*muDxyVtx)[mu2_fromB0_index]));

        hB0Vtx_CL           ->  Fill((*B0Vtx_CL)[myB0Idx]);
        hB0CosAlphaPV       ->	Fill((*B0CosAlphaPV)[myB0Idx]);
        hB0CtauPV_by_E      ->	Fill((*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx]);
        hMuMuVtx_CL         ->	Fill((*MuMuVtx_CL)[jpsi_index]);
        htrack_fromB0_Pt	->	Fill(pion_fromB0_Pt);
        htrack_fromB0_Pt	->	Fill(kaon_fromB0_Pt);
        hB0Pt               ->	Fill(B0_Pt);
        hjpsi_fromB0_Pt     ->	Fill(jpsi_fromB0_Pt);
        hjpsi_track_deltaR	->	Fill(jpsip4.DeltaR(pip4));
        hjpsi_track_deltaR	->	Fill(jpsip4.DeltaR(kp4));
        htrackChi2byNDF     ->	Fill(((*trackChi2)[pi_orig_Index]/(*trackNDF)[pi_orig_Index]));
        htrackChi2byNDF     ->	Fill(((*trackChi2)[ka_orig_Index]/(*trackNDF)[ka_orig_Index]));
        htrackShits         ->	Fill((*trackShits)[pi_orig_Index]);
        htrackShits         ->	Fill((*trackShits)[ka_orig_Index]);
        htrackPhits         ->	Fill((*trackPhits)[pi_orig_Index]);
        htrackPhits         ->	Fill((*trackPhits)[ka_orig_Index]);

	htrack_fromB0_Eta   ->  Fill(pion_from_B0_Eta);
	htrack_fromB0_Eta   ->  Fill(kaon_from_B0_Eta);


  //
  // NEW SOFT MUON 2013
  //
    

  if ( 1 && 
  ((*muQual)[mu1_fromB0_index] & (1 << muonQual[3])) && ((*muQual)[mu2_fromB0_index] & (1 << muonQual[3])) && //TMOneSTationTight
  ((*muChi2)[mu1_fromB0_index]/(*muNDF)[mu1_fromB0_index])<3. && ((*muChi2)[mu2_fromB0_index]/(*muNDF)[mu2_fromB0_index])<3. && // cut opt val ~3
  (*muShits)[mu1_fromB0_index]>5 && (*muShits)[mu2_fromB0_index]>5 && // dont see much variation
  (*muPhits)[mu1_fromB0_index]>0 && (*muPhits)[mu2_fromB0_index]>0 &&                      // new soft muons 2013 (was 1 in old soft muons) keep
  fabs((*muDzVtx)[mu1_fromB0_index])<20. && fabs((*muDzVtx)[mu2_fromB0_index])<20. &&        // new soft muons 2013 (was 30 in old soft muons) keep
  fabs((*muDxyVtx)[mu1_fromB0_index])<0.3 && fabs((*muDxyVtx)[mu2_fromB0_index])<0.3         // new soft muons 2013 (was 3 in old soft muons) was 0.3 for psiprime
   )
  {

   newsoftID = true;
  }

  Bool_t Mu1_PtSel = false;
  Bool_t Mu2_PtSel = false;


  if ( ( ( (fabs(mu1_p4.Eta()) < 1.2 ) && (mu1_p4.Pt()>4.)) ) || ( ( mu1_p4.Eta() >= 1.2 || mu1_p4.Eta() <=- 1.2) && (mu1_p4.Pt()>3.3) ) ) Mu1_PtSel = true;
  if ( ( ( (fabs(mu2_p4.Eta()) < 1.2 ) && (mu2_p4.Pt()>4.)) ) || ( ( mu2_p4.Eta() >= 1.2 || mu2_p4.Eta() <=- 1.2) && (mu2_p4.Pt()>3.3) ) ) Mu2_PtSel = true;

  if ( 1 && newsoftID  // cuts loose
  && ( (*B0Vtx_CL)[myB0Idx] > 0.05 ) //0.05
  && ( (*B0CosAlphaPV)[myB0Idx] > 0.99 ) //0.998
  && ( (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 7.0 ) //7.0
  && ( fabs( (*MuMuMass)[jpsi_index] - jpsi_mass ) < 0.2 ) // 0.12 was 0.2 for baseline cuts
  && ( (*MuMuVtx_CL)[jpsi_index] > 0.02 ) //0.02
  && ( pion_fromB0_Pt > 0.45 ) // 0.45 >2.0
  && ( kaon_fromB0_Pt > 0.45 ) // 0.45 >2.0
  && ( B0_Pt > 5.) // >7 // >18
//  && ( jpsi_fromB0_Pt > 5.)
  && ( mu1_p4.Pt()>3.3 && mu2_p4.Pt() > 3.3)
  && Mu1_PtSel && Mu2_PtSel
  ) // cuts loose
  {
  
    hJpsiPiMass->Fill(JpsiPiMass);
    hKPiMass->Fill(KPiMass);
    hPiPiMass->Fill((pip4+kp4_exchanged).Mag());
    hKKMass->Fill((kp4+pip4_exchanged).Mag());
    
    hjpsiKPiMassBaseSelAlt->Fill( B0MassAlt );
    hjpsiKKMassBaseSelAlt->Fill( BsMassAlt );
    
    if ( B0MassAlt>5.22 && B0MassAlt<5.34 ) { // Dalitz peak
           hDalitz_peak->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
        
           hJpsiPiMass_peak->Fill(JpsiPiMass);
           hKPiMass_peak->Fill(KPiMass);
           hPiPiMass_peak->Fill((pip4+kp4_exchanged).Mag());
           hKKMass_peak->Fill((kp4+pip4_exchanged).Mag());
        
           } // Dalitz peak
    if ( (B0MassAlt>5.16 && B0MassAlt<5.22) || (B0MassAlt>5.34 && B0MassAlt<5.40) ) { // Dalitz sideband
           hDalitz_sideband->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);

           hJpsiPiMass_sb->Fill(JpsiPiMass);
           hKPiMass_sb->Fill(KPiMass);
           hPiPiMass_sb->Fill((pip4+kp4_exchanged).Mag());
           hKKMass_sb->Fill((kp4+pip4_exchanged).Mag());
        
           } // Dalitz sideband
      
    baselineB0Sel = true;
    
		if ( (pip4_exchanged+kp4).Mag()> 1.01 &&  (pip4_exchanged+kp4).Mag()< 1.03  ) { // phi mass window
		hjpsiPhiToKKMass->Fill(BsMassAlt);
		} // phi mass window
      
//       if (  (BsMassAlt<5.332 || BsMassAlt>5.40)  ) { // no Bs
       if (  ((pip4_exchanged+kp4).Mag()< 1.01 ||  (pip4_exchanged+kp4).Mag()> 1.03) && (BsMassAlt<5.332 || BsMassAlt>5.40)  ) { // no Bs
       hjpsiKPiMassNoPhi->Fill(B0MassAlt);
       hKPiMass_noBs->Fill((pip4+kp4).Mag());
       } // no Bs

/*
       if (  (BsMassAlt<5.332 || BsMassAlt>5.40) && ((pip4_exchanged+kp4).Mag()< 1.01 ||  (pip4_exchanged+kp4).Mag()> 1.03) ) { // no Bs
       hjpsiKPiMassNoPhi->Fill(B0MassAlt);
       hKPiMass_noBs->Fill((pip4+kp4).Mag());
       } // no Bs
*/
 
  } // cuts loose

    } // b0 loop
      
}//b0 requirement


   return kTRUE;
}

void BkgAnalysis::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

  TDirectory *savedir = gDirectory;
  if (fOut) 
    {      
      fOut->cd();
      //// Write histograms in output file
      gStyle->SetOptStat(111111) ;

      hMuMuMass->Write();
      
      hjpsiKPiMassBaseSelAlt->Write();
//      hjpsiKPiMassSelAlt->Write();
      hjpsiPhiToKKMass->Write();
      hjpsiKPiMassNoPhi->Write();
//      hjpsiKPiMassNoPhiNoBs->Write();
      
      hJpsiPiMass->Write();
      hKPiMass->Write();
      hPiPiMass->Write();
      hKKMass->Write();
      hKPiMass_noBs->Write();

      hJpsiPiMass_peak->Write();
      hKPiMass_peak->Write();
      hPiPiMass_peak->Write();
      hKKMass_peak->Write();

      hJpsiPiMass_sb->Write();
      hKPiMass_sb->Write();
      hPiPiMass_sb->Write();
      hKKMass_sb->Write();


        hDalitz_peak->Write();
        hDalitz_sideband->Write();
        

      hChi2byNDF->Write() ;
      hmuShits->Write() ;
      hmuPhits->Write() ;
      hmuDz->Write() ;
      hmuDxy->Write() ;
        
      hB0Vtx_CL           ->	Write();
      hB0CosAlphaPV       ->	Write();
      hB0CtauPV_by_E      ->	Write();
      hMuMuVtx_CL         ->	Write();
      htrack_fromB0_Pt    ->	Write();
      htrack_fromB0_Eta   ->	Write();
      hB0Pt               ->    Write();
      hjpsi_fromB0_Pt     ->	Write();
      hjpsi_track_deltaR  ->	Write();
      htrackChi2byNDF	  ->	Write();
      htrackShits         ->    Write();
      htrackPhits         ->    Write();


        
      OutFile->Print();
      fOutput->Add(OutFile); 
      hMuMuMass->SetDirectory(0); // any hname
//      hjpsiKPiMassSelAlt->SetDirectory(0) ;
//      gDirectory = savedir;
      fOut->Close();
    }




}

void BkgAnalysis::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
