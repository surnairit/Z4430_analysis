{
    
    TFile f4("Bkg_LambdaBToPsiMuMu.root");
    TCanvas *c41 = new TCanvas("c41","c41",1050,1050);
    //hjpsiKPiMassBaseSelAlt_hard->SetMaximum(17000);
    hjpsiKProtonMassBaseSelAlt_hard->SetMinimum(1);
    hjpsiKProtonMassBaseSelAlt_hard->Draw();
    hjpsiKPiMassBaseSelAlt_hard->SetLineColor(kBlack);
    hjpsiKPiMassBaseSelAlt_hard->Draw("same");
    hjpsiKPiMass_LambdaBpeak_hard->SetLineColor(kRed);
    hjpsiKPiMass_LambdaBpeak_hard->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hjpsiKProtonMassBaseSelAlt_hard,"JpsiKProton whole spectrum","L");
    l->AddEntry(hjpsiKPiMassBaseSelAlt_hard,"JpsiKPi whole spectrum","L");
    l->AddEntry(hjpsiKPiMass_LambdaBpeak_hard,"under LambdaB peak(5.6-5.66)GeV","L");
    l->Draw();
    //c41->SaveAs("Bkg_LambdaB_MuMuPiK_underLambdaB_compare_hard.png");
    //gPad-> SetLogy();
    //c41->SaveAs("Bkg_LambdaB_MuMuPiK_underLambdaB_compare_log_hard.png");


}
