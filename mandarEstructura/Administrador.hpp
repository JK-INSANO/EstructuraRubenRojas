
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Usuario.hpp" // se incluye para poder usar la clase Usuario

using namespace std;

// Administrador hereda de Usuario
class Administrador : public Usuario {
private:
    string correo; 

public: 
    Administrador(const string& nombreUsuario, const string& contrasena, int edad, const string& correo)
        : Usuario(nombreUsuario, contrasena, edad), correo(correo) {}

    void mostrarInfo() const override {
        cout << "Tipo de usuario: Administrador" << endl;
        cout << "Correo: " << correo << endl;
        cout << "Dinero disponible: $" << getDinero() << endl;
    }

    

    
};