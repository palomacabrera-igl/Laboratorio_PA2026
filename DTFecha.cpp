#include "DTFecha.h"

DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

int DTFecha::getDia() const { return dia; }
int DTFecha::getMes() const { return mes; }
int DTFecha::getAnio() const { return anio; }

bool DTFecha::operator>(const DTFecha& otra) const {
    if (anio != otra.anio) return anio > otra.anio;
    if (mes != otra.mes) return mes > otra.mes;
    return dia > otra.dia;
}