{

    TLegend *l = new TLegend(.7,.75,.89,.89);

    TFile f1("Bkg_B0ToPsiMuMu_0004.root");

    
    TCanvas *c11 = new TCanvas("c11","c11",1050,1050);
    hjpsiKKMassBaseSelAlt->SetMinimum(1);
    hjpsiKKMassBaseSelAlt->Draw();
    hjpsiKKMassNoPhi->SetLineColor(kRed);
    hjpsiKKMassNoPhi->Draw("same");
    hjpsiKKMassNoPhi_discard->SetFillColor( kRed);
    hjpsiKKMassNoPhi_discard->Draw("same");
    
    TLegend *l = new TLegend(.60,.60,.89,.73);
    l->AddEntry(hjpsiKKMassBaseSelAlt,"before Phi->KK removal","L");
    l->AddEntry(hjpsiKKMassNoPhi,"after Phi->KK removal","L");
    l->AddEntry(hjpsiKKMassNoPhi_discard, "Rejected events", "F");
    l->SetBorderSize(0);
    l->SetTextSize(0.025);
    l->Draw();
    c11->SaveAs("Bkg_B0_MuMuKK_compare.png");
    gPad-> SetLogy();
    c11->SaveAs("Bkg_B0_MuMuKK_compare_log.png");
    
    TCanvas *c12 = new TCanvas("c12","c12",1050,1050);
    Int_t bxmax=hJpsiKK_KK->GetYaxis()->FindBin(1.5);
    Int_t bxmin=hJpsiKK_KK->GetYaxis()->FindBin(0.9);
    hJpsiKK_KK->GetYaxis()->SetRange(bxmin,bxmax);
    hJpsiKK_KK->Draw("colz");
    TLine *line1 = new TLine(5.332,1.01,5.332,1.03);
    TLine *line2 = new TLine(5.4,1.01,5.4,1.03);
    TLine *line3 = new TLine(5.332,1.01,5.4,1.01);
    TLine *line4 = new TLine(5.332,1.03,5.4,1.03);
    line1->SetLineColor(kRed);
    line2->SetLineColor(kRed);
    line3->SetLineColor(kRed);
    line4->SetLineColor(kRed);
    line1->SetLineWidth(4);
    line2->SetLineWidth(4);
    line3->SetLineWidth(4);
    line4->SetLineWidth(4);
    line1->Draw();
    line2->Draw();
    line3->Draw();
    line4->Draw();
    c12->SaveAs("Bkg_B0_JpsiKK_KK.png");

    TLegend *ll = new TLegend(.60,.60,.89,.73);
    ll->AddEntry(hPiPiMass,"before Phi->KK removal","L");
    ll->AddEntry(hPiPiMass_noBs,"after Phi->KK removal","L");
    ll->SetBorderSize(0);
    ll->SetTextSize(0.025);


    TCanvas *c13 = new TCanvas("c13","c13",1050,1050);
    Int_t pxmax=hPiPiMass->GetXaxis()->FindBin(3.0);
    Int_t pxmin=hPiPiMass->GetXaxis()->FindBin(0.0);
    hPiPiMass->GetXaxis()->SetRange(pxmin,pxmax);
    hPiPiMass->Draw();
    hPiPiMass_noBs->SetLineColor(kRed);
    hPiPiMass_noBs->Draw("same");
    ll->Draw();
    c13->SaveAs("Bkg_B0_PiPiMass_compare.png");

    f1->Close();

    
    TFile f2("Bkg_BpToPsiMuMu_0000.root");
    
    TCanvas *c21 = new TCanvas("c21","c21",1050,1050);
    hjpsiKKMassBaseSelAlt->SetMinimum(1);
    hjpsiKKMassNoPhi->SetMinimum(1);
    hjpsiKKMassBaseSelAlt->Draw();
    hjpsiKKMassNoPhi->SetLineColor(kRed);
    hjpsiKKMassNoPhi->Draw("same");
    hjpsiKKMassNoPhi_discard->SetFillColor( kRed);
    hjpsiKKMassNoPhi_discard->Draw("same");
    l->Draw();
    c21->SaveAs("Bkg_Bp_MuMuKK_compare.png");
    gPad-> SetLogy();
    c21->SaveAs("Bkg_Bp_MuMuKK_compare_log.png");
    
    TCanvas *c22 = new TCanvas("c22","c22",1050,1050);
    hJpsiKK_KK->GetYaxis()->SetRange(bxmin,bxmax);
    hJpsiKK_KK->Draw("colz");
    line1->Draw();
    line2->Draw();
    line3->Draw();
    line4->Draw();
    c22->SaveAs("Bkg_Bp_JpsiKK_KK.png");

    TCanvas *c23 = new TCanvas("c23","c23",1050,1050);
    hPiPiMass->GetXaxis()->SetRange(pxmin,pxmax);
    hPiPiMass->Draw();
    hPiPiMass_noBs->SetLineColor(kRed);
    hPiPiMass_noBs->Draw("same");
    ll->Draw();
    c23->SaveAs("Bkg_Bp_PiPiMass_compare.png");


    f2->Close();

    
    TFile f3("Bkg_BsToPsiMuMu_0001.root");
    
    TCanvas *c31 = new TCanvas("c31","c31",1050,1050);
    hjpsiKKMassBaseSelAlt->SetMinimum(1);
    hjpsiKKMassNoPhi->SetMinimum(1);
    hjpsiKKMassBaseSelAlt->Draw();
    hjpsiKKMassNoPhi->SetLineColor(kRed);
    hjpsiKKMassNoPhi->Draw("same");
    hjpsiKKMassNoPhi_discard->SetFillColor( kRed);
    hjpsiKKMassNoPhi_discard->Draw("same");
    l->Draw();
    c31->SaveAs("Bkg_Bs_MuMuKK_compare.png");
    gPad-> SetLogy();
    c31->SaveAs("Bkg_Bs_MuMuKK_compare_log.png");
    
    TCanvas *c32 = new TCanvas("c32","c32",1050,1050);
    hJpsiKK_KK->GetYaxis()->SetRange(bxmin,bxmax);
    hJpsiKK_KK->Draw("colz");
    line1->Draw();
    line2->Draw();
    line3->Draw();
    line4->Draw();
    c32->SaveAs("Bkg_Bs_JpsiKK_KK.png");

    TCanvas *c33 = new TCanvas("c33","c33",1050,1050);
    hPiPiMass->GetXaxis()->SetRange(pxmin,pxmax);
    hPiPiMass->Draw();
    hPiPiMass_noBs->SetLineColor(kRed);
    hPiPiMass_noBs->Draw("same");
    ll->Draw();
    c33->SaveAs("Bkg_Bs_PiPiMass_compare.png");

    f3->Close();

    
    TFile f4("Bkg_LambdaBToPsiMuMu.root");
    
    TCanvas *c41 = new TCanvas("c41","c41",1050,1050);
    hjpsiKKMassBaseSelAlt->SetMinimum(1);
    hjpsiKKMassNoPhi->SetMinimum(1);
    hjpsiKKMassBaseSelAlt->Draw();
    hjpsiKKMassNoPhi->SetLineColor(kRed);
    hjpsiKKMassNoPhi->Draw("same");
    hjpsiKKMassNoPhi_discard->SetFillColor( kRed);
    hjpsiKKMassNoPhi_discard->Draw("same");
    l->Draw();
    c41->SaveAs("Bkg_LambdaB_MuMuKK_compare.png");
    gPad-> SetLogy();
    c41->SaveAs("Bkg_LambdaB_MuMuKK_compare_log.png");
    
    TCanvas *c42 = new TCanvas("c42","c42",1050,1050);
    hJpsiKK_KK->GetYaxis()->SetRange(bxmin,bxmax);
    hJpsiKK_KK->Draw("colz");
    line1->Draw();
    line2->Draw();
    line3->Draw();
    line4->Draw();
    c42->SaveAs("Bkg_LambdaB_JpsiKK_KK.png");

    TCanvas *c43 = new TCanvas("c43","c43",1050,1050);
    hPiPiMass->GetXaxis()->SetRange(pxmin,pxmax);
    hPiPiMass->Draw();
    hPiPiMass_noBs->SetLineColor(kRed);
    hPiPiMass_noBs->Draw("same");
    ll->Draw();
    c43->SaveAs("Bkg_LambdaB_PiPiMass_compare.png");

    
    f4->Close();
    

}
