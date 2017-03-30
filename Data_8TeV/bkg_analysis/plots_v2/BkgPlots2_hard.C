{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABCD_BkgAnalysis.root");
    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt_hard->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMassNoPhi_hard->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt_hard->Draw();
    hjpsiPiPiMassNoPhi_hard->SetLineColor(kRed);
    hjpsiPiPiMassNoPhi_hard->Draw("same");
    hjpsiPiPiMassNoPhi_discard_hard->SetFillColor( kRed);
    hjpsiPiPiMassNoPhi_discard_hard->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hjpsiPiPiMassBaseSelAlt_hard,"before Phi->KK removal","L");
    l->AddEntry(hjpsiPiPiMassNoPhi_hard,"after Phi->KK removal","L");
    l->AddEntry(hjpsiPiPiMassNoPhi_discard_hard, "Rejected events", "F");
    l->SetBorderSize(0);
    l->SetTextSize(0.025);
    l->Draw();
    c11->SaveAs("Bkg_MuOnia2012ABCD_MuMuPiPi_compare_hard.png");
    f1->Close();
    
}
