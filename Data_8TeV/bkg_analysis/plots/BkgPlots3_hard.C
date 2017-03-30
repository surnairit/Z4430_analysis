{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABCD_BkgAnalysis.root");
    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt_hard->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMass_noK892_hard->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt_hard->Draw();
    hjpsiPiPiMass_noK892_hard->SetLineColor(kRed);
    hjpsiPiPiMass_noK892_hard->Draw("same");
    hjpsiPiPiMass_noK892_discard_hard->SetFillColor( kRed);
    hjpsiPiPiMass_noK892_discard_hard->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hjpsiPiPiMassBaseSelAlt_hard,"before K*(892) removal","L");
    l->AddEntry(hjpsiPiPiMass_noK892_hard,"after K*(892) removal","L");
    l->AddEntry(hjpsiPiPiMass_noK892_discard_hard, "Rejected events", "F");
    l->SetBorderSize(0);
    l->SetTextSize(0.025);
    l->Draw();
    c11->SaveAs("Bkg_MuOnia2012ABCD_MuMuPiPi_noK892_compare_hard.png");
    f1->Close();
    
}
