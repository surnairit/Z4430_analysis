#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif


using namespace RooFit ;
B0_fit_trial()
{ // main

  TFile *f0 = new TFile("MuMuPiK_Jpsi_MuOnia2012ABCD_output_small_ntpls_jpsi_eta_cut.root");
  ofstream outfile;
  outfile.open("purity_Jpsi_MuOnia2012ABCD_etacut_test.txt");
  outfile<<"cut_val	nsig	nsig_err	nbkg	nbkg_err	S/(S+B) 	sig_err"<<endl;


  RooRealVar Bzero_mass("Bzero_mass","M (GeV/c^{2})",5.15,5.40) ;

//  RooRealVar Bzero_mass("Bzero_mass","M (GeV/c^{2})",5.2,5.35) ;
  int n_gr = 2;
  char datahist[100];
  char histname[100];
  char canvas[100];

  TH1F *histo[10];
  TCanvas* c[10];
  RooDataHist *dh[10];

  double x[10],y[10],x_err[10],y_err[10];

  int j = 1;

	double k = j;
	double cut=0.4+k*0.1;
//	double cut = k;
	sprintf(datahist,"dh%i",j);
        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuChi2_by_NDF%i",j+4);
	sprintf(canvas,"c%i",j);

//	histo[j]=(TH1F*)f0->Get(histname);
//	histo[j]=(TH1F*)f0->Get("hjpsiKPiMassSelAltZoom");
//	histo[j]=(TH1F*)f0->Get("hjpsiKPiMassSelAlt");
    histo[j]=(TH1F*)f0->Get("hjpsiKPiMassSelAlt_etacut_1sigma");
	c[j]= new TCanvas(canvas,canvas,570,400);
//	histo[j]->Draw();
	dh[j]= new RooDataHist(datahist,datahist,RooArgSet(Bzero_mass),Import(*histo[j]));


  // Print number of events in dataset
  dh[j]->Print();

  RooPlot* frame = Bzero_mass.frame(Title("M_{B^{0}}")) ;
  dh[j]->plotOn(frame) ;


  RooRealVar m("m","m",5.279,5.2421,5.3099);
  RooRealVar s("s","s",0.0105,0.01,0.015);
//  RooRealVar s("s","s",0.01,0.001,0.035);
  RooRealVar s2("s2","s2",0.03,0.0105,0.07);
//  RooRealVar s2("s2","s2",0.015,0.01,0.07);
  RooGaussian g1("g1","gaussian1",Bzero_mass,m,s);
  RooGaussian g2("g2","gaussian2",Bzero_mass,m,s2);
  RooRealVar frac("frac","frac",0.5,0.0,1.0); // 0.5,0.0,1.0 // 0.4,0.35,0.45
  RooAddPdf sig("sig","Total signal PDF",RooArgList(g1,g2),RooArgList(frac));
//  RooRealVar cs("cs","Slope of Polynomial", 0.0, -0.5, 0.5);
//  RooChebychev cheb("cheb","BG PDF for DeltaM",Bzero_mass , cs);
    RooRealVar c0("c0","c0",0.,-1.,1.);
    RooRealVar c1("c1","c1",0.,-1.,1.);
    RooRealVar c2("c2","c2",0.,-1.,1.);
    RooChebychev cheb("cheb","BG PDF for DeltaM",Bzero_mass,RooArgList(c0,c1,c2));
//    RooChebychev cheb("cheb","BG PDF for DeltaM",Bzero_mass,RooArgList(c0,c1));
  RooRealVar nsig("nsig","nsig",1000000,50000,1500000); // 10000,100,15000
  RooRealVar nbkg("nbkg","nbkg",300000,20000,5000000); // 3000,100,50000
  RooAddPdf total("total","Total signal PDF",RooArgList(sig,cheb),RooArgList(nsig,nbkg));

/*
RooRealVar mass("mass","Invariant mass",5.20,5.30) ;
RooRealVar width("width","B0 mass width",0.00027,"GeV");
RooRealVar mb0("mb0","B0 mass",5.2794,"GeV") ;
RooGaussian total("total","B0 sig PDF",mass,mb0,width);
*/


  total.fitTo(*dh[j]);
  total.plotOn(frame);
  total.paramOn(frame,Layout(0.6,0.9,0.9));
  
  total.plotOn(frame,Components(RooArgList(g1)), LineColor(kRed),LineStyle(2), LineWidth(4));
  total.plotOn(frame,Components(RooArgList(g2)), LineColor(kGreen),LineStyle(2), LineWidth(4));
  total.plotOn(frame,Components(RooArgList(cheb)), LineColor(kBlue),LineStyle(2), LineWidth(4));

 
  frame->Draw();

  double fitted_mean = m.getVal();
  double fitted_sigmalarge = s2.getVal();

//  double fitted_mean = 5.279;
//  double fitted_sigmalarge = 0.02;

  Bzero_mass.setRange("peak",fitted_mean-2.0*fitted_sigmalarge,fitted_mean+2.0*fitted_sigmalarge);

  RooAbsReal* peakBkgN = cheb.createIntegral(Bzero_mass,Bzero_mass,"peak");
  double bkg_integral =  peakBkgN->getVal();
  
  RooAbsReal* peakSigN = sig.createIntegral(Bzero_mass,Bzero_mass,"peak");
  double sig_integral =  peakSigN->getVal();


  RooArgSet* params = total.getVariables();
  RooRealVar* signal =(RooRealVar*) params->find("nsig");
  RooRealVar* bkgrnd =(RooRealVar*) params->find("nbkg");

  Double_t nsig_val_abs =  signal->getVal();
  Double_t nbkg_val_abs =  bkgrnd->getVal();


  double nbkg_val = bkg_integral*nbkg_val_abs;
  double nsig_val = sig_integral*nsig_val_abs;

  Double_t nsig_err =  signal->getError();
  Double_t nbkg_err =  bkgrnd->getError();

  double purity = nsig_val/(nsig_val+nbkg_val);
  double delsbys2 = (nsig_err/nsig_val)*(nsig_err/nsig_val);
  double dels2plusdelb2 = (nsig_err*nsig_err) + (nbkg_err*nbkg_err);
  double splusb2 = pow((nsig_val+nbkg_val),2); 
  double sig_error = purity*sqrt(delsbys2+ (dels2plusdelb2/splusb2) );

//  coutfile<<"cut_val	nsig	nsig_err	nbkg	nbkg_err	S/(S+RooRealVar mass(“mass”,”Invariant mass”,5.20,5.30) ;

  outfile<<cut<<"     "<<nsig_val<<"     "<<nsig_err<<"     "<<nbkg_val<<"     "<<nbkg_err<<"     "<<purity<<"     "<<sig_error<<endl;
  x[j] = cut;
  y[j] = purity;
  x_err[j]= 0.0;
//  y_err[j] = sig_error;
  y_err[j]= 0.0;

//  c->SaveAs("Nairit.png");


//  } // loop over cut opt variable

 outfile.close();

  TCanvas* c_purity = new TCanvas("purity","Purity",570,400);
  c_purity->SetGrid();
  TGraphErrors *gr = new TGraphErrors(n_gr,x,y,x_err,y_err);
  gr->Draw("AP*");
  gr->SetMarkerStyle(20);
//  gr->Fit("pol2");
  gr->SetTitle("Significance Jpsi eta cut");
  gr->GetXaxis()->SetTitle("jpsi eta cut ");
//  gr->SetTitle("purity as a Function of track Pt cut");
//  gr->GetXaxis()->SetTitle("track Pt cut ");
  gr->GetYaxis()->SetTitle("#frac{S}{(S+B)}");




} // main
