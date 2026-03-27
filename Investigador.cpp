#include "Investigador.h"
#include "Publicacion.h"
#include <iostream>

Investigador::Investigador(const std::string& ORCID, const std::string& nombre, const std::string& institucion)
    : ORCID(ORCID), nombre(nombre), institucion(institucion) {}

Investigador::~Investigador() {}

std::string Investigador::getORCID() const { return ORCID; }
std::string Investigador::getNombre() const { return nombre; }
std::string Investigador::getInstitucion() const { return institucion; }
const std::set<Publicacion*>& Investigador::getPublicaciones() const { return publicaciones; }

void Investigador::agregarPublicacion(Publicacion* pub) {
    publicaciones.insert(pub);
}

void Investigador::quitarPublicacion(Publicacion* pub) {
    publicaciones.erase(pub);
}

std::string Investigador::toString() const {
    return ORCID + "->" + nombre + "/" + institucion;
}

std::set<std::string> Investigador::listarPublicaciones(const DTFecha& desde, const std::string& palabra) const {
    std::set<std::string> resultado;
    for (auto* pub : publicaciones) {
        // Filtro por fecha (posterior a 'desde')
        if (pub->getFecha() > desde) {
            // Verifica si contiene la palabra
            if (pub->contienePalabra(palabra)) {
                resultado.insert(pub->getDOI());
            }
        }
    }
    return resultado;
}