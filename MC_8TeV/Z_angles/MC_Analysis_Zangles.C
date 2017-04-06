#define MC_Analysis_Zangles_cxx
// The class definition in MC_Analysis_Zangles.h has been generated automatically
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
// Root > T->Process("MC_Analysis_Zangles.C")
// Root > T->Process("MC_Analysis_Zangles.C","some options")
// Root > T->Process("MC_Analysis_Zangles.C+")
//

#include "MC_Analysis_Zangles.h"
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


void MC_Analysis_Zangles::Begin(TTree * /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).
    
    TString option = GetOption();
    
}

void MC_Analysis_Zangles::SlaveBegin(TTree * /*tree*/)
{
    // The SlaveBegin() function is called after the Begin() function.
    // When running with PROOF SlaveBegin() is called on each slave server.
    // The tree argument is deprecated (on PROOF 0 is passed).
    
    TString option = GetOption();
    
    //    OutFile = new TProofOutputFile( "Bkg_B0ToPsiMuMu_0004.root" );
    //    OutFile = new TProofOutputFile( "Bkg_BsToPsiMuMu_0001.root" );
    //   OutFile = new TProofOutputFile( "Bkg_BpToPsiMuMu_0000.root" );
    OutFile = new TProofOutputFile( "Bkg_LambdaBToPsiMuMu.root" );
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
    
    hJpsiPiMass_peak        = new TH1F("hJpsiPiMass_peak","hJpsiPiMass_peak",1000,0,10);
    hKPiMass_peak           = new TH1F("hKPiMass_peak","hKPiMass_peak",1000,0,10);
 
    hJpsiPiMass_sb          = new TH1F("hJpsiPiMass_sb","hJpsiPiMass_sb",1000,0,10);
    hKPiMass_sb             = new TH1F("hKPiMass_sb","hKPiMass_sb",1000,0,10);
    
    hjpsiKPiMassBaseSelAlt      = new TH1F("hjpsiKPiMassBaseSelAlt"," MuMuKPiMass after basic selection",100, 4.8, 5.8);
    hjpsiKPiMassNoPhi           = new TH1F("hjpsiKPiMassNoPhi","hjpsiKPiMass No Phi to KK ", 100, 4.8, 5.8);
    
    h_cos_theta_Jpsi        = new TH1F("h_cos_theta_Jpsi","Cosine of J/#psi helicity angle ;cos(#theta_{J/#psi})", 102, -1.02, 1.02);
    h_cos_theta_Kstar       = new TH1F("h_cos_theta_Kstar","Cosine of K* helicity angle ;cos(#theta_{K*})", 102, -1.02, 1.02);
    h_cos_theta_Z           = new TH1F("h_cos_theta_Z","Cosine of Z helicity angle ;cos(#theta_{Z})", 102, -1.02, 1.02);
    h_phi_planes            = new TH1F("h_phi_planes","Angle between K#pi and #mu#mu planes;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;

}

Bool_t MC_Analysis_Zangles::Process(Long64_t entry)
{
    // The Process() function is called for each entry in the tree (or possibly
    // keyed object in the case of PROOF) to be processed. The entry argument
    // specifies which entry in the currently loaded tree is to be processed.
    // It can be passed to either MC_Analysis_Zangles::GetEntry() or TBranch::GetEntry()
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
    TLorentzVector pip4, pip4_exchanged, pip4_proton;
    TLorentzVector kp4, kp4_exchanged, kp4_proton;
    TLorentzVector Pip4_orig, Kp4_orig;
    TLorentzVector B0p4, B0p4_KPiExchanged, Bsp4_JpsiKK, JpsiPiPip4;
    TLorentzVector JpsiKProton_p4, JpsiPiProton_p4;
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
            
            pip4_proton.SetVectM(pip4.Vect(), proton_mass) ;
            kp4_proton.SetVectM(kp4.Vect(), proton_mass) ;
            
            //  TLorentzVector B0p4, B0p4_KPiExchanged, Bsp4_JpsiKK, JpsiPiPip4;
            B0p4 = jpsip4+pip4+kp4;
            Bsp4_JpsiKK = jpsip4+kp4+pip4_exchanged;
            JpsiPiPip4 = jpsip4+pip4+kp4_exchanged;
            JpsiKProton_p4 = jpsip4+kp4+pip4_proton;
            JpsiPiProton_p4 = jpsip4+pip4+kp4_proton;
            
            
            
            //  Float_t
            B0MassAlt = (jpsip4+pip4+kp4).Mag() - jpsip4.M() + jpsi_mass;
            Float_t BsMassAlt = (jpsip4+kp4+pip4_exchanged).Mag() - jpsip4.M() + jpsi_mass;
            Float_t JpsiPiPiMass = (jpsip4+pip4+kp4_exchanged).Mag()- jpsip4.M() + jpsi_mass;
            
            Float_t JpsiPiProtonMass = (jpsip4+pip4+kp4_proton).Mag()- jpsip4.M() + jpsi_mass;
            Float_t JpsiKProtonMass = (jpsip4+kp4+pip4_proton).Mag()- jpsip4.M() + jpsi_mass;
            
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
            Float_t B0ExchangedMassAlt = B0p4_KPiExchanged.Mag() - jpsip4.M() + jpsi_mass;
            
            
            //  hjpsifromBMass->Fill((*MuMuMass)[(*B0MuMuIdx)[myB0Idx]]);
            //  int jpsiId = (*B0MuMuIdx)[myB0Idx];
            
            
            Bool_t newsoftID = false;
            Bool_t baselineB0Sel = false;
            
            
            
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
                baselineB0Sel = true;

            } // cuts loose loop
            
            if ( 1 // cuts tight
                && baselineB0Sel
                //  && B0_Pt > 8.
                //  && pion_fromB0_Pt > 0.7
                && ( (*B0Vtx_CL)[myB0Idx] > 0.09 ) //0.09
                && ( (*B0CosAlphaPV)[myB0Idx] > 0.998 ) //0.998
                && ( (*B0CTauPV)[myB0Idx]/(*B0CTauPVE)[myB0Idx] > 9.0 ) //9.0
                && ( fabs( (*MuMuMass)[jpsi_index] - jpsi_mass ) < 0.12 ) // 0.12 was 0.2 for baseline cuts
                && ( (*MuMuVtx_CL)[jpsi_index] > 0.02 ) //0.02
                && ( pion_fromB0_Pt > 0.45 ) // 0.45 >2.0
                && ( kaon_fromB0_Pt > 0.45 ) // 0.45 >2.0
                && ( B0_Pt > 8.) // >7 // >18
                
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
                hJpsiPiMass->Fill(JpsiPiMass);
                hKPiMass->Fill(KPiMass);
                
                hjpsiKPiMassBaseSelAlt->Fill( B0MassAlt );
                
                if ( B0MassAlt>5.22 && B0MassAlt<5.34 ) { // Dalitz peak
                    
                    hJpsiPiMass_peak->Fill(JpsiPiMass);
                    hKPiMass_peak->Fill(KPiMass);
                } // Dalitz peak
                if ( (B0MassAlt>5.16 && B0MassAlt<5.22) || (B0MassAlt>5.34 && B0MassAlt<5.40) ) { // Dalitz sideband
                    
                    hJpsiPiMass_sb->Fill(JpsiPiMass);
                    hKPiMass_sb->Fill(KPiMass);
                    
                } // Dalitz sideband
                
                if (  !(((pip4_exchanged+kp4).Mag()> 1.01 &&  (pip4_exchanged+kp4).Mag()< 1.03) && (BsMassAlt>5.332 && BsMassAlt<5.40)) )  { // no Bs
                    hjpsiKPiMassNoPhi->Fill(B0MassAlt);
                    
                } // no Bs
                
                //double
                theta_Jpsi = GetThetaMuMu(B0p4, jpsip4, mu1Charge>0 ? mu1_p4 : mu2_p4, beam_energy, jpsi_mass, muon_mass);
                h_cos_theta_Jpsi->Fill(theta_Jpsi);
                //        phi = getPlanesAngle(B0p4, kp4, pip4, muM_p4, muP_p4) ;
                //        phi = GetPhi(B0p4,mu1_p4, mu2_p4, kp4, pip4 );
                phi = GetPhi(B0p4,mu1Charge>0 ? mu1_p4 : mu2_p4,mu1Charge>0 ? mu2_p4 : mu1_p4, kp4, pip4 );
                h_phi_planes->Fill(phi);
                
                double m2KPi = KPiMass*KPiMass;
                double m2JpsiPi = JpsiPiMass*JpsiPiMass;
                
                if (fabs(costhetaHel(m2B,m2KPi,m2K,m2Pi,m2Jpsi,m2JpsiPi))<1 ) {
                    double costheta_k = costhetaHel(m2B,m2KPi,m2K,m2Pi,m2Jpsi,m2JpsiPi);
                    h_cos_theta_Kstar->Fill(costheta_Kstar);
                }

                if (fabs(costhetaHel(m2B,m2JpsiPi,m2Jpsi,m2Pi,m2K,m2KPi))<1 ) {
                    double costheta_z = costhetaHel(m2B,m2JpsiPi,m2Jpsi,m2Pi,m2K,m2KPi);
                    h_cos_theta_Z->Fill(costheta_z);
                }
               
            } // cuts tight loop
            
            
        } // b0 loop
        
    }//b0 requirement
    
    
    return kTRUE;
}

void MC_Analysis_Zangles::SlaveTerminate()
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
        hjpsiKPiMassNoPhi->Write();
        
        hJpsiPiMass->Write();
        hKPiMass->Write();
        
        hJpsiPiMass_peak->Write();
        hKPiMass_peak->Write();
        
        hJpsiPiMass_sb->Write();
        hKPiMass_sb->Write();
        
        h_cos_theta_Jpsi->Write();
        h_cos_theta_Kstar->Write();
        h_cos_theta_Z->Write();
        h_phi_planes->Write();

        
        
        OutFile->Print();
        fOutput->Add(OutFile); 
        hMuMuMass->SetDirectory(0); // any hname
        //      hjpsiKPiMassSelAlt->SetDirectory(0) ;
        //      gDirectory = savedir;
        fOut->Close();
    }
    
    
    
    
}

void MC_Analysis_Zangles::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.
    
}



//================ Decay Momentum ====================
// Momentum in 2-particle decay : m0->m1+m2

double MC_Analysis_Zangles::sq_calc(double x,double y, double z) const
{
    return pow(x,2)+pow(y,2)+pow(z,2)-2.0*x*y-2.0*x*z-2.0*y*z; // corr sign
}

double MC_Analysis_Zangles::dec2mm (double m0, double m1, double m2) const
{
    double temp = sq_calc(m0*m0,m1*m1,m2*m2);
    if (temp >= 0) {
        return sqrt(temp)/(2.0*m0);
    }
    else {
        return 0.0;
    }
}
//================ Decay Momentum ====================


//================ costheta_helicity ===========================
double MC_Analysis_Zangles::costhetaHel(double m2Mom, double m2Dau, double m2GDau, double m2GDau2, double m2Dau2, double m2Dau2GDau2) const
{
    double num      = 0.5*m2Dau*(m2Mom-m2Dau2GDau2+m2GDau)-0.25*(m2Mom-m2Dau2+m2Dau)*(m2GDau-m2GDau2+m2Dau);
    double denom2   = (0.25*(pow((m2Mom+m2Dau-m2Dau2),2))-(m2Mom*m2Dau))*(0.25*(pow((m2GDau+m2Dau-m2GDau2),2))-(m2GDau*m2Dau));
    double denom = sqrt(denom2);
    
    double costheta_helicity = num/denom;
    return costheta_helicity;

}
//================ costheta_helicity ===========================


// functions calculating angles

double MC_Analysis_Zangles::getPlanesAngle(TLorentzVector B0, TLorentzVector K, TLorentzVector Pi, TLorentzVector muM, TLorentzVector muP) {
    
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


double MC_Analysis_Zangles::GetPhi(TLorentzVector LoreVecB0,TLorentzVector LoreVecMum, TLorentzVector LoreVecMup, TLorentzVector LoreVecK, TLorentzVector LoreVecPi)	{
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



float MC_Analysis_Zangles::GetThetaMuMu(TLorentzVector BVec, TLorentzVector JPsiVec, TLorentzVector MuPlusVec, float BeamEnergy, float JPsiPDG , float muonPDG) {
    
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

void MC_Analysis_Zangles::GetMomentumInMotherFrame( TLorentzVector Mother,TLorentzVector Particle, double BeamEnergy , TVector3 &Particle_rotated){
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


