#ifndef MuMuPiKPAT_interface_VertexReProducer_h
#define MuMuPiKPAT_interface_VertexReProducer_h

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "RecoVertex/PrimaryVertexProducer/interface/PrimaryVertexProducerAlgorithm.h"

#include <vector>
using namespace std;

class VertexReProducer {
    public:
        /// This is the real constructor to be used
        VertexReProducer(const edm::Handle<reco::VertexCollection> &configFromOriginalVertexCollection, const edm::Event &iEvent ) ;
        /// This is only for testing
        VertexReProducer(const edm::ParameterSet &configByHand) { configure(configByHand); } 

        /// Make the vertices
        std::vector<TransientVertex> makeVertices(const reco::TrackCollection &tracks, const reco::BeamSpot &bs, const edm::EventSetup &iSetup) const;
	// added by Leo
	std::vector<TransientVertex> makeVertices(const std::vector<reco::TransientTrack> &tracks, const reco::BeamSpot &bs, const edm::EventSetup &iSetup) const; 

        /// Get the configuration used in the VertexProducer
        const edm::ParameterSet & inputConfig()   const { return config_; }

        /// Get the InputTag of the TrackCollection used in the VertexProducer
        const edm::InputTag &     inputTracks()   const { return tracksTag_; }

        /// Get the InputTag of the BeamSpot used in the VertexProducer
        const edm::InputTag &     inputBeamSpot() const { return beamSpotTag_; }
    private:
        void configure(const edm::ParameterSet &iConfig) ;

        edm::ParameterSet config_;
        edm::InputTag     tracksTag_;
        edm::InputTag     beamSpotTag_;
        std::auto_ptr<PrimaryVertexProducerAlgorithm> algo_;
};

#endif

// rsync -vut --existing interface/VertexReProducer.h cristella@cmssusy.ba.infn.it:/cmshome/cristella/work/Z_analysis/exclusive/clean_14ott/CMSSW_5_3_22/src/UserCode/MuMuPiKPAT/interface/VertexReProducer.h

