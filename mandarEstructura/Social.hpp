
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Software.hpp" 

using namespace std;

class Social : public Software { 
private:
    vector<string> usuariosSociales;

public:
    Social(const string& nombre, const string& desarrollador, int edad, float precio)
        : Software(nombre, desarrollador, edad, precio) {} 

  
    void agregarUsuarioSocial(const string& nombreUsuario) { // agrega un usuario social al vector de usuarios sociales
        usuariosSociales.push_back(nombreUsuario); 
    }

   
    void eliminarUsuarioSocial(const string& nombreUsuario) { // elimina un usuario social del vector de usuarios sociales
        for (auto it = usuariosSociales.begin(); it != usuariosSociales.end(); ++it) {
            if (*it == nombreUsuario) {
                usuariosSociales.erase(it);
                return;
            }
        }
    }

    const vector<string>& getUsuariosSociales() const { return usuariosSociales; } // retorna el vector de usuarios sociales
}; 