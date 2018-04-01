////////////////////////////////////////////////////////////////////////
// Class:       DaqDecoder
// Plugin Type: producer (art v2_09_06)
// File:        DaqDecoder.cxx
//
// Generated at Thu Feb  8 16:41:18 2018 by Gray Putnam using cetskelgen
// from cetlib version v3_01_03.
////////////////////////////////////////////////////////////////////////

#include "DaqDecoder.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"
#include "canvas/Utilities/InputTag.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include <memory>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "art/Framework/Core/ModuleMacros.h"

#include "artdaq-core/Data/Fragment.hh"

#include "lardataobj/RawData/RawDigit.h"

#include "sbnddaq-datatypes/Overlays/NevisTPCFragment.hh"
#include "sbnddaq-datatypes/NevisTPC/NevisTPCTypes.hh"
#include "sbnddaq-datatypes/NevisTPC/NevisTPCUtilities.hh"

#include "HeaderData.hh"
#include "ChannelMap.hh"

DEFINE_ART_MODULE(daq::DaqDecoder)


daq::DaqDecoder::DaqDecoder(fhicl::ParameterSet const & param)
  : _tag("daq","NEVISTPC")
{
  // amount of time to wait in between processing events
  // useful for debugging redis
  double wait_time = param.get<double>("wait_time", -1 /* units of seconds */);
  _wait_sec = (int) wait_time;
  _wait_usec = (int) (wait_time / 1000000);
  
  // produce stuff
  produces<std::vector<raw::RawDigit>>();
  _produce_header = param.get<bool>("produce_header", false);
  if (_produce_header) {
    produces<std::vector<daqAnalysis::HeaderData>>();
  }
}

void daq::DaqDecoder::produce(art::Event & event)
{
  if (_wait_sec >= 0) {
    std::this_thread::sleep_for(std::chrono::seconds(_wait_sec) + std::chrono::microseconds(_wait_usec));
  }
  auto const& daq_handle = event.getValidHandle<std::vector<artdaq::Fragment>>(_tag);

  std::unique_ptr<std::vector<raw::RawDigit>> product_collection(new std::vector<raw::RawDigit>);
  std::unique_ptr<std::vector<daqAnalysis::HeaderData>> header_collection(new std::vector<daqAnalysis::HeaderData>);
  for (auto const &rawfrag: *daq_handle) {
    process_fragment(rawfrag, product_collection, header_collection);
  }
  event.put(std::move(product_collection));
  if (_produce_header) {
    event.put(std::move(header_collection));
  }
}

// Calculate the mode to find a baseline of the passed in waveform.
// Mode finding algorithm from: http://erikdemaine.org/papers/NetworkStats_ESA2002/paper.pdf (Algorithm FREQUENT)
int16_t Mode(const std::vector<int16_t> &adcs) {
  // 10 counters seem good
  std::array<unsigned, 10> counters {}; // zero-initialize
  std::array<short, 10> modes {};

  for (auto val: adcs) {
    int home = -1;
    // look for a home for the val
    for (int i = 0; i < (int)modes.size(); i ++) {
      if (modes[i] == val) {
        home = i; 
        break;
      }
    }
    // invade a home if you don't have one
    if (home < 0) {
      for (int i = 0; i < (int)modes.size(); i++) {
        if (counters[i] == 0) {
          home = i;
          modes[i] = val;
          break;
        }
      }
    }
    // incl if home
    if (home >= 0) counters[home] ++;
    // decl if no home
    else {
      for (int i = 0; i < (int)counters.size(); i++) {
        counters[i] = (counters[i]==0) ? 0 : counters[i] - 1;
      }
    }
  }
  // highest counter has the mode
  unsigned max_counters = 0;
  short ret = 0;
  for (int i = 0; i < (int)counters.size(); i++) {
    if (counters[i] > max_counters) {
      max_counters = counters[i];
      ret = modes[i];
    }
  }
  return ret;
}

raw::ChannelID_t daq::DaqDecoder::get_wire_id(const sbnddaq::NevisTPCHeader *header, uint16_t nevis_channel_id) {
 daqAnalysis::ChannelMap::board_channel channel {header->getSlot(), header->getFEMID(), (size_t) nevis_channel_id };
 return daqAnalysis::ChannelMap::Channel2Wire(channel);
}

void daq::DaqDecoder::process_fragment(const artdaq::Fragment &frag, 
  std::unique_ptr<std::vector<raw::RawDigit>> &product_collection,
  std::unique_ptr<std::vector<daqAnalysis::HeaderData>> &header_collection) {

  sbnddaq::NevisTPCFragment fragment(frag);

  validate_header(fragment.header());

  std::unordered_map<uint16_t,sbnddaq::NevisTPC_Data_t> waveform_map;
  size_t n_waveforms = fragment.decode_data(waveform_map);
  (void)n_waveforms;

  if (_produce_header) {
    header_collection->emplace_back(fragment.header());
  }

  for (auto waveform: waveform_map) {
    std::vector<int16_t> raw_digits_waveform;
    raw::ChannelID_t wire_id = get_wire_id(fragment.header(), waveform.first);
    // TODO: is this too expensive an operation?
    for (auto digit: waveform.second) {
      raw_digits_waveform.push_back( (int16_t) digit);
    }  
    product_collection->emplace_back(wire_id, raw_digits_waveform.size(), raw_digits_waveform);
    (*product_collection)[product_collection->size() - 1].SetPedestal( Mode(raw_digits_waveform) ); 
  }
}
void daq::DaqDecoder::validate_header(const sbnddaq::NevisTPCHeader *header) {
  // TODO: implement
  (void) header;
  return; 
}


 

