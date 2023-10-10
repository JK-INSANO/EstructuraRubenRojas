
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Software { 
private:
    string nombre; 
    string desarrollador; 
    int edad;  
    float precio;  
    vector<string> usuarios;   
public:
    Software(const string& nombre, const string& desarrollador, int edad, float precio)
        : nombre(nombre), desarrollador(desarrollador), edad(edad), precio(precio) {} 

    const string& getNombre() const { return nombre; } 
    int getEdad() const { return edad; }   
    float getPrecio() const { return precio; } 

    void agregarUsuario(const string& nombreUsuario) { // agrega un usuario al vector de usuarios
        usuarios.push_back(nombreUsuario);
    }

    void eliminarUsuario(const string& nombreUsuario) { 
        for (auto it = usuarios.begin(); it != usuarios.end(); ++it) { 
            if (*it == nombreUsuario) { 
                usuarios.erase(it); 
                return; 
            }
        }
    }

    const vector<string>& getUsuarios() const { return usuarios; }

    virtual ~Software() {}  // destructor virtual
};