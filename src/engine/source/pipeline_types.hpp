#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace genbu::engine {

struct RawEvent {
    std::string source;
    std::string payload;
};

struct ParsedEvent {
    std::string kind;
    std::unordered_map<std::string, std::string> fields;
};

struct RoutedEvent {
    std::string route;
    ParsedEvent parsed;
};

struct EnrichedEvent {
    std::string route;
    std::string risk_score;
    ParsedEvent parsed;
};

} // namespace genbu::engine
