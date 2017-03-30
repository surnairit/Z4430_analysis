{
    TFile *f0 = new TFile("MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_finalcuts_4.root");
    
    TH2F *hist_peak=(TH2F*)hDalitz_peak_bin3->Clone();
    TH2F *hist_sideband=(TH2F*)hDalitz_sideband_bin3->Clone();
    
//    hist_sideband->Scale(0.249);
    hist_sideband->Scale(0.9257);
    hist_peak->Add(hist_sideband,-1);
 //   hist_sideband->Add(hist_peak,-1);
    hist_peak->Draw("colz");
}