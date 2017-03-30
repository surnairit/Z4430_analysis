{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("Bkg_B0ToPsiMuMu_0004.root");
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
    c11->SaveAs("Bkg_B0_MuMuPiPi_noK892_compare.png");
    f1->Close();
    
    TFile f2("Bkg_BpToPsiMuMu_0000.root");
    TCanvas *c21 = new TCanvas("c21","c21",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMass_noK892->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt->Draw();
    hjpsiPiPiMass_noK892->SetLineColor(kRed);
    hjpsiPiPiMass_noK892->Draw("same");
    hjpsiPiPiMass_noK892_discard->SetFillColor( kRed);
    hjpsiPiPiMass_noK892_discard->Draw("same");
    l->Draw();
    c21->SaveAs("Bkg_Bp_MuMuPiPi_noK892_compare.png");
    f2->Close();


    TFile f3("Bkg_BsToPsiMuMu_0001.root");
    TCanvas *c31 = new TCanvas("c31","c31",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMass_noK892->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt->Draw();
    hjpsiPiPiMass_noK892->SetLineColor(kRed);
    hjpsiPiPiMass_noK892->Draw("same");
    hjpsiPiPiMass_noK892_discard->SetFillColor( kRed);
    hjpsiPiPiMass_noK892_discard->Draw("same");
    l->Draw();
    c31->SaveAs("Bkg_Bs_MuMuPiPi_noK892_compare.png");
    f3->Close();

    TFile f4("Bkg_LambdaBToPsiMuMu.root");
    TCanvas *c41 = new TCanvas("c41","c41",1050,1050);
    //hjpsiKPiMassBaseSelAlt->SetMaximum(17000);
    hjpsiPiPiMassBaseSelAlt->SetMinimum(0.0);
    //hjpsiKPiMassNoPhi->SetMaximum(17000);
    hjpsiPiPiMass_noK892->SetMinimum(0.0);
    hjpsiPiPiMassBaseSelAlt->Draw();
    hjpsiPiPiMass_noK892->SetLineColor(kRed);
    hjpsiPiPiMass_noK892->Draw("same");
    hjpsiPiPiMass_noK892_discard->SetFillColor( kRed);
    hjpsiPiPiMass_noK892_discard->Draw("same");
    l->Draw();
    c41->SaveAs("Bkg_LambdaB_MuMuPiPi_noK892_compare.png");


}
