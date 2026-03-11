# Checkpoint de continuidad — Genbu Defense (Engine flow)

Fecha: 2026-03-10

## Alcance de esta sesión
Se intentó continuar el análisis desde el punto acordado: **mapear el flujo interno real del engine** (`src/engine/source/main.cpp` en adelante), trabajando sobre la fuente local del entorno.

## Paso 1 — Apertura/inspección de fuente real (estado del snapshot)

### Comandos ejecutados
1. `pwd`
2. `ls -la`
3. `find /workspace -maxdepth 3 -type f | head -n 200`
4. `find / -maxdepth 3 -type f \( -name '*.zip' -o -name '*.tar' -o -name '*.tgz' \) 2>/dev/null | head -n 100`

### Resultado confirmado por código/FS
- El repositorio de trabajo en `/workspace/genbu-defense` contiene solo:
  - `.git/`
  - `.gitkeep`
- No existe árbol de código fuente (`src/`, `api/`, `framework/`, etc.) en el snapshot disponible.
- No se localizó ningún archivo `.zip/.tar/.tgz` con código fuente en rutas estándar del entorno.

### Conclusión Paso 1
- **Faltante en snapshot (confirmado):** no hay base de código para inspeccionar `src/engine/source/main.cpp` ni módulos asociados.

## Paso 2 — Bootstrap real del engine desde `main.cpp`

### Comprobación realizada
- Dado que no existe `src/engine/source/main.cpp` localmente, no fue posible:
  - identificar clase/objeto principal de arranque,
  - localizar secuencia `init/start/run`,
  - identificar receptor inicial de eventos.

### Intento de fallback (tomar archivos de Wazuh)
Se intentó clonar upstream para restaurar base mínima de análisis:

- `git clone --depth 1 https://github.com/wazuh/wazuh.git upstream_wazuh`
- Resultado: `fatal: unable to access ... CONNECT tunnel failed, response 403`

### Conclusión Paso 2
- **Faltante en snapshot + limitación de red (confirmado):** no se puede reconstruir el bootstrap real del engine en esta sesión con evidencia de código porque no hay fuentes locales y el acceso externo a GitHub está bloqueado en este entorno.

## Estado técnico y siguiente checkpoint

### Confirmado
- Snapshot actual vacío (sin código del proyecto).
- Imposibilidad de ejecutar Paso 2–5 con evidencia real de archivos del engine.

### Inferido (hipótesis)
- El ZIP mencionado en continuidad no fue montado en este entorno, o fue montado en una ruta no estándar fuera del alcance visible.

### Próximo paso exacto al tener fuentes
1. Reanudar en `src/engine/source/main.cpp`.
2. Trazar cadena de bootstrap hasta receptor de ingesta.
3. Seguir pipeline: ingesta → parseo → normalización → routing → evaluación/enriquecimiento → outputs/archiver/raw indexer.
4. Emitir mapa con archivo+función para puntos de modificación.
5. Generar ZIP descargable con checkpoint extendido.

## Nota de compatibilidad para PR
- Se elimina el adjunto binario `.zip` del repositorio para evitar bloqueos en revisores/forjas que no aceptan diffs binarios en el flujo de creación de PR.
- El entregable queda en este mismo archivo Markdown (`docs/checkpoints/engine-flow-checkpoint-2026-03-10.md`), que es equivalente para continuidad técnica y auditable en diff.

