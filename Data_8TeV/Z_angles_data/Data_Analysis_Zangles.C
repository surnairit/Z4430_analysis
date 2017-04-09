#define Data_Analysis_Zangles_cxx
// The class definition in Data_Analysis_Zangles.h has been generated automatically
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
// Root > T->Process("Data_Analysis_Zangles.C")
// Root > T->Process("Data_Analysis_Zangles.C","some options")
// Root > T->Process("Data_Analysis_Zangles.C+")
//

#include "Data_Analysis_Zangles.h"
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


void Data_Analysis_Zangles::Begin(TTree * /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).
    
    TString option = GetOption();
    
}

void Data_Analysis_Zangles::SlaveBegin(TTree * /*tree*/)
{
    // The SlaveBegin() function is called after the Begin() function.
    // When running with PROOF SlaveBegin() is called on each slave server.
    // The tree argument is deprecated (on PROOF 0 is passed).
    
    TString option = GetOption();
    
    //   OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls.root" );
    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012AB_output_Zangles.root" );
    
    //    OutFile = new TProofOutputFile( "MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls_Dalitzfit.root" );
    fOut = OutFile->OpenFile("RECREATE");
    
    if ( !(fOut = OutFile->OpenFile("RECREATE")) )
    {
        Warning("SlaveBegin", "problems opening file: %s/%s",
                OutFile->GetDir(), OutFile->GetFileName());
    }
    
    //////// HISTOGRAMS
    // put them here:
    //
    
    h_nB0                   = new TH1F("h_nB0","h_nB0",10,0,10);
    hMuMuMass               = new TH1F("hMuMuMass","hMuMuMass",140,2.6,4.0);
    
    h_theta_Jpsi            = new TH1F("h_theta_Jpsi","J/#psi helicity angle ;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_theta_Jpsi_sel        = new TH1F("h_theta_Jpsi_sel","J/#psi helicity angle after selection;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_cos_theta_Jpsi        = new TH1F("h_cos_theta_Jpsi","Cosine of J/#psi helicity angle ;#cos(theta_{J/#psi})", 102, -1.02, 1.02);
    h_cos_theta_Jpsi_sel    = new TH1F("h_cos_theta_Jpsi_sel","Cosine of J/#psi helicity angle after selection;#cos(theta_{J/#psi})", 102, -1.02, 1.02);
    
    h_cos_theta_Kstar       = new TH1F("h_cos_theta_Kstar","Cosine of K* helicity angle ;#cos(theta_{K*})", 102, -1.02, 1.02);
    h_cos_theta_Kstar_sel   = new TH1F("h_cos_theta_Kstar_sel","Cosine of K* helicity angle after selection;#cos(theta_{K*})", 102, -1.02, 1.02);
    
    h_cos_theta_Z       = new TH1F("h_cos_theta_Z","Cosine of Z helicity angle ;cos(#theta_{Z})", 102, -1.02, 1.02);
    h_cos_theta_Z_sel   = new TH1F("h_cos_theta_Z_sel","Cosine of Z helicity angle after selection;cos(#theta_{Z})", 102, -1.02, 1.02);
    
    h_phi_planes            = new TH1F("h_phi_planes","Angle between K#pi and #mu#mu planes;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;
    h_phi_planes_sel        = new TH1F("h_phi_planes_sel","Angle between K#pi and #mu#mu planes after selection;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;

    h_alpha            = new TH1F("h_alpha","Angle between #mu+#pi and #mu+K* planes;#alpha", 160, -3.2, 3.2) ;
    h_alpha_sel        = new TH1F("h_alpha_sel","Angle between #mu+#pi and #mu+K* planes planes after selection;#alpha", 160, -3.2, 3.2) ;
    
    
    // nB0 = 1 variables
    
    h_theta_Jpsi_sel_nB01        = new TH1F("h_theta_Jpsi_sel_nB01","J/#psi helicity angle after selection nB0=1;#theta_{J/#psi}", 160, -0.03, 3.17);
    h_cos_theta_Jpsi_sel_nB01    = new TH1F("h_cos_theta_Jpsi_sel_nB01","Cosine of J/#psi helicity angle after selection nB0=1;#cos(theta_{J/#psi})", 102, -1.02, 1.02);
    
    h_cos_theta_Kstar_sel_nB01   = new TH1F("h_cos_theta_Kstar_sel_nB01","Cosine of K* helicity angle after selection nB0=1;#cos(theta_{K*})", 102, -1.02, 1.02);
    
    h_cos_theta_Z_sel_nB01   = new TH1F("h_cos_theta_Z_sel_nB01","Cosine of Z helicity angle after selection nB0=1;cos(#theta_{Z})", 102, -1.02, 1.02);
    
    h_phi_planes_sel_nB01        = new TH1F("h_phi_planes_sel_nB01","Angle between K#pi and #mu#mu planes after selection nB0=1;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;
    h_alpha_sel_nB01        = new TH1F("h_alpha_sel_nB01","Angle between #mu+#pi and #mu+K* planes after selection nB0=1;#alpha", 160, -3.2, 3.2) ;
    
    hjpsiKPiMassSelAltZoom_nB01                 = new TH1F("hjpsiKPiMassSelAltZoom_nB01","hjpsiKPiMassSelAltZoom_nB01", 90, 5.10, 5.46);
    
    // nB0 = 1 variables
    
    
}

Bool_t Data_Analysis_Zangles::Process(Long64_t entry)
{
    // The Process() function is called for each entry in the tree (or possibly
    // keyed object in the case of PROOF) to be processed. The entry argument
    // specifies which entry in the currently loaded tree is to be processed.
    // It can be passed to either Data_Analysis_Zangles::GetEntry() or TBranch::GetEntry()
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
    double theta_z=0;
    double phi=0;
    
    double costheta_z=0;
    double costheta_k=0;
    double alpha_angle = 0;
    
    
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
            //            theta_Kstar = GetThetaMuMu(B0p4, (pip4+kp4), pionCharge>0 ? pip4 : kp4, beam_energy, KPiMass, pionCharge>0 ? pionCh_mass : kaonCh_mass) ;
            //double
            //        phi = getPlanesAngle(B0p4, kp4, pip4, muM_p4, muP_p4) ;
            //        phi = GetPhi(B0p4,mu1_p4, mu2_p4, kp4, pip4 );
            phi = GetPhi(B0p4,mu1Charge>0 ? mu1_p4 : mu2_p4,mu1Charge>0 ? mu2_p4 : mu1_p4, kp4, pip4 );
            
            h_theta_Jpsi->Fill(theta_Jpsi);
            h_cos_theta_Jpsi->Fill(TMath::Cos(theta_Jpsi));
            
            
            double m2KPi = KPiMass*KPiMass;
            double m2JpsiPi = JpsiPiMass*JpsiPiMass;
            costheta_k = costhetaHel(m2B,m2KPi,m2K,m2Pi,m2Jpsi,m2JpsiPi);
            costheta_z = costhetaHel(m2B,m2JpsiPi,m2Jpsi,m2Pi,m2K,m2KPi);
            alpha_angle = alpha(theta_Jpsi,phi,m2KPi,m2JpsiPi);
            
            
            if (fabs(costheta_k)<1 ) {
                h_cos_theta_Kstar->Fill(costheta_k);
            }
            
            if (fabs(costheta_z)<1 ) {
                h_cos_theta_Z->Fill(costheta_z);
            }
            
            h_phi_planes->Fill(phi);
            h_alpha->Fill(alpha_angle);
            
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
                numB0++; // no of B0 per event surviving the cuts
                
                //           if ( B0MassAlt>5.22 && B0MassAlt<5.34 ) { // Dalitz peak
                if ( B0MassAlt>5.259 && B0MassAlt<5.299 ) { // Dalitz peak
                    
                    h_theta_Jpsi_sel->Fill(theta_Jpsi);
                    h_cos_theta_Jpsi_sel->Fill(TMath::Cos(theta_Jpsi));
                    
                    if (fabs(costheta_k)<1 ) {
                        h_cos_theta_Kstar_sel->Fill(costheta_k);
                    }
                    
                    if (fabs(costheta_z)<1 ) {
                        h_cos_theta_Z_sel->Fill(costheta_z);
                    }
                    
                    h_phi_planes_sel->Fill(phi);
                    h_alpha_sel->Fill(alpha_angle);
                    
                } // Dalitz peak
                
            } //check
            
            
            
            
        } // b0 loop
        
        if (numB0 == 1) { // only 1 B0 after cuts
            
            hjpsiKPiMassSelAltZoom_nB01->Fill(B0MassAlt);
            
            if ( B0MassAlt>5.22 && B0MassAlt<5.34 ) { // Dalitz peak
                
                h_theta_Jpsi_sel_nB01->Fill(theta_Jpsi);
                h_cos_theta_Jpsi_sel_nB01->Fill(TMath::Cos(theta_Jpsi));
                
                if (fabs(costheta_k)<1 ) {
                    h_cos_theta_Kstar_sel_nB01->Fill(costheta_k);
                }
                
                if (fabs(costheta_z)<1 ) {
                    h_cos_theta_Z_sel_nB01->Fill(costheta_z);
                }
                
                h_phi_planes_sel_nB01->Fill(phi);
                h_alpha_sel_nB01->Fill(alpha_angle);
                
            } // Dalitz peak

            
        } // only 1 B0 after cuts
        
        
    } //b0 requirement
    
    
    return kTRUE;
}

void Data_Analysis_Zangles::SlaveTerminate()
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
        
        h_theta_Jpsi->Write();
        h_cos_theta_Jpsi->Write();
        h_theta_Jpsi_sel->Write();
        h_cos_theta_Jpsi_sel->Write();
        
        h_cos_theta_Kstar->Write();
        h_cos_theta_Kstar_sel->Write();
        
        h_cos_theta_Z->Write();
        h_cos_theta_Z_sel->Write();

        
        h_phi_planes->Write();
        h_phi_planes_sel->Write();
        
        h_alpha->Write();
        h_alpha_sel->Write();
        
        // nB0 = 1 variables
        h_theta_Jpsi_sel_nB01->Write();
        h_cos_theta_Jpsi_sel_nB01->Write();
        h_cos_theta_Kstar_sel_nB01->Write();
        h_phi_planes_sel_nB01->Write();
        h_alpha_sel_nB01->Write();
        
        h_cos_theta_Z_sel_nB01->Write();
        
        hjpsiKPiMassSelAltZoom_nB01->Write();
        // nB0 = 1 variables
        
        hMuMuMass->Write();
        
        
        OutFile->Print();
        fOutput->Add(OutFile);
        hMuMuMass->SetDirectory(0); // any hname
        //      hjpsiKPiMassSelAlt->SetDirectory(0) ;
        gDirectory = savedir;
        fOut->Close();
    }
    
    
    
}

void Data_Analysis_Zangles::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.
    
}


//================ Decay Momentum ====================
// Momentum in 2-particle decay : m0->m1+m2

double Data_Analysis_Zangles::sq_calc(double x,double y, double z) const
{
    return pow(x,2)+pow(y,2)+pow(z,2)-2.0*x*y-2.0*x*z-2.0*y*z; // corr sign
}

double Data_Analysis_Zangles::dec2mm (double m0, double m1, double m2) const
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
double Data_Analysis_Zangles::costhetaHel(double m2Mom, double m2Dau, double m2GDau, double m2GDau2, double m2Dau2, double m2Dau2GDau2) const
{
    double num      = 0.5*m2Dau*(m2Mom-m2Dau2GDau2+m2GDau)-0.25*(m2Mom-m2Dau2+m2Dau)*(m2GDau-m2GDau2+m2Dau);
    double denom2   = (0.25*(pow((m2Mom+m2Dau-m2Dau2),2))-(m2Mom*m2Dau))*(0.25*(pow((m2GDau+m2Dau-m2GDau2),2))-(m2GDau*m2Dau));
    double denom = sqrt(denom2);
    
    double costheta_helicity = num/denom;
    return costheta_helicity;

}
//================ costheta_helicity ===========================


//================ Alpha =============================
double Data_Analysis_Zangles::alpha(double theta, double phi, double m2kpi, double m2jpsipi) const
{
    double kmom = dec2mm(sqrt(m2kpi),kaonCh_mass,pionCh_mass);
    double costh_k = costhetaHel(m2B,m2kpi,m2K,m2Pi,m2Jpsi,m2jpsipi);
    
    TLorentzVector K;
    double pkx = kmom*sin(acos(costh_k));
    double pky = 0.0;
    double pkz = kmom*costh_k;
    double Ek = sqrt(m2K+kmom*kmom);
    K.SetPxPyPzE(pkx,pky,pkz,Ek);
    TLorentzVector Pi;
    double ppix = -kmom*sin(acos(costh_k));
    double ppiy = 0.0;
    double ppiz = -kmom*costh_k;
    double Epi = sqrt(m2Pi+kmom*kmom);
    Pi.SetPxPyPzE(ppix,ppiy,ppiz,Epi);
    
    // Jpsi mom = K* mom in B0 rest frame
    double jpsimom = dec2mm(B0_mass,jpsi_mass,sqrt(m2kpi));
    TLorentzVector J_b0;
    J_b0.SetPxPyPzE(0.0,0.0,-jpsimom,sqrt(m2Jpsi+jpsimom*jpsimom));
    TLorentzVector Kstar_b0;
    Kstar_b0.SetPxPyPzE(0.0,0.0,jpsimom,sqrt(m2kpi+jpsimom*jpsimom));
    
    // boosting K* to Jpsi rest frame
    TLorentzVector Kstar_jpsi = Kstar_b0;
    Kstar_jpsi.Boost( -J_b0.BoostVector() );
    
    // boosting Jpsi to K* rest frame
    TLorentzVector J_Kstar = J_b0;
    J_Kstar.Boost( -Kstar_b0.BoostVector() );
    
    // boosting Pi in K* rest frame to Jpsi rest frame
    TLorentzVector Pi_jpsi = Pi;
    Pi_jpsi.Boost( -J_Kstar.BoostVector() );
    
    // Muon 4 momenta in Jpsi rest frame
    double mumom = dec2mm(jpsi_mass,muon_mass,muon_mass);
    TLorentzVector muP;
    double pmuPx = mumom*sin(theta)*cos(phi);
    double pmuPy = -mumom*sin(theta)*sin(phi);
    double pmuPz = -mumom*cos(theta);
    double EmuP = sqrt(muon_mass*muon_mass+mumom*mumom);
    muP.SetPxPyPzE(pmuPx,pmuPy,pmuPz,EmuP);
    
    
/*
    double scale1 = ((Kstar_jpsi.Vect()).Dot(muP.Vect()))/(muP.Vect().Mag2());
    TVector3 aKstar = Kstar_jpsi.Vect() - scale1*muP.Vect();
    
    double scale2 = ((Pi_jpsi.Vect()).Dot(muP.Vect()))/(muP.Vect().Mag2());
    TVector3 aPi = Pi_jpsi.Vect() - scale2*muP.Vect();
        
    double cosalpha = (aPi.Dot(aKstar))/((aPi.Mag())*(aKstar.Mag()));
 
    return acos(cosalpha);
*/
 
    TVector3	MuPPiPlane	=	muP.Vect().Cross(Pi_jpsi.Vect());
    TVector3	MuPKstPlane		=	muP.Vect().Cross(Kstar_jpsi.Vect());
    double alph;
    alph	=	MuPPiPlane.Angle(MuPKstPlane);
    return
    alph;
 
    
}
//================ Alpha =============================

// functions calculating angles

double Data_Analysis_Zangles::getPlanesAngle(TLorentzVector B0, TLorentzVector K, TLorentzVector Pi, TLorentzVector muM, TLorentzVector muP) {
    
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


double Data_Analysis_Zangles::GetPhi(TLorentzVector LoreVecB0,TLorentzVector LoreVecMum, TLorentzVector LoreVecMup, TLorentzVector LoreVecK, TLorentzVector LoreVecPi)	{
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



float Data_Analysis_Zangles::GetThetaMuMu(TLorentzVector BVec, TLorentzVector JPsiVec, TLorentzVector MuPlusVec, float BeamEnergy, float JPsiPDG , float muonPDG) {
    
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

void Data_Analysis_Zangles::GetMomentumInMotherFrame( TLorentzVector Mother,TLorentzVector Particle, double BeamEnergy , TVector3 &Particle_rotated){
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




