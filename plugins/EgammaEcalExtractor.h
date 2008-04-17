#ifndef EgammaIsolationAlgos_EgammaEcalIsolation_h
#define EgammaIsolationAlgos_EgammaEcalIsolation_h

//*****************************************************************************
// File:      EgammaEcalExtractor.h
// ----------------------------------------------------------------------------
// Type:      Class implementation header
// Package:   EgammaIsolationAlgos/EgammaIsolationAlgos
// Class:     EgammaEcalExtractor
// Language:  Standard C++
// Project:   CMS
// OrigAuth:  Gilles De Lentdecker
// Institute: IIHE-ULB
//=============================================================================
//*****************************************************************************


#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "PhysicsTools/IsolationAlgos/interface/IsoDepositExtractor.h"
#include "DataFormats/RecoCandidate/interface/IsoDeposit.h"

namespace egammaisolation {

    class EgammaEcalExtractor : public reco::isodeposit::IsoDepositExtractor  {
        public:
            EgammaEcalExtractor(const edm::ParameterSet& par) : 
                    etMin_(par.getParameter<double>("etMin")),
                    conesize_(par.getParameter<double>("extRadius")),
                    basicClusterTag_(par.getParameter<edm::InputTag>("basicClusters")),
                    superClusterTag_(par.getParameter<edm::InputTag>("superClusters")) { }
            

            virtual ~EgammaEcalExtractor();

            virtual void fillVetos(const edm::Event & ev, const edm::EventSetup & evSetup, const reco::TrackCollection & tracks) { }
            virtual reco::IsoDeposit deposit(const edm::Event & ev, const edm::EventSetup & evSetup, const reco::Track & track) const {
                throw cms::Exception("Configuration Error") << "This extractor " << (typeid(this).name()) << " is not made for tracks";
            }
            virtual reco::IsoDeposit deposit(const edm::Event & ev, const edm::EventSetup & evSetup, const reco::Candidate & c) const ;

        private:

            // ---------- member data --------------------------------

            // Parameters of isolation cone geometry. 
            // Photon case
            double etMin_;
            double conesize_;
            edm::InputTag basicClusterTag_;
            edm::InputTag superClusterTag_;
    };

}
#endif
