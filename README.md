# Genbu Defense

Repositorio base en texto plano para poder versionar en GitHub sin binarios.

## Estado actual
- Este snapshot no contiene el código original completo de Wazuh/Genbu.
- Se dejó un **esqueleto de engine** en `src/engine/source/` para continuar desarrollo sin ZIP.
- Se dejó documentación de continuidad en `docs/checkpoints/` y mapa técnico en `docs/architecture/`.

## Compilación rápida del esqueleto
```bash
cmake -S . -B build
cmake --build build -j
./build/genbu-engine-skeleton
```

## Objetivo del esqueleto
- Mantener un pipeline explícito: `ingest -> parse -> route -> enrich -> output + archive + raw index`.
- Dejar puntos concretos para reemplazar con lógica real cuando esté el código fuente completo.
