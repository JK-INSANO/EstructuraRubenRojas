
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp" // se incluye para poder usar la clase Software

using namespace std;

// Navegador hereda de Software
class Navegador : public Software {
private:
    vector<string> historial; 

public:
    Navegador(const string& nombre, const string& desarrollador, int edad, float precio) 
        : Software(nombre, desarrollador, edad, precio) {}

    void agregarPaginaAlHistorial(const string& pagina) { // agrega una pagina al historial
        historial.push_back(pagina);
        if (historial.size() > 10) {
            historial.erase(historial.begin());
        }
    }

    const vector<string>& getHistorialNavegacion() const { return historial; } // retorna el historial de navegacion
};