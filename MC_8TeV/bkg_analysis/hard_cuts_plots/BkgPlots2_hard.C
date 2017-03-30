{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("Bkg_B0ToPsiMuMu_0004.root");
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
    c11->SaveAs("Bkg_B0_MuMuPiPi_compare_hard.png");
    f1->Close();
    
    TFile f2("Bkg_BpToPsiMuMu_0000.root");
    TCanvas *c21 = new TCanvas("c21","c21",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt_hard->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMassNoPhi_hard->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt_hard->Draw();
    hjpsiPiPiMassNoPhi_hard->SetLineColor(kRed);
    hjpsiPiPiMassNoPhi_hard->Draw("same");
    hjpsiPiPiMassNoPhi_discard_hard->SetFillColor( kRed);
    hjpsiPiPiMassNoPhi_discard_hard->Draw("same");
    l->Draw();
    c21->SaveAs("Bkg_Bp_MuMuPiPi_compare_hard.png");
    f2->Close();


    TFile f3("Bkg_BsToPsiMuMu_0001.root");
    TCanvas *c31 = new TCanvas("c31","c31",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt_hard->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMassNoPhi_hard->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt_hard->Draw();
    hjpsiPiPiMassNoPhi_hard->SetLineColor(kRed);
    hjpsiPiPiMassNoPhi_hard->Draw("same");
    hjpsiPiPiMassNoPhi_discard_hard->SetFillColor( kRed);
    hjpsiPiPiMassNoPhi_discard_hard->Draw("same");
    l->Draw();
    c31->SaveAs("Bkg_Bs_MuMuPiPi_compare_hard.png");
    f3->Close();

    TFile f4("Bkg_LambdaBToPsiMuMu.root");
    TCanvas *c41 = new TCanvas("c41","c41",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt_hard->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMassNoPhi_hard->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt_hard->Draw();
    hjpsiPiPiMassNoPhi_hard->SetLineColor(kRed);
    hjpsiPiPiMassNoPhi_hard->Draw("same");
    hjpsiPiPiMassNoPhi_discard_hard->SetFillColor( kRed);
    hjpsiPiPiMassNoPhi_discard_hard->Draw("same");
    l->Draw();
    c41->SaveAs("Bkg_LambdaB_MuMuPiPi_compare_hard.png");


}
