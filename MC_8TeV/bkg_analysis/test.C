    hJpsiPiMass_hard             = new TH1F("hJpsiPiMass_hard","hJpsiPiMass_hard",1000,0,10);
    hKPiMass_hard                = new TH1F("hKPiMass_hard","hKPiMass_hard",1000,0,10);
    hKPiRevMass_hard             = new TH1F("hKPiRevMass_hard","hKPiRevMass_hard",1000,0,10);
    hPiPiMass_hard               = new TH1F("hPiPiMass_hard","hPiPiMass_hard",1000,0,10);
    hKKMass_hard                 = new TH1F("hKKMass_hard","hKKMass_hard",1000,0,10);
    hKProtonMass_hard            = new TH1F("hKProtonMass_hard","hKProtonMass_hard",1000,0,10);
    hPiProtonMass_hard           = new TH1F("hPiProtonMass_hard","hPiProtonMass_hard",1000,0,10);
    hKPiMass_noBs_hard           = new TH1F("hKPiMass_noBs_hard","hKPiMass_noBs_hard",1000,0,10);
    
    hJpsiPiMass_peak_hard        = new TH1F("hJpsiPiMass_peak_hard","hJpsiPiMass_peak_hard",1000,0,10);
    hKPiMass_peak_hard           = new TH1F("hKPiMass_peak_hard","hKPiMass_peak_hard",1000,0,10);
    hKPiRevMass_peak_hard        = new TH1F("hKPiRevMass_peak_hard","hKPiRevMass_peak_hard",1000,0,10);
    hPiPiMass_peak_hard          = new TH1F("hPiPiMass_peak_hard","hPiPiMass_peak_hard",1000,0,10);
    hKKMass_peak_hard            = new TH1F("hKKMass_peak_hard","hKKMass_peak_hard",1000,0,10);
    hKProtonMass_peak_hard       = new TH1F("hKProtonMass_peak_hard","hKProtonMass_peak_hard",1000,0,10);
    hPiProtonMass_peak_hard      = new TH1F("hPiProtonMass_peak_hard","hPiProtonMass_peak_hard",1000,0,10);
    
    hJpsiPiMass_sb_hard          = new TH1F("hJpsiPiMass_sb_hard","hJpsiPiMass_sb_hard",1000,0,10);
    hKPiMass_sb_hard             = new TH1F("hKPiMass_sb_hard","hKPiMass_sb_hard",1000,0,10);
    hKPiRevMass_sb_hard          = new TH1F("hKPiRevMass_sb_hard","hKPiRevMass_sb_hard",1000,0,10);
    hPiPiMass_sb_hard            = new TH1F("hPiPiMass_sb_hard","hPiPiMass_sb_hard",1000,0,10);
    hKKMass_sb_hard              = new TH1F("hKKMass_sb_hard","hKKMass_sb_hard",1000,0,10);
    hKProtonMass_sb_hard         = new TH1F("hKProtonMass_sb_hard","hKProtonMass_sb_hard",1000,0,10);
    hPiProtonMass_sb_hard        = new TH1F("hPiProtonMass_sb_hard","hPiProtonMass_sb_hard",1000,0,10);
    
    hjpsiKPiMassBaseSelAlt_hard      = new TH1F("hjpsiKPiMassBaseSelAlt_hard"," MuMuKPiMass after hard selection",100, 4.8, 5.8);
    hjpsiKPiRevMassBaseSelAlt_hard   = new TH1F("hjpsiKPiRevMassBaseSelAlt_hard"," MuMuKPiMass K-Pi reversed after hard selection",100, 4.8, 5.8);
    hjpsiKKMassBaseSelAlt_hard       = new TH1F("hjpsiKKMassBaseSelAlt_hard"," MuMuKKMass after hard selection",100, 4.8, 5.8);
    hjpsiPiPiMassBaseSelAlt_hard     = new TH1F("hjpsiPiPiMassBaseSelAlt_hard"," MuMuPiPiMass after hard selection",100, 4.8, 5.8);
    hjpsiKProtonMassBaseSelAlt_hard      = new TH1F("hjpsiKProtonMassBaseSelAlt_hard"," MuMuKProtonMass after hard selection",100, 4.8, 5.8);
    hjpsiPiProtonMassBaseSelAlt_hard      = new TH1F("hjpsiPiProtonMassBaseSelAlt_hard"," MuMuPiProtonMass after hard selection",100, 4.8, 5.8);
    hjpsiPhiToKKMass_hard            = new TH1F("hjpsiPhiToKKMass_hard"," Jpsi Phi (-> KK) Mass after hard selection",100, 4.8, 5.8);
//    hjpsiKPiMassSelAlt		= new TH1F("hjpsiKPiMassSelAlt","hmjpsiKPiMassSel ALTERNATIVE", 100, 4.8, 5.8);
    hjpsiKPiMassNoPhi_hard 		= new TH1F("hjpsiKPiMassNoPhi_hard","hjpsiKPiMass No Phi to KK hard sel ", 100, 4.8, 5.8);
    hjpsiKPiMassNoPhi_discard_hard 		= new TH1F("hjpsiKPiMassNoPhi_discard_hard","hjpsiKPiMass discarded for Phi->KK hard sel", 100, 4.8, 5.8);
    hjpsiPiPiMassNoPhi_hard 		= new TH1F("hjpsiPiPiMassNoPhi_hard","hjpsiPiPiMass No Phi to KK hard sel", 100, 4.8, 5.8);
    hjpsiPiPiMassNoPhi_discard_hard		= new TH1F("hjpsiPiPiMassNoPhi_discard_hard","hjpsiPiPiMass discarded for Phi->KK hard sel", 100, 4.8, 5.8);
//    hjpsiKPiMassNoPhiNoBs 	= new TH1F("hjpsiKPiMassNoPhiNoBs","hjpsiKPiMass No Phi to KK && no Bs ", 100, 4.8, 5.8);

    hJpsiKPi_JpsiKKBaseSelAlt_hard   = new TH2F("hJpsiKPi_JpsiKKBaseSelAlt_hard", "m(JpsiKPi)(x) vs m(JpsiKK)(y) hard sel",100, 4.8, 5.8,100, 4.8, 5.8 );
    hJpsiKPi_JpsiPiPiBaseSelAlt_hard   = new TH2F("hJpsiKPi_JpsiPiPiBaseSelAlt_hard", "m(JpsiKPi)(x) vs m(JpsiPiPi)(y) hard sel",100, 4.8, 5.8,100, 4.8, 5.8 );
    hJpsiKPi_JpsiPiProtonBaseSelAlt_hard   = new TH2F("hJpsiKPi_JpsiPiProtonBaseSelAlt_hard", "m(JpsiKPi)(x) vs m(JpsiProtonPi)(y) hard sel",100, 4.8, 5.8,100, 4.8, 5.8 );
    hJpsiKPi_JpsiKProtonBaseSelAlt_hard   = new TH2F("hJpsiKPi_JpsiKProtonBaseSelAlt_hard", "m(JpsiKPi)(x) vs m(JpsiKProton)(y) hard sel",100, 4.8, 5.8,100, 4.8, 5.8 );

    hDalitz_peak_hard            = new TH2F("hDalitz_peak_hard","hDalitz_peak hard sel",600,0,6,1700,9,26);
    hDalitz_sideband_hard        = new TH2F("hDalitz_sideband_hard","hDalitz_sideband hard sel",600,0,6,1700,9,26);
