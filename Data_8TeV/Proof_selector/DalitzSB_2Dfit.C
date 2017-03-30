#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif


using namespace RooFit ;
DalitzSB_2Dfit()
{//main
    
    TFile *f0 = new TFile("MuMuPiK_Jpsi_MuOnia2012B_output_small_ntpls.root");
    
    TH2F *fit_histoDalitzSB;
    TH1F *fit_histoProj_m2KPi_SB;
    
    TCanvas *c1 = new TCanvas ("c1","c1",570,400);
    fit_histoProj_m2KPi_SB = (TH1F*)f0->Get("hDalitzProj_m2KPi_sideband");
//    fit_histoProj_m2KPi_SB->Draw();
    
    RooDataHist *dh_m2KPi_SB = new RooDataHist ("dh_m2KPi_SB","dh_m2KPi_SB",RooArgSet(),Import(*fit_histoProj_m2KPi_SB));
    
} //main