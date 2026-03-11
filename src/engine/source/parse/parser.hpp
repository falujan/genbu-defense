#pragma once

#include "pipeline_types.hpp"

namespace genbu::engine::parse {

ParsedEvent parse_event(const RawEvent& raw);

} // namespace genbu::engine::parse
