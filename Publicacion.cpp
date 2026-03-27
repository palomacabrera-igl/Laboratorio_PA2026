#include "Publicacion.h"
#include "Investigador.h" // ahora sí podemos usar Investigador completamente

Publicacion::Publicacion(const std::string& DOI, const std::string& titulo, const DTFecha& fecha)
    : DOI(DOI), titulo(titulo), fecha(fecha) {}

Publicacion::~Publicacion() {}

std::string Publicacion::getDOI() const { return DOI; }
std::string Publicacion::getTitulo() const { return titulo; }
DTFecha Publicacion::getFecha() const { return fecha; }
const std::set<Investigador*>& Publicacion::getAutores() const { return autores; }

void Publicacion::agregarAutor(Investigador* autor) {
    autores.insert(autor);
}

void Publicacion::quitarAutor(Investigador* autor) {
    autores.erase(autor);
}

DTRefer Publicacion::getDT() const {
    std::set<std::string> nombresAutores;
    for (const auto& autor : autores) {
        nombresAutores.insert(autor->getNombre());
    }
    return DTRefer(DOI, titulo, fecha, nombresAutores);
}