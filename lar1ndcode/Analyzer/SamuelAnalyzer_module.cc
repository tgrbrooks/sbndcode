////////////////////////////////////////////////////////////////////////
// Class:       SamuelAnalyzer
// Module Type: analyzer
// File:        SamuelAnalyzer_module.cc
//
// Generated at Thu Jun 18 11:41:33 2015 by Samuel Santana using artmod
// from cetpkgsupport v1_08_06.
////////////////////////////////////////////////////////////////////////


/*#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "art/Utilities/InputTag.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"
#include "Simulation/SimChannel.h"

//#include "Simulation/SimChannel.h"

#include "AnalysisBase/ParticleID.h"

// Larsoft includes

#include "SimulationBase/MCParticle.h"
#include "SimulationBase/MCTruth.h"
//#include "Simulation/LArG4Parameters.h" 

// C++ includes

#include <iostream> */

// LArSoft includes
#include "Simulation/SimChannel.h"
#include "Simulation/LArG4Parameters.h"
#include "RecoBase/Hit.h"
#include "RecoBase/Cluster.h"
#include "Geometry/Geometry.h"
#include "SimulationBase/MCParticle.h"
#include "SimulationBase/MCTruth.h"
#include "SimpleTypesAndConstants/geo_types.h"
#include "MCCheater/BackTracker.h"
#include "Simulation/ParticleList.h"
#include "Simulation/sim.h"

// Framework includes
#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/SubRun.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Services/Optional/TFileService.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Core/FindManyP.h"
#include "messagefacility/MessageLogger/MessageLogger.h"
#include "fhiclcpp/ParameterSet.h"
#include "cetlib/exception.h"
#include "MCCheater/BackTracker.h"
#include "Utilities/DetectorProperties.h"
#include "Utilities/LArProperties.h"
#include "Simulation/SimChannel.h"
#include "Simulation/sim.h"
#include "SimulationBase/MCTruth.h"
#include "AnalysisBase/ParticleID.h"
#include "SimpleTypesAndConstants/geo_types.h"
#include "SummaryData/POTSummary.h"

// ROOT includes
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TProfile.h"

// C++ Includes
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

// Sowjanya's includes
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/SubRun.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/View.h"
#include "art/Persistency/Common/Ptr.h"
#include "art/Persistency/Common/PtrVector.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Services/Optional/TFileService.h"
#include "art/Framework/Services/Optional/TFileDirectory.h"
#include "art/Framework/Core/FindMany.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include "SimulationBase/MCTruth.h"
#include "SimulationBase/MCFlux.h"
#include "Simulation/SimChannel.h"
#include "Simulation/AuxDetSimChannel.h"
#include "AnalysisBase/Calorimetry.h"
#include "AnalysisBase/ParticleID.h"
#include "RawData/RawDigit.h"
#include "RawData/BeamInfo.h"
#include "Utilities/LArProperties.h"
#include "Utilities/AssociationUtil.h"
#include "Utilities/DetectorProperties.h"
#include "SummaryData/POTSummary.h"
#include "MCCheater/BackTracker.h"
#include "RecoBase/Track.h"
#include "RecoBase/Cluster.h"
#include "RecoBase/Hit.h"
#include "RecoBase/EndPoint2D.h"
#include "RecoBase/Vertex.h"
#include "SimpleTypesAndConstants/geo_types.h"
#include "RecoObjects/BezierTrack.h"

/*#include "EventDisplay/RawDataDrawer.h"
#include <cmath>
#include "TH1F.h"
#include "TPolyLine3D.h"
#include "TBox.h"
#include "EventDisplayBase/evdb.h"
#include "EventDisplayBase/EventHolder.h"
#include "EventDisplay/ColorDrawingOptions.h"
#include "EventDisplay/RawDrawingOptions.h"
#include "RawData/raw.h"
#include "Filters/ChannelFilter.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Principal/Event.h"
#include "art/Persistency/Common/Ptr.h"
#include "messagefacility/MessageLogger/MessageLogger.h"*/

// nusoft includes
#include "SimulationBase/MCFlux.h"
#include "SimulationBase/MCNeutrino.h"
#include "SimulationBase/MCTruth.h"
#include "SimulationBase/GTruth.h"
#include "SimulationBase/MCParticle.h"
#include "SummaryData/POTSummary.h"


namespace lar1nd {
  class SamuelAnalyzer;
}

class lar1nd::SamuelAnalyzer : public art::EDAnalyzer {
public:

  explicit SamuelAnalyzer(fhicl::ParameterSet const & p);
  // The destructor generated by the compiler is fine for classes
  // without bare pointers or other resource use.

  // Plugins should not be copied or assigned.
  SamuelAnalyzer(SamuelAnalyzer const &) = delete;
  SamuelAnalyzer(SamuelAnalyzer &&) = delete;
  SamuelAnalyzer & operator = (SamuelAnalyzer const &) = delete;
  SamuelAnalyzer & operator = (SamuelAnalyzer &&) = delete;

  // Required functions.
  //void analyze(art::Event const & e) override;
  void analyze(art::Event const & e);

  // Selected optional functions.
 //oid beginJob() override;
  void beginJob();
 //oid reconfigure(fhicl::ParameterSet const & p) override;
void reconfigure(fhicl::ParameterSet const & p);

private:

  // Declare member data here.
    TH1D *fnumChannels; ///< The number of channels recieving charge per event
    TProfile *fnumIDEs; ///< Number of drift electrons per channel.
    TH1D *fEventCharge; ///< Charge collected per event
    TH1D *fEventEnergy; ///< Energy collected per event
    TProfile *fChannelCharge; ///< Charge per channel.
    TProfile *fChannelEnergy; ///< Energy per channel.
    TH1D *chargex, *chargey, *chargez;
    TH2D *chargexy;
    TH1D *Qposx[3];
    TProfile *fratioQoE[3]; ///< Ratio of charge over energy as a function of x
    TProfile *ChargeX[3], *EnergyX[3];
    
  // The parameters from the .fcl file.
 // std::string fSimulationProducerLabel; // The name of the producer that tracked simulated particles through the detector
    std::string fGenieModuleLabel;
    std::string fG4ModuleLabel;
  //std::string fLarg4ModuleLabel;
};


lar1nd::SamuelAnalyzer::SamuelAnalyzer(fhicl::ParameterSet const & p)
  :
  EDAnalyzer(p)  // ,
 // More initializers here.
{
 // Read in the parameters from the .fcl file.
   this->reconfigure(p);
}

void lar1nd::SamuelAnalyzer::analyze(art::Event const & e)
{
  // Implementation of required member function here.
   std::cout << std::endl;
   std::cout << "--Sam: xxxxxxxxxxxxxxxxx Analyzer xxxxxxxxxxxxxxxxx"<< std::endl;
   int runNumber = e.run();
   int evtNumber = e.event();
   int SubRunNumber = e.subRun();
   std::cout<<"--Sam: run:   "<<runNumber<<"   evt:     "<< evtNumber <<"   SubRunNumber:      "<< SubRunNumber << std::endl;
   std::cout << std::endl;
   
   art::Handle< std::vector<simb::MCTruth> > mclistGENIE;
   e.getByLabel(fGenieModuleLabel,mclistGENIE);

  /* art::Handle<std::vector<simb::MCParticle> > mcpHandle;
   e.getByLabel(fSimulationProducerLabel,mcpHandle);
  
        
    // Check is data product is found or not
    if(!mcpHandle.isValid())
    {
      std::cout << "Did not find MCParticle from label..." << std::endl << std::endl;
      return;
    }
      std::cout<<"Si paso, fSimulationProducerLabel:    "<<fSimulationProducerLabel<<std::endl;
      std::cout<<"size:   "<<mcpHandle->size()<<std::endl;
  
      
      std::vector<const simb::MCParticle* > particle;
     //sim::ParticleList plist;

     //std::cout<<"size:   "<<particle->size()<<std::endl;//this gives an error

     for(auto i = particle.begin(), iend = particle.end(); i != iend; ++i)
    {
      int pdg = (*i)->PdgCode();
      int trackId = (*i)->TrackId();
      std::cout<<"===================== entro al loop!! =============================="<<std::endl;
      std::cout<<pdg<<trackId<<std::endl;
    }

  
 // contains the gtruth object
   art::Ptr<simb::MCTruth> mc(mclistGENIE,0);

  // simb::MCNeutrino neutrino = mc -> GetNeutrino();

   art::Ptr<simb::MCParticle > pHandle(mcpHandle,0);
   
   //int isCC = -99;

   //std::cout<<"pHandle:   "<<pHandle->isCC << std::endl;

 */


////Andrzej copying things 

    art::ServiceHandle<geo::Geometry> geom;
    
    //get the list of particles from this event
    art::ServiceHandle<cheat::BackTracker> bt;
    const sim::ParticleList& plist = bt->ParticleList(); //this is coming from larsim/LArG4/LArG4Ana_module.cc

    // loop over all sim::SimChannels in the event and make sure there are no
    // sim::IDEs with trackID values that are not in the sim::ParticleList
    std::vector<const sim::SimChannel*> sccol;
    e.getView(fG4ModuleLabel, sccol);

    double totalCharge=0.0;
    double totalEnergy=0.0;
    fnumChannels->Fill(sccol.size());
    std::cout << "--Sam: sccol.size():    " << sccol.size() << std::endl;
    for(size_t sc = 0; sc < sccol.size(); ++sc){
      double numIDEs=0.0;
      double scCharge=0.0;
      double scEnergy=0.0;
      
   // we need to distiguish the U and V planes
      geo::View_t view = geom->View(sc);
      
      
      const std::map<unsigned short, std::vector<sim::IDE> >& tdcidemap = sccol[sc]->TDCIDEMap();
      for(auto mapitr = tdcidemap.begin(); mapitr != tdcidemap.end(); mapitr++){
	const std::vector<sim::IDE> idevec = (*mapitr).second;
	numIDEs += idevec.size(); 
      	for(size_t iv = 0; iv < idevec.size(); ++iv){
	  if(plist.find( idevec[iv].trackID ) == plist.end()
	     && idevec[iv].trackID != sim::NoParticleId) 
	  mf::LogWarning("LArG4Ana") << idevec[iv].trackID << " is not in particle list"; 
	  totalCharge +=idevec[iv].numElectrons;
	  scCharge += idevec[iv].numElectrons;
	  totalEnergy +=idevec[iv].energy;
	  scEnergy += idevec[iv].energy;

          //for (const auto& ide : ideVec) {
	  //totalElectrons += ide.numElectrons;
          std::cout << iv << "--Sam:z =    " << idevec[iv].z << "   diff =   " << idevec[iv].x - idevec[iv].y << std::endl;
	  std::cout << iv << "--Sam:view= :"<< view << " plane U: " << geo::kU << " plane V: " << geo::kV << " plane Z: " << geo::kZ<< std::endl;
      
          //}

          chargex->Fill(idevec[iv].x);
          chargey->Fill(idevec[iv].y);
          chargez->Fill(idevec[iv].z);
          chargexy->Fill(idevec[iv].x, idevec[iv].y);
          for(size_t i=0; i<=2; i++)
             if( i==view )Qposx[i]->Fill(idevec[iv].x);
          if(view >= 3)
               std::cout <<"--Sam: badView!  " << view << std::endl;
	       
	  double ratioQoE = idevec[iv].numElectrons/idevec[iv].energy;
	  fratioQoE[view]->Fill(idevec[iv].x,ratioQoE);
	  ChargeX[view]->Fill(idevec[iv].x,idevec[iv].numElectrons);
	  EnergyX[view]->Fill(idevec[iv].x,idevec[iv].energy);
	  
	 // std::cout << "--Sam: ratioQoE =  " << ratioQoE << std::endl;
	}
      }
    fnumIDEs->Fill(sc,numIDEs);
    fChannelCharge->Fill(sc,scCharge);
    fChannelEnergy->Fill(sc,scEnergy);
    }

   fEventCharge->Fill(totalCharge);
   fEventEnergy->Fill(totalEnergy);
   std::cout << "--Sam: totalCharge:    " << totalCharge << std::endl;
   std::cout << "--Sam: totalEnergy:    " << totalEnergy << std::endl;
   
////end Andrzej copying things   
   
   
   
    art::Handle< std::vector<simb::GTruth> > mcgtruth;
    e.getByLabel(fGenieModuleLabel,mcgtruth);

 // Check is data product is found or not
    if(!mcgtruth.isValid())
    {
      std::cout << "Did not find mcgtruth from label..." << std::endl << std::endl;
      return;
    }
      std::cout<<"Si paso, fGenieModuleLabel:    "<<fGenieModuleLabel<<std::endl;
      std::cout<<"size:   "<<mcgtruth->size()<<std::endl;    

 // contains the gtruth object
    art::Ptr<simb::GTruth > gtruth(mcgtruth,0);

    std::cout << "The interaction info is: \n" 
              << "  gtruth->ftgtPDG................." << gtruth->ftgtPDG << "\n"
              << "  gtruth->ftgtZ..................." << gtruth->ftgtZ << "\n"
              << "  gtruth->ftgtA..................." << gtruth->ftgtA << "\n"
              << "  gtruth->fGint..................." << gtruth->fGint << "\n"
              << "  gtruth->fGscatter..............." << gtruth->fGscatter << "\n"
              << "  gtruth->fweight................." << gtruth->fweight << "\n"
    //          << "  neutrino.Mode()................." << neutrino.Mode() << "\n"
    //           << "  neutrino.InteractionType()......" << neutrino.InteractionType() << "\n"
    //           << "  neutrino.CCNC()................." << neutrino.CCNC() << "\n"
    //           << "  neutrino.Target()..............." << neutrino.Target() << "\n"
              << std::endl;


}

void lar1nd::SamuelAnalyzer::beginJob()
{

    // Implementation of optional member function here.
    std::cout << std::endl;
    std::cout << "xxxxxxxxxxxxxxx Empezando xxxxxxxxxxxxxxx"<< std::endl;
    std::cout << std::endl;

    art::ServiceHandle<art::TFileService> tfs;
    art::ServiceHandle<geo::Geometry> geo;
    
    double Nch = geo->Nchannels();

    std::cout << "--Sam: Nch     :" << Nch << std::endl;

  

    // Some histograms relating to drift electrons, active detector
    // channels and charge/energy on channels
    fnumChannels = tfs->make<TH1D>("fnumChannels", 
				   "Active channels;Active channels;# events",
				   256, 0, geo->Nchannels()); 
    fnumIDEs = tfs->make<TProfile>("fnumIDEs", 
				   "Drift Electrons per channel;Channel;Drift electrons",
				   geo->Nchannels()+1, 0, geo->Nchannels(),
				   0, 1e4); 
     fEventCharge = tfs->make<TH1D>("fEventCharge", 
				   "Charge in event;Total charge per event;# events",
				   100, 0, 2.5e8); 
     fEventEnergy = tfs->make<TH1D>("fEventEnergy", 
				   "Energy in event;Total energy per event;# events",
				   100, 0, 1e4); 
  
     fChannelCharge = tfs->make<TProfile>("fChannelCharge", 
					 "Charge on channel;Channel;Total charge per channel",
					 geo->Nchannels()+1,0,geo->Nchannels(),
					 0,1e5);
     fChannelEnergy = tfs->make<TProfile>("fChannelEnergy", 
					 "Energy on channel;Channel;Total energy per channel",
					 geo->Nchannels()+1,0,geo->Nchannels(),
					 0, 1e3); 
					 
     chargex = tfs->make<TH1D>("chargex", "Charge x position", 1000, -500, 500);
     chargey = tfs->make<TH1D>("chargey", "Charge y position", 1000, -500, 500); 
     chargez = tfs->make<TH1D>("chargez", "Charge z position", 1000, 0, 1000);
     chargexy = tfs->make<TH2D>("chargexy", "Charge x vs y position", 1000, -500, 500, 1000, -500, 500); 
     Qposx[0] = tfs->make<TH1D>("qposx0", "Charge X position 0", 10000, -250, 250);
     Qposx[1] = tfs->make<TH1D>("qposx1", "Charge X position 1", 10000, -250, 250);
     Qposx[2] = tfs->make<TH1D>("qposx2", "Charge X position 2", 10000, -250, 250);

     fratioQoE[0] = tfs->make<TProfile>("fratioQoE0", "Ratio of charge over energy as a function of x0",400, -200, 200,0, 2e4);
     fratioQoE[1] = tfs->make<TProfile>("fratioQoE1", "Ratio of charge over energy as a function of x1",400, -200, 200,0, 2e4);
     fratioQoE[2] = tfs->make<TProfile>("fratioQoE2", "Ratio of charge over energy as a function of x2",400, -200, 200,0, 2e4);
     
     ChargeX[0] = tfs->make<TProfile>("ChargeX0", "Charge as a function of x0",400, -200, 200,0, 2e4);
     ChargeX[1] = tfs->make<TProfile>("ChargeX1", "Charge as a function of x1",400, -200, 200,0, 2e4);
     ChargeX[2] = tfs->make<TProfile>("ChargeX2", "Charge as a function of x2",400, -200, 200,0, 2e4);
     
     EnergyX[0] = tfs->make<TProfile>("EnergyX0", "Charge as a function of x0",400, -200, 200,0, 2e4);
     EnergyX[1] = tfs->make<TProfile>("EnergyX1", "Charge as a function of x1",400, -200, 200,0, 2e4);
     EnergyX[2] = tfs->make<TProfile>("EnergyX2", "Charge as a function of x2",400, -200, 200,0, 2e4);
  }

void lar1nd::SamuelAnalyzer::reconfigure(fhicl::ParameterSet const & p)
{
  // Implementation of optional member function here.

   std::cout << std::endl;
   std::cout << "xxxxxxxxxxxxxxxxx Reco xxxxxxxxxxxxxxxxx"<< std::endl;
   std::cout << std::endl;

 //fSimulationProducerLabel = p.get< std::string >("SimulationLabel");
   fGenieModuleLabel        = p.get< std::string >("GenieGenModuleLabel");
   fG4ModuleLabel        = p.get< std::string >("LArG4ModuleLabel");
 //fLarg4ModuleLabel        = p.get< std::string >("LArG4ModuleLabel");
   
}

DEFINE_ART_MODULE(lar1nd::SamuelAnalyzer)
