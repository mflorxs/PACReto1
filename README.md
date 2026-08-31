# Reto 1 — Entorno Aislado y Herramienta de Diagnóstico en C++

Programación Avanzada para Ciberseguridad (PAC) — Fase 1

> ⚠️ **Este README es una plantilla.** Bórrenlo y reescríbanlo con su propia información antes de entregar — no debe quedar ningún texto entre `[corchetes]`.

## Equipo

| Integrante | Rol / aportación |
|---|---|
| Anateyssi Hernandez Meza | Entorno.h |
| Miguel Eduardo Flores Salazar | Entorno.cpp |
| Marcos Adrian Gonzalez Soto | Diagnostico.h |
| Carlos Adrian Ramos Zacarias | Diagnostico.cpp |
| Axel Simon Moreno Lozano | main.cpp |

## Descripción del proyecto

La herramienta detecta si se está ejecutando dentro de un entorno virtualizado o aislado, consultando datos del sistema (fabricante y modelo vía archivos DMI de Ubuntu) y del hostname de la máquina. Compara esa información contra una lista de indicadores conocidos de virtualización (VirtualBox, VMware, KVM, QEMU, Hyper-V) para tomar la decisión. Si detecta aislamiento, muestra una alerta y bloquea la ejecución de la acción "real" mediante manejo de excepciones (try/catch); si no lo detecta, permite que el programa continúe con normalidad. Todo el resultado del diagnóstico —incluyendo los datos evaluados y la conclusión— se registra tanto en pantalla como en un archivo de log. El proyecto está dividido en módulos independientes (Entorno para la detección, Diagnostico para el procesamiento y registro, y main como orquestador), usando struct, punteros/memoria dinámica y las demás estructuras de control que pide el reto.

## Cómo compilar

Todos los archivos `.cpp` se compilan juntos en un solo paso:

```bash
g++ src/main.cpp src/Entorno.cpp src/Diagnostico.cpp -o diagnostico
```

## Cómo ejecutar

```bash
./diagnostico
```

En Windows, el ejecutable se genera como `diagnostico.exe`.

## Comportamiento esperado

**Dentro del entorno aislado:**
Al ejecutarse dentro de la máquina virtual (VirtualBox), el programa detecta el fabricante y modelo del sistema mediante los archivos DMI (/sys/class/dmi/id/), encontrando el texto "innotek GmbH VirtualBox" — uno de los indicadores conocidos de virtualización. En pantalla, muestra el dato de sistema y hostname obtenidos, junto con el mensaje "Indicador de virtualizacion encontrado." Se lanza y captura una excepción con el mensaje "ALERTA DE SEGURIDAD: Entorno aislado detectado. Se aborta la ejecucion de la accion real.", bloqueando así la ejecución de la acción principal. El resultado queda registrado en el log como Aislado: si, junto con el detalle correspondiente.


**Fuera del entorno aislado (en otra VM sin aislar, o en su equipo host):**
Al ejecutarse fuera de la VM, no se encuentra ninguno de los indicadores de virtualización conocidos en los datos del sistema. El programa muestra en pantalla "No se encontraron indicadores conocidos de virtualizacion." y confirma con "[EXITO] Entorno seguro/real confirmado. Ejecutando la accion principal del programa...", permitiendo que la ejecución continúe con normalidad. El resultado se registra en el log como Aislado: no, con el detalle "No se encontraron coincidencia de hipervisores o artefactos de virtualizacion conocidos."
## Estructura del proyecto

```
Reto1-NombreDelEquipo/
├── README.md                 <- este archivo
├── src/
│   ├── main.cpp               <- punto de entrada del programa
│   ├── Entorno.h               <- declaraciones: detección de entorno
│   ├── Entorno.cpp             <- definiciones: detección de entorno
│   ├── Diagnostico.h           <- declaraciones: struct + procesamiento
│   └── Diagnostico.cpp         <- definiciones: struct + procesamiento
├── logs/
│   └── (aquí se genera el archivo de registro al ejecutar el programa)
└── entorno-aislado/
    └── README.md               <- cómo armaron su sandbox, paso a paso
```

## Requisitos técnicos cubiertos

Marquen con ✅ conforme los vayan completando — esto les sirve como checklist propio, y a mí para revisar rápido:

- [✅] Entorno aislado propio, construido y documentado
- [✅] Tipos de datos y operadores usados con propósito real (no solo de adorno)
- [✅] Al menos una decisión (if/switch) y un bucle (for/while) con propósito real
- [✅] Al menos 3 funciones con responsabilidades distintas
- [✅] Una `struct` que agrupe los datos recolectados del entorno
- [✅] Al menos un uso justificado de puntero o `new`/`delete`
- [✅] Proyecto dividido en más de un archivo (`.h` + `.cpp` + `main.cpp`)
- [✅] El resultado del diagnóstico se guarda en un archivo de registro
- [✅] Manejo de al menos un caso de error con `try`/`catch`
