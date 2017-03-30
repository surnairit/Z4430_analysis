#define SignalExtract_Jpsi_small_ntpls_cxx
// The class definition in SignalExtract_Jpsi_small_ntpls.h has been generated automatically
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
// Root > T->Process("SignalExtract_Jpsi_small_ntpls.C")
// Root > T->Process("SignalExtract_Jpsi_small_ntpls.C","some options")
// Root > T->Process("SignalExtract_Jpsi_small_ntpls.C+")
//

#include "SignalExtract_Jpsi_small_ntpls.h"
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


void SignalExtract_Jpsi_small_ntpls::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void SignalExtract_Jpsi_small_ntpls::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls.root" );
     OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_finalcuts_m2jpsipi_cases.root" );
    
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls_Dalitzfit.root" );
   fOut = OutFile->OpenFile("RECREATE");

   if ( !(fOut = OutFile->OpenFile("RECREATE")) )
    {
      Warning("SlaveBegin", "problems opening file: %s/%s",
              OutFile->GetDir(), OutFile->GetFileName());
    }

    
    // Book NTuple
    _nt = new TNtupleD("_nt","_nt","B0_mass:KPi_mass:Jpsi_mass:JpsiPi_mass:B0_3mom:KPi_3mom:Jpsi_3mom:K_3mom:Pi_3mom:Theta_Kstar:Theta_Jpsi:Phi:evtNum:runNum:lumiNum"); // output ntuple
    
    //////// HISTOGRAMS
  // put them here:
  //

    h_nB0                   = new TH1F("h_nB0","h_nB0",10,0,10);
    h_nB0_sel               = new TH1F("h_nB0_sel","h_nB0_sel",10,0,10);
    
    h_theta_Jpsi            = new TH1F("h_theta_Jpsi","J/#psi helicity angle ;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_theta_Jpsi_sel        = new TH1F("h_theta_Jpsi_sel","J/#psi helicity angle after selection;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_cos_theta_Jpsi        = new TH1F("h_cos_theta_Jpsi","Cosine of J/#psi helicity angle ;#cos(theta_{J/#psi})", 102, -1.02, 1.02);
    h_cos_theta_Jpsi_sel    = new TH1F("h_cos_theta_Jpsi_sel","Cosine of J/#psi helicity angle after selection;#cos(theta_{J/#psi})", 102, -1.02, 1.02);

    h_theta_Kstar           = new TH1F("h_theta_Kstar","K* helicity angle ;#theta_{K*}", 160, -0.03, 3.17);
    h_theta_Kstar_sel       = new TH1F("h_theta_Kstar_sel","K* helicity angle after selection;#theta_{K*}", 160, -0.03, 3.17);
    h_cos_theta_Kstar       = new TH1F("h_cos_theta_Kstar","Cosine of K* helicity angle ;#cos(theta_{K*})", 102, -1.02, 1.02);
    h_cos_theta_Kstar_sel   = new TH1F("h_cos_theta_Kstar_sel","Cosine of K* helicity angle after selection;#cos(theta_{K*})", 102, -1.02, 1.02);
    
    h_phi_planes            = new TH1F("h_phi_planes","Angle between K#pi and #mu#mu planes;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;
    h_phi_planes_sel        = new TH1F("h_phi_planes_sel","Angle between K#pi and #mu#mu planes after selection;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;
    
    
    h_theta_Jpsi_Trackpt4p3            = new TH1F("h_theta_Jpsi_Trackpt4p3","J/#psi helicity angle Trackpt > 4.3 ;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_theta_Kstar_Trackpt4p3          = new TH1F("h_theta_Kstar_Trackpt4p3","K* helicity angle Trackpt > 4.3 ;#theta_{K*}", 160, -0.03, 3.17);
    h_phi_planes_Trackpt4p3            = new TH1F("h_phi_planes_Trackpt4p3","Angle between K#pi and #mu#mu planes Trackpt > 4.3 ;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;
    
    hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1 	= new TH1F("hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1","hjpsiKPiMassSel ALTERNATIVE ZOOM Trackpt > 2.5 nB0eq1", 90, 5.15, 5.45);
    hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1	= new TH1F("hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1","hjpsiKPiMassSelAltZoom B0pt >18 GeV,Trackpt > 2.5 nB0eq1 ",90, 5.15, 5.45);
    
    
// nB0 = 1 variables
    
    h_theta_Jpsi_sel_nB01        = new TH1F("h_theta_Jpsi_sel_nB01","J/#psi helicity angle after selection nB0=1;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_cos_theta_Jpsi_sel_nB01    = new TH1F("h_cos_theta_Jpsi_sel_nB01","Cosine of J/#psi helicity angle after selection nB0=1;#cos(theta_{J/#psi})", 102, -1.02, 1.02);
    
    h_theta_Kstar_sel_nB01       = new TH1F("h_theta_Kstar_sel_nB01","K* helicity angle after selection nB0=1;#theta_{K*}", 160, -0.03, 3.17);
    h_cos_theta_Kstar_sel_nB01   = new TH1F("h_cos_theta_Kstar_sel_nB01","Cosine of K* helicity angle after selection nB0=1;#cos(theta_{K*})", 102, -1.02, 1.02);
    
    h_phi_planes_sel_nB01        = new TH1F("h_phi_planes_sel_nB01","Angle between K#pi and #mu#mu planes after selection nB0=1;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;

//    hjpsiKPiMassSelAltZoom_nB01 		= new TH1F("hjpsiKPiMassSelAltZoom_nB01","hjpsiKPiMassSelAltZoom_nB01", 90, 5.15, 5.45);
//    hjpsiKPiMass_noKstar_nB01           = new TH1F("hjpsiKPiMass_noKstar_nB01","hjpsiKPiMass_noKstar_nB01", 90, 5.15, 5.45);
    hjpsiKPiMassSelAltZoom_nB01                 = new TH1F("hjpsiKPiMassSelAltZoom_nB01","hjpsiKPiMassSelAltZoom_nB01", 90, 5.10, 5.46);
    hjpsiKPiMass_noKstar_nB01           = new TH1F("hjpsiKPiMass_noKstar_nB01","hjpsiKPiMass_noKstar_nB01", 90, 5.10, 5.46);

    
    hjpsiPiMass2_nB01            = new TH1F("hjpsiPiMass2","hjpsiPiMass2",1700,9,26);
    hjpsiPiMass2_noKstar_nB01    = new TH1F("hjpsiPiMass2_noKstar_nB01","hjpsiPiMass2_noKstar_nB01",1700,9,26);
    hjpsiPiMass2_nB01_case1    = new TH1F("hjpsiPiMass2_nB01_case1","hjpsiPiMass2_nB01 M2KPi < 1.2 GeV",1700,9,26);
    hjpsiPiMass2_nB01_case2    = new TH1F("hjpsiPiMass2_nB01_case2","hjpsiPiMass2_nB01 1.2 < M2KPi < 2.05 GeV",1700,9,26);
    hjpsiPiMass2_nB01_case3    = new TH1F("hjpsiPiMass2_nB01_case3","hjpsiPiMass2_nB01 2.05 < M2KPi < 3.2 GeV",1700,9,26);
    hjpsiPiMass2_nB01_case4    = new TH1F("hjpsiPiMass2_nB01_case4","hjpsiPiMass2_nB01 M2KPi > 3.2 GeV",1700,9,26);
    
    hjpsiPiMass_nB01             = new TH1F("hjpsiPiMass_nB01","hjpsiPiMass_nB01",40,3.8,4.8);
    hjpsiPiMass_noKstar_nB01     = new TH1F("hjpsiPiMass_noKstar_nB01","hjpsiPiMass noKstar_nB01",40,3.8,4.8);
    
    
    hjpsiKPiMassSelAltZoomB0pt18_nB0eq1 	= new TH1F("hjpsiKPiMassSelAltZoomB0pt18_nB0eq1","hjpsiKPiMassSel ALTERNATIVE ZOOM B0pt >18 GeV nB0eq1", 90, 5.10, 5.46);
    hjpsiKPiMassSelAltZoomTrackpt4p3_nB0eq1 = new TH1F("hjpsiKPiMassSelAltZoomTrackpt4p3_nB0eq1","hjpsiKPiMassSel ALTERNATIVE ZOOM Trackpt > 4.3 nB0eq1", 90, 5.10, 5.46);
    hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3_nB0eq1	= new TH1F("hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3_nB0eq1","hjpsiKPiMassSelAltZoom B0pt >18 GeV,Trackpt > 4.3 nB0eq1 ",90, 5.10, 5.46);

    
    
    hDalitz_peak_nB01_bin1          = new TH2F("hDalitz_peak_nB01_bin1","hDalitz_peak_nB01_bin1",600,0,6,1700,9,26);
    hDalitz_sideband_nB01_bin1      = new TH2F("hDalitz_sideband_nB01_bin1","hDalitz_sideband_nB01_bin1",600,0,6,1700,9,26);
    hDalitz_peak_nB01_bin2          = new TH2F("hDalitz_peak_nB01_bin2","hDalitz_peak_nB01_bin2",300,0,6,850,9,26);
    hDalitz_sideband_nB01_bin2      = new TH2F("hDalitz_sideband_nB01_bin2","hDalitz_sideband_bin2",300,0,6,850,9,26);
    hDalitz_peak_nB01_bin3          = new TH2F("hDalitz_peak_nB01_bin3","hDalitz_peak_nB01_bin3",200,0,6,567,9,26);
    hDalitz_sideband_nB01_bin3      = new TH2F("hDalitz_sideband_nB01_bin3","hDalitz_sideband_bin3",200,0,6,567,9,26);
    hDalitz_peak_nB01_bin4          = new TH2F("hDalitz_peak_nB01_bin4","hDalitz_peak_nB01_bin4",150,0,6,425,9,26);
    hDalitz_sideband_nB01_bin4      = new TH2F("hDalitz_sideband_nB01_bin4","hDalitz_sideband_nB01_bin4",20,0,6,30,9,26);

    hDalitzProj_m2KPi_nB01_peak         = new TH1F("hDalitzProj_m2KPi_nB01_peak","m^{2}(K#pi) in B0 peak nB01",600,0,6);
    hDalitzProj_m2KPi_nB01_sideband     = new TH1F("hDalitzProj_m2KPi_nB01_sideband","m^{2}(K#pi) in B0 sideband nB01",100,0,6);
    
    hDalitzProj_m2JpsiPi_nB01_peak      = new TH1F("hDalitzProj_m2JpsiPi_nB01_peak","m^{2}(J/#psi#pi) in B0 peak nB01",1700,9,26);
    hDalitzProj_m2JpsiPi_nB01_sideband  = new TH1F("hDalitzProj_m2JpsiPi_nB01_sideband","m^{2}(J/#psi#pi) in B0 sideband nB01",150,9,26);
    
// nB0 = 1 variables
    
    hMuMuMass               = new TH1F("hMuMuMass","hMuMuMass",1000,0,10);
    hKPiMassB0              = new TH1F("hKPiMassB0","hKPiMassB0",1000,0,5);
    hKPiMass_noBs           = new TH1F("hKPiMass_noBs","hKPiMass_noBs",1000,0,5);
    hKKMassB0               = new TH1F("hKKMassB0","hKKMassB0",1000,0,5);
    hKKMass_control         = new TH1F("hKKMass_control","hKKMass_control",1000,0,5);
    hPiPiMassB0             = new TH1F("hPiPiMassB0","hPiPiMassB0",1000,0,5);

    hPiPiMassB0_noVertexCut	= new TH1F("hPiPiMassB0_noVertexCut","hPiPiMassB0 noVertexCut",1000,0,5);
    
    hjpsiPiMass             = new TH1F("hjpsiPiMass","hjpsiPiMass",40,3.8,4.8);
    hjpsiPiMass_noKstar     = new TH1F("hjpsiPiMass_noKstar","hjpsiPiMass noKstar",40,3.8,4.8);
    
    hjpsiPiMass2            = new TH1F("hjpsiPiMass2","hjpsiPiMass2",1700,9,26);
    hjpsiPiMass2_noKstar    = new TH1F("hjpsiPiMass2_noKstar","hjpsiPiMass2_noKstar",1700,9,26);
    
    hjpsiPiMass2_case1    = new TH1F("hjpsiPiMass2_case1","hjpsiPiMass2 M2KPi < 1.2 GeV",1700,9,26);
    hjpsiPiMass2_case2    = new TH1F("hjpsiPiMass2_case2","hjpsiPiMass2 1.2 < M2KPi < 2.05 GeV",1700,9,26);
    hjpsiPiMass2_case3    = new TH1F("hjpsiPiMass2_case3","hjpsiPiMass2 2.05 < M2KPi < 3.2 GeV",1700,9,26);
    hjpsiPiMass2_case4    = new TH1F("hjpsiPiMass2_case4","hjpsiPiMass2 M2KPi > 3.2 GeV",1700,9,26);

    hjpsiPiMass2_sb    = new TH1F("hjpsiPiMass2_sb","hjpsiPiMass2 sidebands ",1700,9,26);
    

    
    hPiPiMassPsi2S          = new TH1F("hPiPiMassPsi2S","hPiPiMassPsi2S",1000,0,5);
    hJpsiKKMass             = new TH1F("hJpsiKKMass","hJpsiKKMass",1000,5,10);
    hJpsiKKMass_control     = new TH1F("hJpsiKKMass_control","hJpsiKKMass_control",1000,5,10);
    hJpsiPiPiMass			= new TH1F("hJpsiPiPiMass","hJpsiPiPiMass",2000,0,10);
    hJpsiPhiToKKMass		= new TH1F("hJpsiPhiToKKMass","hJpsiPhiToKKMass",1000,5,10);
    hJpsif1525ToKKMass		= new TH1F("hJpsif1525ToKKMass","hJpsif1525ToKKMass",1000,5,10);
    hjpsiKPiMassSelAlt		= new TH1F("hjpsiKPiMassSelAlt","hmjpsiKPiMassSel ALTERNATIVE", 100, 4.8, 5.8);
    hjpsiKPiMassSelAltZoom 	= new TH1F("hjpsiKPiMassSelAltZoom","hjpsiKPiMassSel ALTERNATIVE ZOOM", 90, 5.10, 5.46);
    
    hjpsiKPiMass_noKstar 	= new TH1F("hjpsiKPiMass_noKstar","hjpsiKPiMassSel no Kstar", 90, 5.10, 5.46);
    
    hJpsiKPi_JpsiKK         = new TH2F("hJpsiKPi_JpsiKK","JpsiKPi(x) vs JpsiKK (y)",1000,5,10,1000,5,10);
    
    hJpsiPiPi_PiPi          = new TH2F("hJpsiPiPi_PiPi","mJpsiPiPi vs mPiPi",2000,0,10,1000,0,5);
    hJpsiKPi_PiPi           = new TH2F("hJpsiKPi_PiPi","mJpsiKPi vs mPiPi",2000,0,10,1000,0,5);
    hJpsiKK_PiPi            = new TH2F("hJpsiKK_PiPi","mJpsiKK vs mPiPi",2000,0,10,1000,0,5);
    hJpsiKK_KK              = new TH2F("hJpsiKK_KK","mJpsiKK vs mKK",2000,0,10,1000,0,5);
    hJpsiPiPi_KK            = new TH2F("hJpsiPiPi_KK","mJpsiPiPi vs mKK",2000,0,10,1000,0,5);
    hJpsiKPi_KK             = new TH2F("hJpsiKPi_KK","mJpsiKPi vs mKK",2000,0,10,1000,0,5);
    
    hPiPi_KK                = new TH2F("hPiPi_KK","mPiPi(y) vs mKK(x)",1000,0,5,100,0,5);
    hPiPi_KPi               = new TH2F("hPiPi_KPi","mPiPi(y) vs mKPi(x)",1000,0,5,100,0,5);
    hPiPi_KPi_swapped       = new TH2F("hPiPi_KPi_swapped","mPiPi(y) vs mKPi_swapped(x)",1000,0,5,100,0,5);
    hKK_KPi                 = new TH2F("hKK_KPi","mKK(y) vs mKPi(x)",1000,0,5,100,0,5);
    hKK_KPi_swapped         = new TH2F("hKK_KPi_swapped","mKK(y) vs mKPi_swapped(x)",1000,0,5,100,0,5);
    
    hDalitz_peak_bin1       = new TH2F("hDalitz_peak_bin1","hDalitz_peak_bin1",600,0,6,1700,9,26);
    hDalitz_sideband_bin1   = new TH2F("hDalitz_sideband_bin1","hDalitz_sideband_bin1",600,0,6,1700,9,26);
    hDalitz_peak_bin2       = new TH2F("hDalitz_peak_bin2","hDalitz_peak_bin2",300,0,6,850,9,26);
    hDalitz_sideband_bin2   = new TH2F("hDalitz_sideband_bin2","hDalitz_sideband_bin2",300,0,6,850,9,26);
    hDalitz_peak_bin3       = new TH2F("hDalitz_peak_bin3","hDalitz_peak_bin3",200,0,6,567,9,26);
    hDalitz_sideband_bin3   = new TH2F("hDalitz_sideband_bin3","hDalitz_sideband_bin3",200,0,6,567,9,26);
    hDalitz_peak_bin4       = new TH2F("hDalitz_peak_bin4","hDalitz_peak_bin4",150,0,6,425,9,26);
//    hDalitz_sideband_bin4   = new TH2F("hDalitz_sideband_bin4","hDalitz_sideband_bin4",100,0,6,425,9,26);

    hDalitz_sideband_bin4   = new TH2F("hDalitz_sideband_bin4","hDalitz_sideband_bin4",20,0,6,30,9,26);

    
    hDalitzProj_m2KPi_peak  = new TH1F("hDalitzProj_m2KPi_peak","m^{2}(K#pi) in B0 peak",600,0,6);
    hDalitzProj_m2KPi_sideband  = new TH1F("hDalitzProj_m2KPi_sideband","m^{2}(K#pi) in B0 sideband",100,0,6);

    hDalitzProj_m2JpsiPi_peak  = new TH1F("hDalitzProj_m2JpsiPi_peak","m^{2}(J/#psi#pi) in B0 peak",1700,9,26);
    hDalitzProj_m2JpsiPi_sideband  = new TH1F("hDalitzProj_m2JpsiPi_sideband","m^{2}(J/#psi#pi) in B0 sideband",150,9,26);
    
    hjpsiKPiMassSelAltZoomB0pt18 		= new TH1F("hjpsiKPiMassSelAltZoomB0pt18","hjpsiKPiMassSel ALTERNATIVE ZOOM B0pt >18 GeV", 90, 5.10, 5.46);
    hjpsiKPiMassSelAltZoomTrackpt4p3 	= new TH1F("hjpsiKPiMassSelAltZoomTrackpt4p3","hjpsiKPiMassSel ALTERNATIVE ZOOM Trackpt > 4.3", 90, 5.10, 5.46);
    hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3	= new TH1F("hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3","hjpsiKPiMassSelAltZoom B0pt >18 GeV,Trackpt > 4.3 ",90, 5.10, 5.46);
    
    hjpsiKPiMassSelAltZoomTrackpt2p5 	= new TH1F("hjpsiKPiMassSelAltZoomTrackpt2p5","hjpsiKPiMassSel ALTERNATIVE ZOOM Trackpt > 2.5", 90, 5.15, 5.45);
    hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5	= new TH1F("hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5","hjpsiKPiMassSelAltZoom B0pt >18 GeV,Trackpt > 2.5 ",90, 5.10, 5.46);
    



    hjpsiKPiMassNoPhi 		= new TH1F("hjpsiKPiMassNoPhi","hjpsiKPiMass No Phi to KK ", 90, 5.10, 5.46);
    hjpsiKPiMassBsTail 		= new TH1F("hjpsiKPiMassBsTail","hjpsiKPiMass in Bs Tail region ", 90, 5.10, 5.46);
    hjpsiKPiMassBs          = new TH1F("hjpsiKPiMassBs","hjpsiKPiMass in Bs signal region ", 90, 5.10, 5.46);

    hjpsiKPiMassBaseSelAlt 	= new TH1F("hjpsiKPiMassBaseSelAlt"," MuMuKPiMass after basic selection",10000, 0, 100);


    hChi2byNDF			= new TH1F("hChi2byNDF","hChi2byNDF",100,0,10);
    hmuShits 			= new TH1F("hmuShits","hmuShits",50,0,50);
    hmuPhits 			= new TH1F("hmuPhits","hmuPhits",15,0,15);
    hmuDz 			= new TH1F("hmuDz","hmuDz",3000,0,30);
    hmuDxy 			= new TH1F("hmuDxy","hmuDxy",1000,0,10);
    hB0Vtx_CL 			= new TH1F("hB0Vtx_CL","hB0Vtx_CL",1000,0,1.0);
   
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

}

Bool_t SignalExtract_Jpsi_small_ntpls::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SignalExtract_Jpsi_small_ntpls::GetEntry() or TBranch::GetEntry()
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
    
    double m2kpi = 0.0;
    

    
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
        
        
        //double
        theta_Jpsi = GetThetaMuMu(B0p4, jpsip4, mu1Charge>0 ? mu1_p4 : mu2_p4, beam_energy, jpsi_mass, muon_mass);
        //double
        theta_Kstar = GetThetaMuMu(B0p4, (pip4+kp4), pionCharge>0 ? pip4 : kp4, beam_energy, KPiMass, pionCharge>0 ? pionCh_mass : kaonCh_mass) ;
        //double
//        phi = getPlanesAngle(B0p4, kp4, pip4, muM_p4, muP_p4) ;
//        phi = GetPhi(B0p4,mu1_p4, mu2_p4, kp4, pip4 );
        phi = GetPhi(B0p4,mu1Charge>0 ? mu1_p4 : mu2_p4,mu1Charge>0 ? mu2_p4 : mu1_p4, kp4, pip4 );

        h_theta_Jpsi->Fill(theta_Jpsi);
        h_cos_theta_Jpsi->Fill(TMath::Cos(theta_Jpsi));
        
        h_theta_Kstar->Fill(theta_Kstar);
        h_cos_theta_Kstar->Fill(TMath::Cos(theta_Kstar));
        
        h_phi_planes->Fill(phi);

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
  && ( (*B0Vtx_CL)[myB0Idx] > 0.09 ) //0.05
  && ( (*B0CosAlphaPV)[myB0Idx] > 0.9985 ) //0.998
  && ( (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 9.0 ) //7.0
  && ( fabs( (*MuMuMass)[jpsi_index] - jpsi_mass ) < 0.12 ) // 0.12 was 0.2 for baseline cuts
  && ( (*MuMuVtx_CL)[jpsi_index] > 0.02 ) //0.02
  && ( pion_fromB0_Pt > 0.45 ) // 0.45 >2.0
  && ( kaon_fromB0_Pt > 0.45 ) // 0.45 >2.0
  && ( B0_Pt > 8.) // >7 // >18
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
  && jpsip4.DeltaR(pip4) < 1.0
  && jpsip4.DeltaR(kp4) < 1.0
  && ((*trackChi2)[pi_orig_Index]/(*trackNDF)[pi_orig_Index]) < 7.0 // <5.0
  && ((*trackChi2)[ka_orig_Index]/(*trackNDF)[ka_orig_Index]) < 7.0 // <5.0
  && (*trackShits)[pi_orig_Index] >= 10 // >=10 >=7
  && (*trackShits)[ka_orig_Index] >= 10 // >=10 >=7
  && (*trackPhits)[pi_orig_Index] > 0
  && (*trackPhits)[ka_orig_Index] > 0
//  && (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 7.0
  && pip4.Eta() < 2.4 && kp4.Eta() < 2.4  

  ) // cuts tight
   {
//       hPiPiMassB0_noVertexCut->Fill((kp4_exchanged+pip4).Mag());
//       if ( (*B0Vtx_CL)[myB0Idx] > 0.03 ) { // b0 vertex condition
     hjpsiKPiMassSelAlt->Fill( B0MassAlt );
     hjpsiKPiMassSelAltZoom->Fill( B0MassAlt );

       
       hJpsiPiPi_PiPi->Fill( JpsiPiPiMass,(kp4_exchanged+pip4).Mag() );
       hJpsiKPi_PiPi->Fill( B0MassAlt,(kp4_exchanged+pip4).Mag() );
       
       hJpsiKK_PiPi->Fill( BsMassAlt,(kp4_exchanged+pip4).Mag() );
       hJpsiKK_KK->Fill( BsMassAlt,(pip4_exchanged+kp4).Mag() );
       hJpsiPiPi_KK->Fill( JpsiPiPiMass,(pip4_exchanged+kp4).Mag() );
       hJpsiKPi_KK->Fill( B0MassAlt,(pip4_exchanged+kp4).Mag() );
       
       hPiPi_KK->Fill((pip4_exchanged+kp4).Mag(),(kp4_exchanged+pip4).Mag());
       hPiPi_KPi->Fill((pip4+kp4).Mag(),(kp4_exchanged+pip4).Mag());
       hPiPi_KPi_swapped->Fill((kp4_exchanged+pip4_exchanged).Mag(),(kp4_exchanged+pip4).Mag());
       hKK_KPi->Fill((pip4+kp4).Mag(),(pip4_exchanged+kp4).Mag());
       hKK_KPi_swapped->Fill((kp4_exchanged+pip4_exchanged).Mag(),(pip4_exchanged+kp4).Mag());

//	if (B0MassAlt < 5.32 && B0MassAlt > 5.24 ) { // B0 mass window 
	hKPiMassB0->Fill( (pip4+kp4).Mag() );
	hKKMassB0->Fill( (pip4_exchanged+kp4).Mag() );
    hPiPiMassB0->Fill( (kp4_exchanged+pip4).Mag() );
	hJpsiKKMass->Fill(BsMassAlt);
    
    hJpsiKPi_JpsiKK->Fill(B0MassAlt,BsMassAlt);
       
       
    hJpsiPiPiMass->Fill(JpsiPiPiMass);
       if(JpsiPiPiMass>3.675 && JpsiPiPiMass<3.695) { // psi2s mass window
           hPiPiMassPsi2S->Fill( (kp4_exchanged+pip4).Mag() );
       } // psi2s mass window
		if ( (pip4_exchanged+kp4).Mag()> 1.01 &&  (pip4_exchanged+kp4).Mag()< 1.03  ) { // phi mass window
		hJpsiPhiToKKMass->Fill(BsMassAlt);
		} // phi mass window
       if ( (pip4_exchanged+kp4).Mag()> 1.51 &&  (pip4_exchanged+kp4).Mag()< 1.535  ) { // f1525 mass window
           hJpsif1525ToKKMass->Fill(BsMassAlt);
       } // f1525 mass window
       
//	} // B0 mass window

//	if ( ((pip4_exchanged+kp4).Mag()<1.01 || (pip4_exchanged+kp4).Mag()>1.03) && (BsMassAlt<5.34 || BsMassAlt>5.40)  ) { // no Bs to JpsiPhi, PhiToKK
       if (  (BsMassAlt<5.332 || BsMassAlt>5.40)  ) { // no Bs
       hjpsiKPiMassNoPhi->Fill(B0MassAlt);
       hKPiMass_noBs->Fill((pip4+kp4).Mag());
           
           
           if(B0_Pt > 18.0) { // B0 pt hard cut
               hjpsiKPiMassSelAltZoomB0pt18->Fill( B0MassAlt );
           } // B0 pt hard cut
           
           
           if(pion_fromB0_Pt > 4.3 && kaon_fromB0_Pt > 4.3) { // track pt hard cut
               hjpsiKPiMassSelAltZoomTrackpt4p3->Fill( B0MassAlt );
               h_theta_Jpsi_Trackpt4p3->Fill(theta_Jpsi);
               h_theta_Kstar_Trackpt4p3->Fill(theta_Kstar);
               h_phi_planes_Trackpt4p3->Fill(phi);               
            } // track pt hard cut
           
           if(   B0_Pt > 18.0  && pion_fromB0_Pt > 4.3 && kaon_fromB0_Pt > 4.3 ) { // All hard cuts
               hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3->Fill( B0MassAlt );
           } // all hard cuts
           
           
           
           if(pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5) { // track pt hard cut
               hjpsiKPiMassSelAltZoomTrackpt2p5->Fill( B0MassAlt );
           } // track pt hard cut
           
           if(   B0_Pt > 18.0  && pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5 ) { // All hard cuts
               hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5->Fill( B0MassAlt );
           } // all hard cuts

           
           
       numB0++; // no of B0 per event surviving the cuts
           
//           if ( B0MassAlt>5.22 && B0MassAlt<5.34 ) { // Dalitz peak
           if ( B0MassAlt>5.259 && B0MassAlt<5.299 ) { // Dalitz peak
           hDalitz_peak_bin1->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               hDalitz_peak_bin2->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               hDalitz_peak_bin3->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               hDalitz_peak_bin4->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               
               hDalitzProj_m2KPi_peak->Fill(KPiMass*KPiMass);
               hDalitzProj_m2JpsiPi_peak->Fill(JpsiPiMass*JpsiPiMass);
               
               h_theta_Jpsi_sel->Fill(theta_Jpsi);
               h_cos_theta_Jpsi_sel->Fill(TMath::Cos(theta_Jpsi));
               
               h_theta_Kstar_sel->Fill(theta_Kstar);
               h_cos_theta_Kstar_sel->Fill(TMath::Cos(theta_Kstar));
               
               h_phi_planes_sel->Fill(phi);

               
//            TLorentzVector Zcandp4;
	    Zcandp4 = jpsip4 + pip4;
	    hjpsiPiMass->Fill(Zcandp4.M());
        hjpsiPiMass2->Fill(Zcandp4.M()*Zcandp4.M());
        if( (pip4+kp4).Mag()<0.84 || ((pip4+kp4).Mag()>0.96 && (pip4+kp4).Mag()<1.4) || (pip4+kp4).Mag()>1.45 ) { //no kstar
            hjpsiPiMass_noKstar->Fill(Zcandp4.M());
            hjpsiPiMass2_noKstar->Fill(Zcandp4.M()*Zcandp4.M());
        } // no kstar
        
              m2kpi = (pip4+kp4).Mag()*(pip4+kp4).Mag();
              if (m2kpi < 1.2) { //case1
              hjpsiPiMass2_case1->Fill(Zcandp4.M()*Zcandp4.M());
              } // case1
              if (m2kpi > 1.2 && m2kpi < 2.05 ) { //case2
              hjpsiPiMass2_case2->Fill(Zcandp4.M()*Zcandp4.M());
              } // case2
              if (m2kpi > 2.05 && m2kpi < 3.2 ) { //case3
              hjpsiPiMass2_case3->Fill(Zcandp4.M()*Zcandp4.M());
              } // case3
              if (m2kpi > 1.2) { //case4
              hjpsiPiMass2_case4->Fill(Zcandp4.M()*Zcandp4.M());
              } // case4

               
           } // Dalitz peak
//           if ( (B0MassAlt>5.16 && B0MassAlt<5.22) || (B0MassAlt>5.34 && B0MassAlt<5.40) ) { // Dalitz sideband
//           if ( (B0MassAlt>5.10 && B0MassAlt<5.18) || (B0MassAlt>5.38 && B0MassAlt<5.46) ) { // Dalitz sideband
           if ( (B0MassAlt>5.209 && B0MassAlt<5.229) || (B0MassAlt>5.329 && B0MassAlt<5.349) ) { // Dalitz sideband
               hDalitz_sideband_bin1->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               hDalitz_sideband_bin2->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               hDalitz_sideband_bin3->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               hDalitz_sideband_bin4->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
               
               hDalitzProj_m2KPi_sideband->Fill(KPiMass*KPiMass);
               hDalitzProj_m2JpsiPi_sideband->Fill(JpsiPiMass*JpsiPiMass);
               
               hjpsiPiMass2_sb->Fill(Zcandp4.M()*Zcandp4.M());
               
           } // Dalitz sideband
	} // no Bs
       

       if ( ((pip4_exchanged+kp4).Mag()> 1.01 &&  (pip4_exchanged+kp4).Mag()< 1.03) && (BsMassAlt<5.332 || BsMassAlt>5.40) ) { // Bs tail
           hjpsiKPiMassBsTail->Fill(B0MassAlt);
       } // Bs tail
       
       if (  ((pip4_exchanged+kp4).Mag()> 1.01 &&  (pip4_exchanged+kp4).Mag()< 1.03) && (BsMassAlt>5.332 && BsMassAlt<5.40) ) { // Bs signal
           hjpsiKPiMassBs->Fill(B0MassAlt);
       } // Bs signal

       
       if(  (pip4+kp4).Mag()<0.84 || ((pip4+kp4).Mag()>0.96 && (pip4+kp4).Mag()<1.4) || (pip4+kp4).Mag()>1.45 ) { // B0 mass no kstar
           hjpsiKPiMass_noKstar->Fill(B0MassAlt);
       } // B0 mass no kstar
       

	if (B0MassAlt > 5.079  &&  B0MassAlt < 5.254) { // control region
        hKKMass_control->Fill( (pip4_exchanged+kp4).Mag() );
        hJpsiKKMass_control->Fill( BsMassAlt );
        
    }// control region
       
/*
	if (B0MassAlt > 5.25  &&  B0MassAlt < 5.3) { // B0 cond
//            TLorentzVector Zcandp4;
	    Zcandp4 = jpsip4 + pip4;
	    hjpsiPiMass->Fill(Zcandp4.M());
        hjpsiPiMass2->Fill(Zcandp4.M()*Zcandp4.M());
        if( (pip4+kp4).Mag()<0.84 || ((pip4+kp4).Mag()>0.96 && (pip4+kp4).Mag()<1.4) || (pip4+kp4).Mag()>1.45 ) { //no kstar
            hjpsiPiMass_noKstar->Fill(Zcandp4.M());
            hjpsiPiMass2_noKstar->Fill(Zcandp4.M()*Zcandp4.M());
        } // no kstar
        
              if (m2kpi < 1.2) { //case1
              hjpsiPiMass2_case1->Fill(Zcandp4.M()*Zcandp4.M());
              } // case1
              if (m2kpi > 1.2 && m2kpi < 2.05 ) { //case2
              hjpsiPiMass2_case2->Fill(Zcandp4.M()*Zcandp4.M());
              } // case2
              if (m2kpi > 2.05 && m2kpi < 3.2 ) { //case3
              hjpsiPiMass2_case3->Fill(Zcandp4.M()*Zcandp4.M());
              } // case3
              if (m2kpi > 1.2) { //case4
              hjpsiPiMass2_case4->Fill(Zcandp4.M()*Zcandp4.M());
              } // case4



	} // B0 cond
 */
           
           
//       } // b0 vertex condition


} //check




    } // b0 loop

h_nB0_sel->Fill(numB0);
      
      if (numB0 == 1) { // only 1 B0 after cuts
          
          hjpsiKPiMassSelAltZoom_nB01->Fill(B0MassAlt);
          
             if(B0_Pt > 18.0) { // B0 pt hard cut
                 hjpsiKPiMassSelAltZoomB0pt18_nB0eq1->Fill( B0MassAlt );
             } // B0 pt hard cut
             
             
             if(pion_fromB0_Pt > 4.3 && kaon_fromB0_Pt > 4.3) { // track pt hard cut
                 hjpsiKPiMassSelAltZoomTrackpt4p3_nB0eq1->Fill( B0MassAlt );
             } // track pt hard cut
             
             if(   B0_Pt > 18.0  && pion_fromB0_Pt > 4.3 && kaon_fromB0_Pt > 4.3 ) { // All hard cuts
                 hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3_nB0eq1->Fill( B0MassAlt );
             } // all hard cuts
          
          
          if(pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5) { // track pt hard cut
              hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1->Fill( B0MassAlt );
          } // track pt hard cut
          
          if(   B0_Pt > 18.0  && pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5 ) { // All hard cuts
              hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1->Fill( B0MassAlt );
              
              if (B0MassAlt > 5.25  &&  B0MassAlt < 5.3) { // B0 cond
              TLorentzVector Zcandp4_nB01;
              Zcandp4_nB01 = jpsip4 + pip4;
              m2kpi = (pip4+kp4).Mag()*(pip4+kp4).Mag();
              hjpsiPiMass_nB01->Fill(Zcandp4_nB01.M());
              hjpsiPiMass2_nB01->Fill(Zcandp4_nB01.M()*Zcandp4_nB01.M());
              if( (pip4+kp4).Mag()<0.84 || ((pip4+kp4).Mag()>0.96 && (pip4+kp4).Mag()<1.4) || (pip4+kp4).Mag()>1.45 ) { //no kstar
                  hjpsiKPiMass_noKstar_nB01->Fill(B0MassAlt);
                  hjpsiPiMass_noKstar_nB01->Fill(Zcandp4_nB01.M());
                  hjpsiPiMass2_noKstar_nB01->Fill(Zcandp4_nB01.M()*Zcandp4_nB01.M());
              } // no kstar

              if (m2kpi < 1.2) { //case1
              hjpsiPiMass2_nB01_case1->Fill(Zcandp4_nB01.M()*Zcandp4_nB01.M());
              } // case1
              if (m2kpi > 1.2 && m2kpi < 2.05 ) { //case2
              hjpsiPiMass2_nB01_case2->Fill(Zcandp4_nB01.M()*Zcandp4_nB01.M());
              } // case2
              if (m2kpi > 2.05 && m2kpi < 3.2 ) { //case3
              hjpsiPiMass2_nB01_case3->Fill(Zcandp4_nB01.M()*Zcandp4_nB01.M());
              } // case3
              if (m2kpi > 1.2) { //case4
              hjpsiPiMass2_nB01_case4->Fill(Zcandp4_nB01.M()*Zcandp4_nB01.M());
              } // case4

              
          } // B0 cond
  
              
          } // all hard cuts
          
          
          if ( B0MassAlt>5.22 && B0MassAlt<5.34 ) { // Dalitz peak
              hDalitz_peak_nB01_bin1->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              hDalitz_peak_nB01_bin2->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              hDalitz_peak_nB01_bin3->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              hDalitz_peak_nB01_bin4->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              
              hDalitzProj_m2KPi_nB01_peak->Fill(KPiMass*KPiMass);
              hDalitzProj_m2JpsiPi_nB01_peak->Fill(JpsiPiMass*JpsiPiMass);
              
              h_theta_Jpsi_sel_nB01->Fill(theta_Jpsi);
              h_cos_theta_Jpsi_sel_nB01->Fill(TMath::Cos(theta_Jpsi));
              
              h_theta_Kstar_sel_nB01->Fill(theta_Kstar);
              h_cos_theta_Kstar_sel_nB01->Fill(TMath::Cos(theta_Kstar));
              
              h_phi_planes_sel_nB01->Fill(phi);
              

/*
              var[0] = B0MassAlt;
              var[1] = KPiMass;
              var[2] = jpsip4.M();//(*MuMuMass)[jpsi_index];
              var[3] = JpsiPiMass;
              var[4] = B0p4.P();
              var[5] = (pip4+kp4).P();
              var[6] = jpsip4.P();
              var[7] = kp4.P();
              var[8] = pip4.P();
              var[9] = theta_Kstar ; //theta_Kstar;
              var[10] = theta_Jpsi; //theta_Jpsi;
              var[11] = phi; //phi;
              var[12] = evtNum;
              var[13] = runNum;
              var[14] = lumiNum;
              
              _nt->Fill(var);
              
*/
              
          } // Dalitz peak
          if ( (B0MassAlt>5.16 && B0MassAlt<5.22) || (B0MassAlt>5.34 && B0MassAlt<5.40) ) { // Dalitz sideband
              hDalitz_sideband_nB01_bin1->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              hDalitz_sideband_nB01_bin2->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              hDalitz_sideband_nB01_bin3->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              hDalitz_sideband_nB01_bin4->Fill(KPiMass*KPiMass,JpsiPiMass*JpsiPiMass);
              
              hDalitzProj_m2KPi_nB01_sideband->Fill(KPiMass*KPiMass);
              hDalitzProj_m2JpsiPi_nB01_sideband->Fill(JpsiPiMass*JpsiPiMass);
              
          } // Dalitz sideband

/*
          if (B0MassAlt > 5.25  &&  B0MassAlt < 5.3) { // B0 cond
              TLorentzVector Zcandp4_nB01;
              Zcandp4_nB01 = jpsip4 + pip4;
              hjpsiPiMass_nB01->Fill(Zcandp4.M());
              hjpsiPiMass2_nB01->Fill(Zcandp4.M()*Zcandp4.M());
              if( (pip4+kp4).Mag()<0.84 || ((pip4+kp4).Mag()>0.96 && (pip4+kp4).Mag()<1.4) || (pip4+kp4).Mag()>1.45 ) { //no kstar
                  hjpsiKPiMass_noKstar_nB01->Fill(B0MassAlt);
                  hjpsiPiMass_noKstar_nB01->Fill(Zcandp4.M());
                  hjpsiPiMass2_noKstar_nB01->Fill(Zcandp4.M()*Zcandp4.M());
              } // no kstar
          } // B0 cond
*/
 
      } // only 1 B0 after cuts
      

} //b0 requirement

//    h_nB0_sel->Fill(numB0);

   return kTRUE;
}

void SignalExtract_Jpsi_small_ntpls::SlaveTerminate()
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

//        _nt->Write();

      h_nB0->Write();
      h_nB0_sel->Write();
        
      h_theta_Jpsi->Write();
      h_cos_theta_Jpsi->Write();
      h_theta_Jpsi_sel->Write();
      h_cos_theta_Jpsi_sel->Write();
        
      h_theta_Kstar->Write();
      h_cos_theta_Kstar->Write();
      h_theta_Kstar_sel->Write();
      h_cos_theta_Kstar_sel->Write();
        
      h_phi_planes->Write();
      h_phi_planes_sel->Write();
        
        h_theta_Jpsi_Trackpt4p3->Write();
        h_theta_Kstar_Trackpt4p3->Write();
        h_phi_planes_Trackpt4p3->Write();
        
// nB0 = 1 variables
        h_theta_Jpsi_sel_nB01->Write();
        h_cos_theta_Jpsi_sel_nB01->Write();
        h_theta_Kstar_sel_nB01->Write();
        h_cos_theta_Kstar_sel_nB01->Write();
        h_phi_planes_sel_nB01->Write();
        
        hjpsiKPiMassSelAltZoom_nB01->Write();
        hjpsiKPiMass_noKstar_nB01->Write();
        
        hjpsiKPiMassSelAltZoomB0pt18_nB0eq1->Write();
        hjpsiKPiMassSelAltZoomTrackpt4p3_nB0eq1->Write();
        hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3_nB0eq1->Write();
        
        hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1->Write();
        hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1->Write();
        
        hjpsiPiMass_nB01->Write();
        hjpsiPiMass_noKstar_nB01->Write();
        hjpsiPiMass2_nB01->Write();
        hjpsiPiMass2_noKstar_nB01->Write();
        hjpsiPiMass2_nB01_case1->Write();
        hjpsiPiMass2_nB01_case2->Write();
        hjpsiPiMass2_nB01_case3->Write();
        hjpsiPiMass2_nB01_case4->Write();
        
        hDalitz_peak_nB01_bin1->Write();
        hDalitz_sideband_nB01_bin1->Write();
        hDalitz_peak_nB01_bin2->Write();
        hDalitz_sideband_nB01_bin2->Write();
        hDalitz_peak_nB01_bin3->Write();
        hDalitz_sideband_nB01_bin3->Write();
        hDalitz_peak_nB01_bin4->Write();
        hDalitz_sideband_nB01_bin4->Write();
        
        hDalitzProj_m2KPi_nB01_peak->Write();
        hDalitzProj_m2JpsiPi_nB01_peak->Write();
        hDalitzProj_m2KPi_nB01_sideband->Write();
        hDalitzProj_m2JpsiPi_nB01_sideband->Write();
// nB0 = 1 variables
        
      hMuMuMass->Write();

      hKPiMassB0->Write();
      hKPiMass_noBs->Write();
      hKKMassB0->Write();
      hKKMass_control->Write();
      hPiPiMassB0->Write();
      hPiPiMassB0_noVertexCut->Write();
      hPiPiMassPsi2S->Write();
      hJpsiKKMass->Write();
      hJpsiKKMass_control->Write();
      hJpsiPiPiMass->Write();
      hJpsiPhiToKKMass->Write();
      hJpsif1525ToKKMass->Write();
        
      hJpsiKPi_JpsiKK->Write();

      hjpsiKPiMassSelAlt->Write() ;
      hjpsiKPiMassSelAltZoom->Write() ;

      hjpsiKPiMassNoPhi->Write();
      hjpsiKPiMassBs->Write();
      hjpsiKPiMassBsTail->Write();
      
      hjpsiKPiMass_noKstar->Write();
        
      hJpsiPiPi_PiPi->Write();
      hJpsiKPi_PiPi->Write();
      hJpsiKK_PiPi->Write();
      hJpsiKK_KK->Write();
      hJpsiPiPi_KK->Write();
      hJpsiKPi_KK->Write();
        
        
      
      hjpsiPiMass->Write();
      hjpsiPiMass_noKstar->Write();
      
        hjpsiPiMass2_case1->Write();
        hjpsiPiMass2_case2->Write();
        hjpsiPiMass2_case3->Write();
        hjpsiPiMass2_case4->Write();
        hjpsiPiMass2_sb->Write();
        
      hPiPi_KK->Write();
      hPiPi_KPi->Write();
      hPiPi_KPi_swapped->Write();
      hKK_KPi->Write();
      hKK_KPi_swapped->Write();
        
        hDalitz_peak_bin1->Write();
        hDalitz_sideband_bin1->Write();
        hDalitz_peak_bin2->Write();
        hDalitz_sideband_bin2->Write();
        hDalitz_peak_bin3->Write();
        hDalitz_sideband_bin3->Write();
        hDalitz_peak_bin4->Write();

        hDalitz_sideband_bin4->Write();
        
        hDalitzProj_m2KPi_peak->Write();
        hDalitzProj_m2JpsiPi_peak->Write();

        hDalitzProj_m2KPi_sideband->Write();
        hDalitzProj_m2JpsiPi_sideband->Write();

        hjpsiKPiMassSelAltZoomB0pt18->Write();
        hjpsiKPiMassSelAltZoomTrackpt4p3->Write();
        hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3->Write();
        
        
        hjpsiKPiMassSelAltZoomTrackpt2p5->Write();
        hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5->Write();
        


      hjpsiKPiMassBaseSelAlt->Write();

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


        
      OutFile->Print();
      fOutput->Add(OutFile); 
      hMuMuMass->SetDirectory(0); // any hname
//      hjpsiKPiMassSelAlt->SetDirectory(0) ;
      gDirectory = savedir;
      fOut->Close();
    }



}

void SignalExtract_Jpsi_small_ntpls::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}


// functions calculating angles

double SignalExtract_Jpsi_small_ntpls::getPlanesAngle(TLorentzVector B0, TLorentzVector K, TLorentzVector Pi, TLorentzVector muM, TLorentzVector muP) {
    
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


double SignalExtract_Jpsi_small_ntpls::GetPhi(TLorentzVector LoreVecB0,TLorentzVector LoreVecMum, TLorentzVector LoreVecMup, TLorentzVector LoreVecK, TLorentzVector LoreVecPi)	{
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



float SignalExtract_Jpsi_small_ntpls::GetThetaMuMu(TLorentzVector BVec, TLorentzVector JPsiVec, TLorentzVector MuPlusVec, float BeamEnergy, float JPsiPDG , float muonPDG) {
    
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

void SignalExtract_Jpsi_small_ntpls::GetMomentumInMotherFrame( TLorentzVector Mother,TLorentzVector Particle, double BeamEnergy , TVector3 &Particle_rotated){
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




