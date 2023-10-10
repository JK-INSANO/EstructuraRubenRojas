
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp" // se incluye para poder usar la clase Software

using namespace std;

// Juegos hereda de Software
class Juegos : public Software {
private:
    vector<string> generos; 
public: // constructor
    Juegos(const string& nombre, const string& desarrollador, int edad, float precio)
        : Software(nombre, desarrollador, edad, precio) {}

    void agregarGenero(const string& genero) { // agrega un genero al vector de generos
        generos.push_back(genero);
    }

    // muestra la informacion del juego
    const vector<string>& getGeneros() const { return generos; }
};