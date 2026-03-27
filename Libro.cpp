#include "Libro.h"

Libro::Libro(const std::string& DOI, const std::string& titulo, const DTFecha& fecha,
             const std::string& editorial, const std::set<std::string>& palabrasClave)
    : Publicacion(DOI, titulo, fecha), editorial(editorial), palabrasClave(palabrasClave) {}

Libro::~Libro() {}

std::string Libro::getEditorial() const { return editorial; }
const std::set<std::string>& Libro::getPalabrasClave() const { return palabrasClave; }

bool Libro::contienePalabra(const std::string& palabra) const {
    return palabrasClave.find(palabra) != palabrasClave.end();
}