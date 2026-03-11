#include "enrich/evaluator.hpp"

namespace genbu::engine::enrich {

EnrichedEvent enrich_and_evaluate(const RoutedEvent& routed) {
    EnrichedEvent out{};
    out.route = routed.route;
    out.parsed = routed.parsed;

    const auto user = routed.parsed.fields.find("user");
    out.risk_score = (user != routed.parsed.fields.end() && user->second == "root") ? "high" : "medium";

    return out;
}

} // namespace genbu::engine::enrich
