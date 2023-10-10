
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"   
using namespace std;

class Produccion : public Software {    // Produccion hereda de Software
private:
    string tipoSolucion;  
public:
    Produccion(const string& nombre, const string& desarrollador, int edad, float precio, const string& tipoSolucion) 
        : Software(nombre, desarrollador, edad, precio), tipoSolucion(tipoSolucion) {}

    const string& getTipoSolucion() const { return tipoSolucion; } // retorna el tipo de solucion
};