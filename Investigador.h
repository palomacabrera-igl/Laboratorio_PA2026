#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H

#include <string>
#include <set>
#include "DTFecha.h"

// Forward declaration
class Publicacion;

class Investigador {
private:
    std::string ORCID;
    std::string nombre;
    std::string institucion;
    std::set<Publicacion*> publicaciones;

public:
    Investigador(const std::string& ORCID, const std::string& nombre, const std::string& institucion);
    ~Investigador();

    // Getters
    std::string getORCID() const;
    std::string getNombre() const;
    std::string getInstitucion() const;
    const std::set<Publicacion*>& getPublicaciones() const;

    // Manejo de relación
    void agregarPublicacion(Publicacion* pub);
    void quitarPublicacion(Publicacion* pub);

    // Operaciones pedidas
    std::string toString() const;
    std::set<std::string> listarPublicaciones(const DTFecha& desde, const std::string& palabra) const;
};

#endif