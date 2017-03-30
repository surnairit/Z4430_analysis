#define SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut_cxx
// The class definition in SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut.h has been generated automatically
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
// Root > T->Process("SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut.C")
// Root > T->Process("SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut.C","some options")
// Root > T->Process("SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut.C+")
//

#include "SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut.h"
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


void SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_jpsi_eta_cut.root" );
//    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls_jpsi_eta_cut.root" );
    
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
    hjpsiKPiMassSelAlt		= new TH1F("hjpsiKPiMassSelAlt","hmjpsiKPiMassSel ALTERNATIVE", 90, 5.15, 5.45); // 100, 4.8, 5.8
    
    hjpsiMass               = new TH1F("hjpsiMass","hjpsiMass",380, 2.90, 3.28);
    hjpsiMass_sel           = new TH1F("hjpsiMass_sel","hjpsiMass_sel",380, 2.90, 3.28);
    
    hjpsiEta               = new TH1F("hjpsiEta","hjpsiEta",100, -5.0, 5.0);
    hjpsiEta_sel           = new TH1F("hjpsiEta_sel","hjpsiEta_sel",100, -5.0, 5.0);
    
    hjpsiKPiMassSelAlt_etacut_1sigma		= new TH1F("hjpsiKPiMassSelAlt_etacut_1sigma","hmjpsiKPiMassSel Jpsi eta dependent mass cut 1sigma", 90, 5.15, 5.45); // 100, 4.8, 5.8
    hjpsiKPiMassSelAlt_etacut_2sigma		= new TH1F("hjpsiKPiMassSelAlt_etacut_2sigma","hmjpsiKPiMassSel Jpsi eta dependent mass cut 2sigma", 90, 5.15, 5.45);
    hjpsiKPiMassSelAlt_etacut_3sigma		= new TH1F("hjpsiKPiMassSelAlt_etacut_3sigma","hmjpsiKPiMassSel Jpsi eta dependent mass cut 3sigma", 90, 5.15, 5.45);

}

Bool_t SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut::GetEntry() or TBranch::GetEntry()
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
    double bin=0.0;
    
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
        
hjpsiMass->Fill(jpsip4.M());
hjpsiEta->Fill(jpsip4.Eta());
        
/*
        for (double k=0;k<21;k++){ // jpsi eta bin
            bin=-2.1+k*0.2;
            if (jpsip4.Eta()>=bin && jpsip4.Eta()<bin+0.2 ) { // cut imp cond
                int l=k;
                hjpsiMass_eta_bin[l]->Fill(jpsip4.M());
            } // cut imp cond
        } // jpsi eta bin
*/


        Float_t mean[] = {3.09235,3.093,3.09315,3.09342,3.0945,3.09528,3.09538,3.0946,3.09474,3.09482,3.09488,3.09478,3.09485,3.09467,3.09491,3.09495,3.09468,3.09387,3.09286,3.093,3.09237};
        Float_t sigma[] = {0.0450689,0.0384943,0.0354644,0.0341724,0.031809,0.0280197,0.0242534,0.0211894,0.0198446,0.0180985,0.0172931,0.01819,0.0198676,0.0212643,0.0239186,0.0280922,0.0316505,0.0341717,0.0356724,0.0389064,0.0445784};
        double n_sigma = 3.0;

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
        



        B0MassAlt = (jpsip4+pip4+kp4).Mag() - jpsip4.M() + jpsi_mass;
        
        double B0_Pt = B0p4.Pt();
        double pion_fromB0_Pt = pip4.Pt();
        double kaon_fromB0_Pt = kp4.Pt();
        double jpsi_fromB0_Pt = jpsip4.Pt();
	    double pion_from_B0_Eta = pip4.Eta();
        double kaon_from_B0_Eta = kp4.Eta();
        
        KPiMass = (pip4+kp4).Mag();


  B0p4_KPiExchanged = jpsip4 + pip4_exchanged + kp4_exchanged;
        
        
        
  Bool_t newsoftID = false;
  Bool_t baselineB0Sel = false;


  //
  // NEW SOFT MUON 2013
  //
    
    
        
        
  if ( 1 && 
  ((*muQual)[mu1_fromB0_index] & (1 << muonQual[3])) && ((*muQual)[mu2_fromB0_index] & (1 << muonQual[3])) && //TMOneSTationTight
  ((*muChi2)[mu1_fromB0_index]/(*muNDF)[mu1_fromB0_index])<3. && ((*muChi2)[mu2_fromB0_index]/(*muNDF)[mu2_fromB0_index])<3. && // cut opt val ~3
  (*muShits)[mu1_fromB0_index]>5 && (*muShits)[mu2_fromB0_index]>5 && // dont see much variation // cut opt = 5
  (*muPhits)[mu1_fromB0_index]>0 && (*muPhits)[mu2_fromB0_index]>0 &&                      // new soft muons 2013 (was 1 in old soft muons) keep
  fabs((*muDzVtx)[mu1_fromB0_index])<20. && fabs((*muDzVtx)[mu2_fromB0_index])<20. &&        // new soft muons 2013 (was 30 in old soft muons) keep // cut opt = 20
  fabs((*muDxyVtx)[mu1_fromB0_index])<0.3 && fabs((*muDxyVtx)[mu2_fromB0_index])<0.3         // new soft muons 2013 (was 3 in old soft muons) // cut opt = 0.3
   )
  {

   newsoftID = true;
  }


  Bool_t Mu1_PtSel = false;
  Bool_t Mu2_PtSel = false;


  if ( ( ( (fabs(mu1_p4.Eta()) < 1.2 ) && (mu1_p4.Pt()>4.)) ) || ( ( mu1_p4.Eta() >= 1.2 || mu1_p4.Eta() <=- 1.2) && (mu1_p4.Pt()>3.3) ) ) Mu1_PtSel = true;
  if ( ( ( (fabs(mu2_p4.Eta()) < 1.2 ) && (mu2_p4.Pt()>4.)) ) || ( ( mu2_p4.Eta() >= 1.2 || mu2_p4.Eta() <=- 1.2) && (mu2_p4.Pt()>3.3) ) ) Mu2_PtSel = true;


  if ( 1 && newsoftID  // cuts loose
  && ( (*B0Vtx_CL)[myB0Idx] > 0.09 )  // cut opt = 0.03
  && ( (*B0CosAlphaPV)[myB0Idx] > 0.9985 ) // cut opt = 0.998
  && ( (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 9.0 ) //cut opt = 6.0
//  && ( fabs( (*MuMuMass)[jpsi_index] - jpsi_mass ) < 0.2 ) // cut opt = 0.12 was 0.2 for baseline cuts
  && ( (*MuMuVtx_CL)[jpsi_index] > 0.02 ) //0.02
  && ( pion_fromB0_Pt > 0.45 ) // 0.45 >2.0
  && ( kaon_fromB0_Pt > 0.45 ) // 0.45 >2.0
  && ( B0_Pt > 8.) // cut opt >8 // >19
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
  && (*trackShits)[pi_orig_Index] >= 10 // >=10
  && (*trackShits)[ka_orig_Index] >= 10 // >=10
  && (*trackPhits)[pi_orig_Index] > 0
  && (*trackPhits)[ka_orig_Index] > 0
//  && (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 7.0
  && pip4.Eta() < 2.4 && kp4.Eta() < 2.4  

  ) // cuts tight
   {
       if ( fabs( (*MuMuMass)[jpsi_index] - jpsi_mass ) < 0.12 ) {
           hjpsiKPiMassSelAlt->Fill( B0MassAlt );
       }
     hjpsiMass_sel->Fill(jpsip4.M());
     hjpsiEta_sel->Fill(jpsip4.Eta());
       

       for (double k=0;k<21;k++){ // jpsi eta bin
           bin=-2.1+k*0.2;
           if (jpsip4.Eta()>=bin && jpsip4.Eta()<bin+0.2 ) { // cut imp cond
               int l=k;
               if ( fabs( (*MuMuMass)[jpsi_index] - mean[l] ) < 1.0*sigma[l] ) { // eta dependent jpsi mass cut
                   hjpsiKPiMassSelAlt_etacut_1sigma->Fill(B0MassAlt);
                } // eta dependent jpsi mass cut
               if ( fabs( (*MuMuMass)[jpsi_index] - mean[l] ) < 2.0*sigma[l] ) { // eta dependent jpsi mass cut
                   hjpsiKPiMassSelAlt_etacut_2sigma->Fill(B0MassAlt);
               } // eta dependent jpsi mass cut
               if ( fabs( (*MuMuMass)[jpsi_index] - mean[l] ) < 3.0*sigma[l] ) { // eta dependent jpsi mass cut
                   hjpsiKPiMassSelAlt_etacut_3sigma->Fill(B0MassAlt);
               } // eta dependent jpsi mass cut

               } // cut imp cond
           } // jpsi eta bin
 
 

   }
    
       

         

    } // b0 loop
      


} //b0 requirement
 



   return kTRUE;
}

void SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut::SlaveTerminate()
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
        
      hjpsiKPiMassSelAlt_etacut_1sigma->Write();
      hjpsiKPiMassSelAlt_etacut_2sigma->Write();
      hjpsiKPiMassSelAlt_etacut_3sigma->Write();
        
      hjpsiMass->Write();
      hjpsiMass_sel->Write();
        
      hjpsiEta->Write();
      hjpsiEta_sel->Write();
        
/*
        for (int j=0;j<21;j++) { //
            
            hjpsiMass_eta_bin[j]->Write();
            hjpsiMass_eta_bin_sel[j]->Write();
        }
*/


        
      OutFile->Print();
      fOutput->Add(OutFile); 
      hMuMuMass->SetDirectory(0); // any hname
//      hjpsiKPiMassSelAlt->SetDirectory(0) ;
      gDirectory = savedir;
      fOut->Close();
    }



}

void SignalExtract_Jpsi_small_ntpls_jpsi_eta_cut::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}



