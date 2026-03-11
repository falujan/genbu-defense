#include "archive/archiver.hpp"

#include <fstream>

namespace genbu::engine::archive {

void archive_raw(const RawEvent& event) {
    std::ofstream ofs("engine-archive.log", std::ios::app);
    ofs << event.source << " | " << event.payload << '\n';
}

} // namespace genbu::engine::archive
