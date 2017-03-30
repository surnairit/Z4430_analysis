{
    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABC_output_small_ntpls.root");
    

    
    TCanvas *c2 = new TCanvas("c2","c2",600,500);
    h_theta_Jpsi_sel->Draw();
    h_theta_Jpsi_sel_nB01->Draw("same");
    h_theta_Jpsi_sel_nB01->SetLineColor(2);
    
    leg2 = new TLegend(0.6,0.5,0.9,0.7);
    leg2->AddEntry(h_theta_Jpsi_sel_nB01,"nB0 > 0","l");
    leg2->AddEntry(h_theta_Jpsi_sel_nB01,"nB0 = 1 after cuts","l");
    leg2->Draw();
    
    TCanvas *c3 = new TCanvas("c3","c3",600,500);
    h_phi_planes_sel->Draw();
    h_phi_planes_sel_nB01->Draw("same");
    h_phi_planes_sel_nB01->SetLineColor(2);
    leg2->Draw();
    
    
    TCanvas *c1 = new TCanvas("c1","c1",600,500);
//    hjpsiKPiMassSelAltZoom->SetTitle("J/#psi K#pi mass [GeV]");
//    hjpsiKPiMassSelAltZoom->Draw();
    hjpsiKPiMassNoPhi->Draw();
    hjpsiKPiMassNoPhi->SetTitle("J/#psi K#pi mass [GeV]");
    hjpsiKPiMassSelAltZoom_nB01->Draw("same");
    hjpsiKPiMassSelAltZoom_nB01->SetLineColor(2);
//    hjpsiKPiMassNoPhi->SetLineColor(8);
    
    leg = new TLegend(0.6,0.5,0.9,0.7);
//    leg->AddEntry(hjpsiKPiMassSelAltZoom,"nB0 > 0","l");
    leg->AddEntry(hjpsiKPiMassNoPhi,"nB0 > 0 ");
    leg->AddEntry(hjpsiKPiMassSelAltZoom_nB01,"nB0 = 1 after cuts","l");

    leg->Draw();
    
}