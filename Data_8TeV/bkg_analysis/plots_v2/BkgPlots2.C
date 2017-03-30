{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABCD_BkgAnalysis.root");
    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMassNoPhi->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt->Draw();
    hjpsiPiPiMassNoPhi->SetLineColor(kRed);
    hjpsiPiPiMassNoPhi->Draw("same");
    hjpsiPiPiMassNoPhi_discard->SetFillColor( kRed);
    hjpsiPiPiMassNoPhi_discard->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hjpsiPiPiMassBaseSelAlt,"before Phi->KK removal","L");
    l->AddEntry(hjpsiPiPiMassNoPhi,"after Phi->KK removal","L");
    l->AddEntry(hjpsiPiPiMassNoPhi_discard, "Rejected events", "F");
    l->SetBorderSize(0);
    l->SetTextSize(0.025);
    l->Draw();
    c11->SaveAs("Bkg_MuOnia2012ABCD_MuMuPiPi_compare.png");
    f1->Close();
    
}
