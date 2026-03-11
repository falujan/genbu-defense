#include "index/raw_indexer.hpp"

#include <fstream>

namespace genbu::engine::index {

void index_raw(const RawEvent& event) {
    std::ofstream ofs("engine-raw-index.log", std::ios::app);
    ofs << "key=" << event.source << ";payload_size=" << event.payload.size() << '\n';
}

} // namespace genbu::engine::index
