{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("Bkg_B0ToPsiMuMu_0004.root");

    
    TCanvas *c16 = new TCanvas("c16","c16",1050,1050);
    Int_t bxmax=hKPiMass->GetXaxis()->FindBin(3.0);
    Int_t bxmin=hKPiMass->GetXaxis()->FindBin(0.0);
    hKPiMass->GetXaxis()->SetRange(bxmin,bxmax);
    hKPiMass->Draw();
    hKPiMass_noBs->SetLineColor(kRed);
    hKPiMass_noBs->Draw("same");
    TLegend *ll = new TLegend(.60,.60,.89,.73);
    ll->AddEntry(hKPiMass,"All entries","L");
    ll->AddEntry(hKPiMass_noBs,"no phi","L");
    ll->SetBorderSize(0);
    ll->SetTextSize(0.025);
    ll->Draw();
    c16->SaveAs("Bkg_B0_KPi_compare.png");
    f1->Close();
    
    TFile f2("Bkg_BpToPsiMuMu_0000.root");
    
    TCanvas *c26 = new TCanvas("c26","c26",1050,1050);
    Int_t bxmax=hKPiMass->GetXaxis()->FindBin(3.0);
    Int_t bxmin=hKPiMass->GetXaxis()->FindBin(0.0);
    hKPiMass->GetXaxis()->SetRange(bxmin,bxmax);
    hKPiMass->Draw();
    hKPiMass_noBs->SetLineColor(kRed);
    hKPiMass_noBs->Draw("same");
    ll->Draw();
    c26->SaveAs("Bkg_Bp_KPi_compare.png");
    f2->Close();

    
    TFile f3("Bkg_BsToPsiMuMu_0001.root");
    
    TCanvas *c36 = new TCanvas("c36","c36",1050,1050);
    Int_t bxmax=hKPiMass->GetXaxis()->FindBin(3.0);
    Int_t bxmin=hKPiMass->GetXaxis()->FindBin(0.0);
    hKPiMass->GetXaxis()->SetRange(bxmin,bxmax);
    hKPiMass->Draw();
    hKPiMass_noBs->SetLineColor(kRed);
    hKPiMass_noBs->Draw("same");
    ll->Draw();
    c36->SaveAs("Bkg_Bs_KPi_compare.png");
    f3->Close();
    
    
    TFile f4("Bkg_LambdaBToPsiMuMu.root");
    
    TCanvas *c46 = new TCanvas("c46","c46",1050,1050);
    Int_t bxmax=hKPiMass->GetXaxis()->FindBin(3.0);
    Int_t bxmin=hKPiMass->GetXaxis()->FindBin(0.0);
    hKPiMass->GetXaxis()->SetRange(bxmin,bxmax);
    hKPiMass->Draw();
    hKPiMass_noBs->SetLineColor(kRed);
    hKPiMass_noBs->Draw("same");
    ll->Draw();
    c46->SaveAs("Bkg_LambdaB_KPi_compare.png");
    f4->Close();
    
    

}
