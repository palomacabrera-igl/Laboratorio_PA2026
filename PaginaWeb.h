#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include "Publicacion.h"
#include <string>

class PaginaWeb : public Publicacion {
private:
    std::string url;
    std::string contenidoExtraido;
public:
    PaginaWeb(const std::string& DOI, const std::string& titulo, const DTFecha& fecha,
              const std::string& url, const std::string& contenidoExtraido);
    virtual ~PaginaWeb();

    std::string getUrl() const;
    std::string getContenidoExtraido() const;

    bool contienePalabra(const std::string& palabra) const override;
};

#endif