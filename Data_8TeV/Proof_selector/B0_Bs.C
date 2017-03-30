{
    TFile f1("MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls.root");
    
    TCanvas *c1 = new TCanvas("c1","c1",900,700);
    gStyle->SetOptStat(110);
    c1->Divide(2,2);
    
    c1->cd(1);
    hKKMassB0->Draw();
    hKKMassB0->SetTitle("Two Track invariant mass with K Hypothesis");
    hKKMassB0->GetXaxis()->SetTitle("m(KK) [GeV]");
    hKKMassB0->GetXaxis()->SetRangeUser(0.95,1.2);
    TLine *l1 = new TLine(1.01,0,1.01,2800);
    l1->SetLineColor(2);
    l1->SetLineStyle(2);
    l1->Draw();
    TLine *l2 = new TLine(1.03,0,1.03,2800);
    l2->SetLineColor(2);
    l2->SetLineStyle(2);
    l2->Draw();
    
    
    c1->cd(2);
    hJpsiPhiToKKMass->Draw();
    hJpsiPhiToKKMass->SetTitle("B_{s} Peak : m(J/#psiKK) in #Phi to KK region");
    hJpsiPhiToKKMass->GetXaxis()->SetTitle("m(J/#psiKK) [GeV]");
    hJpsiPhiToKKMass->GetXaxis()->SetRangeUser(5.1,6.0);
    TLine *l1 = new TLine(5.332,0,5.332,800);
    l1->SetLineColor(2);
    l1->SetLineStyle(2);
    l1->Draw();
    TLine *l2 = new TLine(5.4,0,5.4,800);
    l2->SetLineColor(2);
    l2->SetLineStyle(2);
    l2->Draw();
    
    
    c1->cd(3);
    gPad->SetLogy();
    hjpsiKPiMassSelAltZoom->SetMinimum(10);
    hjpsiKPiMassSelAltZoom->Draw();
    hjpsiKPiMassSelAltZoom->SetTitle("J/#psiK#pi Mass");
    hjpsiKPiMassSelAltZoom->GetXaxis()->SetTitle("m(J/#psiK#pi) [GeV]");
    hjpsiKPiMassBs->Draw("same");
    hjpsiKPiMassBs->SetLineColor(2);
    
    leg = new TLegend(0.57,0.39,0.86,0.60);
    leg->AddEntry(hjpsiKPiMassSelAltZoom,"J/#psiK#pi Mass : All","l");
    leg->AddEntry(hjpsiKPiMassBs,"J/#psiK#pi Mass in B_{s} peak region","l");
    leg->Draw();

    
    c1->cd(4);
    hjpsiKPiMassSelAltZoom->SetMinimum(0);
    hjpsiKPiMassSelAltZoom->Draw();
    hjpsiKPiMassSelAltZoom->SetTitle("J/#psiK#pi Mass");
    hjpsiKPiMassSelAltZoom->GetXaxis()->SetTitle("m(J/#psiK#pi) [GeV]");
    hjpsiKPiMassBs->Draw("same");
    hjpsiKPiMassBs->SetLineColor(2);
    
    leg = new TLegend(0.57,0.39,0.86,0.60);
    leg->AddEntry(hjpsiKPiMassSelAltZoom,"J/#psiK#pi Mass : All","l");
    leg->AddEntry(hjpsiKPiMassBs,"J/#psiK#pi Mass in B_{s} peak region","l");
    leg->Draw();
    

    
}