/*
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TTree.h"
#include "TH1D.h"
#include "TRandom.h"
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

using namespace RooFit ;
*/

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

using namespace RooFit ;
B0_fit_cut_opt_MuDz()
{ // main
//  TCanvas* c = new TCanvas("c","test",570,400);
//  TFile *f0 = new TFile("psi2spipi_cut_opt_trial.root");

  TFile *f0 = new TFile("MuMuPiK_Jpsi_output_new_comb_MuDz.root");
  ofstream outfile;
  outfile.open("purity_MuDz.txt");
  outfile<<"cut_val	nsig	nsig_err	nbkg	nbkg_err	S/(S+B) 	sig_err"<<endl;
 
//  TFile *f0 = new TFile("psi2spipi_test.root");

  // Declare observable
  RooRealVar Bzero_mass("Bzero_mass","M (GeV/c^{2})",5.15,5.40) ;

  int n_gr = 30;
  char datahist[100];
  char histname[100];
  char canvas[100];

  TH1F *histo[30];
  TCanvas* c[30];
  RooDataHist *dh[30];

//  int n_gr = 23;
  double x[30],y[30],x_err[30],y_err[30];

  for (int j=0;j<n_gr;j++) { // loop over cut opt variable

	double k = j;
//	double cut=1.8+k/10.0; 
	double cut = k+1;
	sprintf(datahist,"dh%i",j+1);
        sprintf(histname,"hjpsiKPiMassSelAltZoom_MuDz%i",j+1);
	sprintf(canvas,"c%i",j+1);

	histo[j]=(TH1F*)f0->Get(histname);
	c[j]= new TCanvas(canvas,canvas,570,400);
//	histo[j]->Draw();
	dh[j]= new RooDataHist(datahist,datahist,RooArgSet(Bzero_mass),Import(*histo[j]));


  // Print number of events in dataset
  dh[j]->Print();

  RooPlot* frame = Bzero_mass.frame(Title("M_{B^{0}}")) ;
  dh[j]->plotOn(frame) ;


  RooRealVar m("m","m",5.279,5.2421,5.3099);
  RooRealVar s("s","s",0.0105,0.005,0.012);
//  RooRealVar s("s","s",0.01,0.001,0.035);
  RooRealVar s2("s2","s2",0.03,0.01,0.039);
//  RooRealVar s2("s2","s2",0.015,0.01,0.07);
  RooGaussian g1("g1","gaussian1",Bzero_mass,m,s);
  RooGaussian g2("g2","gaussian2",Bzero_mass,m,s2);
  RooRealVar frac("frac","frac",0.5,0.0,1.0);
  RooAddPdf sig("sig","Total signal PDF",RooArgList(g1,g2),RooArgList(frac));
  RooRealVar cs("cs","Slope of Polynomial", 0.0, -0.5, 0.5);
  RooChebychev cheb("cheb","BG PDF for DeltaM",Bzero_mass , cs);
  RooRealVar nsig("nsig","nsig",10000,800,15000);
  RooRealVar nbkg("nbkg","nbkg",3000,100,50000);
  RooAddPdf total("total","Total signal PDF",RooArgList(sig,cheb),RooArgList(nsig,nbkg));

  total.fitTo(*dh[j]);
  total.plotOn(frame);
  total.paramOn(frame,Layout(0.6,0.9,0.9));
  
  total.plotOn(frame,Components(RooArgList(g1)), LineColor(kRed),LineStyle(2), LineWidth(4));
  total.plotOn(frame,Components(RooArgList(g2)), LineColor(kGreen),LineStyle(2), LineWidth(4));
  total.plotOn(frame,Components(RooArgList(cheb)), LineColor(kBlue),LineStyle(2), LineWidth(4));

 
  frame->Draw();

//  double fitted_mean = 5.279;
//  double fitted_sigmalarge = 0.02;

  double fitted_mean = m.getVal();
  double fitted_sigmalarge = s2.getVal();

  Bzero_mass.setRange("peak",fitted_mean-2.0*fitted_sigmalarge,fitted_mean+2.0*fitted_sigmalarge);

  RooAbsReal* peakBkgN = cheb.createIntegral(Bzero_mass,Bzero_mass,"peak");
  double bkg_integral =  peakBkgN->getVal();
  
  RooAbsReal* peakSigN = sig.createIntegral(Bzero_mass,Bzero_mass,"peak");
  double sig_integral =  peakSigN->getVal();


  RooArgSet* params = total.getVariables();
  RooRealVar* signal =(RooRealVar*) params->find("nsig");
  RooRealVar* bkgrnd =(RooRealVar*) params->find("nbkg");


/*
  Double_t nsig_val =  signal->getVal();
  Double_t nbkg_val =  bkgrnd->getVal();

  Double_t nsig_err =  signal->getError();
  Double_t nbkg_err =  bkgrnd->getError();
*/

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


//  coutfile<<"cut_val	nsig	nsig_err	nbkg	nbkg_err	S/(S+B) 	sig_err"<<endl;
  outfile<<cut<<"     "<<nsig_val<<"     "<<nsig_err<<"     "<<nbkg_val<<"     "<<nbkg_err<<"     "<<purity<<"     "<<sig_error<<endl;
  x[j] = cut;
  y[j] = purity;
  x_err[j]= 0.0;
//  y_err[j] = sig_error;
  y_err[j]= 0.0;

//  c->SaveAs("Nairit.png");


  } // loop over cut opt variable

 outfile.close();

  TCanvas* c_purity = new TCanvas("purity","Purity",570,400);
  c_purity->SetGrid();
  TGraphErrors *gr = new TGraphErrors(n_gr,x,y,x_err,y_err);
  gr->Draw("AP*");
  gr->SetMarkerStyle(20);
//  gr->Fit("pol2");
//  gr->SetTitle("Significance as a Function of ChiSquared/NDoF cut");
//  gr->GetXaxis()->SetTitle("ChiSquared/NDoF cut ");
  gr->SetTitle("B0 purity as a Function of Mu Dz cut");
  gr->GetXaxis()->SetTitle("Mu Dz cut ");
  gr->GetYaxis()->SetTitle("#frac{S}{(S+B)}");
  c_purity->SaveAs("purity_MuDz.pdf");

} // main

