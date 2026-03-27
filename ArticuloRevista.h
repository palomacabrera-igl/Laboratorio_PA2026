#ifndef ARTICULOREVISTA_H
#define ARTICULOREVISTA_H

#include "Publicacion.h"
#include <string>

class ArticuloRevista : public Publicacion {
private:
    std::string revista;
    std::string extracto;
public:
    ArticuloRevista(const std::string& DOI, const std::string& titulo, const DTFecha& fecha,
                    const std::string& revista, const std::string& extracto);
    virtual ~ArticuloRevista();

    std::string getRevista() const;
    std::string getExtracto() const;

    bool contienePalabra(const std::string& palabra) const override;
};

#endif