#include "DTRefer.h"
#include <iostream>

DTRefer::DTRefer(const std::string& DOI, const std::string& titulo, const DTFecha& fecha, const std::set<std::string>& autores)
    : DOI(DOI), titulo(titulo), fecha(fecha), autores(autores) {}

std::string DTRefer::getDOI() const { return DOI; }
std::string DTRefer::getTitulo() const { return titulo; }
DTFecha DTRefer::getFecha() const { return fecha; }
std::set<std::string> DTRefer::getAutores() const { return autores; }

std::ostream& operator<<(std::ostream& os, const DTRefer& ref) {
    os << ref.DOI << "->" << ref.titulo << "("
       << ref.fecha.getDia() << "/" << ref.fecha.getMes() << "/" << ref.fecha.getAnio() << ")/";
    bool primero = true;
    for (const auto& autor : ref.autores) {
        if (!primero) os << ", ";
        os << autor;
        primero = false;
    }
    return os;
}