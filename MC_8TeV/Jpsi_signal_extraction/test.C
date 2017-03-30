{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Aug 19 18:58:20 2015) by ROOT version5.32/00
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",258,110,1163,665);
   Canvas_1->Range(5.1125,2.022694,5.4875,3.066805);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetLogy();
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *hjpsiKPiMassSelAltZoom = new TH1F("hjpsiKPiMassSelAltZoom","hjpsiKPiMassSel ALTERNATIVE ZOOM",30,5.15,5.45);
   hjpsiKPiMassSelAltZoom->SetBinContent(0,11207);
   hjpsiKPiMassSelAltZoom->SetBinContent(1,290);
   hjpsiKPiMassSelAltZoom->SetBinContent(2,288);
   hjpsiKPiMassSelAltZoom->SetBinContent(3,279);
   hjpsiKPiMassSelAltZoom->SetBinContent(4,336);
   hjpsiKPiMassSelAltZoom->SetBinContent(5,291);
   hjpsiKPiMassSelAltZoom->SetBinContent(6,287);
   hjpsiKPiMassSelAltZoom->SetBinContent(7,309);
   hjpsiKPiMassSelAltZoom->SetBinContent(8,323);
   hjpsiKPiMassSelAltZoom->SetBinContent(9,304);
   hjpsiKPiMassSelAltZoom->SetBinContent(10,322);
   hjpsiKPiMassSelAltZoom->SetBinContent(11,353);
   hjpsiKPiMassSelAltZoom->SetBinContent(12,371);
   hjpsiKPiMassSelAltZoom->SetBinContent(13,484);
   hjpsiKPiMassSelAltZoom->SetBinContent(14,469);
   hjpsiKPiMassSelAltZoom->SetBinContent(15,371);
   hjpsiKPiMassSelAltZoom->SetBinContent(16,348);
   hjpsiKPiMassSelAltZoom->SetBinContent(17,323);
   hjpsiKPiMassSelAltZoom->SetBinContent(18,297);
   hjpsiKPiMassSelAltZoom->SetBinContent(19,299);
   hjpsiKPiMassSelAltZoom->SetBinContent(20,279);
   hjpsiKPiMassSelAltZoom->SetBinContent(21,270);
   hjpsiKPiMassSelAltZoom->SetBinContent(22,279);
   hjpsiKPiMassSelAltZoom->SetBinContent(23,288);
   hjpsiKPiMassSelAltZoom->SetBinContent(24,299);
   hjpsiKPiMassSelAltZoom->SetBinContent(25,283);
   hjpsiKPiMassSelAltZoom->SetBinContent(26,268);
   hjpsiKPiMassSelAltZoom->SetBinContent(27,272);
   hjpsiKPiMassSelAltZoom->SetBinContent(28,278);
   hjpsiKPiMassSelAltZoom->SetBinContent(29,278);
   hjpsiKPiMassSelAltZoom->SetBinContent(30,275);
   hjpsiKPiMassSelAltZoom->SetBinContent(31,4427);
   hjpsiKPiMassSelAltZoom->SetEntries(25047);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("hjpsiKPiMassSelAltZoom");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 25047  ");
   text = ptstats->AddText("Mean  =  5.296");
   text = ptstats->AddText("RMS   = 0.08313");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hjpsiKPiMassSelAltZoom->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hjpsiKPiMassSelAltZoom);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   hjpsiKPiMassSelAltZoom->SetLineColor(ci);
   hjpsiKPiMassSelAltZoom->GetXaxis()->SetLabelFont(42);
   hjpsiKPiMassSelAltZoom->GetXaxis()->SetLabelSize(0.035);
   hjpsiKPiMassSelAltZoom->GetXaxis()->SetTitleSize(0.035);
   hjpsiKPiMassSelAltZoom->GetXaxis()->SetTitleFont(42);
   hjpsiKPiMassSelAltZoom->GetYaxis()->SetLabelFont(42);
   hjpsiKPiMassSelAltZoom->GetYaxis()->SetLabelSize(0.035);
   hjpsiKPiMassSelAltZoom->GetYaxis()->SetTitleSize(0.035);
   hjpsiKPiMassSelAltZoom->GetYaxis()->SetTitleFont(42);
   hjpsiKPiMassSelAltZoom->GetZaxis()->SetLabelFont(42);
   hjpsiKPiMassSelAltZoom->GetZaxis()->SetLabelSize(0.035);
   hjpsiKPiMassSelAltZoom->GetZaxis()->SetTitleSize(0.035);
   hjpsiKPiMassSelAltZoom->GetZaxis()->SetTitleFont(42);
   hjpsiKPiMassSelAltZoom->Draw("");
   
   TPaveText *pt = new TPaveText(0.2564918,0.9350908,0.7435082,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("hjpsiKPiMassSel ALTERNATIVE ZOOM");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
