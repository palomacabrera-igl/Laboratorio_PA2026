#include "PaginaWeb.h"

PaginaWeb::PaginaWeb(const std::string& DOI, const std::string& titulo, const DTFecha& fecha,
                     const std::string& url, const std::string& contenidoExtraido)
    : Publicacion(DOI, titulo, fecha), url(url), contenidoExtraido(contenidoExtraido) {}

PaginaWeb::~PaginaWeb() {}

std::string PaginaWeb::getUrl() const { return url; }
std::string PaginaWeb::getContenidoExtraido() const { return contenidoExtraido; }

bool PaginaWeb::contienePalabra(const std::string& palabra) const {
    return contenidoExtraido.find(palabra) != std::string::npos;
}