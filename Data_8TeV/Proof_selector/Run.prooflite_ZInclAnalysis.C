{{
    /////////////////////////////////////////////////////
    //
    // INPUT DATA SAMPLE
    TDSet* dataset = new TDSet("TTree", "Z_data");
    // 
    ////////////////////////////////////////////////////// full path is mandatory
    //
//    dataset->Add("/cmshome/pompili/for-nairit-new/MuOniaRun2012D_13Jul_JPsiPiPiPAT-datasetD_856and1118and2110and3411.root");
//    dataset->Add("/cmshome/pompili/for-nairit-new/MuOniaRun2012C_13Jul_JPsiPiPiPAT_ntpl_3074.root");
//    dataset->Add("/cmshome/nsur/Z_analysis/for-nairit-new/merged_MuOniaRun2012C_13Jul_JPsiPiPiPAT-datasetA_just9_random_files.root");
//    dataset->Add("/lustre/cms/store/user/nsur/MuOniaRun2012B_13Jul_JPsiPiPiPAT-datasetB.root");
//    dataset->Add("/cmshome/cristella/work/Z_analysis/exclusive/CMSSW_5_3_7_patch5/src/UserCode/PsiPrimePiKPAT/test/rootuples/june2014/MuOniaRun2012B_13Jul_JPsiPiPiPAT-datasetB.root");
/*
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0000.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0001.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0002.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0003.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0004.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0005.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0006.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0007.root");
      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaParked_Run2012C_22Jan2013v1_MuMuPiKPAT_0008.root");
*/
//      dataset->Add("/cmshome/nsur/Z_analysis_2/Jpsi_8TeV_ntuples/MuOniaRun2012D_25Apr_MuMuPiPiPAT_first10files.root");
//      dataset->Add("/lustre/cms/store/user/nsur/Jpsi_samples/MuOniaRun2012D_25Apr_MuMuPiPiPAT_ntpl_0000.root");
//      dataset->Add("/lustre/cms/store/user/nsur/Jpsi_samples/MuOniaRun2012D_25Apr_MuMuPiPiPAT_ntpl_0001.root");
//      dataset->Add("/lustre/cms/store/user/nsur/Jpsi_samples/MuOniaRun2012D_25Apr_MuMuPiPiPAT_ntpl_0002.root");
//      dataset->Add("/lustre/cms/store/user/nsur/Jpsi_samples/MuOniaRun2012D_25Apr_MuMuPiPiPAT_ntpl_0003.root"); 
	dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_1-500.root");
	dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_501-999.root");
	dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_1000-1999.root");
	dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_2000-2546.root");
   //
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    //
//    TString selector = "psiPrimePiPi_Bari";
//    TString selector = "psiPrimePiK_Bari_forNairit";
//    TString selector = "SignalExtract_Jpsi_new";
    TString selector = "SignalExtract_Jpsi_small_ntpls";
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
