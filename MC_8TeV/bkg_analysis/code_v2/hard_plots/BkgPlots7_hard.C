{
    
    TFile f4("Bkg_LambdaBToPsiMuMu.root");
    TCanvas *c41 = new TCanvas("c41","c41",1050,1050);
    Int_t pxmax=hKProtonMass_LambdaBpeak_hard->GetXaxis()->FindBin(2.6);
    Int_t pxmin=hKProtonMass_LambdaBpeak_hard->GetXaxis()->FindBin(0.5);
    hKProtonMass_LambdaBpeak_hard->GetXaxis()->SetRange(pxmin,pxmax);
    hKProtonMass_LambdaBpeak_hard->SetMinimum(1);
    hKProtonMass_LambdaBpeak_hard->Draw();
    hKPiMass_LambdaBpeak_hard->SetLineColor(kRed);
    hKPiMass_LambdaBpeak_hard->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hKProtonMass_LambdaBpeak_hard,"KProton under LambdaB peak(5.6-5.66)GeV","L");
    l->AddEntry(hKPiMass_LambdaBpeak_hard,"KPi under LambdaB peak(5.6-5.66)GeV","L");
    l->Draw();
    //c41->SaveAs("Bkg_LambdaB_MuMuPiK_underLambdaB_compare.png");
    //gPad-> SetLogy();
    //c41->SaveAs("Bkg_LambdaB_MuMuPiK_underLambdaB_compare_log.png");


}
