#include <iostream>
#include <set>
#include <string>
#include "ArticuloRevista.h"
#include "Libro.h"
#include "PaginaWeb.h"

int main() {
    // 1. ArticuloRevista
    ArticuloRevista* art = new ArticuloRevista(
        "10.1234/abc123",
        "Fundamentos de POO",
        DTFecha(15, 5, 2023),
        "Programacion Avanzada",
        "Introduccion a los principios fundamentales de la programacion orientada a objetos, explicando sus conceptos clave como clases, objetos, herencia y polimorfismo."
    );

    // 2. Libro
    std::set<std::string> palabras;
    palabras.insert("UML");
    palabras.insert("Diagramas");
    palabras.insert("Modelado");
    Libro* libro = new Libro(
        "10.5678/mno345",
        "Guia de UML",
        DTFecha(20, 8, 2022),
        "IEEE",
        palabras
    );

    // 3. PaginaWeb
    PaginaWeb* web = new PaginaWeb(
        "10.3456/ghi789",
        "Diagramas para Principiantes",
        DTFecha(20, 10, 2024),
        "www.umlparaprincipiantes.com",
        "En esta pagina web se presenta una guia completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades."
    );

    // Arreglo de punteros Publicacion* para probar polimorfismo
    Publicacion* pubs[] = { art, libro, web };

    // Pruebas de contienePalabra
    std::cout << "=== Pruebas de contienePalabra ===" << std::endl;
    std::cout << "ArticuloRevista: 'POO' -> " << (art->contienePalabra("POO") ? "true" : "false") << std::endl;
    std::cout << "ArticuloRevista: 'python' -> " << (art->contienePalabra("python") ? "true" : "false") << std::endl;
    std::cout << "Libro: 'UML' -> " << (libro->contienePalabra("UML") ? "true" : "false") << std::endl;
    std::cout << "Libro: 'Clases' -> " << (libro->contienePalabra("Clases") ? "true" : "false") << std::endl;
    std::cout << "PaginaWeb: 'UML' -> " << (web->contienePalabra("UML") ? "true" : "false") << std::endl;
    std::cout << "PaginaWeb: 'python' -> " << (web->contienePalabra("python") ? "true" : "false") << std::endl;

    // Prueba de polimorfismo: llamar al mismo método desde punteros Publicacion*
    std::cout << "\n=== Polimorfismo (desde Publicacion*) ===" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::string tipo;
        if (dynamic_cast<ArticuloRevista*>(pubs[i])) tipo = "ArticuloRevista";
        else if (dynamic_cast<Libro*>(pubs[i])) tipo = "Libro";
        else tipo = "PaginaWeb";

        std::cout << tipo << " contiene 'UML': " << (pubs[i]->contienePalabra("UML") ? "true" : "false") << std::endl;
    }

    // Limpieza
    delete art;
    delete libro;
    delete web;

    return 0;
}