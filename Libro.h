#ifndef LIBRO_H
#define LIBRO_H

#include "Publicacion.h"
#include <string>
#include <set>

class Libro : public Publicacion {
private:
    std::string editorial;
    std::set<std::string> palabrasClave;
public:
    Libro(const std::string& DOI, const std::string& titulo, const DTFecha& fecha,
          const std::string& editorial, const std::set<std::string>& palabrasClave);
    virtual ~Libro();

    std::string getEditorial() const;
    const std::set<std::string>& getPalabrasClave() const;

    bool contienePalabra(const std::string& palabra) const override;
};

#endif