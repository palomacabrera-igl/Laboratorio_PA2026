#include <iostream>
#include <set>
#include <string>
#include "DTRefer.h"
#include "DTFecha.h"

int main() {
    // Crear un set de autores (nombres)
    std::set<std::string> autores;
    autores.insert("Carla Oliveri");
    autores.insert("Alberto Santos");

    // Crear una fecha
    DTFecha fecha(15, 5, 2023);

    // Crear un objeto DTRefer
    DTRefer ref("10.1234/abc123", "Fundamentos de POO", fecha, autores);

    // Verificar getters
    std::cout << "=== Getters ===" << std::endl;
    std::cout << "DOI: " << ref.getDOI() << std::endl;
    std::cout << "Titulo: " << ref.getTitulo() << std::endl;
    std::cout << "Fecha: " << ref.getFecha().getDia() << "/"
              << ref.getFecha().getMes() << "/"
              << ref.getFecha().getAnio() << std::endl;

    std::cout << "Autores: ";
    for (const auto& autor : ref.getAutores()) {
        std::cout << autor << " ";
    }
    std::cout << std::endl;

    // Probar operador <<
    std::cout << "\n=== Operador << ===" << std::endl;
    std::cout << ref << std::endl;

    // Probar con otro DTRefer con un solo autor
    std::set<std::string> unAutor;
    unAutor.insert("Carla Oliveri");
    DTFecha fecha2(10, 2, 2024);
    DTRefer ref2("10.4567/jkl012", "Utilidad de diagramas UML", fecha2, unAutor);
    std::cout << "\nCon un solo autor:" << std::endl;
    std::cout << ref2 << std::endl;

    return 0;
}