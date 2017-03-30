{
    const double B0_mass = 5.27953;
    const double muon_mass = 0.1056583715;
    const double phi_mass = 1.019455;
    const double jpsi_mass = 3.0967;
    const double psi2S_mass = 3.686109 ;
    const double pionCh_mass = 0.13957018;
    const double kaonCh_mass = 0.493677 ;
    
//    TFile f1("MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls.root");
//    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABC_output_small_ntpls.root");
//    TFile f1("Bkg_B0ToPsiMuMu_2Mu.root");
    TFile f1("Bkg_BsToPsiMuMu.root");
//    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_finalcuts_4.root");
  

    
Int_t m = 19800;
Double_t x[19800], m23_max[19800], m23_min[19800];
Double_t E2[19800], E3[19800];

Double_t m_mother = B0_mass;
Double_t m_dau1 = kaonCh_mass, m_dau2 = pionCh_mass, m_dau3 = jpsi_mass ;

Double_t m12_min = (m_dau1+m_dau2)*(m_dau1+m_dau2);
Double_t m12_max = (m_mother-m_dau3)*(m_mother-m_dau3);
Double_t step = (m12_max - m12_min)/(m-1);

x[0] = m12_min + 0.0001;

for (Int_t k=1; k<m; k++ )
x[k] = x[k-1] + step;

Int_t n = 19799;
for (Int_t i=0; i<n; i++) {
    E2[i] = (x[i] - m_dau1*m_dau1 + m_dau2*m_dau2)/(2*sqrt(x[i]));
    E3[i] = (m_mother*m_mother - x[i] - m_dau3*m_dau3)/(2*sqrt(x[i]));
    m23_min[i] = (E2[i]+E3[i])*(E2[i]+E3[i]) - TMath::Power((sqrt(E2[i]*E2[i] - m_dau2*m_dau2) + sqrt(E3[i]*E3[i] - m_dau3*m_dau3)),2);
    m23_max[i] = (E2[i]+E3[i])*(E2[i]+E3[i]) - TMath::Power((sqrt(E2[i]*E2[i] - m_dau2*m_dau2) - sqrt(E3[i]*E3[i] - m_dau3*m_dau3)),2);
}

TGraph *cont_up = new TGraph(n,x,m23_min); cont_up->SetLineWidth(3);
TGraph *cont_down = new TGraph(n,x,m23_max); cont_down->SetLineWidth(3);
    
    
    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    hDalitz_peak->Draw("colz");
    hDalitz_peak->SetTitle("Dalitz - Peak");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");

    TCanvas *c12 = new TCanvas("c12","c12",1050,1050);
    hDalitz_sideband->Draw("colz");
    hDalitz_sideband->SetTitle("Dalitz - Sideband");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");

    
    /*
    
    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    hDalitz_peak_bin3->Draw("colz");
    hDalitz_peak_bin3->SetTitle("Dalitz - Peak");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    TCanvas *c12 = new TCanvas("c12","c12",1050,1050);
    c12->cd();
    hDalitz_sideband_bin3->Draw("colz");
    hDalitz_sideband_bin3->SetTitle("Dalitz - Sidebands");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");

    

    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    c11->Divide(2,2);

    c11->cd(1);
    hDalitz_peak_bin1->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    //TCanvas *c12 = new TCanvas("c12","c12",900,700);
    c11->cd(2);
    hDalitz_peak_bin2->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    //TCanvas *c13 = new TCanvas("c13","c13",900,700);
    c11->cd(3);
    hDalitz_peak_bin3->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    //TCanvas *c14 = new TCanvas("c14","c14",900,700);
    c11->cd(4);
    hDalitz_peak_bin4->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    
    TCanvas *c21 = new TCanvas("c21","c21",1050,1050);
    c21->Divide(2,2);
    
    c21->cd(1);
    hDalitz_sideband_bin1->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    //TCanvas *c22 = new TCanvas("c22","c22",900,700);
    c21->cd(2);
    hDalitz_sideband_bin2->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    //TCanvas *c23 = new TCanvas("c23","c23",900,700);
    c21->cd(3);
    hDalitz_sideband_bin3->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
    
    //TCanvas *c24 = new TCanvas("c24","c24",900,700);
    c21->cd(4);
    hDalitz_sideband_bin4->Draw("colz");
    cont_down->Draw("lsame");
    cont_up->Draw("lsame");
 */

}