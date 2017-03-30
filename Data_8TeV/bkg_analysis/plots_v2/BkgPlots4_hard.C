{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("MuMuPiK_Jpsi_MuOnia2012ABCD_BkgAnalysis.root");

    
    TCanvas *c16 = new TCanvas("c16","c16",1050,1050);
    Int_t bxmax=hKPiMass->GetXaxis()->FindBin(3.0);
    Int_t bxmin=hKPiMass->GetXaxis()->FindBin(0.0);
    hKPiMass_hard->GetXaxis()->SetRange(bxmin,bxmax);
    hKPiMass_hard->Draw();
    hKPiMass_noBs_hard->SetLineColor(kRed);
    hKPiMass_noBs_hard->Draw("same");
    TLegend *ll = new TLegend(.60,.60,.89,.73);
    ll->AddEntry(hKPiMass_hard,"All entries","L");
    ll->AddEntry(hKPiMass_noBs_hard,"no phi","L");
    ll->SetBorderSize(0);
    ll->SetTextSize(0.025);
    ll->Draw();
    c16->SaveAs("Bkg_MuOnia2012ABCD_KPi_compare_hard.png");
    f1->Close();
    
    
    

}
