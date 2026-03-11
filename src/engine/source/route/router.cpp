#include "route/router.hpp"

namespace genbu::engine::route {

RoutedEvent route_event(const ParsedEvent& parsed) {
    RoutedEvent routed{};
    routed.parsed = parsed;

    if (parsed.kind == "auth_failed") {
        routed.route = "detections/auth";
    } else {
        routed.route = "detections/default";
    }

    return routed;
}

} // namespace genbu::engine::route
