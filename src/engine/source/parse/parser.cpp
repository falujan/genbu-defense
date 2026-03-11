#include "parse/parser.hpp"

#include <sstream>

namespace genbu::engine::parse {

ParsedEvent parse_event(const RawEvent& raw) {
    ParsedEvent parsed{};
    parsed.kind = "generic";

    std::istringstream iss(raw.payload);
    std::string token;
    while (iss >> token) {
        auto sep = token.find('=');
        if (sep == std::string::npos || sep == 0 || sep == token.size() - 1) {
            continue;
        }

        auto key = token.substr(0, sep);
        auto value = token.substr(sep + 1);
        parsed.fields[key] = value;

        if (key == "type") {
            parsed.kind = value;
        }
    }

    parsed.fields["source"] = raw.source;
    return parsed;
}

} // namespace genbu::engine::parse
