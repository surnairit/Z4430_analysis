#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif


using namespace RooFit ;
Jpsi_fit_eta_trial()
{ // main

  TFile *f0 = new TFile("MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_jpsi_eta.root");
  ofstream outfile;
//  outfile.open("Jpsi_Mass_etabins_MuOnia2012ABCD_test.txt");
  outfile.open("Jpsi_Mass_total_MuOnia2012ABCD_sel.txt");
  outfile<<"eta_bin         mean        sigma1          n1      sigma2          n2      sigma_eff"<<endl;


  RooRealVar Jpsi_mass("Jpsi_mass","M (GeV/c^{2})",2.9,3.28) ;

  int n_gr = 2;
  char datahist[100];
  char histname[100];
  char canvas[100];

  TH1F *histo[10];
  TCanvas* c[10];
  RooDataHist *dh[10];

  double x[10],y[10],x_err[10],y_err[10];

  int j = 8;

	double k = j;
	double etarange = -2.1+k*0.2;
    
	sprintf(datahist,"dh%i",j);
        sprintf(histname,"hjpsiMass_eta_bin%i",j);
	sprintf(canvas,"c%i",j);

//	histo[j]=(TH1F*)f0->Get(histname);
    histo[j]=(TH1F*)f0->Get("hjpsiMass_sel");
	c[j]= new TCanvas(canvas,canvas,956,709);
	dh[j]= new RooDataHist(datahist,datahist,RooArgSet(Jpsi_mass),Import(*histo[j]));


  // Print number of events in dataset
  dh[j]->Print();

  RooPlot* frame = Jpsi_mass.frame(Title("M_{J/#psi}")) ;
//  dh[j]->plotOn(frame, Binning(20)) ;
  dh[j]->plotOn(frame) ;

  RooRealVar m("m","m",3.097,3.09,3.098);
  RooRealVar s1("s1","s1",0.0105,0.01,0.05);
  RooRealVar s2("s2","s2",0.0105,0.01,0.07);
  RooGaussian g1("g1","gaussian1",Jpsi_mass,m,s1);
  RooGaussian g2("g2","gaussian2",Jpsi_mass,m,s2);
  RooRealVar frac("frac","frac",0.5,0.0,1.0); // 0.5,0.0,1.0 // 0.4,0.35,0.45
//  RooAddPdf total("total","Total signal PDF",RooArgList(g1,g2),RooArgList(frac));
    
  RooRealVar ng1("ng1","ng1",400000,1000,100000000); // 400000,1000,1000000
  RooRealVar ng2("ng2","ng2",400000,1000,100000000); // 400000,1000,1000000
  RooAddPdf total("total","Total signal PDF",RooArgList(g1,g2),RooArgList(ng1,ng2));



  total.fitTo(*dh[j]);
  total.plotOn(frame);
  total.paramOn(frame,Layout(0.6,0.9,0.9));
  
  total.plotOn(frame,Components(RooArgList(g1)), LineColor(kRed),LineStyle(2), LineWidth(4));
  total.plotOn(frame,Components(RooArgList(g2)), LineColor(kGreen),LineStyle(2), LineWidth(4));

  frame->Draw();


  double fitted_mean = m.getVal();
  double fitted_sigma1 = s1.getVal();
  double fitted_sigma2 = s2.getVal();
    
  double fitted_num1 = ng1.getVal();
  double fitted_num2 = ng2.getVal();
    
  double sigma_eff = (fitted_sigma1*fitted_num1 + fitted_sigma2*fitted_num2)/(fitted_num1+fitted_num2);
    
  outfile<<etarange<<"to"<<etarange+0.2<<"     "<<fitted_mean<<"     "<<fitted_sigma1<<"     "<<fitted_num1<<"     "<<fitted_sigma2<<"     "<<fitted_num2<<"    "<<sigma_eff<<endl;
    



 outfile.close();


} // main
