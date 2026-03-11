# Mapa interno del engine (esqueleto inicial)

> Estado: **implementación base generada para versionar en GitHub sin ZIP/binarios**.
> Este documento NO reemplaza el mapeo del código real de Wazuh/Genbu cuando el snapshot completo esté disponible.

## Flujo implementado

1. **Ingesta**
   - Archivo: `src/engine/source/ingest/receiver.cpp`
   - Función: `receive_demo_event()`

2. **Archiver (raw)**
   - Archivo: `src/engine/source/archive/archiver.cpp`
   - Función: `archive_raw(const RawEvent&)`

3. **Raw Indexer**
   - Archivo: `src/engine/source/index/raw_indexer.cpp`
   - Función: `index_raw(const RawEvent&)`

4. **Parseo**
   - Archivo: `src/engine/source/parse/parser.cpp`
   - Función: `parse_event(const RawEvent&)`

5. **Routing**
   - Archivo: `src/engine/source/route/router.cpp`
   - Función: `route_event(const ParsedEvent&)`

6. **Enriquecimiento / Evaluación**
   - Archivo: `src/engine/source/enrich/evaluator.cpp`
   - Función: `enrich_and_evaluate(const RoutedEvent&)`

7. **Outputs**
   - Archivo: `src/engine/source/output/sink.cpp`
   - Función: `emit(const EnrichedEvent&)`

8. **Orquestación**
   - Archivo: `src/engine/source/main.cpp`
   - Función: `main()`

## Puntos de modificación directos

- Lógica de detección: `enrich/evaluator.cpp`
- Parseo de formatos reales: `parse/parser.cpp`
- Estrategia de routing: `route/router.cpp`
- Persistencia de eventos crudos: `archive/archiver.cpp`
- Índice de eventos crudos: `index/raw_indexer.cpp`
- Integraciones de salida: `output/sink.cpp`
