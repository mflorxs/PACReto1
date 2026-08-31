/*
 * ============================================================
 *  Entorno.cpp — Definiciones del módulo de detección de entorno
 * ============================================================
 * Aquí va la implementación real de las funciones declaradas
 * en Entorno.h. Esta es la parte más abierta del reto: el
 * diseño de CÓMO detectan el aislamiento es decisión de su
 * equipo, siempre y cuando quede bien justificado en su README.
 * ============================================================
 */

#include "Entorno.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Implementación de la lógica de detección.
//
// Estrategia elegida:
//   - Obtener información del sistema desde archivos DMI de Ubuntu.
//   - Obtener el hostname como dato adicional del entorno.
//   - Buscar indicadores conocidos de virtualización.
//
// Se usan con propósito real:
//   - Estructuras de control (if).
//   - Bucles (for).
//   - Tipos de datos y operadores.

// Función auxiliar interna.
// Convierte un texto completo a minúsculas para evitar que una
// diferencia entre mayúsculas y minúsculas afecte la detección.
static string convertirAMinusculas(string texto) {
    for (char& caracter : texto) {
        caracter = static_cast<char>(
            tolower(static_cast<unsigned char>(caracter))
        );
    }

    return texto;
}

// Obtiene información del fabricante y del producto del sistema.
// En Ubuntu, estos datos se encuentran en archivos DMI dentro de
// /sys/class/dmi/id/.
string obtenerDatoDeSistema() {
    ifstream archivoFabricante("/sys/class/dmi/id/sys_vendor");
    ifstream archivoProducto("/sys/class/dmi/id/product_name");

    string fabricante = "";
    string producto = "";

    // Se verifica que el archivo pueda abrirse antes de leerlo.
    if (archivoFabricante.is_open()) {
        getline(archivoFabricante, fabricante);
        archivoFabricante.close();
    }

    // Se verifica que el archivo pueda abrirse antes de leerlo.
    if (archivoProducto.is_open()) {
        getline(archivoProducto, producto);
        archivoProducto.close();
    }

    // Se unen ambos valores para analizarlos como un solo texto.
    return fabricante + " " + producto;
}

// Obtiene el hostname configurado en Ubuntu.
// Este valor se utiliza como información adicional del entorno
// y se muestra al usuario durante el diagnóstico.
string obtenerDatoDeRed() {
    ifstream archivoHostname("/etc/hostname");

    string hostname = "";

    if (archivoHostname.is_open()) {
        getline(archivoHostname, hostname);
        archivoHostname.close();
    }

    return hostname;
}

bool estaEnEntornoAislado() {
    // Inicialmente se asume que no se está ejecutando dentro
    // de un entorno aislado.
    bool aislado = false;

    // Se recolectan los datos mediante las funciones declaradas
    // en Entorno.h.
    string datoSistema = obtenerDatoDeSistema();
    string datoRed = obtenerDatoDeRed();

    // El texto se convierte a minúsculas para hacer comparaciones
    // sin depender del uso de mayúsculas o minúsculas.
    string sistemaMinusculas = convertirAMinusculas(datoSistema);

    // Indicadores comunes que pueden aparecer en los datos DMI
    // cuando Ubuntu se ejecuta dentro de una máquina virtual.
    string indicadores[] = {
        "virtualbox",
        "vmware",
        "kvm",
        "qemu",
        "virtual machine",
        "hyper-v"
    };

    // La cantidad de elementos se calcula automáticamente para
    // evitar escribir manualmente el tamaño del arreglo.
    int cantidadIndicadores =
        static_cast<int>(sizeof(indicadores) / sizeof(indicadores[0]));

    // Se recorren todos los indicadores de virtualización.
    for (int i = 0; i < cantidadIndicadores; i++) {

        // find() devuelve string::npos cuando el texto NO aparece.
        // Si se encuentra algún indicador, se considera que existe
        // evidencia de virtualización.
        if (sistemaMinusculas.find(indicadores[i]) != string::npos) {
            aislado = true;
            break;
        }
    }

    // Se muestran los datos evaluados para que el usuario pueda
    // observar qué información utilizó el diagnóstico.
    cout << "Dato de sistema: " << datoSistema << endl;
    cout << "Dato de red (hostname): " << datoRed << endl;

    // Se muestra el resultado específico de este módulo.
    if (aislado) {
        cout << "Indicador de virtualizacion encontrado." << endl;
    } else {
        cout << "No se encontraron indicadores conocidos de virtualizacion." << endl;
    }

    return aislado;
}
