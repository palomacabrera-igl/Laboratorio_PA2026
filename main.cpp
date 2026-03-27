#include <iostream>
#include <vector>
#include <set>
#include <map>   5
#include <utility>
#include "DTFecha.h"
#include "ArticuloRevista.h"
#include "Libro.h"
#include "PaginaWeb.h"
#include "Investigador.h"

using namespace std;

int main() {
    // ==================== PASO a ====================
    // Crear artículos de revista
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

    // ==================== PASO b ====================
    // Crear libros
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

    // ==================== PASO c ====================
    // Crear páginas web
    PaginaWeb* web1 = new PaginaWeb(
        "10.3456/ghi789",
        "Diagramas para Principiantes",
        DTFecha(20, 10, 2024),
        "www.umlparaprincipiantes.com",
        "En esta pagina web se presenta una guia completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades."
    );

    // Agrupar todas las publicaciones en un vector para facilitar manejo
    vector<Publicacion*> publicaciones;
    publicaciones.push_back(art1);
    publicaciones.push_back(art2);
    publicaciones.push_back(libro1);
    publicaciones.push_back(libro2);
    publicaciones.push_back(web1);

    // ==================== PASO d ====================
    // Imprimir getDT() de cada publicación
    cout << "=== Paso d ===" << endl;
    for (auto* pub : publicaciones) {
        cout << pub->getDT() << endl;
    }

    // ==================== PASO e ====================
    // Crear investigadores
    Investigador* inv1 = new Investigador("0000-0003-1234-5678", "Carla Oliveri", "Universidad de la Republica");
    Investigador* inv2 = new Investigador("0000-0001-8765-4321", "Alberto Santos", "Instituto Tecnico");

    // ==================== PASO f ====================
    // Imprimir toString de cada investigador
    cout << "\n=== Paso f ===" << endl;
    cout << inv1->toString() << endl;
    cout << inv2->toString() << endl;

    // ==================== PASO g ====================
    // Registrar relaciones (bidireccional)
    // Nota: la consigna lista pares Investigador-Publicacion
    // Creamos un mapa de DOI a publicación para facilitar búsqueda
    map<string, Publicacion*> mapaPublicaciones;
    for (auto* pub : publicaciones) {
        mapaPublicaciones[pub->getDOI()] = pub;
    }

    // Lista de relaciones: (ORCID, DOI)
    vector<pair<string, string>> relaciones = {
        {"0000-0003-1234-5678", "10.1234/abc123"},
        {"0000-0003-1234-5678", "10.4567/jkl012"},
        {"0000-0003-1234-5678", "10.5678/mno345"},
        {"0000-0003-1234-5678", "10.3456/ghi789"},
        {"0000-0001-8765-4321", "10.1234/abc123"},
        {"0000-0001-8765-4321", "10.2345/def456"},
        {"0000-0001-8765-4321", "10.4567/jkl012"}
    };

    // Asociar
    for (const auto& rel : relaciones) {
        Investigador* inv = (rel.first == inv1->getORCID()) ? inv1 : inv2;
        Publicacion* pub = mapaPublicaciones[rel.second];
        if (inv && pub) {
            inv->agregarPublicacion(pub);
            pub->agregarAutor(inv);
        }
    }

    // ==================== PASO h ====================
    // Invocar listarPublicaciones para Carla Oliveri (inv1) con fecha 10/12/2023 y palabra "UML"
    cout << "\n=== Paso h ===" << endl;
    DTFecha desde_h(10, 12, 2023);
    set<string> resultados_h = inv1->listarPublicaciones(desde_h, "UML");
    for (const auto& doi : resultados_h) {
        cout << doi << endl;
    }

    // ==================== PASO i ====================
    // Eliminar el objeto con DOI "10.4567/jkl012" (art2)
    // La letra dice "ejecutar la eliminación del objeto ... de la clase Publication"
    // Eliminamos de la memoria y también de las relaciones
    Publicacion* aEliminar = mapaPublicaciones["10.4567/jkl012"];
    if (aEliminar) {
        // Primero, para cada autor de esta publicación, eliminar la publicación de su set
        // Hacemos copia de autores porque vamos a modificar el set mientras iteramos
        set<Investigador*> autoresCopy = aEliminar->getAutores();
        for (auto* autor : autoresCopy) {
            autor->quitarPublicacion(aEliminar);
        }
        // Luego eliminamos la publicación
        delete aEliminar;
        // También debemos quitarlo del vector de publicaciones para no usarlo después
        for (auto it = publicaciones.begin(); it != publicaciones.end(); ++it) {
            if (*it == aEliminar) {
                publicaciones.erase(it);
                break;
            }
        }
        // Opcional: también borrar del mapa
        mapaPublicaciones.erase("10.4567/jkl012");
    }

    // ==================== PASO j ====================
    // Invocar listarPublicaciones para Carla Oliveri con fecha 1/1/2020 y palabra "UML"
    cout << "\n=== Paso j ===" << endl;
    DTFecha desde_j(1, 1, 2020);
    set<string> resultados_j = inv1->listarPublicaciones(desde_j, "UML");
    for (const auto& doi : resultados_j) {
        cout << doi << endl;
    }

    // ==================== PASO k ====================
    // Imprimir getDT() de cada publicación (las que quedan)
    cout << "\n=== Paso k ===" << endl;
    for (auto* pub : publicaciones) {
        cout << pub->getDT() << endl;
    }

    // ==================== LIMPIEZA ====================
    // Eliminar objetos dinámicos restantes
    for (auto* pub : publicaciones) {
        delete pub;
    }
    delete inv1;
    delete inv2;

    return 0;
}