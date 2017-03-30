#define KinFitCheck_cxx
#include "KinFitCheck.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void KinFitCheck::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L KinFitCheck.C
//      Root > KinFitCheck t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   
    TFile* f2=new TFile("MuMuPiK_KinFitCheck.root","RECREATE");
    cout<<"total events :"<<nentries<<endl;
   
    TH2* h_mu1Px_rel = new TH2F("h_mu1Px_rel","(mu1Px_refitted - mu1Px_original)/mu1Px_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_mu1Py_rel = new TH2F("h_mu1Py_rel","(mu1Py_refitted - mu1Py_original)/mu1Py_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_mu1Pz_rel = new TH2F("h_mu1Pz_rel","(mu1Pz_refitted - mu1Pz_original)/mu1Pz_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);

    TH2* h_mu2Px_rel = new TH2F("h_mu2Px_rel","(mu2Px_refitted - mu2Px_original)/mu2Px_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_mu2Py_rel = new TH2F("h_mu2Py_rel","(mu2Py_refitted - mu2Py_original)/mu2Py_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_mu2Pz_rel = new TH2F("h_mu2Pz_rel","(mu2Pz_refitted - mu2Pz_original)/mu2Pz_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);

    TH2* h_piPx_rel = new TH2F("h_piPx_rel","(piPx_refitted - piPx_original)/piPx_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_piPy_rel = new TH2F("h_piPy_rel","(piPy_refitted - piPy_original)/piPy_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_piPz_rel = new TH2F("h_piPz_rel","(piPz_refitted - piPz_original)/piPz_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);

    TH2* h_kPx_rel = new TH2F("h_kPx_rel","(kPx_refitted - kPx_original)/kPx_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_kPy_rel = new TH2F("h_kPy_rel","(kPy_refitted - kPy_original)/kPy_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);
    TH2* h_kPz_rel = new TH2F("h_kPz_rel","(kPz_refitted - kPz_original)/kPz_original ; B0 Mass Constraint; Jpsi Mass Constraint",100,-0.1,0.1,100,-0.1,0.1);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) { // jentry loop
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if ( Muon1Px_MuMuPiK->size() > 0 ) {
      cout << "B0 const vector size : " << Muon1Px_MuMuPiK_B0Mass->size() << endl;
      cout << "Jpsi const vector size : " << Muon1Px_MuMuPiK->size() << endl;
      }
      // if (Cut(ientry) < 0) continue;
        int n_size = Muon1Px_MuMuPiK_B0Mass_rel->size();
        for (int nn = 0; nn < n_size; nn++) {
            h_mu1Px_rel->Fill(Muon1Px_MuMuPiK_B0Mass_rel->at(nn),Muon1Px_MuMuPiK_JpsiMass_rel->at(nn));
            h_mu1Py_rel->Fill(Muon1Py_MuMuPiK_B0Mass_rel->at(nn),Muon1Py_MuMuPiK_JpsiMass_rel->at(nn));
            h_mu1Pz_rel->Fill(Muon1Pz_MuMuPiK_B0Mass_rel->at(nn),Muon1Pz_MuMuPiK_JpsiMass_rel->at(nn));

            h_mu2Px_rel->Fill(Muon2Px_MuMuPiK_B0Mass_rel->at(nn),Muon2Px_MuMuPiK_JpsiMass_rel->at(nn));
            h_mu2Py_rel->Fill(Muon2Py_MuMuPiK_B0Mass_rel->at(nn),Muon2Py_MuMuPiK_JpsiMass_rel->at(nn));
            h_mu2Pz_rel->Fill(Muon2Pz_MuMuPiK_B0Mass_rel->at(nn),Muon2Pz_MuMuPiK_JpsiMass_rel->at(nn));

            h_piPx_rel->Fill(PionPx_MuMuPiK_B0Mass_rel->at(nn),PionPx_MuMuPiK_JpsiMass_rel->at(nn));
            h_piPy_rel->Fill(PionPy_MuMuPiK_B0Mass_rel->at(nn),PionPy_MuMuPiK_JpsiMass_rel->at(nn));
            h_piPz_rel->Fill(PionPz_MuMuPiK_B0Mass_rel->at(nn),PionPz_MuMuPiK_JpsiMass_rel->at(nn));

            h_kPx_rel->Fill(KaonPx_MuMuPiK_B0Mass_rel->at(nn),KaonPx_MuMuPiK_JpsiMass_rel->at(nn));
            h_kPy_rel->Fill(KaonPy_MuMuPiK_B0Mass_rel->at(nn),KaonPy_MuMuPiK_JpsiMass_rel->at(nn));
            h_kPz_rel->Fill(KaonPz_MuMuPiK_B0Mass_rel->at(nn),KaonPz_MuMuPiK_JpsiMass_rel->at(nn));
            
        }
      
      
   } // jentry loop ends
   
   
TCanvas* c_px = new TCanvas("c_px","c_px",260,94,1016,575);
gStyle->SetOptStat(10);
c_px->Divide(2,2);
c_px->cd(1);
h_mu1Px_rel->Draw("colz");
c_px->cd(2);
h_mu2Px_rel->Draw("colz");
c_px->cd(3);
h_piPx_rel->Draw("colz");
c_px->cd(4);
h_kPx_rel->Draw("colz");


TCanvas* c_py = new TCanvas("c_py","c_py",260,94,1016,575);
gStyle->SetOptStat(10);
c_py->Divide(2,2);
c_py->cd(1);
h_mu1Py_rel->Draw("colz");
c_py->cd(2);
h_mu2Py_rel->Draw("colz");
c_py->cd(3);
h_piPy_rel->Draw("colz");
c_py->cd(4);
h_kPy_rel->Draw("colz");


TCanvas* c_pz = new TCanvas("c_pz","c_pz",260,94,1016,575);
gStyle->SetOptStat(10);
c_pz->Divide(2,2);
c_pz->cd(1);
h_mu1Pz_rel->Draw("colz");
c_pz->cd(2);
h_mu2Pz_rel->Draw("colz");
c_pz->cd(3);
h_piPz_rel->Draw("colz");
c_pz->cd(4);
h_kPz_rel->Draw("colz");

//c_px->SaveAs("c_px.pdf");
//c_py->SaveAs("c_py.pdf");
//c_pz->SaveAs("c_pz.pdf");
   
//f2->Write();
//f2->Close();

}
