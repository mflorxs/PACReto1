/*
 * ============================================================
 *  Diagnostico.cpp — Definiciones: procesamiento y registro
 * ============================================================
 */

#include "Diagnostico.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// TODO: implementen el registro en archivo, con manejo de
// excepciones. Aquí tienen un esqueleto de partida:

void registrarResultado(const InfoEntorno& info, const string& rutaLog) {
    try {
        string rutaCompleta = "logs/" + rutaLog;
        ofstream log(rutaCompleta, ios::out | ios::app);

        // Si el archivo no se pudo abrir, lanzamos una excepción
        // en vez de dejar que el programa falle en silencio.
        if (!log.is_open()) {
            throw runtime_error("No se pudo crear o abrir el archivo de log: " + rutaLog);
        }

        // TODO: escriban aquí el resultado del diagnóstico en el
        // formato que decidan (incluyan al menos: si se detectó
        // aislamiento o no, y el detalle de qué se evaluó).
        if (log.fail()) {
            throw runtime_error(
                "Ocurrio un error al escribir en el archivo de log: " + rutaLog
            );
        }

        log.close();

    } catch (const exception& e) {
        cout << "Error al registrar el resultado: "
             << e.what()
             << endl;
    }
}


