#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include "DTFecha.h"
#include "ArticuloRevista.h"
#include "Libro.h"
#include "PaginaWeb.h"
#include "Investigador.h"

using namespace std;

// Variables globales para acceder desde el menú
vector<Publicacion*> publicaciones;
map<string, Publicacion*> mapaPublicaciones;
Investigador* inv1 = nullptr;
Investigador* inv2 = nullptr;

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n=== MENU DE PRUEBAS ===" << endl;
    cout << "1. Listar todas las publicaciones (getDT)" << endl;
    cout << "2. Listar todos los investigadores (toString)" << endl;
    cout << "3. Establecer relaciones" << endl;
    cout << "4. Listar publicaciones de Carla Oliveri (fecha > 10/12/2023, contiene 'UML')" << endl;
    cout << "5. Eliminar publicacion con DOI '10.4567/jkl012'" << endl;
    cout << "6. Listar publicaciones de Carla Oliveri (fecha > 1/1/2020, contiene 'UML')" << endl;
    cout << "7. Listar publicaciones de Alberto Santos (fecha > 1/1/2020, contiene 'UML')" << endl;
    cout << "8. Salir" << endl;
    cout << "Opcion: ";
}

// Función para listar todas las publicaciones
void listarPublicaciones() {
    cout << "\n=== PUBLICACIONES ===" << endl;
    for (auto* pub : publicaciones) {
        cout << pub->getDT() << endl;
    }
}

// Función para listar investigadores
void listarInvestigadores() {
    cout << "\n=== INVESTIGADORES ===" << endl;
    if (inv1) cout << inv1->toString() << endl;
    if (inv2) cout << inv2->toString() << endl;
}

// Función para establecer relaciones
void establecerRelaciones() {
    for (auto* pub : publicaciones) {
        set<Investigador*> autoresCopy = pub->getAutores();
        for (auto* autor : autoresCopy) {
            pub->quitarAutor(autor);
            autor->quitarPublicacion(pub);
        }
    }

    // Lista de relaciones (ORCID, DOI)
    vector<pair<string, string>> relaciones = {
        {"0000-0003-1234-5678", "10.1234/abc123"},
        {"0000-0003-1234-5678", "10.4567/jkl012"},
        {"0000-0003-1234-5678", "10.5678/mno345"},
        {"0000-0003-1234-5678", "10.3456/ghi789"},
        {"0000-0001-8765-4321", "10.1234/abc123"},
        {"0000-0001-8765-4321", "10.2345/def456"},
        {"0000-0001-8765-4321", "10.4567/jkl012"}
    };

    for (const auto& rel : relaciones) {
        Investigador* inv = (rel.first == inv1->getORCID()) ? inv1 : inv2;
        Publicacion* pub = mapaPublicaciones[rel.second];
        if (inv && pub) {
            inv->agregarPublicacion(pub);
            pub->agregarAutor(inv);
        }
    }
    cout << "\nRelaciones establecidas correctamente." << endl;
}

// Función para listar publicaciones de un investigador con filtro
void listarPublicacionesDe(Investigador* inv, const DTFecha& desde, const string& palabra, const string& nombreInv) {
    if (!inv) {
        cout << "Investigador no existe." << endl;
        return;
    }
    set<string> resultados = inv->listarPublicaciones(desde, palabra);
    cout << "\n=== Publicaciones de " << nombreInv << " (fecha > "
         << desde.getDia() << "/" << desde.getMes() << "/" << desde.getAnio()
         << ", contiene '" << palabra << "') ===" << endl;
    if (resultados.empty()) {
        cout << "Ninguna publicacion cumple los criterios." << endl;
    } else {
        for (const auto& doi : resultados) {
            cout << doi << endl;
        }
    }
}

// Función para eliminar una publicación por DOI
void eliminarPublicacion(const string& doi) {
    auto it = mapaPublicaciones.find(doi);
    if (it == mapaPublicaciones.end()) {
        cout << "No se encontro publicacion con DOI: " << doi << endl;
        return;
    }

    Publicacion* pub = it->second;

    // Quitar la publicación de los autores
    set<Investigador*> autoresCopy = pub->getAutores();
    for (auto* autor : autoresCopy) {
        autor->quitarPublicacion(pub);
    }

    // Quitar del vector de publicaciones
    for (auto itVec = publicaciones.begin(); itVec != publicaciones.end(); ++itVec) {
        if (*itVec == pub) {
            publicaciones.erase(itVec);
            break;
        }
    }

    // Eliminar del mapa y liberar memoria
    mapaPublicaciones.erase(doi);
    delete pub;

    cout << "Publicacion con DOI " << doi << " eliminada correctamente." << endl;
}

int main() {
    // ==================== CREACION DE OBJETOS ====================
    // Artículos de revista
    ArticuloRevista* art1 = new ArticuloRevista(
        "10.1234/abc123",
        "Fundamentos de POO",
        DTFecha(15, 5, 2023),
        "Programacion Avanzada",
        "Introduccion a los principios fundamentales de la programacion orientada a objetos, explicando sus conceptos clave como clases, objetos, herencia y polimorfismo."
    );

    ArticuloRevista* art2 = new ArticuloRevista(
        "10.4567/jkl012",
        "Utilidad de diagramas UML",
        DTFecha(10, 2, 2024),
        "Modelado de Software",
        "Ejercicio empirico de como los diagramas UML pueden ayudar en el proceso y documentacion de software, cubriendo los tipos mas importantes utilizados, como clases."
    );

    // Libros
    set<string> palabrasLibro1 = {"Diseno", "OOP", "Class"};
    Libro* libro1 = new Libro(
        "10.2345/def456",
        "Patrones de Diseno en c++",
        DTFecha(20, 8, 2022),
        "Software Design",
        palabrasLibro1
    );

    set<string> palabrasLibro2 = {"Diagrams", "UML", "Software", "Modelado"};
    Libro* libro2 = new Libro(
        "10.5678/mno345",
        "Guia de UML",
        DTFecha(20, 8, 2022),
        "IEEE",
        palabrasLibro2
    );

    // Página web
    PaginaWeb* web1 = new PaginaWeb(
        "10.3456/ghi789",
        "Diagramas para Principiantes",
        DTFecha(20, 10, 2024),
        "www.umlparaprincipiantes.com",
        "En esta pagina web se presenta una guia completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades."
    );

    // Agregar a la lista global
    publicaciones.push_back(art1);
    publicaciones.push_back(art2);
    publicaciones.push_back(libro1);
    publicaciones.push_back(libro2);
    publicaciones.push_back(web1);

    // Mapa para búsqueda rápida por DOI
    for (auto* pub : publicaciones) {
        mapaPublicaciones[pub->getDOI()] = pub;
    }

    // Crear investigadores
    inv1 = new Investigador("0000-0003-1234-5678", "Carla Oliveri", "Universidad de la Republica");
    inv2 = new Investigador("0000-0001-8765-4321", "Alberto Santos", "Instituto Tecnico");

    // ==================== MENU INTERACTIVO ====================
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                listarPublicaciones();
                break;
            case 2:
                listarInvestigadores();
                break;
            case 3:
                establecerRelaciones();
                break;
            case 4:
                listarPublicacionesDe(inv1, DTFecha(10, 12, 2023), "UML", "Carla Oliveri");
                break;
            case 5:
                eliminarPublicacion("10.4567/jkl012");
                break;
            case 6:
                listarPublicacionesDe(inv1, DTFecha(1, 1, 2020), "UML", "Carla Oliveri");
                break;
            case 7:
                listarPublicacionesDe(inv2, DTFecha(1, 1, 2020), "UML", "Alberto Santos");
                break;
            case 8:
                cout << "Saliendo... liberando memoria." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 8);

    // ==================== LIMPIEZA ====================
    for (auto* pub : publicaciones) {
        delete pub;
    }
    delete inv1;
    delete inv2;

    return 0;
}