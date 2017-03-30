		    // muon1 // B0 mass const relative change // nsmod
		    mu1Px_MuMuPiK_B0Mass_rel->push_back(( mu1_MuMuPiK_B0Mass->currentState().globalMomentum().x() - rmu1->px() )/ rmu1->px());
		    mu1Py_MuMuPiK_B0Mass_rel->push_back(( mu1_MuMuPiK_B0Mass->currentState().globalMomentum().y() - rmu1->py() )/ rmu1->py());
		    mu1Pz_MuMuPiK_B0Mass_rel->push_back(( mu1_MuMuPiK_B0Mass->currentState().globalMomentum().z() - rmu1->pz() )/ rmu1->pz());
		    mu1E_MuMuPiK_B0Mass_rel->push_back(( mu1_MuMuPiK_B0Mass->currentState().kinematicParameters().energy() - rmu1->energy() )/ rmu1->energy());
		    // muon2 // B0 mass const relative change // nsmod
		    mu2Px_MuMuPiK_B0Mass_rel->push_back(( mu2_MuMuPiK_B0Mass->currentState().globalMomentum().x() - rmu2->px() )/ rmu2->px());
		    mu2Py_MuMuPiK_B0Mass_rel->push_back(( mu2_MuMuPiK_B0Mass->currentState().globalMomentum().y() - rmu2->py() )/ rmu2->py());
		    mu2Pz_MuMuPiK_B0Mass_rel->push_back(( mu2_MuMuPiK_B0Mass->currentState().globalMomentum().z() - rmu2->pz() )/ rmu2->pz());
		    mu2E_MuMuPiK_B0Mass_rel->push_back(( mu2_MuMuPiK_B0Mass->currentState().kinematicParameters().energy() - rmu2->energy() )/ rmu2->energy());
		    // pion // B0 mass const relative change // nsmod
		    piPx_MuMuPiK_B0Mass_rel->push_back(( pi_MuMuPiK_B0Mass->currentState().globalMomentum().x() - Track1->px() )/ Track1->px());
		    piPy_MuMuPiK_B0Mass_rel->push_back(( pi_MuMuPiK_B0Mass->currentState().globalMomentum().y() - Track1->py() )/ Track1->py());
		    piPz_MuMuPiK_B0Mass_rel->push_back(( pi_MuMuPiK_B0Mass->currentState().globalMomentum().z() - Track1->pz() )/ Track1->pz());
		    piE_MuMuPiK_B0Mass_rel->push_back(( pi_MuMuPiK_B0Mass->currentState().kinematicParameters().energy() - Track1->energy() )/ Track1->energy());
		    // kaon // B0 mass const relative change // nsmod
		    kPx_MuMuPiK_B0Mass_rel->push_back(( k_MuMuPiK_B0Mass->currentState().globalMomentum().x() - Track2->px() )/ Track2->px());
		    kPy_MuMuPiK_B0Mass_rel->push_back(( k_MuMuPiK_B0Mass->currentState().globalMomentum().y() - Track2->py() )/ Track2->py());
		    kPz_MuMuPiK_B0Mass_rel->push_back(( k_MuMuPiK_B0Mass->currentState().globalMomentum().z() - Track2->pz() )/ Track2->pz());
		    kE_MuMuPiK_B0Mass_rel->push_back(( k_MuMuPiK_B0Mass->currentState().kinematicParameters().energy() - Track2->energy() )/ Track2->energy());

		    // muon1 // Jpsi mass const relative change // nsmod
		    mu1Px_MuMuPiK_JpsiMass_rel->push_back(( mu1_MuMuPiK_JpsiMass->currentState().globalMomentum().x() - rmu1->px() )/ rmu1->px());
		    mu1Py_MuMuPiK_JpsiMass_rel->push_back(( mu1_MuMuPiK_JpsiMass->currentState().globalMomentum().y() - rmu1->py() )/ rmu1->py());
		    mu1Pz_MuMuPiK_JpsiMass_rel->push_back(( mu1_MuMuPiK_JpsiMass->currentState().globalMomentum().z() - rmu1->pz() )/ rmu1->pz());
		    mu1E_MuMuPiK_JpsiMass_rel->push_back(( mu1_MuMuPiK_JpsiMass->currentState().kinematicParameters().energy() - rmu1->energy() )/ rmu1->energy());
		    // muon2 // Jpsi mass const relative change // nsmod
		    mu2Px_MuMuPiK_JpsiMass_rel->push_back(( mu2_MuMuPiK_JpsiMass->currentState().globalMomentum().x() - rmu2->px() )/ rmu2->px());
		    mu2Py_MuMuPiK_JpsiMass_rel->push_back(( mu2_MuMuPiK_JpsiMass->currentState().globalMomentum().y() - rmu2->py() )/ rmu2->py());
		    mu2Pz_MuMuPiK_JpsiMass_rel->push_back(( mu2_MuMuPiK_JpsiMass->currentState().globalMomentum().z() - rmu1->pz() )/ rmu1->pz());
		    mu2E_MuMuPiK_JpsiMass_rel->push_back(( mu2_MuMuPiK_JpsiMass->currentState().kinematicParameters().energy() - rmu2->energy() )/ rmu2->energy());
		    // pion // Jpsi mass const relative change // nsmod
		    piPx_MuMuPiK_JpsiMass_rel->push_back(( pi_MuMuPiK_JpsiMass->currentState().globalMomentum().x() - Track1->px() )/ Track1->px());
		    piPy_MuMuPiK_JpsiMass_rel->push_back(( pi_MuMuPiK_JpsiMass->currentState().globalMomentum().y() - Track1->py() )/ Track1->py());
		    piPz_MuMuPiK_JpsiMass_rel->push_back(( pi_MuMuPiK_JpsiMass->currentState().globalMomentum().z() - Track1->pz() )/ Track1->pz());
		    piE_MuMuPiK_JpsiMass_rel->push_back(( pi_MuMuPiK_JpsiMass->currentState().kinematicParameters().energy() - Track1->energy() )/ Track1->energy());
		    // kaon // Jpsi mass const relative change // nsmod
		    kPx_MuMuPiK_JpsiMass_rel->push_back(( k_MuMuPiK_JpsiMass->currentState().globalMomentum().x() - Track2->px() )/ Track2->px());
		    kPy_MuMuPiK_JpsiMass_rel->push_back(( k_MuMuPiK_JpsiMass->currentState().globalMomentum().y() - Track2->py() )/ Track2->py());
		    kPz_MuMuPiK_JpsiMass_rel->push_back(( k_MuMuPiK_JpsiMass->currentState().globalMomentum().z() - Track2->pz() )/ Track2->pz());
		    kE_MuMuPiK_JpsiMass_rel->push_back(( k_MuMuPiK_JpsiMass->currentState().kinematicParameters().energy() - Track2->energy() )/ Track2->energy());
