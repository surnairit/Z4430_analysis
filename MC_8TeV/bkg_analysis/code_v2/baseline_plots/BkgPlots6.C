{
    
    TFile f4("Bkg_LambdaBToPsiMuMu.root");
    TCanvas *c41 = new TCanvas("c41","c41",1050,1050);
    //hjpsiKPiMassBaseSelAlt_hard->SetMaximum(17000);
    hjpsiKProtonMassBaseSelAlt->SetMinimum(1);
    hjpsiKProtonMassBaseSelAlt->Draw();
    hjpsiKPiMassBaseSelAlt->SetLineColor(kBlack);
    hjpsiKPiMassBaseSelAlt->Draw("same");
    hjpsiKPiMass_LambdaBpeak->SetLineColor(kRed);
    hjpsiKPiMass_LambdaBpeak->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hjpsiKProtonMassBaseSelAlt,"JpsiKProton whole spectrum","L");
    l->AddEntry(hjpsiKPiMassBaseSelAlt,"JpsiKPi whole spectrum","L");
    l->AddEntry(hjpsiKPiMass_LambdaBpeak,"JpsiKPi under LambdaB peak(5.6-5.66)GeV","L");
    l->Draw();
    //c41->SaveAs("Bkg_LambdaB_MuMuPiK_underLambdaB_compare.png");
    //gPad-> SetLogy();
    //c41->SaveAs("Bkg_LambdaB_MuMuPiK_underLambdaB_compare_log.png");


}
