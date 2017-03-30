#define SignalExtract_Jpsi_small_ntpls_cut_opt_cxx
// The class definition in SignalExtract_Jpsi_small_ntpls_cut_opt.h has been generated automatically
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
// Root > T->Process("SignalExtract_Jpsi_small_ntpls_cut_opt.C")
// Root > T->Process("SignalExtract_Jpsi_small_ntpls_cut_opt.C","some options")
// Root > T->Process("SignalExtract_Jpsi_small_ntpls_cut_opt.C+")
//

#include "SignalExtract_Jpsi_small_ntpls_cut_opt.h"
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


void SignalExtract_Jpsi_small_ntpls_cut_opt::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void SignalExtract_Jpsi_small_ntpls_cut_opt::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls_cut_opt.root" );
//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_MuChi2_by_NDF.root" );
//     OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_MuS_hits.root" );
//     OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_MuP_hits.root" );
//     OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_MuDz.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_MuDxy.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_B0CosAlphaPV.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_B0Vtx_CL.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_B0CTauPV.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_MuMuVtx_CL.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_B0Pt.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_trackPt.root" );
    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_cut_opt_MuMu_Track_deltaR.root" );
    
   fOut = OutFile->OpenFile("RECREATE");

   if ( !(fOut = OutFile->OpenFile("RECREATE")) )
    {
      Warning("SlaveBegin", "problems opening file: %s/%s",
              OutFile->GetDir(), OutFile->GetFileName());
    }

    
    // Book NTuple
//    _nt = new TNtupleD("_nt","_nt","B0_mass:KPi_mass:Jpsi_mass:JpsiPi_mass:B0_3mom:KPi_3mom:Jpsi_3mom:K_3mom:Pi_3mom:Theta_Kstar:Theta_Jpsi:Phi:evtNum:runNum:lumiNum"); // output ntuple
    
    //////// HISTOGRAMS
  // put them here:
  //
    
    hMuMuMass               = new TH1F("hMuMuMass","hMuMuMass",1000,0,10);
    hjpsiKPiMassBaseSelAlt  = new TH1F("hjpsiKPiMassBaseSelAlt"," MuMuKPiMass after basic selection",10000, 0, 100);
    hjpsiKPiMassSelAlt		= new TH1F("hjpsiKPiMassSelAlt","hmjpsiKPiMassSel ALTERNATIVE", 100, 4.8, 5.8);


/*
    h_nB0                   = new TH1F("h_nB0","h_nB0",10,0,10);
    h_nB0_sel               = new TH1F("h_nB0_sel","h_nB0_sel",10,0,10);
    
    h_theta_Jpsi            = new TH1F("h_theta_Jpsi","J/#psi helicity angle ;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_theta_Jpsi_sel        = new TH1F("h_theta_Jpsi_sel","J/#psi helicity angle after selection;#theta_{J/#psi}", 160, -0.03, 3.17);

    h_theta_Kstar           = new TH1F("h_theta_Kstar","K* helicity angle ;#theta_{K*}", 160, -0.03, 3.17);
    h_theta_Kstar_sel       = new TH1F("h_theta_Kstar_sel","K* helicity angle after selection;#theta_{K*}", 160, -0.03, 3.17);
    
    h_phi_planes            = new TH1F("h_phi_planes","Angle between K#pi and #mu#mu planes;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;
    h_phi_planes_sel        = new TH1F("h_phi_planes_sel","Angle between K#pi and #mu#mu planes after selection;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;
    
    



    

    hChi2byNDF			= new TH1F("hChi2byNDF","hChi2byNDF",100,0,10);
    hmuShits 			= new TH1F("hmuShits","hmuShits",50,0,50);
    hmuPhits 			= new TH1F("hmuPhits","hmuPhits",15,0,15);
    hmuDz 			= new TH1F("hmuDz","hmuDz",3000,0,30);
    hmuDxy 			= new TH1F("hmuDxy","hmuDxy",1000,0,10);
    hB0Vtx_CL 			= new TH1F("hB0Vtx_CL","hB0Vtx_CL",100,0,0.1);
   
    hB0CosAlphaPV       	= new TH1F("hB0CosAlphaPV","hB0CosAlphaPV",1000 ,0.0 ,0.999);
    hB0CtauPV_by_E      	= new TH1F("hB0CtauPV_by_E","hB0CtauPV_by_E",500 ,0 ,50);
    hMuMuVtx_CL         	= new TH1F("hMuMuVtx_CL","hMuMuVtx_CL",1000 ,0 ,0.1);
    htrack_fromB0_Pt		= new TH1F("htrack_fromB0_Pt","htrack_fromB0_Pt",1000 ,0.0 ,100);
    htrack_fromB0_Eta		= new TH1F("htrack_fromB0_Eta","htrack_fromB0_Eta",100,-5.0,5.0);
    hB0Pt               	= new TH1F("hB0Pt","hB0Pt",1000 ,0 ,100);
    hjpsi_fromB0_Pt		= new TH1F("hjpsi_fromB0_Pt","hjpsi_fromB0_Pt",1000 ,0 ,100);
    hjpsi_track_deltaR		= new TH1F("hjpsi_track_deltaR","hjpsi_track_deltaR",100 ,0 ,10);
    htrackChi2byNDF		= new TH1F("htrackChi2byNDF","htrackChi2byNDF",100 ,0 ,10);
    htrackShits         	= new TH1F("htrackShits","htrackShits",50 ,0 ,50);
    htrackPhits         	= new TH1F("htrackPhits","htrackPhits",15 ,0 ,15);
    
*/
    

    
    char histname[100];
    char histname2[100];
    
//    for (int j=0;j<21;j++) { // histname loop // S hits
//    for (int j=0;j<11;j++) { // histname loop // Phits
//    for (int j=0;j<30;j++) { // histname loop // MuDz
//    for (int j=0;j<11;j++) { // histname loop // MuDxy
//   for (int j=0;j<20;j++) { // histname loop //B0CosAlphaPV // B0Pt
//   for (int j=0;j<40;j++) { // histname loop //B0CosAlphaPV // B0Pt //trackPt
//   for (int j=0;j<10;j++) { // histname loop // B0Vtx_CL
//   for (int j=0;j<10;j++) { // histname loop // B0CTauPV // MuMuVtx_CL
    for (int j=0;j<7;j++) { // histname loop //MuMu_Track_deltaR
       
//            sprintf(histname,"hjpsiKPiMassSelAltZoom_MuChi2_by_NDF%i",j);
//            sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuChi2_by_NDF%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//            hjpsiKPiMassSelAltZoom_MuChi2_by_NDF[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);
        
//            sprintf(histname,"hjpsiKPiMassSelAltZoom_MuS_hits%i",j);
//            sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuS_hits%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//            hjpsiKPiMassSelAltZoom_MuS_hits[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);
        
//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuP_hits%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuP_hits%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_MuP_hits[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);
        
//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuDz%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuDz%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_MuDz[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuDxy%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuDxy%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_MuDxy[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_B0CosAlphaPV0.99%i",j+65);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_B0CosAlphaPV0.99%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j+65);
//        hjpsiKPiMassSelAltZoom_B0CosAlphaPV[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_B0Vtx_CL0.0%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_B0Vtx_CL0.0%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_B0Vtx_CL[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);
       
//        sprintf(histname,"hjpsiKPiMassSelAltZoom_B0CTauPV%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_B0CTauPV%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_B0CTauPV[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuMuVtx_CL0.0%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuMuVtx_CL0.0%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_MuMuVtx_CL[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_B0Pt%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_B0Pt%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_B0Pt[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);
       
//       sprintf(histname,"hjpsiKPiMassSelAltZoom_trackPt%i",j+4);
//       sprintf(histname2,"hjpsiKPiMassSelAltZoom_trackPt%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j+4);
//       hjpsiKPiMassSelAltZoom_trackPt[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuMu_Track_deltaR%i",j+2);
        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuMu_Track_deltaR%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j+2);
        hjpsiKPiMassSelAltZoom_MuMu_Track_deltaR[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);
        
       
        
    }// histname loop

}

Bool_t SignalExtract_Jpsi_small_ntpls_cut_opt::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SignalExtract_Jpsi_small_ntpls_cut_opt::GetEntry() or TBranch::GetEntry()
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
    
//    h_nB0->Fill(nB0);
    int numB0 = 0;
    
    Float_t B0MassAlt=0;
    double theta_Jpsi=0;
    double theta_Kstar=0;
    double phi=0;
    double KPiMass = 0;
    
    TLorentzVector mu1_p4, mu2_p4;
    TLorentzVector jpsip4;
    TLorentzVector pip4, pip4_exchanged;
    TLorentzVector kp4, kp4_exchanged;
    TLorentzVector Pip4_orig, Kp4_orig;
    TLorentzVector B0p4, B0p4_KPiExchanged;
    

    
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
        


  Float_t mu1E = 0., mu2E = 0.;
  mu1E = sqrt( pow((*muPx)[mu1_fromB0_index],2) + pow((*muPy)[mu1_fromB0_index],2) + pow((*muPz)[mu1_fromB0_index],2) + pow(muon_mass,2) );
  mu2E = sqrt( pow((*muPx)[mu2_fromB0_index],2) + pow((*muPy)[mu2_fromB0_index],2) + pow((*muPz)[mu2_fromB0_index],2) + pow(muon_mass,2) );
  mu1_p4.SetPxPyPzE( (*muPx)[mu1_fromB0_index], (*muPy)[mu1_fromB0_index], (*muPz)[mu1_fromB0_index], mu1E);
  mu2_p4.SetPxPyPzE( (*muPx)[mu2_fromB0_index], (*muPy)[mu2_fromB0_index], (*muPz)[mu2_fromB0_index], mu2E);

       

  Float_t jpsi_E = 0.;
  jpsi_E = sqrt( pow((*MuMuPx)[jpsi_index],2) + pow((*MuMuPy)[jpsi_index], 2) + pow((*MuMuPz)[jpsi_index], 2) + pow((*MuMuMass)[jpsi_index], 2) ) ;
  jpsip4.SetPxPyPzE( (*MuMuPx)[jpsi_index], (*MuMuPy)[jpsi_index], (*MuMuPz)[jpsi_index], jpsi_E) ;



  pip4.SetPxPyPzE( (*PionPx_MuMuPiK)[myB0Idx], (*PionPy_MuMuPiK)[myB0Idx], (*PionPz_MuMuPiK)[myB0Idx], (*PionE_MuMuPiK)[myB0Idx]) ;

  kp4.SetPxPyPzE( (*KaonPx_MuMuPiK)[myB0Idx], (*KaonPy_MuMuPiK)[myB0Idx], (*KaonPz_MuMuPiK)[myB0Idx], (*KaonE_MuMuPiK)[myB0Idx]) ;

     
  Pip4_orig.SetPxPyPzE( (*trackPx)[pi_orig_Index], (*trackPy)[pi_orig_Index], (*trackPz)[pi_orig_Index], (*trackEnergy)[pi_orig_Index]) ; // original
  float pionCharge = (*trackCharge)[pi_orig_Index];

  Float_t K_E = 0.;
  K_E = sqrt( pow((*trackPx)[ka_orig_Index], 2) + pow((*trackPy)[ka_orig_Index], 2) + pow((*trackPz)[ka_orig_Index], 2) + pow(kaonCh_mass, 2) ) ; // original
  Kp4_orig.SetPxPyPzE( (*trackPx)[ka_orig_Index], (*trackPy)[ka_orig_Index], (*trackPz)[ka_orig_Index], K_E) ; // original
  float kaonCharge = (*trackCharge)[ka_orig_Index];
        
        
  pip4_exchanged.SetVectM(pip4.Vect(), kaonCh_mass) ;
  kp4_exchanged.SetVectM(kp4.Vect(), pionCh_mass) ;

  B0p4 = jpsip4+pip4+kp4;
        


//  Float_t
        B0MassAlt = (jpsip4+pip4+kp4).Mag() - jpsip4.M() + jpsi_mass;
        
        double B0_Pt = B0p4.Pt();
        double pion_fromB0_Pt = pip4.Pt();
        double kaon_fromB0_Pt = kp4.Pt();
        double jpsi_fromB0_Pt = jpsip4.Pt();
	    double pion_from_B0_Eta = pip4.Eta();
        double kaon_from_B0_Eta = kp4.Eta();
        
        KPiMass = (pip4+kp4).Mag();


  B0p4_KPiExchanged = jpsip4 + pip4_exchanged + kp4_exchanged;
        


        theta_Jpsi = GetThetaMuMu(B0p4, jpsip4, mu1Charge>0 ? mu1_p4 : mu2_p4, beam_energy, jpsi_mass, muon_mass);
        theta_Kstar = GetThetaMuMu(B0p4, (pip4+kp4), pionCharge>0 ? pip4 : kp4, beam_energy, KPiMass, pionCharge>0 ? pionCh_mass : kaonCh_mass) ;
        phi = GetPhi(B0p4,mu1Charge>0 ? mu1_p4 : mu2_p4,mu1Charge>0 ? mu2_p4 : mu1_p4, kp4, pip4 );

//        h_theta_Jpsi->Fill(theta_Jpsi);
//        h_theta_Kstar->Fill(theta_Kstar);
//        h_phi_planes->Fill(phi);

        
        
  Bool_t newsoftID = false;
  Bool_t baselineB0Sel = false;

/*
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
        
        
*/

  //
  // NEW SOFT MUON 2013
  //
    
// for (double k=0;k<21;k++){ // cut opt loop // S hits
//for (double k=0;k<11;k++){ // cut opt loop // P hits
//for (double k=0;k<30;k++){ // cut opt loop // MuDz
//for (double k=0;k<11;k++){ // cut opt loop // MuDxy
//for (double k=0;k<20;k++){ // cut opt loop // B0CosAlphaPV // B0Pt
//for (double k=0;k<40;k++){ // cut opt loop //trackPt
//for (double k=0;k<10;k++){ // cut opt loop // B0Vtx_CL, B0CTauPV
for (double k=0;k<7;k++){ // cut opt loop //MuMu_Track_deltaR
//double cut=k; // MuChi2, S hits, P Hits, MuDz , B0CTauPV
//double cut=k*0.1; //Dxy
//double cut=0.9965+k*0.0001; // B0CosAlphaPV
//double cut=k*0.01; // B0Vtx_CL
//double cut = k*0.01;    // MuMuVtx_CL
//double cut = k+10; // B0Pt
//double cut=0.4+k*0.1; // trackPt
    double cut=0.2+k*0.2; //MuMu_Track_deltaR


    //=============== basic selection variables =================
    
    //if (((*muChi2)[mu1_fromB0_index]/(*muNDF)[mu1_fromB0_index])<cut && ((*muChi2)[mu2_fromB0_index]/(*muNDF)[mu2_fromB0_index])<cut) { // cut imp cond
    //if ( (*muShits)[mu1_fromB0_index]>cut && (*muShits)[mu2_fromB0_index]>cut ) { // cut imp cond
    //if ( (*muPhits)[mu1_fromB0_index]>cut && (*muPhits)[mu2_fromB0_index]>cut ) { // cut imp cond
    //if(   fabs((*muDzVtx)[mu1_fromB0_index])<cut && fabs((*muDzVtx)[mu2_fromB0_index])<cut ) { // cut imp cond
    //if(   fabs((*muDxyVtx)[mu1_fromB0_index])<cut && fabs((*muDxyVtx)[mu2_fromB0_index])<cut) { // cut imp cond
    
    // ============== tight variables ======================
    
    //if( (*B0CosAlphaPV)[myB0Idx] > cut ) { // cut imp cond
    //if( (*B0Vtx_CL)[myB0Idx] > cut ) { // cut imp cond
    //if( (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > cut ) { // cut imp cond
//        if( (*MuMuVtx_CL)[jpsi_index] > cut ) { // cut imp cond
//    if(  B0_Pt > cut ) { // cut imp cond
//    if( pion_fromB0_Pt > cut && kaon_fromB0_Pt > cut ) { // cut imp cond
    if (jpsip4.DeltaR(pip4) < cut && jpsip4.DeltaR(kp4) < 1.0) { // cut imp cond
    
        
        
  if ( 1 && 
  ((*muQual)[mu1_fromB0_index] & (1 << muonQual[3])) && ((*muQual)[mu2_fromB0_index] & (1 << muonQual[3])) && //TMOneSTationTight
  ((*muChi2)[mu1_fromB0_index]/(*muNDF)[mu1_fromB0_index])<3. && ((*muChi2)[mu2_fromB0_index]/(*muNDF)[mu2_fromB0_index])<3. && // cut opt val ~3
  (*muShits)[mu1_fromB0_index]>3 && (*muShits)[mu2_fromB0_index]>5 && // dont see much variation // cut opt = 5
  (*muPhits)[mu1_fromB0_index]>0 && (*muPhits)[mu2_fromB0_index]>0 &&                      // new soft muons 2013 (was 1 in old soft muons) keep
  fabs((*muDzVtx)[mu1_fromB0_index])<20. && fabs((*muDzVtx)[mu2_fromB0_index])<20. &&        // new soft muons 2013 (was 30 in old soft muons) keep // cut opt = 20
  fabs((*muDxyVtx)[mu1_fromB0_index])<0.4 && fabs((*muDxyVtx)[mu2_fromB0_index])<0.4         // new soft muons 2013 (was 3 in old soft muons) // cut opt = 0.3
   )
  {

   newsoftID = true;
  }


  Bool_t Mu1_PtSel = false;
  Bool_t Mu2_PtSel = false;


  if ( ( ( (fabs(mu1_p4.Eta()) < 1.2 ) && (mu1_p4.Pt()>4.)) ) || ( ( mu1_p4.Eta() >= 1.2 || mu1_p4.Eta() <=- 1.2) && (mu1_p4.Pt()>3.3) ) ) Mu1_PtSel = true;
  if ( ( ( (fabs(mu2_p4.Eta()) < 1.2 ) && (mu2_p4.Pt()>4.)) ) || ( ( mu2_p4.Eta() >= 1.2 || mu2_p4.Eta() <=- 1.2) && (mu2_p4.Pt()>3.3) ) ) Mu2_PtSel = true;


  if ( 1 && newsoftID  // cuts loose
  && ( (*B0Vtx_CL)[myB0Idx] > 0.05 )  // cut opt = 0.03
  && ( (*B0CosAlphaPV)[myB0Idx] > 0.99 ) // cut opt = 0.998
  && ( (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 4.0 ) //cut opt = 6.0
  && ( fabs( (*MuMuMass)[jpsi_index] - jpsi_mass ) < 0.2 ) // cut opt = 0.12 was 0.2 for baseline cuts
  && ( (*MuMuVtx_CL)[jpsi_index] > 0.03 ) //0.02
//  && ( pion_fromB0_Pt > 0.45 ) // 0.45 >2.0
//  && ( kaon_fromB0_Pt > 0.45 ) // 0.45 >2.0
  && ( B0_Pt > 5.) // cut opt >8 // >19
//  && ( jpsi_fromB0_Pt > 5.)
  && ( mu1_p4.Pt()>3.3 && mu2_p4.Pt() > 3.3)
  && Mu1_PtSel && Mu2_PtSel
  ) // cuts loose
  {
    hjpsiKPiMassBaseSelAlt->Fill( B0MassAlt );
    baselineB0Sel = true;
  }




  if ( 1 // cuts tight
  && baselineB0Sel
//  && B0_Pt > 8.
//  && pion_fromB0_Pt > 0.7
//  && jpsip4.DeltaR(pip4) < 1.0
//  && jpsip4.DeltaR(kp4) < 1.0
  && ((*trackChi2)[pi_orig_Index]/(*trackNDF)[pi_orig_Index]) < 7.0 // <5.0
  && ((*trackChi2)[ka_orig_Index]/(*trackNDF)[ka_orig_Index]) < 7.0 // <5.0
  && (*trackShits)[pi_orig_Index] >= 7 // >=10
  && (*trackShits)[ka_orig_Index] >= 7 // >=10
  && (*trackPhits)[pi_orig_Index] > 0
  && (*trackPhits)[ka_orig_Index] > 0
//  && (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 7.0
  && pip4.Eta() < 2.4 && kp4.Eta() < 2.4  

  ) // cuts tight
   {
     hjpsiKPiMassSelAlt->Fill( B0MassAlt );
//     hjpsiKPiMassSelAltZoom->Fill( B0MassAlt );
       
       int l=k;
       //hjpsiKPiMassSelAltZoom_MuChi2_by_NDF[l]-> Fill( B0MassAlt );
       //hjpsiKPiMassSelAltZoom_MuS_hits[l]-> Fill( B0MassAlt );
       //hjpsiKPiMassSelAltZoom_MuP_hits[l]-> Fill( B0MassAlt );
       //hjpsiKPiMassSelAltZoom_MuDz[l]-> Fill( B0MassAlt );
       //hjpsiKPiMassSelAltZoom_MuDxy[l]-> Fill( B0MassAlt );
       //hjpsiKPiMassSelAltZoom_B0CosAlphaPV[l]-> Fill( B0MassAlt );
       //  hjpsiKPiMassSelAltZoom_B0Vtx_CL[l]-> Fill( B0MassAlt );
       //  hjpsiKPiMassSelAltZoom_B0CTauPV[l]-> Fill( B0MassAlt );
       //  hjpsiKPiMassSelAltZoom_MuMuVtx_CL[l]-> Fill( B0MassAlt );
       //hjpsiKPiMassSelAltZoom_B0Pt[l]-> Fill( B0MassAlt );
//       hjpsiKPiMassSelAltZoom_trackPt[l]-> Fill( B0MassAlt );
       hjpsiKPiMassSelAltZoom_MuMu_Track_deltaR[l]-> Fill( B0MassAlt );
   }
    
       
} // cut imp cond
    
} // cut opt loop
         

    } // b0 loop
      


} //b0 requirement
 



   return kTRUE;
}

void SignalExtract_Jpsi_small_ntpls_cut_opt::SlaveTerminate()
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
      hjpsiKPiMassSelAlt->Write();
        
        
        h_theta_Jpsi->Write();
        h_theta_Jpsi_sel->Write();
        
        h_theta_Kstar->Write();
        h_theta_Kstar_sel->Write();
        
        h_phi_planes->Write();
        h_phi_planes_sel->Write();

/*
      h_nB0->Write();
      h_nB0_sel->Write();
        
      h_theta_Jpsi->Write();
      h_theta_Jpsi_sel->Write();
        
      h_theta_Kstar->Write();
      h_theta_Kstar_sel->Write();
        
      h_phi_planes->Write();
      h_phi_planes_sel->Write();
        



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
      hB0Pt               ->    Write();
      hjpsi_fromB0_Pt     ->	Write();
      hjpsi_track_deltaR  ->	Write();
      htrackChi2byNDF	  ->	Write();
      htrackShits         ->    Write();
      htrackPhits	  ->    Write();

      htrack_fromB0_Eta   ->    Write();
 */
        
//        for (int j=0;j<21;j++) { // S hits
//        for (int j=0;j<11;j++) { // P hits
//        for (int j=0;j<30;j++) { // MuDz
//        for (int j=0;j<11;j++) { // MuDxy
//        for (int j=0;j<20;j++) { // B0CosAlphaPV //B0Pt
//        for (int j=0;j<40;j++) { // trackPt
//        for (int j=0;j<10;j++) { // B0Vtx_CL, B0CTauPV, MuMuVtx_CL
        for (int j=0;j<7;j++) { // MuMu_Track_deltaR
            
            //      hjpsiKPiMassSelAltZoom_MuChi2_by_NDF[j]->Write();
            //      hjpsiKPiMassSelAltZoom_MuS_hits[j]->Write();
            //     hjpsiKPiMassSelAltZoom_MuP_hits[j]->Write();
            //      hjpsiKPiMassSelAltZoom_MuDz[j]->Write();
            //      hjpsiKPiMassSelAltZoom_MuDxy[j]->Write();
            //      hjpsiKPiMassSelAltZoom_B0CosAlphaPV[j]->Write();
            //      hjpsiKPiMassSelAltZoom_B0Vtx_CL[j]->Write();
            //        hjpsiKPiMassSelAltZoom_B0CTauPV[j]->Write();
            //        hjpsiKPiMassSelAltZoom_MuMuVtx_CL[j]->Write();
            //        hjpsiKPiMassSelAltZoom_B0Pt[j]->Write();
            //      hjpsiKPiMassSelAltZoom_trackPt[j]->Write();
              hjpsiKPiMassSelAltZoom_MuMu_Track_deltaR[j]->Write();
        }
        


        
      OutFile->Print();
      fOutput->Add(OutFile); 
      hMuMuMass->SetDirectory(0); // any hname
//      hjpsiKPiMassSelAlt->SetDirectory(0) ;
      gDirectory = savedir;
      fOut->Close();
    }



}

void SignalExtract_Jpsi_small_ntpls_cut_opt::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}


// functions calculating angles

double SignalExtract_Jpsi_small_ntpls_cut_opt::getPlanesAngle(TLorentzVector B0, TLorentzVector K, TLorentzVector Pi, TLorentzVector muM, TLorentzVector muP) {
    
    TLorentzVector KBoosted = K, PiBoosted = Pi, muMBoosted = muM, muPBoosted = muP ;
    muPBoosted.Boost( -B0.BoostVector() ) ;
    muMBoosted.Boost( -B0.BoostVector() ) ;
    KBoosted.Boost( -B0.BoostVector() ) ;
    PiBoosted.Boost( -B0.BoostVector() ) ;
    TVector3 MuMuPlane_normal = muPBoosted.Vect().Cross( muMBoosted.Vect() ) ;
    TVector3 KPiPlane_normal = KBoosted.Vect().Cross( PiBoosted.Vect() ) ;
    Double_t angle = 10. ;
    /*
     TVector3 KstPlane  = LoreVecK.Vect().Cross(LoreVecPi.Vect());
     */
    if (MuMuPlane_normal.Cross(KPiPlane_normal).Dot( -B0.Vect() ) > 0.0)
        angle = MuMuPlane_normal.Angle(KPiPlane_normal);
    else
        angle = -MuMuPlane_normal.Angle(KPiPlane_normal);
    
    return angle;
}


double SignalExtract_Jpsi_small_ntpls_cut_opt::GetPhi(TLorentzVector LoreVecB0,TLorentzVector LoreVecMum, TLorentzVector LoreVecMup, TLorentzVector LoreVecK, TLorentzVector LoreVecPi)	{
    //	#	B0	->	K+	pi-	mu	mu	#
    TVector3	boostB0	=	LoreVecB0.BoostVector();
    LoreVecMum.Boost(-boostB0);
    LoreVecMup.Boost(-boostB0);
    LoreVecK.Boost(-boostB0);
    LoreVecPi.Boost(-boostB0);
    TVector3	MuMuPlane	=	LoreVecMup.Vect().Cross(LoreVecMum.Vect());
    TVector3	KstPlane		=	LoreVecK.Vect().Cross(LoreVecPi.Vect());
    double phiKstMuMuPlane;
    if	(	MuMuPlane.Cross(KstPlane).Dot(-LoreVecB0.Vect())	>	0.0	)
        phiKstMuMuPlane	=	MuMuPlane.Angle(KstPlane);
    else
        phiKstMuMuPlane	=	-MuMuPlane.Angle(KstPlane);
    return
    phiKstMuMuPlane;
}



float SignalExtract_Jpsi_small_ntpls_cut_opt::GetThetaMuMu(TLorentzVector BVec, TLorentzVector JPsiVec, TLorentzVector MuPlusVec, float BeamEnergy, float JPsiPDG , float muonPDG) {
    
    TVector3 JPsiInBFrame, MuInBFrame, MuInJPsiFrame, MuInJPsiFromBFrame;
    TLorentzVector JPsiInBFrameTLVec, MuInBFrameTLVec;
    /*
     // Alessandra
     // get the momentum of the X in the in the B rest-frame : XInBFrame
     GetMomentumInMotherFrame( BVec , XVec , BeamEnergy, XInBFrame);
     XInBFrameTLVec.SetPtEtaPhiM(XInBFrame.Perp() , XInBFrame.Eta(),  XInBFrame.Phi() ,XCandPDG);
     // get the momentum of the J/psi int he X rest-frame with two steps in cascade:
     // 1) step 1 : apply B boost in lab
     GetMomentumInMotherFrame( BVec , JPsiVec, BeamEnergy, JPsiInBFrame);
     JPsiInBFrameTLVec.SetPtEtaPhiM( JPsiInBFrame.Perp() , JPsiInBFrame.Eta(),JPsiInBFrame.Phi() ,JPsiPDG );
     // 2) step 2: apply X boost in B rest-frame
     GetMomentumInMotherFrame( XInBFrameTLVec, JPsiInBFrameTLVec, BeamEnergy, JPsiInXFromBFrame);
     JPsiInXFromBFrameTLVec.SetPtEtaPhiM(JPsiInXFromBFrame.Perp() ,JPsiInXFromBFrame.Eta(),JPsiInXFromBFrame.Phi() ,JPsiPDG );
     */
    
    // B0 - >J/psi K pi
    
    // get the momentum of the J/psi in the in the B rest-frame : JPsiInBFrame
    GetMomentumInMotherFrame( BVec , JPsiVec , BeamEnergy, JPsiInBFrame);
    JPsiInBFrameTLVec.SetPtEtaPhiM(JPsiInBFrame.Perp() , JPsiInBFrame.Eta(),  JPsiInBFrame.Phi() , JPsiPDG);
    
    // get momentum of the mu+ in JPsi rest-frame
    GetMomentumInMotherFrame( BVec , MuPlusVec, BeamEnergy, MuInBFrame); // B boost
    MuInBFrameTLVec.SetPtEtaPhiM(MuInBFrame.Perp() , MuInBFrame.Eta(),  MuInBFrame.Phi() ,muonPDG);
    //GetMomentumInMotherFrame(XInBFrameTLVec, MuInBFrameTLVec, BeamEnergy, MuInXFromBFrame); // X in B r.f. boost
    //MuInXFromBFrameTLVec.SetPtEtaPhiM(MuInXFromBFrame.Perp() ,MuInXFromBFrame.Eta(), MuInXFromBFrame.Phi() ,muonPDG);
    //GetMomentumInMotherFrame( JPsiInXFromBFrameTLVec, MuInXFromBFrameTLVec, BeamEnergy, MuInJPsiFromXFromBFrame);
    GetMomentumInMotherFrame( JPsiInBFrameTLVec, MuInBFrameTLVec, BeamEnergy, MuInJPsiFromBFrame);
    
    float thetaJPsi = MuInJPsiFromBFrame.Angle(JPsiInBFrame);
    
    /*
     // lab frame
     GetMomentumInMotherFrame( JPsiVec , MuPlusVec, BeamEnergy, MuInJPsiFrame); // B boost
     float thetaJPsi = MuInJPsiFrame.Angle(JPsiVec.Vect());
     */
    return thetaJPsi;
    
}

void SignalExtract_Jpsi_small_ntpls_cut_opt::GetMomentumInMotherFrame( TLorentzVector Mother,TLorentzVector Particle, double BeamEnergy , TVector3 &Particle_rotated){
    //Mother momentum in lab frame
    TVector3 bMother = Mother.BoostVector();
    TLorentzVector beam1(0., 0.,  BeamEnergy, BeamEnergy); // beam momentum in lab frame
    TLorentzVector beam2(0., 0., -BeamEnergy, BeamEnergy); // beam momentum in lab frame
    beam1.Boost(-bMother);      // beam momentum in JPsi rest frame
    beam2.Boost(-bMother);     // beam momentum in JPsi rest frame
    TVector3 beam1_dir = beam1.Vect().Unit();  // beam direction in Mother rest frame
    TVector3 beam2_dir = beam2.Vect().Unit();  // beam direction in Mother rest frame
    
    TVector3 Y = beam1_dir.Cross( beam2_dir ).Unit(); // the production plane normal
    TVector3 Z = Mother.Vect().Unit();         // Mother direction in lab frame
    TVector3 X = Y.Cross(Z).Unit();         // completes the right-handed coordinate
    
    Particle.Boost(-bMother);     // Particle momentum in Mother rest frame
    
    
    TRotation rotation;
    rotation.SetToIdentity();
    rotation.RotateAxes(X,Y,Z);
    rotation.Invert(); // transforms coordinates from the "xyz" frame to the new frame
    //TVector3 Particle_rotated = Particle.Vect(); // io: particle coordinates in the rotated frame
    Particle_rotated = Particle.Vect();
    //Particle_rotated.Transform(rotation);
    
}




