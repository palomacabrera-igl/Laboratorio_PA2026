#include <iostream>
#include <set>
#include <string>
#include "ArticuloRevista.h"
#include "Libro.h"
#include "PaginaWeb.h"
#include "Investigador.h"

int main() {
    // 1. Crear algunas publicaciones (similares a las del laboratorio)
    ArticuloRevista* art1 = new ArticuloRevista(
        "10.1234/abc123",
        "Fundamentos de POO",
        DTFecha(15, 5, 2023),
        "Programacion Avanzada",
        "Introduccion a los principios fundamentales de la programacion orientada a objetos..."
    );

    Libro* libro1 = new Libro(
        "10.5678/mno345",
        "Guia de UML",
        DTFecha(20, 8, 2022),
        "IEEE",
        std::set<std::string>{"UML", "Diagramas", "Modelado"}
    );

    PaginaWeb* web1 = new PaginaWeb(
        "10.3456/ghi789",
        "Diagramas para Principiantes",
        DTFecha(20, 10, 2024),
        "www.umlparaprincipiantes.com",
        "En esta pagina web se presenta una guia completa sobre los diagramas UML..."
    );

    // 2. Crear investigadores
    Investigador* carla = new Investigador("0000-0003-1234-5678", "Carla Oliveri", "Universidad de la Republica");
    Investigador* alberto = new Investigador("0000-0001-8765-4321", "Alberto Santos", "Instituto Tecnico");

    // 3. Establecer relaciones bidireccionales
    // Carla es autora de art1 y web1
    carla->agregarPublicacion(art1);
    art1->agregarAutor(carla);
    carla->agregarPublicacion(web1);
    web1->agregarAutor(carla);
    // Alberto es autor de art1 y libro1
    alberto->agregarPublicacion(art1);
    art1->agregarAutor(alberto);
    alberto->agregarPublicacion(libro1);
    libro1->agregarAutor(alberto);

    // 4. Probar toString()
    std::cout << "=== toString() ===" << std::endl;
    std::cout << carla->toString() << std::endl;
    std::cout << alberto->toString() << std::endl;

    // 5. Probar listarPublicaciones para Carla
    std::cout << "\n=== Carla: publicaciones despues de 1/1/2023 con 'UML' ===" << std::endl;
    DTFecha desde(1, 1, 2023);
    std::set<std::string> resultadosCarla = carla->listarPublicaciones(desde, "UML");
    for (const auto& doi : resultadosCarla) {
        std::cout << doi << std::endl;
    }

    std::cout << "\n=== Carla: publicaciones despues de 1/1/2025 con 'UML' (ninguna) ===" << std::endl;
    DTFecha desde2(1, 1, 2025);
    resultadosCarla = carla->listarPublicaciones(desde2, "UML");
    for (const auto& doi : resultadosCarla) {
        std::cout << doi << std::endl;
    }

    // 6. Probar listarPublicaciones para Alberto
    std::cout << "\n=== Alberto: publicaciones despues de 1/1/2020 con 'UML' ===" << std::endl;
    DTFecha desde3(1, 1, 2020);
    std::set<std::string> resultadosAlberto = alberto->listarPublicaciones(desde3, "UML");
    for (const auto& doi : resultadosAlberto) {
        std::cout << doi << std::endl;
    }

    // 7. Probar que las relaciones están en ambos lados
    std::cout << "\n=== Autores de art1 ===" << std::endl;
    for (auto* autor : art1->getAutores()) {
        std::cout << autor->getNombre() << std::endl;
    }

    // 8. Limpieza (no olvidar eliminar objetos)
    delete art1;
    delete libro1;
    delete web1;
    delete carla;
    delete alberto;

    return 0;
}