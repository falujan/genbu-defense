#include "ingest/receiver.hpp"

namespace genbu::engine::ingest {

RawEvent receive_demo_event() {
    return RawEvent{
        .source = "api-webhook",
        .payload = "type=auth_failed user=alice srcip=10.0.0.7"
    };
}

} // namespace genbu::engine::ingest
