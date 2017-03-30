#define SignalExtract_Jpsi_new_cxx
// The class definition in SignalExtract_Jpsi_new.h has been generated automatically
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
// Root > T->Process("SignalExtract_Jpsi_new.C")
// Root > T->Process("SignalExtract_Jpsi_new.C","some options")
// Root > T->Process("SignalExtract_Jpsi_new.C+")
//

#include "SignalExtract_Jpsi_new.h"
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
//#include <TH2.h>
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


void SignalExtract_Jpsi_new::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void SignalExtract_Jpsi_new::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0002_MuChi2_by_NDF.root" );
//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0002_MuS_hits.root" );
//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0002_MuP_hits.root" );
//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0002_MuDz.root" );
//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0000_MuDxy.root" );
//   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0000_B0CosAlphaPV.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0000_B0Vtx_CL.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0000_B0CTauPV.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0000_MuMuVtx_CL.root" );
//     OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0000_B0Pt.root" );
       OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_output_new_0000_trackPt.root" );
    
    fOut = OutFile->OpenFile("RECREATE");

   if ( !(fOut = OutFile->OpenFile("RECREATE")) )
    {
      Warning("SlaveBegin", "problems opening file: %s/%s",
              OutFile->GetDir(), OutFile->GetFileName());
    }
  //////// HISTOGRAMS
  // put them here:
  //


   hjpsiKPiMassSelAlt = new TH1F("hjpsiKPiMassSelAlt","hmjpsiKPiMassSel ALTERNATIVE", 100, 4.8, 5.8);
//   hjpsiKPiMassSelAltZoom = new TH1F("hjpsiKPiMassSelAltZoom","hjpsiKPiMassSel ALTERNATIVE ZOOM", 90, 5.15, 5.45);

   hjpsiKPiMassBaseSelAlt = new TH1F("hjpsiKPiMassBaseSelAlt"," MuMuKPiMass after basic selection",10000, 0, 100);

   hChi2byNDF = new TH1F("hChi2byNDF","hChi2byNDF",100,0,10);
   hmuShits = new TH1F("hmuShits","hmuShits",50,0,50);
   hmuPhits = new TH1F("hmuPhits","hmuPhits",15,0,15);
   hmuDz = new TH1F("hmuDz","hmuDz",3000,0,30);
   hmuDxy = new TH1F("hmuDxy","hmuDxy",1000,0,10);

   char histname[100];
   char histname2[100];

  for (int j=0;j<20;j++) { // histogram loop

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuChi2_by_NDF%i",j+1);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuChi2_by_NDF%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j+1);
//        hjpsiKPiMassSelAltZoom_MuChi2_by_NDF[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuS_hits%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuS_hits%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_MuS_hits[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuP_hits%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuP_hits%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_MuP_hits[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);

//        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuDz%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_MuDz%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
//        hjpsiKPiMassSelAltZoom_MuDz[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);


//        sprintf(histname,"hjpsiKPiMassSelAltZoom_B0CosAlphaPV0.99%i",j);
//        sprintf(histname2,"hjpsiKPiMassSelAltZoom_B0CosAlphaPV0.99%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j);
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
      
      sprintf(histname,"hjpsiKPiMassSelAltZoom_trackPt%i",j+4);
      sprintf(histname2,"hjpsiKPiMassSelAltZoom_trackPt%i;m(J/#Psi K^{+}#pi^{-}) [GeV]",j+4);
      hjpsiKPiMassSelAltZoom_trackPt[j] = new TH1F(histname,histname2, 90, 5.15, 5.45);
      

  } //  histogram loop


}

Bool_t SignalExtract_Jpsi_new::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SignalExtract_Jpsi_new::GetEntry() or TBranch::GetEntry()
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


//  for (Int_t myMuMuIdx = 0; myMuMuIdx < abs(nMuMu); myMuMuIdx++) {
//    hMuMuMass->Fill((*MuMuMass)[myMuMuIdx]) ;
//	}


  int muonQual[] = {1,3,4,12};

  if ( nB0>0 ) { //b0 requirement

  for (Int_t myB0Idx = 0; myB0Idx < abs(nB0); myB0Idx++)

    {  // b0 loop
  Int_t pi_orig_Index = (*B0PionIdx)[myB0Idx] ;
  Int_t ka_orig_Index = (*B0KaonIdx)[myB0Idx] ;
  Int_t jpsi_index = (*B0MuMuIdx)[myB0Idx];
  Int_t mu1_fromB0_index = (*mu1Idx)[jpsi_index];
  Int_t mu2_fromB0_index = (*mu2Idx)[jpsi_index];

  TLorentzVector mu1_p4, mu2_p4;

  Float_t mu1E = 0., mu2E = 0.;
  mu1E = sqrt( pow((*muPx)[mu1_fromB0_index],2) + pow((*muPy)[mu1_fromB0_index],2) + pow((*muPz)[mu1_fromB0_index],2) + pow(muon_mass,2) );
  mu2E = sqrt( pow((*muPx)[mu2_fromB0_index],2) + pow((*muPy)[mu2_fromB0_index],2) + pow((*muPz)[mu2_fromB0_index],2) + pow(muon_mass,2) );
  mu1_p4.SetPxPyPzE( (*muPx)[mu1_fromB0_index], (*muPy)[mu1_fromB0_index], (*muPz)[mu1_fromB0_index], mu1E);
  mu2_p4.SetPxPyPzE( (*muPx)[mu2_fromB0_index], (*muPy)[mu2_fromB0_index], (*muPz)[mu2_fromB0_index], mu2E);


  TLorentzVector jpsip4;
  Float_t jpsi_E = 0.;
  jpsi_E = sqrt( pow((*MuMuPx)[jpsi_index],2) + pow((*MuMuPy)[jpsi_index], 2) + pow((*MuMuPz)[jpsi_index], 2) + pow((*MuMuMass)[jpsi_index], 2) ) ;
  jpsip4.SetPxPyPzE( (*MuMuPx)[jpsi_index], (*MuMuPy)[jpsi_index], (*MuMuPz)[jpsi_index], jpsi_E) ;




  TLorentzVector pip4, pip4_exchanged;
  pip4.SetPxPyPzE( (*PionPx_MuMuPiK)[myB0Idx], (*PionPy_MuMuPiK)[myB0Idx], (*PionPz_MuMuPiK)[myB0Idx], (*PionE_MuMuPiK)[myB0Idx]) ; 



  TLorentzVector kp4, kp4_exchanged;
  kp4.SetPxPyPzE( (*KaonPx_MuMuPiK)[myB0Idx], (*KaonPy_MuMuPiK)[myB0Idx], (*KaonPz_MuMuPiK)[myB0Idx], (*KaonE_MuMuPiK)[myB0Idx]) ;

     
  TLorentzVector Pip4_orig, Kp4_orig;
  Pip4_orig.SetPxPyPzE( (*trackPx)[pi_orig_Index], (*trackPy)[pi_orig_Index], (*trackPz)[pi_orig_Index], (*trackEnergy)[pi_orig_Index]) ; // original

  Float_t K_E = 0.;
  K_E = sqrt( pow((*trackPx)[ka_orig_Index], 2) + pow((*trackPy)[ka_orig_Index], 2) + pow((*trackPz)[ka_orig_Index], 2) + pow(kaonCh_mass, 2) ) ; // original
  Kp4_orig.SetPxPyPzE( (*trackPx)[ka_orig_Index], (*trackPy)[ka_orig_Index], (*trackPz)[ka_orig_Index], K_E) ; // original

  TLorentzVector B0p4, B0p4_KPiExchanged;
  B0p4 = jpsip4+pip4+kp4;



  Float_t B0MassAlt = (jpsip4+pip4+kp4).Mag() - jpsip4.M() + jpsi_mass;
        
        double B0_Pt = B0p4.Pt();
        double pion_fromB0_Pt = pip4.Pt();
        double kaon_fromB0_Pt = kp4.Pt();



//    hjpsiKPiMassBaseSelAlt->Fill( B0MassAlt );

  pip4_exchanged.SetVectM(pip4.Vect(), kaonCh_mass) ;
  kp4_exchanged.SetVectM(kp4.Vect(), pionCh_mass) ;
  B0p4_KPiExchanged = jpsip4 + pip4_exchanged + kp4_exchanged;


//  hjpsifromBMass->Fill((*MuMuMass)[(*B0MuMuIdx)[myB0Idx]]);
  int jpsiId = (*B0MuMuIdx)[myB0Idx];


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


  //
  // NEW SOFT MUON 2013
  //

for (double k=0;k<20;k++){ // cut opt loop
double cut=0.4+k*0.1;
    
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
//    if( (*MuMuVtx_CL)[jpsi_index] > cut ) { // cut imp cond
//    if(  B0_Pt > cut ) { // cut imp cond
    if( pion_fromB0_Pt > cut && kaon_fromB0_Pt > cut ) { // cut imp cond
        

  if ( 1 && 
  ((*muQual)[mu1_fromB0_index] & (1 << muonQual[3])) && ((*muQual)[mu2_fromB0_index] & (1 << muonQual[3])) && //TMOneSTationTight
  ((*muChi2)[mu1_fromB0_index]/(*muNDF)[mu1_fromB0_index])<3. && ((*muChi2)[mu2_fromB0_index]/(*muNDF)[mu2_fromB0_index])<3. && // cut opt val ~3
  (*muShits)[mu1_fromB0_index]>5 && (*muShits)[mu2_fromB0_index]>5 && // dont see much variation
  (*muPhits)[mu1_fromB0_index]>0 && (*muPhits)[mu2_fromB0_index]>0 &&                      // new soft muons 2013 (was 1 in old soft muons) keep
  fabs((*muDzVtx)[mu1_fromB0_index])<20. && fabs((*muDzVtx)[mu2_fromB0_index])<20. &&        // new soft muons 2013 (was 30 in old soft muons) keep
  fabs((*muDxyVtx)[mu1_fromB0_index])<0.2 && fabs((*muDxyVtx)[mu2_fromB0_index])<0.2         // new soft muons 2013 (was 3 in old soft muons) was 0.3 for psiprime
   )
  {

   newsoftID = true;
  }

  Bool_t Mu1_PtSel = false;
  Bool_t Mu2_PtSel = false;


  if ( ( ( (fabs(mu1_p4.Eta()) < 1.2 ) && (mu1_p4.Pt()>4.)) ) || ( ( mu1_p4.Eta() >= 1.2 || mu1_p4.Eta() <=- 1.2) && (mu1_p4.Pt()>3.3) ) ) Mu1_PtSel = true;
  if ( ( ( (fabs(mu2_p4.Eta()) < 1.2 ) && (mu2_p4.Pt()>4.)) ) || ( ( mu2_p4.Eta() >= 1.2 || mu2_p4.Eta() <=- 1.2) && (mu2_p4.Pt()>3.3) ) ) Mu2_PtSel = true;

  if ( 1 && newsoftID  // cuts loose
  && ( (*B0Vtx_CL)[myB0Idx] > 0.01 ) //0.05
  && ( (*B0CosAlphaPV)[myB0Idx] > 0.99 ) //0.998
  && ( (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 3.0 ) //7.0
  && ( fabs( (*MuMuMass)[jpsi_index] - jpsi_mass ) < 0.2 ) // 0.12 was 0.2 for baseline cuts
  && ( (*MuMuVtx_CL)[jpsi_index] > 0.009 ) //0.02
//  && ( pion_fromB0_Pt > 0.45 ) // 0.45
//  && ( kaon_fromB0_Pt > 0.45 ) // 0.45
  && ( B0_Pt > 7.)
//  && ( jpsi_fromB0_Pt > 5.)
  && ( mu1_p4.Pt()>3.3 && mu2_p4.Pt() > 3.3)
  && Mu1_PtSel && Mu2_PtSel
  ) // cuts loose
  {
    hjpsiKPiMassBaseSelAlt->Fill( B0MassAlt );
//    hExclMuMuKPiMassSel->Fill( (*B0Mass)[myB0Idx] ) ;
//    hjpsiKPiMass_bothCombSel->Fill(myB0p4.M());
//    hjpsiKPiMass_bothCombSel->Fill(myB0p4_KPiExchanged.M());
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
  ) // cuts tight
   {
    hjpsiKPiMassSelAlt->Fill( B0MassAlt );
//     hjpsiKPiMassSelAltZoom->Fill( B0MassAlt );

//if (((*muChi2)[mu1_fromB0_index]/(*muNDF)[mu1_fromB0_index])<cut && ((*muChi2)[mu2_fromB0_index]/(*muNDF)[mu2_fromB0_index])<cut) { // cut imp cond 
int l=k;
//hjpsiKPiMassSelAltZoom_MuS_hits[l]-> Fill( B0MassAlt );
//hjpsiKPiMassSelAltZoom_MuP_hits[l]-> Fill( B0MassAlt );
//hjpsiKPiMassSelAltZoom_MuDz[l]-> Fill( B0MassAlt );
//hjpsiKPiMassSelAltZoom_MuDxy[l]-> Fill( B0MassAlt );
//hjpsiKPiMassSelAltZoom_B0CosAlphaPV[l]-> Fill( B0MassAlt );
//  hjpsiKPiMassSelAltZoom_B0Vtx_CL[l]-> Fill( B0MassAlt );
//  hjpsiKPiMassSelAltZoom_B0CTauPV[l]-> Fill( B0MassAlt );
//  hjpsiKPiMassSelAltZoom_MuMuVtx_CL[l]-> Fill( B0MassAlt );
  hjpsiKPiMassSelAltZoom_trackPt[l]-> Fill( B0MassAlt );
       
//} // cut imp cond 

/*
	if (B0MassAlt > 5.25  &&  B0MassAlt < 5.3) { // B0 cond
	  hjpsiMass_fromB0->Fill(jpsip4.M());
	  if (fabs(jpsip4.M()-jpsi_mass)< 0.05){ // jpsi cond
            TLorentzVector Zcandp4;
	    Zcandp4 = jpsip4 + pip4;
	    hjpsiPiMass->Fill(Zcandp4.M());

	  } // jpsi cond

	} // B0 cond
*/

}

} // cut imp cond
} // cut opt loop



    } // b0 loop


} //b0 requirement



   return kTRUE;
}

void SignalExtract_Jpsi_new::SlaveTerminate()
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



      hjpsiKPiMassSelAlt->Write() ;
//      hjpsiKPiMassSelAltZoom->Write() ;

  for (int j=0;j<20;j++) {
//      hjpsiKPiMassSelAltZoom_MuChi2_by_NDF[j]->Write();
//      hjpsiKPiMassSelAltZoom_MuS_hits[j]->Write();
//      hjpsiKPiMassSelAltZoom_MuP_hits[j]->Write();
//      hjpsiKPiMassSelAltZoom_MuDz[j]->Write();
//      hjpsiKPiMassSelAltZoom_MuDxy[j]->Write();
//      hjpsiKPiMassSelAltZoom_B0CosAlphaPV[j]->Write();
//      hjpsiKPiMassSelAltZoom_B0Vtx_CL[j]->Write();
//        hjpsiKPiMassSelAltZoom_B0CTauPV[j]->Write();
//        hjpsiKPiMassSelAltZoom_MuMuVtx_CL[j]->Write();
//        hjpsiKPiMassSelAltZoom_B0Pt[j]->Write();
        hjpsiKPiMassSelAltZoom_trackPt[j]->Write();
      
  }
      hjpsiKPiMassBaseSelAlt->Write();

   hChi2byNDF->Write() ;
   hmuShits->Write() ;
   hmuPhits->Write() ;
   hmuDz->Write() ;
   hmuDxy->Write() ;

/*
   hPiPtcalc	->Write();
   hPiEtacalc	->Write();
   hPiPhicalc	->Write();
   hPiMasscalc	->Write();
	
   hKPtcalc	->Write();
   hKEtacalc	->Write();
   hKPhicalc	->Write();
   hKMasscalc	->Write();
	
   hJpsiPtcalc	->Write();
   hJpsiEtacalc	->Write();
   hJpsiPhicalc	->Write();
   hJpsiMasscalc->Write();
	
   hB0Ptcalc	->Write();
   hB0Etacalc	->Write();
   hB0Phicalc	->Write();
   hB0Masscalc	->Write();

   hJpsiMassDiff->Write();





      hjpsiKPiMassBaseSelAlt2->Write();
      hjpsiKPiMassBaseSelAlt3->Write();
      hjpsiKPiMassBaseSelAlt4->Write();


*/

      OutFile->Print();
      fOutput->Add(OutFile); 
//      hMuMuMass->SetDirectory(0); // any hname
      hjpsiKPiMassSelAlt->SetDirectory(0) ;
      gDirectory = savedir;
      fOut->Close();
    }

}

void SignalExtract_Jpsi_new::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
