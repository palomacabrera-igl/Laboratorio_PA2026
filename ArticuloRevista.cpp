#include "ArticuloRevista.h"

ArticuloRevista::ArticuloRevista(const std::string& DOI, const std::string& titulo, const DTFecha& fecha,
                                 const std::string& revista, const std::string& extracto)
    : Publicacion(DOI, titulo, fecha), revista(revista), extracto(extracto) {}

ArticuloRevista::~ArticuloRevista() {}

std::string ArticuloRevista::getRevista() const { return revista; }
std::string ArticuloRevista::getExtracto() const { return extracto; }

bool ArticuloRevista::contienePalabra(const std::string& palabra) const {
    return extracto.find(palabra) != std::string::npos;
}