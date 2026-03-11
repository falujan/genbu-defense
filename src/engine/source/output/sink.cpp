#include "output/sink.hpp"

#include <iostream>

namespace genbu::engine::output {

void emit(const EnrichedEvent& event) {
    std::cout << "[output] route=" << event.route << " risk=" << event.risk_score << '\n';
}

} // namespace genbu::engine::output
