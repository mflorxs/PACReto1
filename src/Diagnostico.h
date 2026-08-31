/*
 * ============================================================
 *  Diagnostico.h — struct de resultados + procesamiento y registro
 * ============================================================
 */

#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include <string>
using namespace std;

// Estructura que agrupa todo el resultado del diagnóstico.
//
// NOTA PARA QUIEN ARME main.cpp:
// Deben crear una variable de este tipo y llenar los 4 campos
// antes de llamar a registrarResultado(). Ejemplo:
//
//   InfoEntorno resultado;
//   resultado.datoRed = obtenerDatoDeRed();         // de Entorno.h
//   resultado.datoSistema = obtenerDatoDeSistema(); // de Entorno.h
//   resultado.aislado = estaEnEntornoAislado();      // de Entorno.h
//   resultado.detalle = "..."; // describan en texto qué se evaluó
//
struct InfoEntorno {
    bool aislado;        // true si se detectó entorno aislado, false si no
    string detalle;       // explicación en texto: qué se evaluó y por qué se llegó a esa conclusión
    string datoRed;        // resultado de obtenerDatoDeRed() (Entorno.h)
    string datoSistema;    // resultado de obtenerDatoDeSistema() (Entorno.h)
};

// Escribe el resultado del diagnóstico en el archivo de log indicado.
//
// NOTA PARA QUIEN ARME main.cpp:
// Llámenla al final, ya con el struct InfoEntorno completamente
// lleno. rutaLog es la ruta del archivo, ej: "logs/diagnostico.log"
// (la carpeta logs/ debe existir o la función fallará al abrir
// el archivo — eso ya está contemplado con el try/catch interno).
//
// No necesitan hacer try/catch alrededor de esta llamada: el
// manejo de la excepción ya ocurre DENTRO de registrarResultado
// (ver Diagnostico.cpp), que atrapa el error y avisa en pantalla.
//
void registrarResultado(const InfoEntorno& info, const string& rutaLog);

#endif
