{{
    /////////////////////////////////////////////////////
    //
    // INPUT DATA SAMPLE
//    TDSet* dataset = new TDSet("TTree", "Z_data","mkcands");
    TDSet* dataset = new TDSet("TTree", "Z_data"); 
   // 
    ////////////////////////////////////////////////////// full path is mandatory
    //
//    dataset->Add("/cmshome/pompili/for-nairit-new/MuOniaRun2012D_13Jul_JPsiPiPiPAT-datasetD_856and1118and2110and3411.root");
//    dataset->Add("/cmshome/pompili/for-nairit-new/MuOniaRun2012C_13Jul_JPsiPiPiPAT_ntpl_3074.root");
//    dataset->Add("/cmshome/nsur/Z_analysis/for-nairit-new/merged_MuOniaRun2012C_13Jul_JPsiPiPiPAT-datasetA_just9_random_files.root");
//    dataset->Add("/lustre/cms/store/user/nsur/MuOniaRun2012B_13Jul_JPsiPiPiPAT-datasetB.root");
//    dataset->Add("/cmshome/cristella/work/Z_analysis/exclusive/CMSSW_5_3_7_patch5/src/UserCode/PsiPrimePiKPAT/test/rootuples/june2014/MuOniaRun2012B_13Jul_JPsiPiPiPAT-datasetB.root");
//     dataset->Add("/lustre/cms/store/user/nsur/DoubleMu_Run2012A_13Jul2012_RECO_MuMuPiKPAT_ntpl_merged.root");
//     dataset->Add("/lustre/cms/store/user/nsur/DoubleMu_Run2012D_PromptReco_RECO_MuMuPiKPAT_ntpl_merged.root");
//     dataset->Add("/lustre/cms/store/user/lecriste/june2016/B0ToPsiMuMu_2MuPtEtaFilter_8TeV-pythia6-evtgen/crab_official_MC_B0ToPsiMuMu_nB0/160529_225236/officialBdToPsiMuMu_noPtEtaCut_MuMuPiKPAT_ntpl__0004.root");
//     dataset->Add("/lustre/cms/store/user/lecriste/june2016/BsToPsiMuMu_2MuPtEtaFilter_8TeV-pythia6-evtgen/crab_official_MC_Bs0ToPsiMuMu_nB0/160624_172914/officialBsToPsiMuMu_noPtEtaCut_MuMuPiKPAT_ntpl__0001.root");
     dataset->Add("/lustre/cms/store/user/lecriste/june2016/BpToPsiMuMu_2MuPtEtaFilter_8TeV-pythia6-evtgen/crab_official_MC_Bu0ToPsiMuMu_nB0/160705_133450/BuToJpsiK_18Mar_MuMuPiKPAT_ntpl__0001.root");
//     dataset->Add("/lustre/cms/store/user/lecriste/june2016/LambdaBToPsiMuMu_2MuPtEtaFilter_8TeV-pythia6-evtgen/crab_official_MC_LambdaBToPsiMuMu_nB0/160926_095259/officialLambdabToPsiMuMu_noPtEtaCut_MuMuPiKPAT_ntpl_.root");
//     dataset->Add("/lustre/home/nsur/Z_analysis_bkg/officialBdToPsiMuMu_noPtEtaCut_MuMuPiKPAT_ntpl_619.root");
/*
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/lustre/cms/store/user/nsur/DoubleMu_Run2012A_13Jul2012_RECO_MuMuPiPiPAT_ntpl_merged.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/lustre/cms/store/user/nsur/DoubleMu_Run2012A_13Jul2012_RECO_MuMuPiPiPAT_ntpl_merged.root");
      }

     TDirectory * dir = (TDirectory*)f->Get("/lustre/cms/store/user/nsur/DoubleMu_Run2012A_13Jul2012_RECO_MuMuPiPiPAT_ntpl_merged.root:/mkcands");
TTree *tree=0;
     dir->GetObject("Z_data",tree);
    //
    dataset->Add(tree);
*/
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    //
//    TString selector = "TestSel";
    TString selector = "BkgAnalysis";
    // 
//    TProof *p = TProof::Open("workers=4");
    TProof *p = TProof::Open("workers=8");
    //
    // Processing...
    cout << ">> Processing " << selector << " ..." << endl;
    TString selectorcplus = selector;
    selectorcplus+= ".C+";
    p->Process(dataset,selectorcplus);  
    //
//////////////////////////////
// how configure PROOF:
//
// root -l 
// root [1] TFile *f=TFile::Open("/yourpath/yourname.root")
// root [2] TTree *tree=(TTree*)f->Get("Z_data")    // get the tree with the name chosen at analyzer level
// root [3] tree->MakeSelector("PsiPrimePiPi_Bari") // choose a name
//
// following one is not a real problem
// Error in <TTreePlayer::MakeClass>: The branch named nX (full path name: nX) is hidden by another branch of the same name and its data will not be loaded.
// Info in <TTreePlayer::MakeClass>: Files: psiPrimePiPi_Bari.h and psiPrimePiPi_Bari.C generated from TTree: Z_data
// (Int_t)0
//
// root [0] .x Run.prooflite_ZInclAnalysis.C // wrapper to run proof-lite can have any name
////////////////////////////
   //
  }}
