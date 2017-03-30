{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Jan  4 12:20:47 2017) by ROOT version5.34/32
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",260,93,841,576);
   Canvas_1->Range(-1.25,-1068353,11.25,9615180);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *h_nB0 = new TH1F("h_nB0","h_nB0",10,0,10);
   h_nB0->SetBinContent(2,8136982);
   h_nB0->SetBinContent(3,961590);
   h_nB0->SetBinContent(4,429092);
   h_nB0->SetBinContent(5,285678);
   h_nB0->SetBinContent(6,167670);
   h_nB0->SetBinContent(7,121333);
   h_nB0->SetBinContent(8,84296);
   h_nB0->SetBinContent(9,63446);
   h_nB0->SetBinContent(10,46884);
   h_nB0->SetBinContent(11,212305);
   h_nB0->SetEntries(1.050928e+07);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h_nB0");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries =   1.050928e+07");
   text = ptstats->AddText("Mean  =  1.513");
   text = ptstats->AddText("RMS   =    1.3");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h_nB0->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h_nB0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_nB0->SetLineColor(ci);
   h_nB0->GetXaxis()->SetLabelFont(42);
   h_nB0->GetXaxis()->SetLabelSize(0.035);
   h_nB0->GetXaxis()->SetTitleSize(0.035);
   h_nB0->GetXaxis()->SetTitleFont(42);
   h_nB0->GetYaxis()->SetLabelFont(42);
   h_nB0->GetYaxis()->SetLabelSize(0.035);
   h_nB0->GetYaxis()->SetTitleSize(0.035);
   h_nB0->GetYaxis()->SetTitleFont(42);
   h_nB0->GetZaxis()->SetLabelFont(42);
   h_nB0->GetZaxis()->SetLabelSize(0.035);
   h_nB0->GetZaxis()->SetTitleSize(0.035);
   h_nB0->GetZaxis()->SetTitleFont(42);
   h_nB0->Draw("E1");
   
   TPaveText *pt = new TPaveText(0.4466075,0.94,0.5533925,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("h_nB0");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
