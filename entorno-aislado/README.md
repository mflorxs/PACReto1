# Nuestro entorno aislado

## Herramienta elegida

**Herramienta:** Oracle VirtualBox

**Por qué la elegimos:** Se eligió Oracle VirtualBox porque permite crear y configurar fácilmente una máquina virtual para probar el programa en un entorno aislado.
Además, facilita controlar recursos y red sin afectar directamente al sistema operativo principal.

## Requisitos para replicar nuestro entorno

- Sistema operativo host usado: Windows 11
- Versión de la herramienta: VirtualBox 7.2.14.24565
- Sistema operativo invitado (guest): Ubuntu 26.04.1
- Recursos asignados a la VM: 4 GB en RAM, 1 núcleo, 30 GB en disco

## Pasos para armar el entorno

1. Se descargó e instaló Oracle VirtualBox desde su sitio oficial en la computadora principal.
2. Se creó una nueva máquina virtual y se seleccionó Ubuntu como sistema operativo.
3. Se asignaron los recursos necesarios a la máquina virtual, como memoria RAM, procesadores y espacio en disco.
4. Se instaló Ubuntu dentro de la máquina virtual utilizando una imagen ISO.
5. Una vez terminada la instalación, se inició Ubuntu y se comprobó que funcionara correctamente.
6. Se instaló el compilador de C++ necesario para ejecutar el proyecto utilizando sudo apt install g++.
7. Se colocaron los archivos del proyecto dentro de Ubuntu y se compiló el programa con g++ src/main.cpp src/Entorno.cpp src/Diagnostico.cpp -o diagnostico.
8. Para convertir la máquina virtual en un entorno aislado y sin red, se apagó Ubuntu y se entró a VirtualBox → Configuración → Red.
9. En Adaptador 1, se desactivó el adaptador de red, evitando que la máquina virtual tuviera acceso a Internet o a otras redes externas.
10. Se volvió a iniciar Ubuntu y se verificó la ausencia de conexión de red antes de ejecutar las pruebas del programa.]

## Configuración de red aislada

**Tipo de red usada:** Sin adaptador de red

**Cómo la configuramos:** En Oracle VirtualBox apagamos la máquina virtual, entramos a Configuración → Red → Adaptador 1 y desactivamos la opción “Habilitar adaptador de red”. Después iniciamos Ubuntu y verificamos que no tuviera acceso a Internet ni conexión con redes externas.

**Cómo verificamos que el aislamiento funciona:** Un Ping a 8.8.8.8 debe ser inalcanzable.

## Snapshot

**Nombre del snapshot base:** 2026-PAC-AislamientoBase

**Qué contiene:** El snapshot contiene Ubuntu instalado y configurado dentro de Oracle VirtualBox, con el proyecto preparado para ejecutarse y el adaptador de red desactivado. Este punto permite regresar al estado inicial del entorno aislado antes de realizar las pruebas.

## Evidencia

<img width="1280" height="800" alt="VirtualBox_PACub_30_08_2026_21_48_28" src="https://github.com/user-attachments/assets/596192a5-0a9b-4cf9-bbdd-5e8d5f3c5c3d" />

