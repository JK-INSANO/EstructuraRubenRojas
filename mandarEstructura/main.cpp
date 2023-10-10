#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Incluye los archivos de cabecera de las clases necesarias
#include <Usuario.hpp>
#include <Administrador.hpp>
#include <Normal.hpp>
#include <Nino.hpp>

#include <Software.hpp>
#include <Juegos.hpp>
#include <Ofimatica.hpp>
#include <Produccion.hpp>
#include <Navegador.hpp>
#include <Seguridad.hpp>
#include <Social.hpp>

#include <Sistema.hpp>


using namespace std;



// Función que elimina un software de la biblioteca de un usuario
void eliminarSoftware(Sistema& sistema, const string& nombreUsuario){
    string nombreSoftware;
    cout << "Ingrese el nombre del software que desea eliminar: ";
    cin >> nombreSoftware;
    bool exito = sistema.eliminarSoftware(nombreUsuario, nombreSoftware);
    if (exito) {
        cout << "El software se eliminó con éxito." << endl;
    } else {
        cout << "No se pudo eliminar el software." << endl;
    }
    
}

// Función que muestra el registro de actividad del sistema
void mostrarRegistro(Sistema& sistema, const string& nombreUsuario){
    if (dynamic_cast<Administrador*>(sistema.getUsuario(nombreUsuario)) != nullptr) {
        sistema.getUsuario(nombreUsuario)->mostrarRegistroActividad(sistema.getRegistroActividad());
    } else {
        cout << "Acceso denegado. Solo los administradores pueden acceder a actividad." << endl;
    }
}

// Función que agrega un software a la biblioteca de un usuario
// Función que agrega un software a la biblioteca de un usuario
void agregarSoftware(Sistema& sistema, const string& nombreUsuario){
    string nombreSoftware;
    cout << "Ingrese el nombre del software que desea agregar: ";
    cin.ignore(); // Limpiar el buffer del teclado
    getline(cin, nombreSoftware); // Leer una línea completa, incluidos los espacios en blanco

    bool exito = sistema.agregarSoftware(nombreUsuario, nombreSoftware);
    if (exito) {
        cout << "El software se agregó con éxito." << endl;
    } else {
        cout << "No se pudo agregar el software." << endl;
    }
}


// Función que muestra el menú de un software de redes sociales
void softwareSocial( Sistema& sistema, const string& nombreUsuario, int opcion, Social* social){
    cout << "Usando software: " << social->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1.-Agregar amigo" << endl;
    cout << "2.-Eliminar amigo" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        string nombreAmigo;
        cout << "Ingrese el nombre del amigo que desea agregar: ";
        cin >> nombreAmigo;
        social->agregarUsuarioSocial(nombreAmigo);
        cout << "Amigo agregado con éxito." << endl;
    } else if (opcion == 2) {
        string nombreAmigo;
        cout << "Ingrese el nombre del amigo que desea eliminar: ";
        cin >> nombreAmigo;
        social->eliminarUsuarioSocial(nombreAmigo);
        cout << "Amigo eliminado con éxito." << endl;
    } else {
        cout << "Opción no válida." << endl;
    }
}

// Función que muestra el menú de un software de seguridad
void softwareSeguridad( Sistema& sistema, const string& nombreUsuario, int opcion, Seguridad* seguridad){
    
    if (dynamic_cast<Administrador*>(sistema.getUsuario(nombreUsuario)) != nullptr) {
        cout << "Usando el software de seguridad: " << seguridad->getNombre() << endl;
        cout << "Menú:" << endl;
        cout << "1.-Escanear" << endl;
        cout << "2.-Analizar tipo de malware" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        
        if (opcion == 1) {
            cout << "Escaneando..." << endl;
        } else if (opcion == 2) {
            cout << "Tipo de malware: " << seguridad->getTipoMalware() << endl;
        } else {
            cout << "Opción no válida." << endl;
        }
    } else {
        cout << "Acceso denegado. Solo los administradores pueden usar el software de seguridad." << endl;
    }
}

// Función que muestra el menú de un software de navegación
void softwareNavegacion( Sistema& sistema, const string& nombreUsuario, int opcion, Navegador* navegador){
    cout << "Usando el navegador: " << navegador->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1.-Hacer una busqueda" << endl;
    cout << "2.-Ver historial de navegación" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        string busqueda;
        cout << "Ingrese la busqueda que desea hacer: ";
        cin >> busqueda;
        cout << "Buscando " << busqueda << "..." << endl;
        navegador->agregarPaginaAlHistorial(busqueda);
    } else if (opcion == 2) {
        cout << "Historial de navegación:" << endl;
        for (const string& pagina : navegador->getHistorialNavegacion()) {
            cout << pagina << endl;
        }
    } else {
        cout << "Opción no válida." << endl;
    }
}

// menú de producción
void softwareProduccion( Sistema& sistema, const string& nombreUsuario, int opcion, Produccion* prod){
    cout << "Usando el software de producción: " << prod->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1.-Crear solución" << endl;
    cout << "2.-Eliminar solución" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        cout << "Creando solución..." << endl;
    } else if (opcion == 2) {
        cout << "Eliminando solución..." << endl;
    } else {
        cout << "Opción no válida." << endl;
    }
}

// menú de ofimática
void softwareOfimatica( Sistema& sistema, const string& nombreUsuario, int opcion, Ofimatica* ofi){
    cout << "Usando el software de ofimática: " << ofi->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1.-Crear archivo" << endl;
    cout << "2.-Eliminar archivo" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        ofi->crearArchivo();
        cout << "Archivo creado con éxito." << endl;
    } else if (opcion == 2) {
        ofi->borrarArchivo();
        cout << "Archivo eliminado con éxito." << endl;
    } else {
        cout << "Opción no válida." << endl;
    }
}

// menú de juegos
void softwareJuego( Sistema& sistema, const string& nombreUsuario, int opcion, Juegos* juego){
    cout << "Usando el juego: " << juego->getNombre() << endl;
    cout << "Menú:" << endl;
    cout << "1.-Jugar" << endl;
    cout << "2.-Ver géneros" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    if (opcion == 1) {
        cout << "Jugando..." << endl;
    } else if (opcion == 2) {
        cout << "Géneros:" << endl;
        for (const string& genero : juego->getGeneros()) {
            cout << genero << endl;
        }
    } else {
        cout << "Opción no válida." << endl;
    }
}

// Función que muestra la biblioteca de un usuario y le permite elegir un software para usar
void mostrarBiblioteca(Sistema& sistema, const string& nombreUsuario, int opcion){
    sistema.getUsuario(nombreUsuario)->verBiblioteca();
    if (sistema.getUsuario(nombreUsuario)->getBiblioteca().empty()) {
        cout << "Biblioteca vacía." << endl;
    }
    
    cout << "Ingrese el nombre del software que desea utilizar: ";
    string nombreSoftware;
    cin.ignore(); 
    getline(cin, nombreSoftware);

    // Busca el software en la base de datos
    Software* softwareElegido = sistema.getSoftware(nombreSoftware);

    if (softwareElegido) {
        const vector<string>& usuariosConAcceso = softwareElegido->getUsuarios();
        bool tieneAcceso = false;
        for (const string& usuario : usuariosConAcceso) {
            if (usuario == nombreUsuario) {
                tieneAcceso = true;
                break;
            }
        }
        // Si el usuario tiene acceso al software, se ejecuta el menú correspondiente
        if (tieneAcceso) {
            if (Juegos* juego = dynamic_cast<Juegos*>(softwareElegido)) {
                softwareJuego(sistema, nombreUsuario, opcion, juego); // Llama a la función que muestra el menú de un juego
            } else if (Ofimatica* ofi = dynamic_cast<Ofimatica*>(softwareElegido)) {
                softwareOfimatica(sistema, nombreUsuario, opcion, ofi); // Llama a la función que muestra el menú de un software de ofimática
            } else if (Produccion* prod = dynamic_cast<Produccion*>(softwareElegido)) {
                softwareProduccion(sistema, nombreUsuario, opcion, prod); // Llama a la función que muestra el menú de un software de producción
            } else if (Navegador* navegador = dynamic_cast<Navegador*>(softwareElegido)) {
                softwareNavegacion(sistema, nombreUsuario, opcion, navegador); // Llama a la función que muestra el menú de un software de navegación
            } else if (Seguridad* seguridad = dynamic_cast<Seguridad*>(softwareElegido)) {
                softwareSeguridad(sistema, nombreUsuario, opcion, seguridad); // Llama a la función que muestra el menú de un software de seguridad
            } else if (Social* social = dynamic_cast<Social*>(softwareElegido)) {
                softwareSocial(sistema, nombreUsuario, opcion, social); // Llama a la función que muestra el menú de un software de redes sociales
            } else {
                cout << "Este software no tiene una función específica definida." << endl;
            }
        } else {
            cout << "No tienes acceso a este software." << endl;
        }
    } else {
        cout << "El software no existe en la base de datos." << endl;
    }
}
//Ejecuta el sistema
void ejecutarSistema(Sistema& sistema){

    string nombreUsuario, contrasena;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese la contraseña: ";
    cin >> contrasena;
    
    bool inicioSesionCorrecto = sistema.iniciarSesion(nombreUsuario, contrasena);

    // Si el inicio de sesión es correcto, se ejecuta el menú principal
    if (inicioSesionCorrecto) {
        cout << "Acceso correcto" << endl;
        int opcion;
    
        do {
            cout << "Menú:" << endl;
            cout << "1.-Ver biblioteca" << endl;
            cout << "2.-Agregar software" << endl;
            cout << "3.-Eliminar software" << endl;
            cout << "4.-Ver registro de actividad" << endl;
            cout << "5.-Logout" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;
    
            switch (opcion) {
                case 1: {
                    mostrarBiblioteca(sistema, nombreUsuario, opcion);
                    break;
                }

                case 2: {
                    agregarSoftware(sistema, nombreUsuario); 
                    break;
                }
                case 3: {
                    eliminarSoftware(sistema, nombreUsuario); 
                }
                case 4: {
                    mostrarRegistro(sistema, nombreUsuario); 
                }
                // Si el usuario elige la opción 5, se le da la opción de cerrar sesión o terminar el programa
                case 5: {
                    int logoutOption;
                    cout << "1.-Logear con otro usuario" << endl;
                    cout << "2.-Terminar el programa" << endl;
                    cout << "Ingrese una opción: ";
                    cin >> logoutOption;
                    if (logoutOption == 1) {
                        ejecutarSistema(sistema);
                    } else if (logoutOption == 2) {
                        cout << "Saliendo del programa..." << endl;
                        
                    } else {
                        cout << "Opción no válida. Volviendo al menú principal." << endl;
                    }
                    break;
                }
                default: {
                    cout << "Opción no válida. Intente de nuevo." << endl;
                    break;
                }
            }
    
        } while (opcion != 5);
    } else {
        cout << "Acceso incorrecto" << endl;
    }
}

// Función principal
int main() {
    
    Sistema sistema; 
    

Usuario* n1 = new Nino("nino", "nino", 12);
Usuario* n2 = new Nino("Anna", "5678", 10);
Usuario* n3 = new Nino("Peter", "abcd", 8);
Usuario* n4 = new Nino("Lucas", "efgh", 9);
Usuario* u1 = new Normal("normal", "normal", 18, "mark@example.com");
Usuario* u2 = new Normal("Laura", "mnop", 20, "laura@example.com");
Usuario* u3 = new Normal("Carla", "qrst", 25, "carla@example.com");
Usuario* u4 = new Normal("Edward", "uvwx", 30, "edward@example.com");
Usuario* u5 = new Normal("Isabel", "yzab", 22, "isabel@example.com");
Usuario* u6 = new Normal("Charles", "12345", 28, "charles@example.com");
Usuario* u7 = new Normal("AnneMarie", "abcdef", 24, "annemarie@example.com");
Usuario* u8 = new Normal("Javier", "qwerty", 22, "javier@example.com");
Usuario* u9 = new Normal("Mariana", "abc123", 30, "mariana@example.com");
Usuario* u10 = new Normal("Lucia", "456789", 26, "lucia@example.com");
Usuario* admin = new Administrador("admin", "admin", 21, "JKADMINin@adminAdmin.com");

    // Agregar usuarios al sistema
    sistema.agregarUsuario(admin);
    sistema.agregarUsuario(n1);
    sistema.agregarUsuario(n2);
    sistema.agregarUsuario(n3);
    sistema.agregarUsuario(n4);
    sistema.agregarUsuario(u1);
    sistema.agregarUsuario(u2);
    sistema.agregarUsuario(u3);
    sistema.agregarUsuario(u4);
    sistema.agregarUsuario(u5);

    Software* j1 = new Juegos("Street Fighter", "Capcom", 16, 3500);
    Software* j2 = new Juegos("The Sims 5", "Electronic Arts", 12, 4200);
    Software* j3 = new Juegos("Counter-Strike: Global Offensive", "Valve", 18, 3500);
    Software* j4 = new Juegos("The Legend of Zelda: Breath of the Wild", "Nintendo", 10, 4500);
    Software* j5 = new Juegos("Grand Theft Auto: San Andreas", "Rockstar Games", 18, 3800);
    Software* j6 = new Juegos("FIFA 23", "EA Sports", 7, 4800);
    Software* j7 = new Juegos("Resident Evil Village", "Capcom", 18, 4100);
    Software* j8 = new Juegos("Cities: Skylines", "Paradox Interactive", 10, 3900);
    Software* j9 = new Juegos("Sid Meier's Civilization VII", "Firaxis Games", 12, 5500);
    Software* j10 = new Juegos("NBA 2K23", "2K Sports", 0, 4700);
    Software* j11 = new Juegos("Minecraft: Dungeons", "Mojang", 10, 4200);
    Software* j12 = new Juegos("Resident Evil 7: Biohazard", "Capcom", 18, 4600);
    Software* j13 = new Juegos("The Elder Scrolls V: Skyrim", "Bethesda Game Studios", 17, 3800);
    Software* j14 = new Juegos("Far Cry 6", "Ubisoft", 18, 4900);
    Software* j15 = new Juegos("Dirt Rally 3", "Codemasters", 7, 4700);
    Software* j16 = new Juegos("Dark Souls III", "FromSoftware", 16, 4200);
    Software* j17 = new Juegos("Starbound", "Chucklefish", 10, 3900);
    Software* j18 = new Juegos("Dead Space", "Electronic Arts", 18, 4100);
    Software* j19 = new Juegos("Tekken 7", "Bandai Namco", 16, 4400);
    Software* j20 = new Juegos("F1 2023", "Codemasters", 3, 4600);

    // Agregar géneros a los juegos
    static_cast<Juegos*>(j1)->agregarGenero("Street Fighter");
    static_cast<Juegos*>(j2)->agregarGenero("The Sims 5");
    static_cast<Juegos*>(j3)->agregarGenero("Counter-Strike: Global Offensive");
    static_cast<Juegos*>(j4)->agregarGenero("The Legend of Zelda: Breath of the Wild");
    static_cast<Juegos*>(j5)->agregarGenero("Grand Theft Auto: San Andreas");
    static_cast<Juegos*>(j6)->agregarGenero("FIFA 23");
    static_cast<Juegos*>(j7)->agregarGenero("Resident Evil Village");
    static_cast<Juegos*>(j8)->agregarGenero("Cities: Skylines");
    static_cast<Juegos*>(j9)->agregarGenero("Sid Meier's Civilization VII");
    static_cast<Juegos*>(j10)->agregarGenero("NBA 2K23");
    static_cast<Juegos*>(j11)->agregarGenero("Minecraft: Dungeons");
    static_cast<Juegos*>(j12)->agregarGenero("Resident Evil 7: Biohazard");
    static_cast<Juegos*>(j13)->agregarGenero("The Elder Scrolls V: Skyrim");
    static_cast<Juegos*>(j14)->agregarGenero("Far Cry 6");
    static_cast<Juegos*>(j15)->agregarGenero("Dirt Rally 3");
    static_cast<Juegos*>(j16)->agregarGenero("Dark Souls III");
    static_cast<Juegos*>(j17)->agregarGenero("Starbound");
    static_cast<Juegos*>(j18)->agregarGenero("Dead Space");
    static_cast<Juegos*>(j19)->agregarGenero("Tekken 7");
    static_cast<Juegos*>(j20)->agregarGenero("F1 2023");

    // Agregar los juegos al sistema
    sistema.agregarSoftware(j1);
    sistema.agregarSoftware(j2);
    sistema.agregarSoftware(j3);
    sistema.agregarSoftware(j4);
    sistema.agregarSoftware(j5);
    sistema.agregarSoftware(j6);
    sistema.agregarSoftware(j7);
    sistema.agregarSoftware(j8);
    sistema.agregarSoftware(j9);
    sistema.agregarSoftware(j10);
    
    Software* o1 = new Ofimatica("Microsoft Office", "Microsoft", 18, 20000);
    Software* o2 = new Ofimatica("LibreOffice", "The Document Foundation", 0, 0);
    Software* o3 = new Ofimatica("Google Docs", "Google", 0, 0);
    Software* o4 = new Ofimatica("WPS Office", "Kingsoft Office Software", 0, 0);
    Software* o5 = new Ofimatica("OnlyOffice", "Ascensio System SIA", 0, 0);

    // Agregar software de ofimatica al sistema
    sistema.agregarSoftware(o1);
    sistema.agregarSoftware(o2);
    sistema.agregarSoftware(o3);
    sistema.agregarSoftware(o4);
    sistema.agregarSoftware(o5);


   Software* p1 = new Produccion("AutoCAD 2023", "Autodesk", 18, 5500, "Diseño 2D y 3D");
    Software* p2 = new Produccion("DaVinci Resolve", "Blackmagic Design", 18, 2700, "Edición de Video");
    Software* p3 = new Produccion("Logic Pro", "Apple", 18, 3200, "Producción de Audio");
    Software* p4 = new Produccion("CATIA", "Dassault Systèmes", 18, 4800, "Diseño de Ingeniería");


    // Agregar software de producción al sistema
    sistema.agregarSoftware(p1);
    sistema.agregarSoftware(p2);
    sistema.agregarSoftware(p3);
    sistema.agregarSoftware(p4);


    Software* n5 = new Navegador("Google Chrome", "Google", 0, 0);
    Software* n6 = new Navegador("Brave", "Brave", 0, 0);


    sistema.agregarSoftware(n5);
    sistema.agregarSoftware(n6);

 
   Software* s3 = new Seguridad("CyberShield", "TechGuard", 0, 550, "Firewall");
    Software* s4 = new Seguridad("VirusGuard Pro", "SecureTech", 0, 350, "Antivirus");
    Software* s5 = new Seguridad("MalwareStopper", "CyberGuardians", 18, 1200, "Anti-Malware");
    Software* s6 = new Seguridad("SpywareDefender", "Guardian Software", 0, 750, "Anti-Spyware");

    // Agregar software de seguridad al sistema
    sistema.agregarSoftware(s3);
    sistema.agregarSoftware(s4);
    sistema.agregarSoftware(s5);
    sistema.agregarSoftware(s6);
    
    Software* s8 = new Social("Facebook", "Facebook", 18, 0);
    Software* s7 = new Social("Instagram", "Facebook", 13, 0);

    // Agregar software de redes sociales al sistema
    sistema.agregarSoftware(s8);
    sistema.agregarSoftware(s7);

    //Llammada a la funcion que ejecuta el sistema
    ejecutarSistema(sistema); 

    return 0;
} ;
