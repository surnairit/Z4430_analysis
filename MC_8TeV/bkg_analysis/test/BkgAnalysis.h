//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Sep 27 15:12:53 2016 by ROOT version 5.32/00
// from TTree Z_data/Z(4430) Data
// found on file: /lustre/cms/store/user/lecriste/june2016/B0ToPsiMuMu_2MuPtEtaFilter_8TeV-pythia6-evtgen/crab_official_MC_B0ToPsiMuMu_nB0/160529_225236/officialBdToPsiMuMu_noPtEtaCut_MuMuPiKPAT_ntpl_.root
//////////////////////////////////////////////////////////

#ifndef BkgAnalysis_h
#define BkgAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

//#include <TROOT.h>
//#include <TChain.h>
//#include <TFile.h>
//#include <TSelector.h>
#include <TSystem.h>
#include <TTree.h>
#include <TBranch.h>
#include <TCint.h>
#include <TRandom.h>
#include <TMath.h>
#include <TDirectory.h>
#include "TEnv.h"
#include <TString.h>
#include <TProof.h>
#include <TProofOutputFile.h>
#include <TLorentzVector.h>
#include "TPoint.h"
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
#include <TNtupleD.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class BkgAnalysis : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   vector<unsigned int> *TrigRes;
   vector<string>  *TrigNames;
   vector<string>  *MatchTriggerNames;
   vector<unsigned int> *L1TrigRes;
   UInt_t          evtNum;
   UInt_t          runNum;
   UInt_t          lumiNum;
   UInt_t          priVtx_n;
   Float_t         priVtx_X;
   Float_t         priVtx_Y;
   Float_t         priVtx_Z;
   Float_t         priVtx_XE;
   Float_t         priVtx_YE;
   Float_t         priVtx_ZE;
   Float_t         priVtx_NormChi2;
   Float_t         priVtx_Chi2;
   Float_t         priVtx_CL;
   UInt_t          priVtx_tracks;
   Float_t         priVtx_tracksPtSq;
   UInt_t          nMu;
   vector<float>   *muPx;
   vector<float>   *muPy;
   vector<float>   *muPz;
   vector<float>   *muCharge;
   vector<float>   *muD0;
   vector<float>   *muDz;
   vector<float>   *muChi2;
   vector<int>     *muNDF;
   vector<int>     *muPhits;
   vector<int>     *muShits;
   vector<int>     *muLayersTr;
   vector<int>     *muLayersPix;
   vector<float>   *muD0E;
   vector<float>   *muDzVtxErr;
   vector<unsigned int> *muKey;
   vector<bool>    *muIsGlobal;
   vector<bool>    *muIsPF;
   vector<int>     *muGlMuHits;
   vector<float>   *muGlChi2;
   vector<int>     *muGlNDF;
   vector<int>     *muGlMatchedStation;
   vector<float>   *muGlDzVtx;
   vector<float>   *muGlDxyVtx;
   vector<int>     *nMatchedStations;
   vector<int>     *muType;
   vector<int>     *muQual;
   vector<int>     *muTrack;
   vector<int>     *muNOverlap;
   vector<int>     *muNSharingSegWith;
   vector<float>   *mufHits;
   vector<bool>    *muFirstBarrel;
   vector<bool>    *muFirstEndCap;
   vector<float>   *muDzVtx;
   vector<float>   *muDxyVtx;
   vector<float>   *trNotRef;
   vector<float>   *trRef;
   vector<float>   *trackPx;
   vector<float>   *trackPy;
   vector<float>   *trackPz;
   vector<float>   *trackEnergy;
   vector<int>     *trackNDF;
   vector<int>     *trackPhits;
   vector<int>     *trackShits;
   vector<float>   *trackChi2;
   vector<float>   *trackD0;
   vector<float>   *trackD0Err;
   vector<float>   *trackCharge;
   vector<int>     *TrackHighPurity;
   vector<int>     *TrackTight;
   vector<float>   *trackfHits;
   vector<bool>    *trackFirstBarrel;
   vector<bool>    *trackFirstEndCap;
   vector<float>   *trackDzVtx;
   vector<float>   *trackDxyVtx;
   vector<double>  *tr_nsigdedx;
   vector<float>   *tr_dedx;
   vector<float>   *tr_dedxMass;
   vector<float>   *tr_theo;
   vector<float>   *tr_sigma;
   vector<float>   *tr_dedx_byHits;
   vector<float>   *tr_dedxErr_byHits;
   vector<int>     *tr_saturMeas_byHits;
   vector<int>     *tr_Meas_byHits;
   UInt_t          nMuMu;
   vector<float>   *MuMuMass;
   vector<float>   *MuMuPx;
   vector<float>   *MuMuPy;
   vector<float>   *MuMuPz;
   vector<float>   *MuMuVtx_CL;
   vector<float>   *MuMuVtx_Chi2;
   vector<float>   *MuMuDecayVtx_X;
   vector<float>   *MuMuDecayVtx_Y;
   vector<float>   *MuMuDecayVtx_Z;
   vector<float>   *MuMuDecayVtx_XE;
   vector<float>   *MuMuDecayVtx_YE;
   vector<float>   *MuMuDecayVtx_ZE;
   vector<int>     *mu1Idx;
   vector<int>     *mu2Idx;
   vector<float>   *mu1Px_MuMu;
   vector<float>   *mu1Py_MuMu;
   vector<float>   *mu1Pz_MuMu;
   vector<float>   *mu1Chi_MuMu2;
   vector<int>     *mu1NDF_MuMu;
   vector<float>   *mu2Px_MuMu;
   vector<float>   *mu2Py_MuMu;
   vector<float>   *mu2Pz_MuMu;
   vector<float>   *mu2Chi2_MuMu;
   vector<int>     *mu2NDF_MuMu;
   vector<int>     *MuMuType;
   vector<bool>    *MuMuMuonTrigMatch;
   vector<int>     *PriVtxMuMuCorr_n;
   vector<float>   *PriVtxMuMuCorr_X;
   vector<float>   *PriVtxMuMuCorr_Y;
   vector<float>   *PriVtxMuMuCorr_Z;
   vector<double>  *PriVtxMuMuCorr_EX;
   vector<double>  *PriVtxMuMuCorr_EY;
   vector<double>  *PriVtxMuMuCorr_EZ;
   vector<float>   *PriVtxMuMuCorr_Chi2;
   vector<float>   *PriVtxMuMuCorr_CL;
   vector<int>     *PriVtxMuMuCorr_tracks;
   vector<int>     *nTrk_afterMuMu;
   UInt_t          nB0;
   UInt_t          nB0_pre0;
   UInt_t          nB0_pre1;
   UInt_t          nB0_pre2;
   UInt_t          nB0_pre3;
   UInt_t          nB0_pre4;
   UInt_t          nB0_pre5;
   UInt_t          nB0_pre6;
   UInt_t          nB0_pre7;
   UInt_t          nB0_pre8;
   UInt_t          nB0_pre9;
   UInt_t          nB0_pre10;
   UInt_t          nB0_pre11;
   UInt_t          nB0_pre12;
   UInt_t          nB0_pre13;
   UInt_t          nB0_pre14;
   vector<float>   *B0Mass;
   vector<float>   *B0Px;
   vector<float>   *B0Py;
   vector<float>   *B0Pz;
   vector<double>  *B0PxE;
   vector<double>  *B0PyE;
   vector<double>  *B0PzE;
   vector<float>   *B0Vtx_CL;
   vector<float>   *B0Vtx_Chi2;
   vector<float>   *B0DecayVtx_X;
   vector<float>   *B0DecayVtx_Y;
   vector<float>   *B0DecayVtx_Z;
   vector<double>  *B0DecayVtx_XE;
   vector<double>  *B0DecayVtx_YE;
   vector<double>  *B0DecayVtx_ZE;
   vector<double>  *B0CosAlphaBS;
   vector<double>  *B0CosAlpha3DBS;
   vector<double>  *B0CTauBS;
   vector<double>  *B0CTauBSE;
   vector<double>  *B0LxyBS;
   vector<double>  *B0LxyBSE;
   vector<double>  *B0LxyzBS;
   vector<double>  *B0LxyzBSE;
   vector<double>  *B0CosAlphaPV;
   vector<double>  *B0CosAlpha3DPV;
   vector<double>  *B0CTauPV;
   vector<double>  *B0CTauPVE;
   vector<double>  *B0LxyPV;
   vector<double>  *B0LxyPVE;
   vector<double>  *B0LxyzPV;
   vector<double>  *B0LxyzPVE;
   vector<int>     *PriVtx_B0CosAlpha_n;
   vector<float>   *PriVtx_B0CosAlpha_X;
   vector<float>   *PriVtx_B0CosAlpha_Y;
   vector<float>   *PriVtx_B0CosAlpha_Z;
   vector<double>  *PriVtx_B0CosAlpha_EX;
   vector<double>  *PriVtx_B0CosAlpha_EY;
   vector<double>  *PriVtx_B0CosAlpha_EZ;
   vector<float>   *PriVtx_B0CosAlpha_Chi2;
   vector<float>   *PriVtx_B0CosAlpha_CL;
   vector<int>     *PriVtx_B0CosAlpha_tracks;
   vector<double>  *B0CosAlphaPVCosAlpha;
   vector<double>  *B0CosAlpha3DPVCosAlpha;
   vector<double>  *B0CTauPVCosAlpha;
   vector<double>  *B0CTauPVCosAlphaE;
   vector<double>  *B0LxyPVCosAlpha;
   vector<double>  *B0LxyPVCosAlphaE;
   vector<double>  *B0LxyzPVCosAlpha;
   vector<double>  *B0LxyzPVCosAlphaE;
   vector<int>     *PriVtx_B0CosAlpha3D_n;
   vector<float>   *PriVtx_B0CosAlpha3D_X;
   vector<float>   *PriVtx_B0CosAlpha3D_Y;
   vector<float>   *PriVtx_B0CosAlpha3D_Z;
   vector<double>  *PriVtx_B0CosAlpha3D_EX;
   vector<double>  *PriVtx_B0CosAlpha3D_EY;
   vector<double>  *PriVtx_B0CosAlpha3D_EZ;
   vector<float>   *PriVtx_B0CosAlpha3D_Chi2;
   vector<float>   *PriVtx_B0CosAlpha3D_CL;
   vector<int>     *PriVtx_B0CosAlpha3D_tracks;
   vector<double>  *B0CosAlphaPVCosAlpha3D;
   vector<double>  *B0CosAlpha3DPVCosAlpha3D;
   vector<double>  *B0CTauPVCosAlpha3D;
   vector<double>  *B0CTauPVCosAlpha3DE;
   vector<double>  *B0LxyPVCosAlpha3D;
   vector<double>  *B0LxyPVCosAlpha3DE;
   vector<double>  *B0LxyzPVCosAlpha3D;
   vector<double>  *B0LxyzPVCosAlpha3DE;
   vector<float>   *B0LessPV_tracksPtSq;
   vector<float>   *B0LessPV_4tracksPtSq;
   vector<int>     *PriVtxB0Less_n;
   vector<float>   *PriVtxB0Less_X;
   vector<float>   *PriVtxB0Less_Y;
   vector<float>   *PriVtxB0Less_Z;
   vector<double>  *PriVtxB0Less_EX;
   vector<double>  *PriVtxB0Less_EY;
   vector<double>  *PriVtxB0Less_EZ;
   vector<float>   *PriVtxB0Less_Chi2;
   vector<float>   *PriVtxB0Less_CL;
   vector<int>     *PriVtxB0Less_tracks;
   vector<double>  *B0CosAlphaB0LessPV;
   vector<double>  *B0CosAlpha3DB0LessPV;
   vector<double>  *B0CTauB0LessPV;
   vector<double>  *B0CTauB0LessPVE;
   vector<double>  *B0LxyB0LessPV;
   vector<double>  *B0LxyB0LessPVE;
   vector<double>  *B0LxyzB0LessPV;
   vector<double>  *B0LxyzB0LessPVE;
   vector<int>     *PriVtxB0Less_B0CosAlpha_n;
   vector<float>   *PriVtxB0Less_B0CosAlpha_X;
   vector<float>   *PriVtxB0Less_B0CosAlpha_Y;
   vector<float>   *PriVtxB0Less_B0CosAlpha_Z;
   vector<double>  *PriVtxB0Less_B0CosAlpha_EX;
   vector<double>  *PriVtxB0Less_B0CosAlpha_EY;
   vector<double>  *PriVtxB0Less_B0CosAlpha_EZ;
   vector<float>   *PriVtxB0Less_B0CosAlpha_Chi2;
   vector<float>   *PriVtxB0Less_B0CosAlpha_CL;
   vector<int>     *PriVtxB0Less_B0CosAlpha_tracks;
   vector<double>  *B0CosAlphaB0LessPVCosAlpha;
   vector<double>  *B0CosAlpha3DB0LessPVCosAlpha;
   vector<double>  *B0CTauB0LessPVCosAlpha;
   vector<double>  *B0CTauB0LessPVCosAlphaE;
   vector<double>  *B0LxyB0LessPVCosAlpha;
   vector<double>  *B0LxyB0LessPVCosAlphaE;
   vector<double>  *B0LxyzB0LessPVCosAlpha;
   vector<double>  *B0LxyzB0LessPVCosAlphaE;
   vector<int>     *PriVtxB0Less_B0CosAlpha3D_n;
   vector<float>   *PriVtxB0Less_B0CosAlpha3D_X;
   vector<float>   *PriVtxB0Less_B0CosAlpha3D_Y;
   vector<float>   *PriVtxB0Less_B0CosAlpha3D_Z;
   vector<double>  *PriVtxB0Less_B0CosAlpha3D_EX;
   vector<double>  *PriVtxB0Less_B0CosAlpha3D_EY;
   vector<double>  *PriVtxB0Less_B0CosAlpha3D_EZ;
   vector<float>   *PriVtxB0Less_B0CosAlpha3D_Chi2;
   vector<float>   *PriVtxB0Less_B0CosAlpha3D_CL;
   vector<int>     *PriVtxB0Less_B0CosAlpha3D_tracks;
   vector<double>  *B0CosAlphaB0LessPVCosAlpha3D;
   vector<double>  *B0CosAlpha3DB0LessPVCosAlpha3D;
   vector<double>  *B0CTauB0LessPVCosAlpha3D;
   vector<double>  *B0CTauB0LessPVCosAlpha3DE;
   vector<double>  *B0LxyB0LessPVCosAlpha3D;
   vector<double>  *B0LxyB0LessPVCosAlpha3DE;
   vector<double>  *B0LxyzB0LessPVCosAlpha3D;
   vector<double>  *B0LxyzB0LessPVCosAlpha3DE;
   vector<int>     *PriVtxB0Corr_n;
   vector<float>   *PriVtxB0Corr_X;
   vector<float>   *PriVtxB0Corr_Y;
   vector<float>   *PriVtxB0Corr_Z;
   vector<double>  *PriVtxB0Corr_EX;
   vector<double>  *PriVtxB0Corr_EY;
   vector<double>  *PriVtxB0Corr_EZ;
   vector<float>   *PriVtxB0Corr_Chi2;
   vector<float>   *PriVtxB0Corr_CL;
   vector<int>     *PriVtxB0Corr_tracks;
   vector<double>  *B0CosAlphaPVX;
   vector<double>  *B0CTauPVX;
   vector<double>  *B0CTauPVXE;
   vector<double>  *B0LxyPVX;
   vector<double>  *B0LxyzPVX;
   vector<float>   *B0CTauPVX_3D;
   vector<float>   *B0CTauPVX_3D_err;
   vector<int>     *B0MuMuIdx;
   vector<int>     *B0PionIdx;
   vector<int>     *B0KaonIdx;
   vector<float>   *PiPiMass_err;
   vector<float>   *Muon1Px_MuMuPiK;
   vector<float>   *Muon1Py_MuMuPiK;
   vector<float>   *Muon1Pz_MuMuPiK;
   vector<float>   *Muon1E_MuMuPiK;
   vector<float>   *Muon2Px_MuMuPiK;
   vector<float>   *Muon2Py_MuMuPiK;
   vector<float>   *Muon2Pz_MuMuPiK;
   vector<float>   *Muon2E_MuMuPiK;
   vector<float>   *PionPx_MuMuPiK;
   vector<float>   *PionPy_MuMuPiK;
   vector<float>   *PionPz_MuMuPiK;
   vector<float>   *PionE_MuMuPiK;
   vector<double>  *pion_nsigdedx;
   vector<float>   *pion_dedx;
   vector<float>   *pion_dedxMass;
   vector<float>   *pion_theo;
   vector<float>   *pion_sigma;
   vector<float>   *pion_dedx_byHits;
   vector<float>   *pion_dedxErr_byHits;
   vector<int>     *pion_saturMeas_byHits;
   vector<int>     *pion_Meas_byHits;
   vector<float>   *KaonPx_MuMuPiK;
   vector<float>   *KaonPy_MuMuPiK;
   vector<float>   *KaonPz_MuMuPiK;
   vector<float>   *KaonE_MuMuPiK;
   vector<double>  *kaon_nsigdedx;
   vector<float>   *kaon_dedx;
   vector<float>   *kaon_dedxMass;
   vector<float>   *kaon_theo;
   vector<float>   *kaon_sigma;
   vector<float>   *kaon_dedx_byHits;
   vector<float>   *kaon_dedxErr_byHits;
   vector<int>     *kaon_saturMeas_byHits;
   vector<int>     *kaon_Meas_byHits;

   // List of branches
   TBranch        *b_TrigRes;   //!
   TBranch        *b_TrigNames;   //!
   TBranch        *b_MatchTriggerNames;   //!
   TBranch        *b_L1TrigRes;   //!
   TBranch        *b_evtNum;   //!
   TBranch        *b_runNum;   //!
   TBranch        *b_lumiNum;   //!
   TBranch        *b_priVtx_n;   //!
   TBranch        *b_priVtx_X;   //!
   TBranch        *b_priVtx_Y;   //!
   TBranch        *b_priVtx_Z;   //!
   TBranch        *b_priVtx_XE;   //!
   TBranch        *b_priVtx_YE;   //!
   TBranch        *b_priVtx_ZE;   //!
   TBranch        *b_priVtx_NormChi2;   //!
   TBranch        *b_priVtx_Chi2;   //!
   TBranch        *b_priVtx_CL;   //!
   TBranch        *b_priVtx_tracks;   //!
   TBranch        *b_priVtx_tracksPtSq;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_muPx;   //!
   TBranch        *b_muPy;   //!
   TBranch        *b_muPz;   //!
   TBranch        *b_muCharge;   //!
   TBranch        *b_muD0;   //!
   TBranch        *b_muDz;   //!
   TBranch        *b_muChi2;   //!
   TBranch        *b_muNDF;   //!
   TBranch        *b_muPhits;   //!
   TBranch        *b_muShits;   //!
   TBranch        *b_muLayersTr;   //!
   TBranch        *b_muLayersPix;   //!
   TBranch        *b_muD0E;   //!
   TBranch        *b_muDzVtxErr;   //!
   TBranch        *b_muKey;   //!
   TBranch        *b_muIsGlobal;   //!
   TBranch        *b_muIsPF;   //!
   TBranch        *b_muGlMuHits;   //!
   TBranch        *b_muGlChi2;   //!
   TBranch        *b_muGlNDF;   //!
   TBranch        *b_muGlMatchedStation;   //!
   TBranch        *b_muGlDzVtx;   //!
   TBranch        *b_muGlDxyVtx;   //!
   TBranch        *b_nMatchedStations;   //!
   TBranch        *b_muType;   //!
   TBranch        *b_muQual;   //!
   TBranch        *b_muTrack;   //!
   TBranch        *b_muNOverlap;   //!
   TBranch        *b_muNSharingSegWith;   //!
   TBranch        *b_mufHits;   //!
   TBranch        *b_muFirstBarrel;   //!
   TBranch        *b_muFirstEndCap;   //!
   TBranch        *b_muDzVtx;   //!
   TBranch        *b_muDxyVtx;   //!
   TBranch        *b_trNotRef;   //!
   TBranch        *b_trRef;   //!
   TBranch        *b_trackPx;   //!
   TBranch        *b_trackPy;   //!
   TBranch        *b_trackPz;   //!
   TBranch        *b_trackEnergy;   //!
   TBranch        *b_trackNDF;   //!
   TBranch        *b_trackPhits;   //!
   TBranch        *b_trackShits;   //!
   TBranch        *b_trackChi2;   //!
   TBranch        *b_trackD0;   //!
   TBranch        *b_trackD0Err;   //!
   TBranch        *b_trackCharge;   //!
   TBranch        *b_TrackHighPurity;   //!
   TBranch        *b_TrackTight;   //!
   TBranch        *b_trackfHits;   //!
   TBranch        *b_trackFirstBarrel;   //!
   TBranch        *b_trackFirstEndCap;   //!
   TBranch        *b_trackDzVtx;   //!
   TBranch        *b_trackDxyVtx;   //!
   TBranch        *b_tr_nsigdedx;   //!
   TBranch        *b_tr_dedx;   //!
   TBranch        *b_tr_dedxMass;   //!
   TBranch        *b_tr_theo;   //!
   TBranch        *b_tr_sigma;   //!
   TBranch        *b_tr_dedx_byHits;   //!
   TBranch        *b_tr_dedxErr_byHits;   //!
   TBranch        *b_tr_saturMeas_byHits;   //!
   TBranch        *b_tr_Meas_byHits;   //!
   TBranch        *b_nMuMu;   //!
   TBranch        *b_MuMuMass;   //!
   TBranch        *b_MuMuPx;   //!
   TBranch        *b_MuMuPy;   //!
   TBranch        *b_MuMuPz;   //!
   TBranch        *b_MuMuVtx_CL;   //!
   TBranch        *b_MuMuVtx_Chi2;   //!
   TBranch        *b_MuMuDecayVtx_X;   //!
   TBranch        *b_MuMuDecayVtx_Y;   //!
   TBranch        *b_MuMuDecayVtx_Z;   //!
   TBranch        *b_MuMuDecayVtx_XE;   //!
   TBranch        *b_MuMuDecayVtx_YE;   //!
   TBranch        *b_MuMuDecayVtx_ZE;   //!
   TBranch        *b_mu1Idx;   //!
   TBranch        *b_mu2Idx;   //!
   TBranch        *b_mu1Px_MuMu;   //!
   TBranch        *b_mu1Py_MuMu;   //!
   TBranch        *b_mu1Pz_MuMu;   //!
   TBranch        *b_mu1Chi_MuMu2;   //!
   TBranch        *b_mu1NDF_MuMu;   //!
   TBranch        *b_mu2Px_MuMu;   //!
   TBranch        *b_mu2Py_MuMu;   //!
   TBranch        *b_mu2Pz_MuMu;   //!
   TBranch        *b_mu2Chi2_MuMu;   //!
   TBranch        *b_mu2NDF_MuMu;   //!
   TBranch        *b_MuMuType;   //!
   TBranch        *b_MuMuMuonTrigMatch;   //!
   TBranch        *b_PriVtxMuMuCorr_n;   //!
   TBranch        *b_PriVtxMuMuCorr_X;   //!
   TBranch        *b_PriVtxMuMuCorr_Y;   //!
   TBranch        *b_PriVtxMuMuCorr_Z;   //!
   TBranch        *b_PriVtxMuMuCorr_EX;   //!
   TBranch        *b_PriVtxMuMuCorr_EY;   //!
   TBranch        *b_PriVtxMuMuCorr_EZ;   //!
   TBranch        *b_PriVtxMuMuCorr_Chi2;   //!
   TBranch        *b_PriVtxMuMuCorr_CL;   //!
   TBranch        *b_PriVtxMuMuCorr_tracks;   //!
   TBranch        *b_nTrk_afterMuMu;   //!
   TBranch        *b_nB0;   //!
   TBranch        *b_nB0_pre0;   //!
   TBranch        *b_nB0_pre1;   //!
   TBranch        *b_nB0_pre2;   //!
   TBranch        *b_nB0_pre3;   //!
   TBranch        *b_nB0_pre4;   //!
   TBranch        *b_nB0_pre5;   //!
   TBranch        *b_nB0_pre6;   //!
   TBranch        *b_nB0_pre7;   //!
   TBranch        *b_nB0_pre8;   //!
   TBranch        *b_nB0_pre9;   //!
   TBranch        *b_nB0_pre10;   //!
   TBranch        *b_nB0_pre11;   //!
   TBranch        *b_nB0_pre12;   //!
   TBranch        *b_nB0_pre13;   //!
   TBranch        *b_nB0_pre14;   //!
   TBranch        *b_B0Mass;   //!
   TBranch        *b_B0Px;   //!
   TBranch        *b_B0Py;   //!
   TBranch        *b_B0Pz;   //!
   TBranch        *b_B0PxE;   //!
   TBranch        *b_B0PyE;   //!
   TBranch        *b_B0PzE;   //!
   TBranch        *b_B0Vtx_CL;   //!
   TBranch        *b_B0Vtx_Chi2;   //!
   TBranch        *b_B0DecayVtx_X;   //!
   TBranch        *b_B0DecayVtx_Y;   //!
   TBranch        *b_B0DecayVtx_Z;   //!
   TBranch        *b_B0DecayVtx_XE;   //!
   TBranch        *b_B0DecayVtx_YE;   //!
   TBranch        *b_B0DecayVtx_ZE;   //!
   TBranch        *b_B0CosAlphaBS;   //!
   TBranch        *b_B0CosAlpha3DBS;   //!
   TBranch        *b_B0CTauBS;   //!
   TBranch        *b_B0CTauBSE;   //!
   TBranch        *b_B0LxyBS;   //!
   TBranch        *b_B0LxyBSE;   //!
   TBranch        *b_B0LxyzBS;   //!
   TBranch        *b_B0LxyzBSE;   //!
   TBranch        *b_B0CosAlphaPV;   //!
   TBranch        *b_B0CosAlpha3DPV;   //!
   TBranch        *b_B0CTauPV;   //!
   TBranch        *b_B0CTauPVE;   //!
   TBranch        *b_B0LxyPV;   //!
   TBranch        *b_B0LxyPVE;   //!
   TBranch        *b_B0LxyzPV;   //!
   TBranch        *b_B0LxyzPVE;   //!
   TBranch        *b_PriVtx_B0CosAlpha_n;   //!
   TBranch        *b_PriVtx_B0CosAlpha_X;   //!
   TBranch        *b_PriVtx_B0CosAlpha_Y;   //!
   TBranch        *b_PriVtx_B0CosAlpha_Z;   //!
   TBranch        *b_PriVtx_B0CosAlpha_EX;   //!
   TBranch        *b_PriVtx_B0CosAlpha_EY;   //!
   TBranch        *b_PriVtx_B0CosAlpha_EZ;   //!
   TBranch        *b_PriVtx_B0CosAlpha_Chi2;   //!
   TBranch        *b_PriVtx_B0CosAlpha_CL;   //!
   TBranch        *b_PriVtx_B0CosAlpha_tracks;   //!
   TBranch        *b_B0CosAlphaPVCosAlpha;   //!
   TBranch        *b_B0CosAlpha3DPVCosAlpha;   //!
   TBranch        *b_B0CTauPVCosAlpha;   //!
   TBranch        *b_B0CTauPVCosAlphaE;   //!
   TBranch        *b_B0LxyPVCosAlpha;   //!
   TBranch        *b_B0LxyPVCosAlphaE;   //!
   TBranch        *b_B0LxyzPVCosAlpha;   //!
   TBranch        *b_B0LxyzPVCosAlphaE;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_n;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_X;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_Y;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_Z;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_EX;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_EY;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_EZ;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_Chi2;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_CL;   //!
   TBranch        *b_PriVtx_B0CosAlpha3D_tracks;   //!
   TBranch        *b_B0CosAlphaPVCosAlpha3D;   //!
   TBranch        *b_B0CosAlpha3DPVCosAlpha3D;   //!
   TBranch        *b_B0CTauPVCosAlpha3D;   //!
   TBranch        *b_B0CTauPVCosAlpha3DE;   //!
   TBranch        *b_B0LxyPVCosAlpha3D;   //!
   TBranch        *b_B0LxyPVCosAlpha3DE;   //!
   TBranch        *b_B0LxyzPVCosAlpha3D;   //!
   TBranch        *b_B0LxyzPVCosAlpha3DE;   //!
   TBranch        *b_B0LessPV_tracksPtSq;   //!
   TBranch        *b_B0LessPV_4tracksPtSq;   //!
   TBranch        *b_PriVtxB0Less_n;   //!
   TBranch        *b_PriVtxB0Less_X;   //!
   TBranch        *b_PriVtxB0Less_Y;   //!
   TBranch        *b_PriVtxB0Less_Z;   //!
   TBranch        *b_PriVtxB0Less_EX;   //!
   TBranch        *b_PriVtxB0Less_EY;   //!
   TBranch        *b_PriVtxB0Less_EZ;   //!
   TBranch        *b_PriVtxB0Less_Chi2;   //!
   TBranch        *b_PriVtxB0Less_CL;   //!
   TBranch        *b_PriVtxB0Less_tracks;   //!
   TBranch        *b_B0CosAlphaB0LessPV;   //!
   TBranch        *b_B0CosAlpha3DB0LessPV;   //!
   TBranch        *b_B0CTauB0LessPV;   //!
   TBranch        *b_B0CTauB0LessPVE;   //!
   TBranch        *b_B0LxyB0LessPV;   //!
   TBranch        *b_B0LxyB0LessPVE;   //!
   TBranch        *b_B0LxyzB0LessPV;   //!
   TBranch        *b_B0LxyzB0LessPVE;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_n;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_X;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_Y;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_Z;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_EX;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_EY;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_EZ;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_Chi2;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_CL;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha_tracks;   //!
   TBranch        *b_B0CosAlphaB0LessPVCosAlpha;   //!
   TBranch        *b_B0CosAlpha3DB0LessPVCosAlpha;   //!
   TBranch        *b_B0CTauB0LessPVCosAlpha;   //!
   TBranch        *b_B0CTauB0LessPVCosAlphaE;   //!
   TBranch        *b_B0LxyB0LessPVCosAlpha;   //!
   TBranch        *b_B0LxyB0LessPVCosAlphaE;   //!
   TBranch        *b_B0LxyzB0LessPVCosAlpha;   //!
   TBranch        *b_B0LxyzB0LessPVCosAlphaE;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_n;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_X;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_Y;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_Z;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_EX;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_EY;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_EZ;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_Chi2;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_CL;   //!
   TBranch        *b_PriVtxB0Less_B0CosAlpha3D_tracks;   //!
   TBranch        *b_B0CosAlphaB0LessPVCosAlpha3D;   //!
   TBranch        *b_B0CosAlpha3DB0LessPVCosAlpha3D;   //!
   TBranch        *b_B0CTauB0LessPVCosAlpha3D;   //!
   TBranch        *b_B0CTauB0LessPVCosAlpha3DE;   //!
   TBranch        *b_B0LxyB0LessPVCosAlpha3D;   //!
   TBranch        *b_B0LxyB0LessPVCosAlpha3DE;   //!
   TBranch        *b_B0LxyzB0LessPVCosAlpha3D;   //!
   TBranch        *b_B0LxyzB0LessPVCosAlpha3DE;   //!
   TBranch        *b_PriVtxB0Corr_n;   //!
   TBranch        *b_PriVtxB0Corr_X;   //!
   TBranch        *b_PriVtxB0Corr_Y;   //!
   TBranch        *b_PriVtxB0Corr_Z;   //!
   TBranch        *b_PriVtxB0Corr_EX;   //!
   TBranch        *b_PriVtxB0Corr_EY;   //!
   TBranch        *b_PriVtxB0Corr_EZ;   //!
   TBranch        *b_PriVtxB0Corr_Chi2;   //!
   TBranch        *b_PriVtxB0Corr_CL;   //!
   TBranch        *b_PriVtxB0Corr_tracks;   //!
   TBranch        *b_B0CosAlphaPVX;   //!
   TBranch        *b_B0CTauPVX;   //!
   TBranch        *b_B0CTauPVXE;   //!
   TBranch        *b_B0LxyPVX;   //!
   TBranch        *b_B0LxyzPVX;   //!
   TBranch        *b_B0CTauPVX_3D;   //!
   TBranch        *b_B0CTauPVX_3D_err;   //!
   TBranch        *b_B0MuMuIdx;   //!
   TBranch        *b_B0PionIdx;   //!
   TBranch        *b_B0KaonIdx;   //!
   TBranch        *b_PiPiMass_err;   //!
   TBranch        *b_Muon1Px_MuMuPiK;   //!
   TBranch        *b_Muon1Py_MuMuPiK;   //!
   TBranch        *b_Muon1Pz_MuMuPiK;   //!
   TBranch        *b_Muon1E_MuMuPiK;   //!
   TBranch        *b_Muon2Px_MuMuPiK;   //!
   TBranch        *b_Muon2Py_MuMuPiK;   //!
   TBranch        *b_Muon2Pz_MuMuPiK;   //!
   TBranch        *b_Muon2E_MuMuPiK;   //!
   TBranch        *b_PionPx_MuMuPiK;   //!
   TBranch        *b_PionPy_MuMuPiK;   //!
   TBranch        *b_PionPz_MuMuPiK;   //!
   TBranch        *b_PionE_MuMuPiK;   //!
   TBranch        *b_pion_nsigdedx;   //!
   TBranch        *b_pion_dedx;   //!
   TBranch        *b_pion_dedxMass;   //!
   TBranch        *b_pion_theo;   //!
   TBranch        *b_pion_sigma;   //!
   TBranch        *b_pion_dedx_byHits;   //!
   TBranch        *b_pion_dedxErr_byHits;   //!
   TBranch        *b_pion_saturMeas_byHits;   //!
   TBranch        *b_pion_Meas_byHits;   //!
   TBranch        *b_KaonPx_MuMuPiK;   //!
   TBranch        *b_KaonPy_MuMuPiK;   //!
   TBranch        *b_KaonPz_MuMuPiK;   //!
   TBranch        *b_KaonE_MuMuPiK;   //!
   TBranch        *b_kaon_nsigdedx;   //!
   TBranch        *b_kaon_dedx;   //!
   TBranch        *b_kaon_dedxMass;   //!
   TBranch        *b_kaon_theo;   //!
   TBranch        *b_kaon_sigma;   //!
   TBranch        *b_kaon_dedx_byHits;   //!
   TBranch        *b_kaon_dedxErr_byHits;   //!
   TBranch        *b_kaon_saturMeas_byHits;   //!
   TBranch        *b_kaon_Meas_byHits;   //!

   BkgAnalysis(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~BkgAnalysis() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   
   
   ///////////// Output files //////////////////
    TProofOutputFile *OutFile;
    TFile            *fOut;

    TH1F* h_nB0;
    TH1F* hMuMuMass;
    
    TH1F* hJpsiPiMass;
    TH1F* hKPiMass;
    TH1F* hPiPiMass;
    TH1F* hKKMass;
    TH1F* hKPiMass_noBs;
    
    TH1F* hJpsiPiMass_peak;
    TH1F* hKPiMass_peak;
    TH1F* hPiPiMass_peak;
    TH1F* hKKMass_peak;

    TH1F* hJpsiPiMass_sb;
    TH1F* hKPiMass_sb;
    TH1F* hPiPiMass_sb;
    TH1F* hKKMass_sb;
    
    TH1F* hjpsiKPiMassBaseSelAlt;
    TH1F* hjpsiKKMassBaseSelAlt;
    TH1F* hjpsiPiPiMassBaseSelAlt;
    TH1F* hjpsiPhiToKKMass;
    TH1F* hjpsiKPiMassNoPhi;
//    TH1F* hjpsiKPiMassNoPhiNoBs;
    
    TH2F* hDalitz_peak;
    TH2F* hDalitz_sideband;
    
    TH1F* hChi2byNDF;
    TH1F* hmuShits;
    TH1F* hmuPhits;
    TH1F* hmuDz;
    TH1F* hmuDxy;
    TH1F* hB0Vtx_CL;
    TH1F* hB0CosAlphaPV;
    TH1F* hB0CtauPV_by_E;
    TH1F* hMuMuVtx_CL;
    TH1F* htrack_fromB0_Pt;
    TH1F* hB0Pt;
    TH1F* htrack_fromB0_Eta;
    TH1F* hjpsi_fromB0_Pt;
    TH1F* hjpsi_track_deltaR;
    TH1F* htrackChi2byNDF;
    TH1F* htrackShits;
    TH1F* htrackPhits;

    Double_t muon_mass, phi_mass, jpsi_mass, psi2S_mass, pionCh_mass, kaonCh_mass, beam_energy;
   

   ClassDef(BkgAnalysis,0);
};

#endif

#ifdef BkgAnalysis_cxx
void BkgAnalysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
   
   
 muon_mass = 0.1056583715;
  //double phi_mass = 1.019455;
 jpsi_mass = 3.0967;
 psi2S_mass = 3.686109 ;
 pionCh_mass = 0.13957018;
 kaonCh_mass = 0.493677 ;
 beam_energy = 4000.0;
   

   // Set object pointer
   TrigRes = 0;
   TrigNames = 0;
   MatchTriggerNames = 0;
   L1TrigRes = 0;
   muPx = 0;
   muPy = 0;
   muPz = 0;
   muCharge = 0;
   muD0 = 0;
   muDz = 0;
   muChi2 = 0;
   muNDF = 0;
   muPhits = 0;
   muShits = 0;
   muLayersTr = 0;
   muLayersPix = 0;
   muD0E = 0;
   muDzVtxErr = 0;
   muKey = 0;
   muIsGlobal = 0;
   muIsPF = 0;
   muGlMuHits = 0;
   muGlChi2 = 0;
   muGlNDF = 0;
   muGlMatchedStation = 0;
   muGlDzVtx = 0;
   muGlDxyVtx = 0;
   nMatchedStations = 0;
   muType = 0;
   muQual = 0;
   muTrack = 0;
   muNOverlap = 0;
   muNSharingSegWith = 0;
   mufHits = 0;
   muFirstBarrel = 0;
   muFirstEndCap = 0;
   muDzVtx = 0;
   muDxyVtx = 0;
   trNotRef = 0;
   trRef = 0;
   trackPx = 0;
   trackPy = 0;
   trackPz = 0;
   trackEnergy = 0;
   trackNDF = 0;
   trackPhits = 0;
   trackShits = 0;
   trackChi2 = 0;
   trackD0 = 0;
   trackD0Err = 0;
   trackCharge = 0;
   TrackHighPurity = 0;
   TrackTight = 0;
   trackfHits = 0;
   trackFirstBarrel = 0;
   trackFirstEndCap = 0;
   trackDzVtx = 0;
   trackDxyVtx = 0;
   tr_nsigdedx = 0;
   tr_dedx = 0;
   tr_dedxMass = 0;
   tr_theo = 0;
   tr_sigma = 0;
   tr_dedx_byHits = 0;
   tr_dedxErr_byHits = 0;
   tr_saturMeas_byHits = 0;
   tr_Meas_byHits = 0;
   MuMuMass = 0;
   MuMuPx = 0;
   MuMuPy = 0;
   MuMuPz = 0;
   MuMuVtx_CL = 0;
   MuMuVtx_Chi2 = 0;
   MuMuDecayVtx_X = 0;
   MuMuDecayVtx_Y = 0;
   MuMuDecayVtx_Z = 0;
   MuMuDecayVtx_XE = 0;
   MuMuDecayVtx_YE = 0;
   MuMuDecayVtx_ZE = 0;
   mu1Idx = 0;
   mu2Idx = 0;
   mu1Px_MuMu = 0;
   mu1Py_MuMu = 0;
   mu1Pz_MuMu = 0;
   mu1Chi_MuMu2 = 0;
   mu1NDF_MuMu = 0;
   mu2Px_MuMu = 0;
   mu2Py_MuMu = 0;
   mu2Pz_MuMu = 0;
   mu2Chi2_MuMu = 0;
   mu2NDF_MuMu = 0;
   MuMuType = 0;
   MuMuMuonTrigMatch = 0;
   PriVtxMuMuCorr_n = 0;
   PriVtxMuMuCorr_X = 0;
   PriVtxMuMuCorr_Y = 0;
   PriVtxMuMuCorr_Z = 0;
   PriVtxMuMuCorr_EX = 0;
   PriVtxMuMuCorr_EY = 0;
   PriVtxMuMuCorr_EZ = 0;
   PriVtxMuMuCorr_Chi2 = 0;
   PriVtxMuMuCorr_CL = 0;
   PriVtxMuMuCorr_tracks = 0;
   nTrk_afterMuMu = 0;
   B0Mass = 0;
   B0Px = 0;
   B0Py = 0;
   B0Pz = 0;
   B0PxE = 0;
   B0PyE = 0;
   B0PzE = 0;
   B0Vtx_CL = 0;
   B0Vtx_Chi2 = 0;
   B0DecayVtx_X = 0;
   B0DecayVtx_Y = 0;
   B0DecayVtx_Z = 0;
   B0DecayVtx_XE = 0;
   B0DecayVtx_YE = 0;
   B0DecayVtx_ZE = 0;
   B0CosAlphaBS = 0;
   B0CosAlpha3DBS = 0;
   B0CTauBS = 0;
   B0CTauBSE = 0;
   B0LxyBS = 0;
   B0LxyBSE = 0;
   B0LxyzBS = 0;
   B0LxyzBSE = 0;
   B0CosAlphaPV = 0;
   B0CosAlpha3DPV = 0;
   B0CTauPV = 0;
   B0CTauPVE = 0;
   B0LxyPV = 0;
   B0LxyPVE = 0;
   B0LxyzPV = 0;
   B0LxyzPVE = 0;
   PriVtx_B0CosAlpha_n = 0;
   PriVtx_B0CosAlpha_X = 0;
   PriVtx_B0CosAlpha_Y = 0;
   PriVtx_B0CosAlpha_Z = 0;
   PriVtx_B0CosAlpha_EX = 0;
   PriVtx_B0CosAlpha_EY = 0;
   PriVtx_B0CosAlpha_EZ = 0;
   PriVtx_B0CosAlpha_Chi2 = 0;
   PriVtx_B0CosAlpha_CL = 0;
   PriVtx_B0CosAlpha_tracks = 0;
   B0CosAlphaPVCosAlpha = 0;
   B0CosAlpha3DPVCosAlpha = 0;
   B0CTauPVCosAlpha = 0;
   B0CTauPVCosAlphaE = 0;
   B0LxyPVCosAlpha = 0;
   B0LxyPVCosAlphaE = 0;
   B0LxyzPVCosAlpha = 0;
   B0LxyzPVCosAlphaE = 0;
   PriVtx_B0CosAlpha3D_n = 0;
   PriVtx_B0CosAlpha3D_X = 0;
   PriVtx_B0CosAlpha3D_Y = 0;
   PriVtx_B0CosAlpha3D_Z = 0;
   PriVtx_B0CosAlpha3D_EX = 0;
   PriVtx_B0CosAlpha3D_EY = 0;
   PriVtx_B0CosAlpha3D_EZ = 0;
   PriVtx_B0CosAlpha3D_Chi2 = 0;
   PriVtx_B0CosAlpha3D_CL = 0;
   PriVtx_B0CosAlpha3D_tracks = 0;
   B0CosAlphaPVCosAlpha3D = 0;
   B0CosAlpha3DPVCosAlpha3D = 0;
   B0CTauPVCosAlpha3D = 0;
   B0CTauPVCosAlpha3DE = 0;
   B0LxyPVCosAlpha3D = 0;
   B0LxyPVCosAlpha3DE = 0;
   B0LxyzPVCosAlpha3D = 0;
   B0LxyzPVCosAlpha3DE = 0;
   B0LessPV_tracksPtSq = 0;
   B0LessPV_4tracksPtSq = 0;
   PriVtxB0Less_n = 0;
   PriVtxB0Less_X = 0;
   PriVtxB0Less_Y = 0;
   PriVtxB0Less_Z = 0;
   PriVtxB0Less_EX = 0;
   PriVtxB0Less_EY = 0;
   PriVtxB0Less_EZ = 0;
   PriVtxB0Less_Chi2 = 0;
   PriVtxB0Less_CL = 0;
   PriVtxB0Less_tracks = 0;
   B0CosAlphaB0LessPV = 0;
   B0CosAlpha3DB0LessPV = 0;
   B0CTauB0LessPV = 0;
   B0CTauB0LessPVE = 0;
   B0LxyB0LessPV = 0;
   B0LxyB0LessPVE = 0;
   B0LxyzB0LessPV = 0;
   B0LxyzB0LessPVE = 0;
   PriVtxB0Less_B0CosAlpha_n = 0;
   PriVtxB0Less_B0CosAlpha_X = 0;
   PriVtxB0Less_B0CosAlpha_Y = 0;
   PriVtxB0Less_B0CosAlpha_Z = 0;
   PriVtxB0Less_B0CosAlpha_EX = 0;
   PriVtxB0Less_B0CosAlpha_EY = 0;
   PriVtxB0Less_B0CosAlpha_EZ = 0;
   PriVtxB0Less_B0CosAlpha_Chi2 = 0;
   PriVtxB0Less_B0CosAlpha_CL = 0;
   PriVtxB0Less_B0CosAlpha_tracks = 0;
   B0CosAlphaB0LessPVCosAlpha = 0;
   B0CosAlpha3DB0LessPVCosAlpha = 0;
   B0CTauB0LessPVCosAlpha = 0;
   B0CTauB0LessPVCosAlphaE = 0;
   B0LxyB0LessPVCosAlpha = 0;
   B0LxyB0LessPVCosAlphaE = 0;
   B0LxyzB0LessPVCosAlpha = 0;
   B0LxyzB0LessPVCosAlphaE = 0;
   PriVtxB0Less_B0CosAlpha3D_n = 0;
   PriVtxB0Less_B0CosAlpha3D_X = 0;
   PriVtxB0Less_B0CosAlpha3D_Y = 0;
   PriVtxB0Less_B0CosAlpha3D_Z = 0;
   PriVtxB0Less_B0CosAlpha3D_EX = 0;
   PriVtxB0Less_B0CosAlpha3D_EY = 0;
   PriVtxB0Less_B0CosAlpha3D_EZ = 0;
   PriVtxB0Less_B0CosAlpha3D_Chi2 = 0;
   PriVtxB0Less_B0CosAlpha3D_CL = 0;
   PriVtxB0Less_B0CosAlpha3D_tracks = 0;
   B0CosAlphaB0LessPVCosAlpha3D = 0;
   B0CosAlpha3DB0LessPVCosAlpha3D = 0;
   B0CTauB0LessPVCosAlpha3D = 0;
   B0CTauB0LessPVCosAlpha3DE = 0;
   B0LxyB0LessPVCosAlpha3D = 0;
   B0LxyB0LessPVCosAlpha3DE = 0;
   B0LxyzB0LessPVCosAlpha3D = 0;
   B0LxyzB0LessPVCosAlpha3DE = 0;
   PriVtxB0Corr_n = 0;
   PriVtxB0Corr_X = 0;
   PriVtxB0Corr_Y = 0;
   PriVtxB0Corr_Z = 0;
   PriVtxB0Corr_EX = 0;
   PriVtxB0Corr_EY = 0;
   PriVtxB0Corr_EZ = 0;
   PriVtxB0Corr_Chi2 = 0;
   PriVtxB0Corr_CL = 0;
   PriVtxB0Corr_tracks = 0;
   B0CosAlphaPVX = 0;
   B0CTauPVX = 0;
   B0CTauPVXE = 0;
   B0LxyPVX = 0;
   B0LxyzPVX = 0;
   B0CTauPVX_3D = 0;
   B0CTauPVX_3D_err = 0;
   B0MuMuIdx = 0;
   B0PionIdx = 0;
   B0KaonIdx = 0;
   PiPiMass_err = 0;
   Muon1Px_MuMuPiK = 0;
   Muon1Py_MuMuPiK = 0;
   Muon1Pz_MuMuPiK = 0;
   Muon1E_MuMuPiK = 0;
   Muon2Px_MuMuPiK = 0;
   Muon2Py_MuMuPiK = 0;
   Muon2Pz_MuMuPiK = 0;
   Muon2E_MuMuPiK = 0;
   PionPx_MuMuPiK = 0;
   PionPy_MuMuPiK = 0;
   PionPz_MuMuPiK = 0;
   PionE_MuMuPiK = 0;
   pion_nsigdedx = 0;
   pion_dedx = 0;
   pion_dedxMass = 0;
   pion_theo = 0;
   pion_sigma = 0;
   pion_dedx_byHits = 0;
   pion_dedxErr_byHits = 0;
   pion_saturMeas_byHits = 0;
   pion_Meas_byHits = 0;
   KaonPx_MuMuPiK = 0;
   KaonPy_MuMuPiK = 0;
   KaonPz_MuMuPiK = 0;
   KaonE_MuMuPiK = 0;
   kaon_nsigdedx = 0;
   kaon_dedx = 0;
   kaon_dedxMass = 0;
   kaon_theo = 0;
   kaon_sigma = 0;
   kaon_dedx_byHits = 0;
   kaon_dedxErr_byHits = 0;
   kaon_saturMeas_byHits = 0;
   kaon_Meas_byHits = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("TrigRes", &TrigRes, &b_TrigRes);
   fChain->SetBranchAddress("TrigNames", &TrigNames, &b_TrigNames);
   fChain->SetBranchAddress("MatchTriggerNames", &MatchTriggerNames, &b_MatchTriggerNames);
   fChain->SetBranchAddress("L1TrigRes", &L1TrigRes, &b_L1TrigRes);
   fChain->SetBranchAddress("evtNum", &evtNum, &b_evtNum);
   fChain->SetBranchAddress("runNum", &runNum, &b_runNum);
   fChain->SetBranchAddress("lumiNum", &lumiNum, &b_lumiNum);
   fChain->SetBranchAddress("priVtx_n", &priVtx_n, &b_priVtx_n);
   fChain->SetBranchAddress("priVtx_X", &priVtx_X, &b_priVtx_X);
   fChain->SetBranchAddress("priVtx_Y", &priVtx_Y, &b_priVtx_Y);
   fChain->SetBranchAddress("priVtx_Z", &priVtx_Z, &b_priVtx_Z);
   fChain->SetBranchAddress("priVtx_XE", &priVtx_XE, &b_priVtx_XE);
   fChain->SetBranchAddress("priVtx_YE", &priVtx_YE, &b_priVtx_YE);
   fChain->SetBranchAddress("priVtx_ZE", &priVtx_ZE, &b_priVtx_ZE);
   fChain->SetBranchAddress("priVtx_NormChi2", &priVtx_NormChi2, &b_priVtx_NormChi2);
   fChain->SetBranchAddress("priVtx_Chi2", &priVtx_Chi2, &b_priVtx_Chi2);
   fChain->SetBranchAddress("priVtx_CL", &priVtx_CL, &b_priVtx_CL);
   fChain->SetBranchAddress("priVtx_tracks", &priVtx_tracks, &b_priVtx_tracks);
   fChain->SetBranchAddress("priVtx_tracksPtSq", &priVtx_tracksPtSq, &b_priVtx_tracksPtSq);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("muPx", &muPx, &b_muPx);
   fChain->SetBranchAddress("muPy", &muPy, &b_muPy);
   fChain->SetBranchAddress("muPz", &muPz, &b_muPz);
   fChain->SetBranchAddress("muCharge", &muCharge, &b_muCharge);
   fChain->SetBranchAddress("muD0", &muD0, &b_muD0);
   fChain->SetBranchAddress("muDz", &muDz, &b_muDz);
   fChain->SetBranchAddress("muChi2", &muChi2, &b_muChi2);
   fChain->SetBranchAddress("muNDF", &muNDF, &b_muNDF);
   fChain->SetBranchAddress("muPhits", &muPhits, &b_muPhits);
   fChain->SetBranchAddress("muShits", &muShits, &b_muShits);
   fChain->SetBranchAddress("muLayersTr", &muLayersTr, &b_muLayersTr);
   fChain->SetBranchAddress("muLayersPix", &muLayersPix, &b_muLayersPix);
   fChain->SetBranchAddress("muD0E", &muD0E, &b_muD0E);
   fChain->SetBranchAddress("muDzVtxErr", &muDzVtxErr, &b_muDzVtxErr);
   fChain->SetBranchAddress("muKey", &muKey, &b_muKey);
   fChain->SetBranchAddress("muIsGlobal", &muIsGlobal, &b_muIsGlobal);
   fChain->SetBranchAddress("muIsPF", &muIsPF, &b_muIsPF);
   fChain->SetBranchAddress("muGlMuHits", &muGlMuHits, &b_muGlMuHits);
   fChain->SetBranchAddress("muGlChi2", &muGlChi2, &b_muGlChi2);
   fChain->SetBranchAddress("muGlNDF", &muGlNDF, &b_muGlNDF);
   fChain->SetBranchAddress("muGlMatchedStation", &muGlMatchedStation, &b_muGlMatchedStation);
   fChain->SetBranchAddress("muGlDzVtx", &muGlDzVtx, &b_muGlDzVtx);
   fChain->SetBranchAddress("muGlDxyVtx", &muGlDxyVtx, &b_muGlDxyVtx);
   fChain->SetBranchAddress("nMatchedStations", &nMatchedStations, &b_nMatchedStations);
   fChain->SetBranchAddress("muType", &muType, &b_muType);
   fChain->SetBranchAddress("muQual", &muQual, &b_muQual);
   fChain->SetBranchAddress("muTrack", &muTrack, &b_muTrack);
   fChain->SetBranchAddress("muNOverlap", &muNOverlap, &b_muNOverlap);
   fChain->SetBranchAddress("muNSharingSegWith", &muNSharingSegWith, &b_muNSharingSegWith);
   fChain->SetBranchAddress("mufHits", &mufHits, &b_mufHits);
   fChain->SetBranchAddress("muFirstBarrel", &muFirstBarrel, &b_muFirstBarrel);
   fChain->SetBranchAddress("muFirstEndCap", &muFirstEndCap, &b_muFirstEndCap);
   fChain->SetBranchAddress("muDzVtx", &muDzVtx, &b_muDzVtx);
   fChain->SetBranchAddress("muDxyVtx", &muDxyVtx, &b_muDxyVtx);
   fChain->SetBranchAddress("trNotRef", &trNotRef, &b_trNotRef);
   fChain->SetBranchAddress("trRef", &trRef, &b_trRef);
   fChain->SetBranchAddress("trackPx", &trackPx, &b_trackPx);
   fChain->SetBranchAddress("trackPy", &trackPy, &b_trackPy);
   fChain->SetBranchAddress("trackPz", &trackPz, &b_trackPz);
   fChain->SetBranchAddress("trackEnergy", &trackEnergy, &b_trackEnergy);
   fChain->SetBranchAddress("trackNDF", &trackNDF, &b_trackNDF);
   fChain->SetBranchAddress("trackPhits", &trackPhits, &b_trackPhits);
   fChain->SetBranchAddress("trackShits", &trackShits, &b_trackShits);
   fChain->SetBranchAddress("trackChi2", &trackChi2, &b_trackChi2);
   fChain->SetBranchAddress("trackD0", &trackD0, &b_trackD0);
   fChain->SetBranchAddress("trackD0Err", &trackD0Err, &b_trackD0Err);
   fChain->SetBranchAddress("trackCharge", &trackCharge, &b_trackCharge);
   fChain->SetBranchAddress("TrackHighPurity", &TrackHighPurity, &b_TrackHighPurity);
   fChain->SetBranchAddress("TrackTight", &TrackTight, &b_TrackTight);
   fChain->SetBranchAddress("trackfHits", &trackfHits, &b_trackfHits);
   fChain->SetBranchAddress("trackFirstBarrel", &trackFirstBarrel, &b_trackFirstBarrel);
   fChain->SetBranchAddress("trackFirstEndCap", &trackFirstEndCap, &b_trackFirstEndCap);
   fChain->SetBranchAddress("trackDzVtx", &trackDzVtx, &b_trackDzVtx);
   fChain->SetBranchAddress("trackDxyVtx", &trackDxyVtx, &b_trackDxyVtx);
   fChain->SetBranchAddress("tr_nsigdedx", &tr_nsigdedx, &b_tr_nsigdedx);
   fChain->SetBranchAddress("tr_dedx", &tr_dedx, &b_tr_dedx);
   fChain->SetBranchAddress("tr_dedxMass", &tr_dedxMass, &b_tr_dedxMass);
   fChain->SetBranchAddress("tr_theo", &tr_theo, &b_tr_theo);
   fChain->SetBranchAddress("tr_sigma", &tr_sigma, &b_tr_sigma);
   fChain->SetBranchAddress("tr_dedx_byHits", &tr_dedx_byHits, &b_tr_dedx_byHits);
   fChain->SetBranchAddress("tr_dedxErr_byHits", &tr_dedxErr_byHits, &b_tr_dedxErr_byHits);
   fChain->SetBranchAddress("tr_saturMeas_byHits", &tr_saturMeas_byHits, &b_tr_saturMeas_byHits);
   fChain->SetBranchAddress("tr_Meas_byHits", &tr_Meas_byHits, &b_tr_Meas_byHits);
   fChain->SetBranchAddress("nMuMu", &nMuMu, &b_nMuMu);
   fChain->SetBranchAddress("MuMuMass", &MuMuMass, &b_MuMuMass);
   fChain->SetBranchAddress("MuMuPx", &MuMuPx, &b_MuMuPx);
   fChain->SetBranchAddress("MuMuPy", &MuMuPy, &b_MuMuPy);
   fChain->SetBranchAddress("MuMuPz", &MuMuPz, &b_MuMuPz);
   fChain->SetBranchAddress("MuMuVtx_CL", &MuMuVtx_CL, &b_MuMuVtx_CL);
   fChain->SetBranchAddress("MuMuVtx_Chi2", &MuMuVtx_Chi2, &b_MuMuVtx_Chi2);
   fChain->SetBranchAddress("MuMuDecayVtx_X", &MuMuDecayVtx_X, &b_MuMuDecayVtx_X);
   fChain->SetBranchAddress("MuMuDecayVtx_Y", &MuMuDecayVtx_Y, &b_MuMuDecayVtx_Y);
   fChain->SetBranchAddress("MuMuDecayVtx_Z", &MuMuDecayVtx_Z, &b_MuMuDecayVtx_Z);
   fChain->SetBranchAddress("MuMuDecayVtx_XE", &MuMuDecayVtx_XE, &b_MuMuDecayVtx_XE);
   fChain->SetBranchAddress("MuMuDecayVtx_YE", &MuMuDecayVtx_YE, &b_MuMuDecayVtx_YE);
   fChain->SetBranchAddress("MuMuDecayVtx_ZE", &MuMuDecayVtx_ZE, &b_MuMuDecayVtx_ZE);
   fChain->SetBranchAddress("mu1Idx", &mu1Idx, &b_mu1Idx);
   fChain->SetBranchAddress("mu2Idx", &mu2Idx, &b_mu2Idx);
   fChain->SetBranchAddress("mu1Px_MuMu", &mu1Px_MuMu, &b_mu1Px_MuMu);
   fChain->SetBranchAddress("mu1Py_MuMu", &mu1Py_MuMu, &b_mu1Py_MuMu);
   fChain->SetBranchAddress("mu1Pz_MuMu", &mu1Pz_MuMu, &b_mu1Pz_MuMu);
   fChain->SetBranchAddress("mu1Chi_MuMu2", &mu1Chi_MuMu2, &b_mu1Chi_MuMu2);
   fChain->SetBranchAddress("mu1NDF_MuMu", &mu1NDF_MuMu, &b_mu1NDF_MuMu);
   fChain->SetBranchAddress("mu2Px_MuMu", &mu2Px_MuMu, &b_mu2Px_MuMu);
   fChain->SetBranchAddress("mu2Py_MuMu", &mu2Py_MuMu, &b_mu2Py_MuMu);
   fChain->SetBranchAddress("mu2Pz_MuMu", &mu2Pz_MuMu, &b_mu2Pz_MuMu);
   fChain->SetBranchAddress("mu2Chi2_MuMu", &mu2Chi2_MuMu, &b_mu2Chi2_MuMu);
   fChain->SetBranchAddress("mu2NDF_MuMu", &mu2NDF_MuMu, &b_mu2NDF_MuMu);
   fChain->SetBranchAddress("MuMuType", &MuMuType, &b_MuMuType);
   fChain->SetBranchAddress("MuMuMuonTrigMatch", &MuMuMuonTrigMatch, &b_MuMuMuonTrigMatch);
   fChain->SetBranchAddress("PriVtxMuMuCorr_n", &PriVtxMuMuCorr_n, &b_PriVtxMuMuCorr_n);
   fChain->SetBranchAddress("PriVtxMuMuCorr_X", &PriVtxMuMuCorr_X, &b_PriVtxMuMuCorr_X);
   fChain->SetBranchAddress("PriVtxMuMuCorr_Y", &PriVtxMuMuCorr_Y, &b_PriVtxMuMuCorr_Y);
   fChain->SetBranchAddress("PriVtxMuMuCorr_Z", &PriVtxMuMuCorr_Z, &b_PriVtxMuMuCorr_Z);
   fChain->SetBranchAddress("PriVtxMuMuCorr_EX", &PriVtxMuMuCorr_EX, &b_PriVtxMuMuCorr_EX);
   fChain->SetBranchAddress("PriVtxMuMuCorr_EY", &PriVtxMuMuCorr_EY, &b_PriVtxMuMuCorr_EY);
   fChain->SetBranchAddress("PriVtxMuMuCorr_EZ", &PriVtxMuMuCorr_EZ, &b_PriVtxMuMuCorr_EZ);
   fChain->SetBranchAddress("PriVtxMuMuCorr_Chi2", &PriVtxMuMuCorr_Chi2, &b_PriVtxMuMuCorr_Chi2);
   fChain->SetBranchAddress("PriVtxMuMuCorr_CL", &PriVtxMuMuCorr_CL, &b_PriVtxMuMuCorr_CL);
   fChain->SetBranchAddress("PriVtxMuMuCorr_tracks", &PriVtxMuMuCorr_tracks, &b_PriVtxMuMuCorr_tracks);
   fChain->SetBranchAddress("nTrk_afterMuMu", &nTrk_afterMuMu, &b_nTrk_afterMuMu);
   fChain->SetBranchAddress("nB0", &nB0, &b_nB0);
   fChain->SetBranchAddress("nB0_pre0", &nB0_pre0, &b_nB0_pre0);
   fChain->SetBranchAddress("nB0_pre1", &nB0_pre1, &b_nB0_pre1);
   fChain->SetBranchAddress("nB0_pre2", &nB0_pre2, &b_nB0_pre2);
   fChain->SetBranchAddress("nB0_pre3", &nB0_pre3, &b_nB0_pre3);
   fChain->SetBranchAddress("nB0_pre4", &nB0_pre4, &b_nB0_pre4);
   fChain->SetBranchAddress("nB0_pre5", &nB0_pre5, &b_nB0_pre5);
   fChain->SetBranchAddress("nB0_pre6", &nB0_pre6, &b_nB0_pre6);
   fChain->SetBranchAddress("nB0_pre7", &nB0_pre7, &b_nB0_pre7);
   fChain->SetBranchAddress("nB0_pre8", &nB0_pre8, &b_nB0_pre8);
   fChain->SetBranchAddress("nB0_pre9", &nB0_pre9, &b_nB0_pre9);
   fChain->SetBranchAddress("nB0_pre10", &nB0_pre10, &b_nB0_pre10);
   fChain->SetBranchAddress("nB0_pre11", &nB0_pre11, &b_nB0_pre11);
   fChain->SetBranchAddress("nB0_pre12", &nB0_pre12, &b_nB0_pre12);
   fChain->SetBranchAddress("nB0_pre13", &nB0_pre13, &b_nB0_pre13);
   fChain->SetBranchAddress("nB0_pre14", &nB0_pre14, &b_nB0_pre14);
   fChain->SetBranchAddress("B0Mass", &B0Mass, &b_B0Mass);
   fChain->SetBranchAddress("B0Px", &B0Px, &b_B0Px);
   fChain->SetBranchAddress("B0Py", &B0Py, &b_B0Py);
   fChain->SetBranchAddress("B0Pz", &B0Pz, &b_B0Pz);
   fChain->SetBranchAddress("B0PxE", &B0PxE, &b_B0PxE);
   fChain->SetBranchAddress("B0PyE", &B0PyE, &b_B0PyE);
   fChain->SetBranchAddress("B0PzE", &B0PzE, &b_B0PzE);
   fChain->SetBranchAddress("B0Vtx_CL", &B0Vtx_CL, &b_B0Vtx_CL);
   fChain->SetBranchAddress("B0Vtx_Chi2", &B0Vtx_Chi2, &b_B0Vtx_Chi2);
   fChain->SetBranchAddress("B0DecayVtx_X", &B0DecayVtx_X, &b_B0DecayVtx_X);
   fChain->SetBranchAddress("B0DecayVtx_Y", &B0DecayVtx_Y, &b_B0DecayVtx_Y);
   fChain->SetBranchAddress("B0DecayVtx_Z", &B0DecayVtx_Z, &b_B0DecayVtx_Z);
   fChain->SetBranchAddress("B0DecayVtx_XE", &B0DecayVtx_XE, &b_B0DecayVtx_XE);
   fChain->SetBranchAddress("B0DecayVtx_YE", &B0DecayVtx_YE, &b_B0DecayVtx_YE);
   fChain->SetBranchAddress("B0DecayVtx_ZE", &B0DecayVtx_ZE, &b_B0DecayVtx_ZE);
   fChain->SetBranchAddress("B0CosAlphaBS", &B0CosAlphaBS, &b_B0CosAlphaBS);
   fChain->SetBranchAddress("B0CosAlpha3DBS", &B0CosAlpha3DBS, &b_B0CosAlpha3DBS);
   fChain->SetBranchAddress("B0CTauBS", &B0CTauBS, &b_B0CTauBS);
   fChain->SetBranchAddress("B0CTauBSE", &B0CTauBSE, &b_B0CTauBSE);
   fChain->SetBranchAddress("B0LxyBS", &B0LxyBS, &b_B0LxyBS);
   fChain->SetBranchAddress("B0LxyBSE", &B0LxyBSE, &b_B0LxyBSE);
   fChain->SetBranchAddress("B0LxyzBS", &B0LxyzBS, &b_B0LxyzBS);
   fChain->SetBranchAddress("B0LxyzBSE", &B0LxyzBSE, &b_B0LxyzBSE);
   fChain->SetBranchAddress("B0CosAlphaPV", &B0CosAlphaPV, &b_B0CosAlphaPV);
   fChain->SetBranchAddress("B0CosAlpha3DPV", &B0CosAlpha3DPV, &b_B0CosAlpha3DPV);
   fChain->SetBranchAddress("B0CTauPV", &B0CTauPV, &b_B0CTauPV);
   fChain->SetBranchAddress("B0CTauPVE", &B0CTauPVE, &b_B0CTauPVE);
   fChain->SetBranchAddress("B0LxyPV", &B0LxyPV, &b_B0LxyPV);
   fChain->SetBranchAddress("B0LxyPVE", &B0LxyPVE, &b_B0LxyPVE);
   fChain->SetBranchAddress("B0LxyzPV", &B0LxyzPV, &b_B0LxyzPV);
   fChain->SetBranchAddress("B0LxyzPVE", &B0LxyzPVE, &b_B0LxyzPVE);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_n", &PriVtx_B0CosAlpha_n, &b_PriVtx_B0CosAlpha_n);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_X", &PriVtx_B0CosAlpha_X, &b_PriVtx_B0CosAlpha_X);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_Y", &PriVtx_B0CosAlpha_Y, &b_PriVtx_B0CosAlpha_Y);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_Z", &PriVtx_B0CosAlpha_Z, &b_PriVtx_B0CosAlpha_Z);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_EX", &PriVtx_B0CosAlpha_EX, &b_PriVtx_B0CosAlpha_EX);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_EY", &PriVtx_B0CosAlpha_EY, &b_PriVtx_B0CosAlpha_EY);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_EZ", &PriVtx_B0CosAlpha_EZ, &b_PriVtx_B0CosAlpha_EZ);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_Chi2", &PriVtx_B0CosAlpha_Chi2, &b_PriVtx_B0CosAlpha_Chi2);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_CL", &PriVtx_B0CosAlpha_CL, &b_PriVtx_B0CosAlpha_CL);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha_tracks", &PriVtx_B0CosAlpha_tracks, &b_PriVtx_B0CosAlpha_tracks);
   fChain->SetBranchAddress("B0CosAlphaPVCosAlpha", &B0CosAlphaPVCosAlpha, &b_B0CosAlphaPVCosAlpha);
   fChain->SetBranchAddress("B0CosAlpha3DPVCosAlpha", &B0CosAlpha3DPVCosAlpha, &b_B0CosAlpha3DPVCosAlpha);
   fChain->SetBranchAddress("B0CTauPVCosAlpha", &B0CTauPVCosAlpha, &b_B0CTauPVCosAlpha);
   fChain->SetBranchAddress("B0CTauPVCosAlphaE", &B0CTauPVCosAlphaE, &b_B0CTauPVCosAlphaE);
   fChain->SetBranchAddress("B0LxyPVCosAlpha", &B0LxyPVCosAlpha, &b_B0LxyPVCosAlpha);
   fChain->SetBranchAddress("B0LxyPVCosAlphaE", &B0LxyPVCosAlphaE, &b_B0LxyPVCosAlphaE);
   fChain->SetBranchAddress("B0LxyzPVCosAlpha", &B0LxyzPVCosAlpha, &b_B0LxyzPVCosAlpha);
   fChain->SetBranchAddress("B0LxyzPVCosAlphaE", &B0LxyzPVCosAlphaE, &b_B0LxyzPVCosAlphaE);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_n", &PriVtx_B0CosAlpha3D_n, &b_PriVtx_B0CosAlpha3D_n);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_X", &PriVtx_B0CosAlpha3D_X, &b_PriVtx_B0CosAlpha3D_X);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_Y", &PriVtx_B0CosAlpha3D_Y, &b_PriVtx_B0CosAlpha3D_Y);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_Z", &PriVtx_B0CosAlpha3D_Z, &b_PriVtx_B0CosAlpha3D_Z);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_EX", &PriVtx_B0CosAlpha3D_EX, &b_PriVtx_B0CosAlpha3D_EX);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_EY", &PriVtx_B0CosAlpha3D_EY, &b_PriVtx_B0CosAlpha3D_EY);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_EZ", &PriVtx_B0CosAlpha3D_EZ, &b_PriVtx_B0CosAlpha3D_EZ);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_Chi2", &PriVtx_B0CosAlpha3D_Chi2, &b_PriVtx_B0CosAlpha3D_Chi2);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_CL", &PriVtx_B0CosAlpha3D_CL, &b_PriVtx_B0CosAlpha3D_CL);
   fChain->SetBranchAddress("PriVtx_B0CosAlpha3D_tracks", &PriVtx_B0CosAlpha3D_tracks, &b_PriVtx_B0CosAlpha3D_tracks);
   fChain->SetBranchAddress("B0CosAlphaPVCosAlpha3D", &B0CosAlphaPVCosAlpha3D, &b_B0CosAlphaPVCosAlpha3D);
   fChain->SetBranchAddress("B0CosAlpha3DPVCosAlpha3D", &B0CosAlpha3DPVCosAlpha3D, &b_B0CosAlpha3DPVCosAlpha3D);
   fChain->SetBranchAddress("B0CTauPVCosAlpha3D", &B0CTauPVCosAlpha3D, &b_B0CTauPVCosAlpha3D);
   fChain->SetBranchAddress("B0CTauPVCosAlpha3DE", &B0CTauPVCosAlpha3DE, &b_B0CTauPVCosAlpha3DE);
   fChain->SetBranchAddress("B0LxyPVCosAlpha3D", &B0LxyPVCosAlpha3D, &b_B0LxyPVCosAlpha3D);
   fChain->SetBranchAddress("B0LxyPVCosAlpha3DE", &B0LxyPVCosAlpha3DE, &b_B0LxyPVCosAlpha3DE);
   fChain->SetBranchAddress("B0LxyzPVCosAlpha3D", &B0LxyzPVCosAlpha3D, &b_B0LxyzPVCosAlpha3D);
   fChain->SetBranchAddress("B0LxyzPVCosAlpha3DE", &B0LxyzPVCosAlpha3DE, &b_B0LxyzPVCosAlpha3DE);
   fChain->SetBranchAddress("B0LessPV_tracksPtSq", &B0LessPV_tracksPtSq, &b_B0LessPV_tracksPtSq);
   fChain->SetBranchAddress("B0LessPV_4tracksPtSq", &B0LessPV_4tracksPtSq, &b_B0LessPV_4tracksPtSq);
   fChain->SetBranchAddress("PriVtxB0Less_n", &PriVtxB0Less_n, &b_PriVtxB0Less_n);
   fChain->SetBranchAddress("PriVtxB0Less_X", &PriVtxB0Less_X, &b_PriVtxB0Less_X);
   fChain->SetBranchAddress("PriVtxB0Less_Y", &PriVtxB0Less_Y, &b_PriVtxB0Less_Y);
   fChain->SetBranchAddress("PriVtxB0Less_Z", &PriVtxB0Less_Z, &b_PriVtxB0Less_Z);
   fChain->SetBranchAddress("PriVtxB0Less_EX", &PriVtxB0Less_EX, &b_PriVtxB0Less_EX);
   fChain->SetBranchAddress("PriVtxB0Less_EY", &PriVtxB0Less_EY, &b_PriVtxB0Less_EY);
   fChain->SetBranchAddress("PriVtxB0Less_EZ", &PriVtxB0Less_EZ, &b_PriVtxB0Less_EZ);
   fChain->SetBranchAddress("PriVtxB0Less_Chi2", &PriVtxB0Less_Chi2, &b_PriVtxB0Less_Chi2);
   fChain->SetBranchAddress("PriVtxB0Less_CL", &PriVtxB0Less_CL, &b_PriVtxB0Less_CL);
   fChain->SetBranchAddress("PriVtxB0Less_tracks", &PriVtxB0Less_tracks, &b_PriVtxB0Less_tracks);
   fChain->SetBranchAddress("B0CosAlphaB0LessPV", &B0CosAlphaB0LessPV, &b_B0CosAlphaB0LessPV);
   fChain->SetBranchAddress("B0CosAlpha3DB0LessPV", &B0CosAlpha3DB0LessPV, &b_B0CosAlpha3DB0LessPV);
   fChain->SetBranchAddress("B0CTauB0LessPV", &B0CTauB0LessPV, &b_B0CTauB0LessPV);
   fChain->SetBranchAddress("B0CTauB0LessPVE", &B0CTauB0LessPVE, &b_B0CTauB0LessPVE);
   fChain->SetBranchAddress("B0LxyB0LessPV", &B0LxyB0LessPV, &b_B0LxyB0LessPV);
   fChain->SetBranchAddress("B0LxyB0LessPVE", &B0LxyB0LessPVE, &b_B0LxyB0LessPVE);
   fChain->SetBranchAddress("B0LxyzB0LessPV", &B0LxyzB0LessPV, &b_B0LxyzB0LessPV);
   fChain->SetBranchAddress("B0LxyzB0LessPVE", &B0LxyzB0LessPVE, &b_B0LxyzB0LessPVE);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_n", &PriVtxB0Less_B0CosAlpha_n, &b_PriVtxB0Less_B0CosAlpha_n);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_X", &PriVtxB0Less_B0CosAlpha_X, &b_PriVtxB0Less_B0CosAlpha_X);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_Y", &PriVtxB0Less_B0CosAlpha_Y, &b_PriVtxB0Less_B0CosAlpha_Y);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_Z", &PriVtxB0Less_B0CosAlpha_Z, &b_PriVtxB0Less_B0CosAlpha_Z);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_EX", &PriVtxB0Less_B0CosAlpha_EX, &b_PriVtxB0Less_B0CosAlpha_EX);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_EY", &PriVtxB0Less_B0CosAlpha_EY, &b_PriVtxB0Less_B0CosAlpha_EY);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_EZ", &PriVtxB0Less_B0CosAlpha_EZ, &b_PriVtxB0Less_B0CosAlpha_EZ);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_Chi2", &PriVtxB0Less_B0CosAlpha_Chi2, &b_PriVtxB0Less_B0CosAlpha_Chi2);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_CL", &PriVtxB0Less_B0CosAlpha_CL, &b_PriVtxB0Less_B0CosAlpha_CL);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha_tracks", &PriVtxB0Less_B0CosAlpha_tracks, &b_PriVtxB0Less_B0CosAlpha_tracks);
   fChain->SetBranchAddress("B0CosAlphaB0LessPVCosAlpha", &B0CosAlphaB0LessPVCosAlpha, &b_B0CosAlphaB0LessPVCosAlpha);
   fChain->SetBranchAddress("B0CosAlpha3DB0LessPVCosAlpha", &B0CosAlpha3DB0LessPVCosAlpha, &b_B0CosAlpha3DB0LessPVCosAlpha);
   fChain->SetBranchAddress("B0CTauB0LessPVCosAlpha", &B0CTauB0LessPVCosAlpha, &b_B0CTauB0LessPVCosAlpha);
   fChain->SetBranchAddress("B0CTauB0LessPVCosAlphaE", &B0CTauB0LessPVCosAlphaE, &b_B0CTauB0LessPVCosAlphaE);
   fChain->SetBranchAddress("B0LxyB0LessPVCosAlpha", &B0LxyB0LessPVCosAlpha, &b_B0LxyB0LessPVCosAlpha);
   fChain->SetBranchAddress("B0LxyB0LessPVCosAlphaE", &B0LxyB0LessPVCosAlphaE, &b_B0LxyB0LessPVCosAlphaE);
   fChain->SetBranchAddress("B0LxyzB0LessPVCosAlpha", &B0LxyzB0LessPVCosAlpha, &b_B0LxyzB0LessPVCosAlpha);
   fChain->SetBranchAddress("B0LxyzB0LessPVCosAlphaE", &B0LxyzB0LessPVCosAlphaE, &b_B0LxyzB0LessPVCosAlphaE);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_n", &PriVtxB0Less_B0CosAlpha3D_n, &b_PriVtxB0Less_B0CosAlpha3D_n);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_X", &PriVtxB0Less_B0CosAlpha3D_X, &b_PriVtxB0Less_B0CosAlpha3D_X);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_Y", &PriVtxB0Less_B0CosAlpha3D_Y, &b_PriVtxB0Less_B0CosAlpha3D_Y);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_Z", &PriVtxB0Less_B0CosAlpha3D_Z, &b_PriVtxB0Less_B0CosAlpha3D_Z);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_EX", &PriVtxB0Less_B0CosAlpha3D_EX, &b_PriVtxB0Less_B0CosAlpha3D_EX);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_EY", &PriVtxB0Less_B0CosAlpha3D_EY, &b_PriVtxB0Less_B0CosAlpha3D_EY);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_EZ", &PriVtxB0Less_B0CosAlpha3D_EZ, &b_PriVtxB0Less_B0CosAlpha3D_EZ);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_Chi2", &PriVtxB0Less_B0CosAlpha3D_Chi2, &b_PriVtxB0Less_B0CosAlpha3D_Chi2);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_CL", &PriVtxB0Less_B0CosAlpha3D_CL, &b_PriVtxB0Less_B0CosAlpha3D_CL);
   fChain->SetBranchAddress("PriVtxB0Less_B0CosAlpha3D_tracks", &PriVtxB0Less_B0CosAlpha3D_tracks, &b_PriVtxB0Less_B0CosAlpha3D_tracks);
   fChain->SetBranchAddress("B0CosAlphaB0LessPVCosAlpha3D", &B0CosAlphaB0LessPVCosAlpha3D, &b_B0CosAlphaB0LessPVCosAlpha3D);
   fChain->SetBranchAddress("B0CosAlpha3DB0LessPVCosAlpha3D", &B0CosAlpha3DB0LessPVCosAlpha3D, &b_B0CosAlpha3DB0LessPVCosAlpha3D);
   fChain->SetBranchAddress("B0CTauB0LessPVCosAlpha3D", &B0CTauB0LessPVCosAlpha3D, &b_B0CTauB0LessPVCosAlpha3D);
   fChain->SetBranchAddress("B0CTauB0LessPVCosAlpha3DE", &B0CTauB0LessPVCosAlpha3DE, &b_B0CTauB0LessPVCosAlpha3DE);
   fChain->SetBranchAddress("B0LxyB0LessPVCosAlpha3D", &B0LxyB0LessPVCosAlpha3D, &b_B0LxyB0LessPVCosAlpha3D);
   fChain->SetBranchAddress("B0LxyB0LessPVCosAlpha3DE", &B0LxyB0LessPVCosAlpha3DE, &b_B0LxyB0LessPVCosAlpha3DE);
   fChain->SetBranchAddress("B0LxyzB0LessPVCosAlpha3D", &B0LxyzB0LessPVCosAlpha3D, &b_B0LxyzB0LessPVCosAlpha3D);
   fChain->SetBranchAddress("B0LxyzB0LessPVCosAlpha3DE", &B0LxyzB0LessPVCosAlpha3DE, &b_B0LxyzB0LessPVCosAlpha3DE);
   fChain->SetBranchAddress("PriVtxB0Corr_n", &PriVtxB0Corr_n, &b_PriVtxB0Corr_n);
   fChain->SetBranchAddress("PriVtxB0Corr_X", &PriVtxB0Corr_X, &b_PriVtxB0Corr_X);
   fChain->SetBranchAddress("PriVtxB0Corr_Y", &PriVtxB0Corr_Y, &b_PriVtxB0Corr_Y);
   fChain->SetBranchAddress("PriVtxB0Corr_Z", &PriVtxB0Corr_Z, &b_PriVtxB0Corr_Z);
   fChain->SetBranchAddress("PriVtxB0Corr_EX", &PriVtxB0Corr_EX, &b_PriVtxB0Corr_EX);
   fChain->SetBranchAddress("PriVtxB0Corr_EY", &PriVtxB0Corr_EY, &b_PriVtxB0Corr_EY);
   fChain->SetBranchAddress("PriVtxB0Corr_EZ", &PriVtxB0Corr_EZ, &b_PriVtxB0Corr_EZ);
   fChain->SetBranchAddress("PriVtxB0Corr_Chi2", &PriVtxB0Corr_Chi2, &b_PriVtxB0Corr_Chi2);
   fChain->SetBranchAddress("PriVtxB0Corr_CL", &PriVtxB0Corr_CL, &b_PriVtxB0Corr_CL);
   fChain->SetBranchAddress("PriVtxB0Corr_tracks", &PriVtxB0Corr_tracks, &b_PriVtxB0Corr_tracks);
   fChain->SetBranchAddress("B0CosAlphaPVX", &B0CosAlphaPVX, &b_B0CosAlphaPVX);
   fChain->SetBranchAddress("B0CTauPVX", &B0CTauPVX, &b_B0CTauPVX);
   fChain->SetBranchAddress("B0CTauPVXE", &B0CTauPVXE, &b_B0CTauPVXE);
   fChain->SetBranchAddress("B0LxyPVX", &B0LxyPVX, &b_B0LxyPVX);
   fChain->SetBranchAddress("B0LxyzPVX", &B0LxyzPVX, &b_B0LxyzPVX);
   fChain->SetBranchAddress("B0CTauPVX_3D", &B0CTauPVX_3D, &b_B0CTauPVX_3D);
   fChain->SetBranchAddress("B0CTauPVX_3D_err", &B0CTauPVX_3D_err, &b_B0CTauPVX_3D_err);
   fChain->SetBranchAddress("B0MuMuIdx", &B0MuMuIdx, &b_B0MuMuIdx);
   fChain->SetBranchAddress("B0PionIdx", &B0PionIdx, &b_B0PionIdx);
   fChain->SetBranchAddress("B0KaonIdx", &B0KaonIdx, &b_B0KaonIdx);
   fChain->SetBranchAddress("PiPiMass_err", &PiPiMass_err, &b_PiPiMass_err);
   fChain->SetBranchAddress("Muon1Px_MuMuPiK", &Muon1Px_MuMuPiK, &b_Muon1Px_MuMuPiK);
   fChain->SetBranchAddress("Muon1Py_MuMuPiK", &Muon1Py_MuMuPiK, &b_Muon1Py_MuMuPiK);
   fChain->SetBranchAddress("Muon1Pz_MuMuPiK", &Muon1Pz_MuMuPiK, &b_Muon1Pz_MuMuPiK);
   fChain->SetBranchAddress("Muon1E_MuMuPiK", &Muon1E_MuMuPiK, &b_Muon1E_MuMuPiK);
   fChain->SetBranchAddress("Muon2Px_MuMuPiK", &Muon2Px_MuMuPiK, &b_Muon2Px_MuMuPiK);
   fChain->SetBranchAddress("Muon2Py_MuMuPiK", &Muon2Py_MuMuPiK, &b_Muon2Py_MuMuPiK);
   fChain->SetBranchAddress("Muon2Pz_MuMuPiK", &Muon2Pz_MuMuPiK, &b_Muon2Pz_MuMuPiK);
   fChain->SetBranchAddress("Muon2E_MuMuPiK", &Muon2E_MuMuPiK, &b_Muon2E_MuMuPiK);
   fChain->SetBranchAddress("PionPx_MuMuPiK", &PionPx_MuMuPiK, &b_PionPx_MuMuPiK);
   fChain->SetBranchAddress("PionPy_MuMuPiK", &PionPy_MuMuPiK, &b_PionPy_MuMuPiK);
   fChain->SetBranchAddress("PionPz_MuMuPiK", &PionPz_MuMuPiK, &b_PionPz_MuMuPiK);
   fChain->SetBranchAddress("PionE_MuMuPiK", &PionE_MuMuPiK, &b_PionE_MuMuPiK);
   fChain->SetBranchAddress("pion_nsigdedx", &pion_nsigdedx, &b_pion_nsigdedx);
   fChain->SetBranchAddress("pion_dedx", &pion_dedx, &b_pion_dedx);
   fChain->SetBranchAddress("pion_dedxMass", &pion_dedxMass, &b_pion_dedxMass);
   fChain->SetBranchAddress("pion_theo", &pion_theo, &b_pion_theo);
   fChain->SetBranchAddress("pion_sigma", &pion_sigma, &b_pion_sigma);
   fChain->SetBranchAddress("pion_dedx_byHits", &pion_dedx_byHits, &b_pion_dedx_byHits);
   fChain->SetBranchAddress("pion_dedxErr_byHits", &pion_dedxErr_byHits, &b_pion_dedxErr_byHits);
   fChain->SetBranchAddress("pion_saturMeas_byHits", &pion_saturMeas_byHits, &b_pion_saturMeas_byHits);
   fChain->SetBranchAddress("pion_Meas_byHits", &pion_Meas_byHits, &b_pion_Meas_byHits);
   fChain->SetBranchAddress("KaonPx_MuMuPiK", &KaonPx_MuMuPiK, &b_KaonPx_MuMuPiK);
   fChain->SetBranchAddress("KaonPy_MuMuPiK", &KaonPy_MuMuPiK, &b_KaonPy_MuMuPiK);
   fChain->SetBranchAddress("KaonPz_MuMuPiK", &KaonPz_MuMuPiK, &b_KaonPz_MuMuPiK);
   fChain->SetBranchAddress("KaonE_MuMuPiK", &KaonE_MuMuPiK, &b_KaonE_MuMuPiK);
   fChain->SetBranchAddress("kaon_nsigdedx", &kaon_nsigdedx, &b_kaon_nsigdedx);
   fChain->SetBranchAddress("kaon_dedx", &kaon_dedx, &b_kaon_dedx);
   fChain->SetBranchAddress("kaon_dedxMass", &kaon_dedxMass, &b_kaon_dedxMass);
   fChain->SetBranchAddress("kaon_theo", &kaon_theo, &b_kaon_theo);
   fChain->SetBranchAddress("kaon_sigma", &kaon_sigma, &b_kaon_sigma);
   fChain->SetBranchAddress("kaon_dedx_byHits", &kaon_dedx_byHits, &b_kaon_dedx_byHits);
   fChain->SetBranchAddress("kaon_dedxErr_byHits", &kaon_dedxErr_byHits, &b_kaon_dedxErr_byHits);
   fChain->SetBranchAddress("kaon_saturMeas_byHits", &kaon_saturMeas_byHits, &b_kaon_saturMeas_byHits);
   fChain->SetBranchAddress("kaon_Meas_byHits", &kaon_Meas_byHits, &b_kaon_Meas_byHits);
}

Bool_t BkgAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef BkgAnalysis_cxx
