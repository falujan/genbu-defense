add_executable(genbu-engine-skeleton
  source/main.cpp
  source/ingest/receiver.cpp
  source/parse/parser.cpp
  source/route/router.cpp
  source/enrich/evaluator.cpp
  source/output/sink.cpp
  source/archive/archiver.cpp
  source/index/raw_indexer.cpp
)

target_include_directories(genbu-engine-skeleton PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)
