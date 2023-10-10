
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp"

using namespace std;

class Seguridad : public Software { // Seguridad hereda de Software
private:
    string tipoMalware; // tipo de malware que detecta

public:
    Seguridad(const string& nombre, const string& desarrollador, int edad, float precio, const string& tipoMalware)   
        : Software(nombre, desarrollador, edad, precio), tipoMalware(tipoMalware) {}

    const string& getTipoMalware() const { return tipoMalware; } // retorna el tipo de malware
};