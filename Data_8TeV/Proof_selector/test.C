GetPhi(TLorentzVector LoreVecB0,TLorentzVector LoreVecMum, TLorentzVector LoreVecMup, TLorentzVector LoreVecK, TLorentzVector LoreVecPi)	{
    //	#	B0	->	K+	pi-	mu	mu	#
    TVector3	boostB0	=	LoreVecB0.BoostVector();
    LoreVecMum.Boost(-boostB0);
    LoreVecMup.Boost(-boostB0);
    LoreVecK.Boost(-boostB0);
    LoreVecPi.Boost(-boostB0);
    TVector3	MuMuPlane	=	LoreVecMup.Vect().Cross(LoreVecMum.Vect());
    TVector3	KstPlane		=	LoreVecK.Vect().Cross(LoreVecPi.Vect());
    if	(	MuMuPlane.Cross(KstPlane).Dot(-LoreVecB0.Vect())	>	0.0	)
        phiKstMuMuPlane	=	MuMuPlane.Angle(KstPlane);
    else
        phiKstMuMuPlane	=	-MuMuPlane.Angle(KstPlane);
    return
    phiKstMuMuPlane;
}