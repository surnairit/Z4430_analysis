{

    TFile *f = new TFile("MuMuPiK_Jpsi_MuOnia2012ABCD_output_finalcuts_ntuple_for_fit.root");
    TNtuple *nt1 = (TNtuple*)f->Get("_nt");
    
    Double_t KPi_mass, JpsiPi_mass, Theta_Jpsi, Phi, Ksign;
    
    nt1->SetBranchAddress("KPi_mass",&KPi_mass);
    nt1->SetBranchAddress("JpsiPi_mass",&JpsiPi_mass);
    nt1->SetBranchAddress("Theta_Jpsi",&Theta_Jpsi);
    nt1->SetBranchAddress("Phi",&Phi);
    nt1->SetBranchAddress("Ksign",&Ksign);
    
    ofstream myfile1 ("MuMuPiK_Jpsi_MuOnia2012ABCD_dataset_all.txt");
    ofstream myfile2 ("MuMuPiK_Jpsi_MuOnia2012ABCD_dataset_B0.txt");
    ofstream myfile3 ("MuMuPiK_Jpsi_MuOnia2012ABCD_dataset_B0bar.txt");
    
    Int_t nentries = (Int_t)nt1->GetEntries();
    for (Int_t i=0;i<nentries;i++) {
        nt1->GetEntry(i);
        Float_t cosMuMu = TMath::Cos(Theta_Jpsi);
        
        myfile1 << KPi_mass << " " << JpsiPi_mass << " " << cosMuMu << " " << Phi << " " << Ksign << endl;
        if (Ksign > 0) {
            myfile2 << KPi_mass << " " << JpsiPi_mass << " " << cosMuMu << " " << Phi << endl;
        } else {
            myfile3 << KPi_mass << " " << JpsiPi_mass << " " << cosMuMu << " " << Phi << endl;
        }
    
    }
    myfile1.close();
    myfile2.close();
    myfile3.close();

}
