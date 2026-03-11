#pragma once

#include "pipeline_types.hpp"

namespace genbu::engine::enrich {

EnrichedEvent enrich_and_evaluate(const RoutedEvent& routed);

} // namespace genbu::engine::enrich
