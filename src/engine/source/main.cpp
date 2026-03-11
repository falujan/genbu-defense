#include "archive/archiver.hpp"
#include "enrich/evaluator.hpp"
#include "index/raw_indexer.hpp"
#include "ingest/receiver.hpp"
#include "output/sink.hpp"
#include "parse/parser.hpp"
#include "route/router.hpp"

int main() {
    const auto raw = genbu::engine::ingest::receive_demo_event();
    genbu::engine::archive::archive_raw(raw);
    genbu::engine::index::index_raw(raw);

    const auto parsed = genbu::engine::parse::parse_event(raw);
    const auto routed = genbu::engine::route::route_event(parsed);
    const auto enriched = genbu::engine::enrich::enrich_and_evaluate(routed);

    genbu::engine::output::emit(enriched);
    return 0;
}
