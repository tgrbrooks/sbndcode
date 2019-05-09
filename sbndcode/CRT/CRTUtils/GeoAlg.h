#ifndef GEOALG_H_SEEN
#define GEOALG_H_SEEN


///////////////////////////////////////////////
// GeoAlg.h
//
// Wrapper for some awkward geometry things
// T Brooks (tbrooks@fnal.gov), November 2018
///////////////////////////////////////////////

// framework
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "fhiclcpp/ParameterSet.h" 
#include "art/Framework/Principal/Handle.h" 
#include "canvas/Persistency/Common/Ptr.h" 
#include "canvas/Persistency/Common/PtrVector.h" 
#include "art/Framework/Services/Registry/ServiceHandle.h" 
#include "art_root_io/TFileService.h" 
#include "art_root_io/TFileDirectory.h" 
#include "messagefacility/MessageLogger/MessageLogger.h" 

// LArSoft
#include "larcore/Geometry/Geometry.h"
#include "larcorealg/Geometry/GeometryCore.h"
#include "nusimdata/SimulationBase/MCParticle.h"

// c++
#include <vector>


namespace sbnd{

  class GeoAlg {
  public:

    GeoAlg();

    ~GeoAlg();

    double MinX() const;
    double MinY() const;
    double MinZ() const;
    double MaxX() const;
    double MaxY() const;
    double MaxZ() const;
    double CpaWidth() const;

    bool EntersVolume(simb::MCParticle particle);
    bool CrossesVolume(simb::MCParticle particle);

  private:

    double fMinX;
    double fMinY;
    double fMinZ;
    double fMaxX;
    double fMaxY;
    double fMaxZ;
    double fCpaWidth;

    geo::GeometryCore const* fGeometryService;

  };

}

#endif
