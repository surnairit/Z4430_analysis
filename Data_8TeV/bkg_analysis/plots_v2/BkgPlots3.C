{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABCD_BkgAnalysis.root");
    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMass_noK892->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt->Draw();
    hjpsiPiPiMass_noK892->SetLineColor(kRed);
    hjpsiPiPiMass_noK892->Draw("same");
    hjpsiPiPiMass_noK892_discard->SetFillColor( kRed);
    hjpsiPiPiMass_noK892_discard->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hjpsiPiPiMassBaseSelAlt,"before K*(892) removal","L");
    l->AddEntry(hjpsiPiPiMass_noK892,"after K*(892) removal","L");
    l->AddEntry(hjpsiPiPiMass_noK892_discard, "Rejected events", "F");
    l->SetBorderSize(0);
    l->SetTextSize(0.025);
    l->Draw();
    c11->SaveAs("Bkg_MuOnia2012ABCD_MuMuPiPi_noK892_compare.png");
    f1->Close();
    
}
