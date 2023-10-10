
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Usuario.hpp"
#include "Software.hpp"
#include "Administrador.hpp"



using namespace std;


class Sistema {     // Sistema es una clase que representa el sistema de la empresa
private:
    unordered_map<string, Usuario*> usuarios; // nombreUsuario -> Usuario*
    unordered_map<string, Software*> software; // nombreSoftware -> Software*
    unordered_map<string, vector<string>> registroActividad; // nombreUsuario -> vector<string>
    Usuario* usuarioActual;

public:
    ~Sistema() { // destructor
        for (auto it = usuarios.begin(); it != usuarios.end(); ++it) { // se recorre el unordered_map usuarios
            delete it->second; // se libera la memoria de cada Usuario*
        }

        for (auto it = software.begin(); it != software.end(); ++it) { // se recorre el unordered_map software
            delete it->second; // se libera la memoria de cada Software*
        }
    }

    bool Sistema::iniciarSesion(const string& nombreUsuario, const string& contrasena) {
        // Buscar el usuario en el sistema
        unordered_map<string, Usuario*>::const_iterator it = usuarios.find(nombreUsuario);

        // Si el usuario existe y la contraseña coincide
        if (it != usuarios.end() && it->second->verificarContrasena(contrasena)) {
            usuarioActual = it->second;
            return true;
        } else {
            usuarioActual = nullptr; // Asegura que usuarioActual se establezca en nullptr si la autenticación falla
            return false; // Usuario o contraseña incorrectos
        }
    }

 
    bool agregarSoftware(const string& nombreUsuario, const string& nombreSoftware) { // agrega un software
        auto usuarioIt = usuarios.find(nombreUsuario); // se busca el usuario
        auto softwareIt = software.find(nombreSoftware); // se busca el software

        if (usuarioIt != usuarios.end() && softwareIt != software.end()) { // si se encuentra el usuario y el software
            Usuario* u = usuarioIt->second; // se obtiene el Usuario*
            Software* s = softwareIt->second; // se obtiene el Software*

            if ((u->getEdad() >= 18 || s->getEdad() < 18) && !(s->getNombre() == "Produccion" && u->getEdad() < 18) &&
                !(s->getNombre() == "Seguridad" && dynamic_cast<Administrador*>(u) == nullptr)) { // se verifica que el usuario pueda comprar el software
                u->agregarSoftware(s->getNombre()); // se agrega el software al usuario
                s->agregarUsuario(u->getNombreUsuario()); // se agrega el usuario al software
                return true;
            }
        }

        return false;
    }

    bool eliminarSoftware(const string& nombreUsuario, const string& nombreSoftware) { // elimina un software
        auto usuarioIt = usuarios.find(nombreUsuario); // se busca el usuario
        auto softwareIt = software.find(nombreSoftware); // se busca el software

        if (usuarioIt != usuarios.end() && softwareIt != software.end()) { // si se encuentra el usuario y el software
            Usuario* u = usuarioIt->second; // se obtiene el Usuario*
            Software* s = softwareIt->second; // se obtiene el Software*

            if (u->eliminarSoftware(s->getNombre())) { // se elimina el software del usuario
                s->eliminarUsuario(u->getNombreUsuario());
                return true; 
            }
        }

        return false;
    }

    void agregarUsuario(Usuario* u) { 
        usuarios[u->getNombreUsuario()] = u;
    }

    void agregarSoftware(Software* s) { 
        software[s->getNombre()] = s;
    }
    
    Usuario* getUsuario(const string& nombreUsuario) const { // retorna un Usuario* dado el nombre de usuario
        auto it = usuarios.find(nombreUsuario); 
        if (it != usuarios.end()) { 
            return it->second;
        }
        return nullptr; 
    }

    Software* getSoftware(const string& nombreSoftware) const { // retorna un Software* dado el nombre de software
        auto it = software.find(nombreSoftware);
        if (it != software.end()) {
            return it->second;
        }
        return nullptr; 
    }
    void agregarActividadUsuario(const string& nombreUsuario, const string& actividad) {
        registroActividad[nombreUsuario].push_back(actividad); 
    }

    const unordered_map<string, vector<string>>& getRegistroActividad() const { 
        return registroActividad;
    }

};