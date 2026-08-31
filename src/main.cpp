/*
 * ============================================================
 *  main.cpp — Punto de entrada
 * ============================================================
 * Este archivo debe quedar corto: solo orquesta las llamadas
 * a las funciones definidas en los otros módulos. La lógica
 * real vive en Entorno.cpp y Diagnostico.cpp.
 * ============================================================
 */

#include <iostream>
#include <string>
#include <stdexcept>

// Incluimos las cabeceras desarrolladas por el equipo
#include "Entorno.h"
#include "Diagnostico.h"

using namespace std;

int main() {
    cout << "==================================================" << endl;
    cout << "   HERRAMIENTA DE DIAGNOSTICO DE ENTORNO (C++)   " << endl;
    cout << "==================================================" << endl;

    // 1. Uso de memoria dinamica y punteros (Requisito del reto)
    InfoEntorno* resultado = new InfoEntorno();

    // 2. Recoleccion de datos utilizando las funciones de Entorno.h
    cout << "\n[+] Recolectando informacion del entorno..." << endl;
    resultado->datoRed = obtenerDatoDeRed();
    resultado->datoSistema = obtenerDatoDeSistema();
    
    // 3. Verificacion de aislamiento
    resultado->aislado = estaEnEntornoAislado();

    // 4. Asignacion del detalle descriptivo segun el analisis
    if (resultado->aislado) {
        resultado->detalle = "Se detectaron artefactos/indicadores de virtualizacion en los datos del sistema DMI.";
    } else {
        resultado->detalle = "No se encontraron coincidencia de hipervisores o artefactos de virtualizacion conocidos.";
    }

    // 5. Manejo de Excepciones para la accion "real"
    // (Si detecta entorno aislado, lanza una excepcion y aborta la ejecucion real)
    try {
        if (resultado->aislado) {
            throw runtime_error("ALERTA DE SEGURIDAD: Entorno aislado detectado. Se aborta la ejecucion de la accion real.");
        }

        cout << "\n[EXITO] Entorno seguro/real confirmado. Ejecutando la accion principal del programa..." << endl;

    } catch (const exception& e) {
        cout << "\n[EXCEPCION CAPTURADA] " << e.what() << endl;
    }

    // 6. Registro del diagnostico en el archivo de log (usando Diagnostico.h)
    cout << "\n[+] Guardando registro de diagnostico en log..." << endl;
    string rutaLog = "diagnostico.log";
    
    // Llamada a la funcion de Diagnostico.h
    registrarResultado(*resultado, rutaLog);

    // 7. Liberacion de memoria dinamica asignada previamente
    delete resultado;
    resultado = nullptr;

    cout << "\n==================================================" << endl;
    cout << "   DIAGNOSTICO FINALIZADO                         " << endl;
    cout << "==================================================" << endl;

    return 0;
}
