# Reto 1 — Entorno Aislado y Herramienta de Diagnóstico en C++

Programación Avanzada para Ciberseguridad (PAC) — Fase 1


## Equipo

| Integrante | Rol / aportación |
|---|---|
| [] | [] |
| [] | [] |
| [] | [] |

## Descripción del proyecto



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


**Fuera del entorno aislado (en otra VM sin aislar, o en su equipo host):**


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

- [ ] Entorno aislado propio, construido y documentado
- [ ] Tipos de datos y operadores usados con propósito real (no solo de adorno)
- [ ] Al menos una decisión (if/switch) y un bucle (for/while) con propósito real
- [ ] Al menos 3 funciones con responsabilidades distintas
- [ ] Una `struct` que agrupe los datos recolectados del entorno
- [ ] Al menos un uso justificado de puntero o `new`/`delete`
- [ ] Proyecto dividido en más de un archivo (`.h` + `.cpp` + `main.cpp`)
- [ ] El resultado del diagnóstico se guarda en un archivo de registro
- [ ] Manejo de al menos un caso de error con `try`/`catch`
