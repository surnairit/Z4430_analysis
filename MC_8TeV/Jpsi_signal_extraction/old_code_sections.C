// from .h file 

   TH1F* hMuMuMass;
   TH1F* hExclusiveMuMuKPiMass ;
   TH1F* hjpsiKPiMass ;
   TH1F* hjpsiKPiMass_KPiExchanged ;
   TH1F* hjpsifromBMass ;

   TH1F* hjpsiMass_fromB0 ;
   TH1F* hjpsiPiMass ;

   TH1F* hPiPtcalc;
   TH1F* hPiEtacalc;
   TH1F* hPiPhicalc;
   TH1F* hPiMasscalc;

   TH1F* hKPtcalc;
   TH1F* hKEtacalc;
   TH1F* hKPhicalc;
   TH1F* hKMasscalc;

   TH1F* hJpsiPtcalc;
   TH1F* hJpsiEtacalc;
   TH1F* hJpsiPhicalc;
   TH1F* hJpsiMasscalc;

   TH1F* hB0Ptcalc;
   TH1F* hB0Etacalc;
   TH1F* hB0Phicalc;
   TH1F* hB0Masscalc;

   TH1F* hJpsiMassDiff;

   TH1F* hjpsiKPiMassBaseSelAlt2;
   TH1F* hjpsiKPiMassBaseSelAlt3;
   TH1F* hjpsiKPiMassBaseSelAlt4;



// from .C file


   hMuMuMass = new TH1F("hMuMuMass", "MuMuMass;m(#mu^{+}#mu^{-}) [GeV]", 200, 2.5, 4.5);
   hExclusiveMuMuKPiMass = new TH1F("hExclusiveMuMuKPiMass","MuMuKPiMass with nB0.gt.0 BEFORE selection",100, 4.8, 5.8);
   hjpsiKPiMass = new TH1F("hjpsiKPiMass","RECALCULATED MuMuKPiMass with nB0.gt.0 BEFORE selection",100, 4.8, 5.8);
   hjpsiKPiMass_KPiExchanged = new TH1F("hjpsiKPiMass_KPiExchanged","RECALCULATED B0Mass nB0.gt.0 BEF sel with inverted K-Pi mass hypotheses", 100, 4.8, 5.8);
   hjpsifromBMass = new TH1F("hjpsifromBMass", "MuMuMass from B0 ;m(#mu^{+}#mu^{-}) [GeV]", 200, 2.5, 4.5);

   hjpsiMass_fromB0 = new TH1F("hjpsiMass_fromB0","hjpsiMass_fromB0", 100, 2.9, 3.3);
   hjpsiPiMass = new TH1F("hjpsiPiMass","J/#Psi #pi Mass;m(J/#Psi  #pi) [GeV]",40,3.8,4.8);


   hPiPtcalc	=	new	TH1F("hPiPtcalc","hPiPtcalc",200,0,200);
   hPiEtacalc	=	new	TH1F("hPiEtacalc","hPiEtacalc",100,-5,5);
   hPiPhicalc	=	new	TH1F("hPiPhicalc","hPiPhicalc",100,-3.15,3.15);
   hPiMasscalc	=	new	TH1F("hPiMasscalc","hPiMasscalc",10000,0,100);
			
   hKPtcalc	=	new	TH1F("hKPtcalc","hKPtcalc",200,0,200);
   hKEtacalc	=	new	TH1F("hKEtacalc","hKEtacalc",100,-5,5);
   hKPhicalc	=	new	TH1F("hKPhicalc","hKPhicalc",100,-3.15,3.15);
   hKMasscalc	=	new	TH1F("hKMasscalc","hKMasscalc",10000,0,100);
			
   hJpsiPtcalc	=	new	TH1F("hJpsiPtcalc","hJpsiPtcalc",200,0,200);
   hJpsiEtacalc	=	new	TH1F("hJpsiEtacalc","hJpsiEtacalc",100,-5,5);
   hJpsiPhicalc	=	new	TH1F("hJpsiPhicalc","hJpsiPhicalc",100,-3.15,3.15);
   hJpsiMasscalc=	new	TH1F("hJpsiMasscalc","hJpsiMasscalc",10000,0,100);
			
   hB0Ptcalc	=	new	TH1F("hB0Ptcalc","hB0Ptcalc",200,0,200);
   hB0Etacalc	=	new	TH1F("hB0Etacalc","hB0Etacalc",100,-5,5);
   hB0Phicalc	=	new	TH1F("hB0Phicalc","hB0Phicalc",100,-3.15,3.15);
   hB0Masscalc	=	new	TH1F("hB0Masscalc","hB0Masscalc",10000,0,100);


   hJpsiMassDiff=	new	TH1F("hJpsiMassDiff","hJpsiMassDiff",10000,-10,10);

   hjpsiKPiMassBaseSelAlt2 = new TH1F("hjpsiKPiMassBaseSelAlt2"," MuMuKPiMass after basic selection 2",10000, 0, 100);
   hjpsiKPiMassBaseSelAlt3 = new TH1F("hjpsiKPiMassBaseSelAlt3"," MuMuKPiMass after basic selection 3",10000, 0, 100);
   hjpsiKPiMassBaseSelAlt4 = new TH1F("hjpsiKPiMassBaseSelAlt4"," MuMuKPiMass after basic selection 4",10000, 0, 100);

hJpsiMassDiff->Fill( jpsi_mass - jpsip4.M() );

hJpsiPtcalc	->Fill(jpsip4.Pt());
hJpsiEtacalc	->Fill(jpsip4.Eta());
hJpsiPhicalc	->Fill(jpsip4.Phi());
hJpsiMasscalc	->Fill(jpsip4.M());

hPiPtcalc	->Fill(pip4.Pt());
hPiEtacalc	->Fill(pip4.Eta());
hPiPhicalc	->Fill(pip4.Phi());
hPiMasscalc	->Fill(pip4.M());

hKPtcalc	->Fill(kp4.Pt());
hKEtacalc	->Fill(kp4.Eta());
hKPhicalc	->Fill(kp4.Phi());
hKMasscalc	->Fill(kp4.M());

hB0Ptcalc	->Fill(B0p4.Pt());
hB0Etacalc	->Fill(B0p4.Eta());
hB0Phicalc	->Fill(B0p4.Phi());
hB0Masscalc	->Fill(B0p4.M());


  hExclusiveMuMuKPiMass->Fill( (*B0Mass)[myB0Idx] ) ; // B0mass before any selection
  hjpsiKPiMass->Fill(B0p4.M());                    // recalculated with 4-vectors
  hjpsiKPiMass_KPiExchanged->Fill(B0p4_KPiExchanged.M()); // recalculated exchanging mass hypotheses


  hjpsifromBMass->Fill((*MuMuMass)[jpsiId]);

      hMuMuMass->Write() ;
      hExclusiveMuMuKPiMass->Write() ;
      hjpsiKPiMass->Write() ;
      hjpsiKPiMass_KPiExchanged->Write() ;
      hjpsifromBMass->Write() ;

      hjpsiMass_fromB0->Write() ;
      hjpsiPiMass->Write() ;



