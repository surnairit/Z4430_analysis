{{
    /////////////////////////////////////////////////////
    //
    // INPUT DATA SAMPLE
//    TDSet* dataset = new TDSet("TTree", "Z_data","mkcands");
    TDSet* dataset = new TDSet("TTree", "Z_data");
    //
    ////////////////////////////////////////////////////// full path is mandatory
    //


    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012A_29Dec_MuMuKPiPAT_ntpl_merged_0000_1-818.root");
/*
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_1-500.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_501-999.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_1000-1999.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012B_08Oct_MuMuKPiPAT_ntpl_merged_0000_2000-2546.root");
    
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012C_29Dec_MuMuKPiPAT_ntpl_merged_0001_1000-1999.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012C_31Dec_MuMuKPiPAT_ntpl_merged_0000_1-999.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012C_31Dec_MuMuKPiPAT_ntpl_merged_0002_2000-2015.root");


    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012D_31Dec_MuMuKPiPAT_ntpl_merged_0000_1-999.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012D_31Dec_MuMuKPiPAT_ntpl_merged_0001_1000-1999.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012D_31Dec_MuMuKPiPAT_ntpl_merged_0002_2000-2999.root");
    dataset->Add("/lustre/cms/store/user/nsur/Jpsi_8TeV_data_small_ntuples/MuOniaRun2012D_31Dec_MuMuKPiPAT_ntpl_merged_0003_3000-3718.root");
*/


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
    TString selector = "Data_Analysis_Zangles";
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
