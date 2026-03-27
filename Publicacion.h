#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTRefer.h"

// Forward declaration para evitar dependencia circular
class Investigador;

class Publicacion {
private:
    std::string DOI;
    std::string titulo;
    DTFecha fecha;
    std::set<Investigador*> autores; // pseudoatributo de la relación

public:
    Publicacion(const std::string& DOI, const std::string& titulo, const DTFecha& fecha);
    virtual ~Publicacion(); // destructor virtual por herencia

    // Getters
    std::string getDOI() const;
    std::string getTitulo() const;
    DTFecha getFecha() const;
    const std::set<Investigador*>& getAutores() const; // devuelve referencia constante para evitar copias

    // Métodos para manejar la relación bidireccional
    void agregarAutor(Investigador* autor);
    void quitarAutor(Investigador* autor);

    // Operaciones
    DTRefer getDT() const; // crea DTRefer con los datos de la publicación
    virtual bool contienePalabra(const std::string& palabra) const = 0; // abstracto
};

#endif