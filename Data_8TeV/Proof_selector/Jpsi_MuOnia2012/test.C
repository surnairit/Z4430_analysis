hjpsiKPiMassSelAltZoomTrackpt2p5 	= new TH1F("hjpsiKPiMassSelAltZoomTrackpt2p5","hjpsiKPiMassSel ALTERNATIVE ZOOM Trackpt > 2.5", 90, 5.15, 5.45);
hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5	= new TH1F("hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5","hjpsiKPiMassSelAltZoom B0pt >18 GeV,Trackpt > 2.5 ",90, 5.15, 5.45);


hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1 	= new TH1F("hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1","hjpsiKPiMassSel ALTERNATIVE ZOOM Trackpt > 2.5 nB0eq1", 90, 5.15, 5.45);
hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1	= new TH1F("hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1","hjpsiKPiMassSelAltZoom B0pt >18 GeV,Trackpt > 2.5 nB0eq1 ",90, 5.15, 5.45)


TH1F* hjpsiKPiMassSelAltZoomTrackpt2p5;
TH1F* hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5;

TH1F* hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1;
TH1F* hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1;



hjpsiKPiMassSelAltZoomTrackpt2p5->Write();
hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5->Write();

hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1->Write();
hjpsiKPiMassSelAltZoomB0pt18Trackpt2p5_nB0eq1->Write();





if(pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5) { // track pt hard cut
    hjpsiKPiMassSelAltZoomTrackpt2p5->Fill( B0MassAlt );
} // track pt hard cut

if(   B0_Pt > 18.0  && pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5 ) { // All hard cuts
    hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3->Fill( B0MassAlt );
} // all hard cuts



if(pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5) { // track pt hard cut
    hjpsiKPiMassSelAltZoomTrackpt2p5_nB0eq1->Fill( B0MassAlt );
} // track pt hard cut

if(   B0_Pt > 18.0  && pion_fromB0_Pt > 2.5 && kaon_fromB0_Pt > 2.5 ) { // All hard cuts
    hjpsiKPiMassSelAltZoomB0pt18Trackpt4p3_nB0eq1->Fill( B0MassAlt );
} // all hard cuts







h_theta_Jpsi_Trackpt2p5            = new TH1F("h_theta_Jpsi_Trackpt2p5","J/#psi helicity angle Trackpt > 2.5 ;#theta_{J/#psi}", 160, -0.03, 3.17);
h_theta_Kstar_Trackpt2p5          = new TH1F("h_theta_Kstar_Trackpt2p5","K* helicity angle Trackpt > 2.5 ;#theta_{K*}", 160, -0.03, 3.17);
h_phi_planes_Trackpt2p5            = new TH1F("h_phi_planes_Trackpt2p5","Angle between K#pi and #mu#mu planes Trackpt > 2.5 ;#phi(J/#psi,K*)", 160, -3.2, 3.2) ;


TH1F* h_theta_Jpsi_Trackpt2p5;
TH1F* h_theta_Kstar_Trackpt2p5;
TH1F* h_phi_planes_Trackpt2p5;

h_theta_Jpsi_Trackpt2p5->Write();
h_theta_Kstar_Trackpt2p5->Write();
h_phi_planes_Trackpt2p5->Write();


h_theta_Jpsi_Trackpt2p5->Fill();
h_theta_Kstar_Trackpt2p5->Fill();
h_phi_planes_Trackpt2p5->Fill();
