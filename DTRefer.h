#ifndef DTREFER_H
#define DTREFER_H

#include <string>
#include <set>
#include "DTFecha.h"

class DTRefer {
private:
    std::string DOI;
    std::string titulo;
    DTFecha fecha;
    std::set<std::string> autores;
public:
    DTRefer(const std::string& DOI, const std::string& titulo, const DTFecha& fecha, const std::set<std::string>& autores);
    std::string getDOI() const;
    std::string getTitulo() const;
    DTFecha getFecha() const;
    std::set<std::string> getAutores() const;
    friend std::ostream& operator<<(std::ostream& os, const DTRefer& ref);
};

#endif