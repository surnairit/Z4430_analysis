          if (doB0MassConst) { // MassConst = 'MC' in the following
		    //MultiTrackKinematicConstraint *MuMu = new  TwoTrackMassKinematicConstraint(psi2S_mass);
		    MultiTrackKinematicConstraint *MuMuPiK = 0;
            MuMuPiK = new MultiTrackMassKinematicConstraint(B0_mass);
    
		    B0VertexFitTree = B0Fitter.fit( b0Daughters, MuMuPiK );
		    if (notRefittedPartner) { // use not refitted kaons
		      b0Daughters.pop_back() ;
		      b0Daughters.push_back(pFactory.particle( kaonTT_notRefit, kaon_mass, chi, ndf, small_sigma));
		      B0VertexFitTree_noKrefit = B0Fitter.fit( b0Daughters, MuMu );
		    }
		  } 
		  else {
            B0VertexFitTree = B0Fitter.fit( b0Daughters, MuMu );
		    if (notRefittedPartner) { // use not refitted kaons
		      b0Daughters.pop_back() ;
		      b0Daughters.push_back(pFactory.particle( kaonTT_notRefit, kaon_mass, chi, ndf, small_sigma));
		      B0VertexFitTree_noKrefit = B0Fitter.fit( b0Daughters, MuMu );
		    }
        }
