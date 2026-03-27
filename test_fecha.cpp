#include <iostream>
#include "DTFecha.h"

int main() {
    DTFecha f1(15, 5, 2023);
    DTFecha f2(10, 2, 2024);
    DTFecha f3(15, 5, 2023);

    std::cout << "f1: " << f1.getDia() << "/" << f1.getMes() << "/" << f1.getAnio() << std::endl;
    std::cout << "f2: " << f2.getDia() << "/" << f2.getMes() << "/" << f2.getAnio() << std::endl;
    std::cout << "f3: " << f3.getDia() << "/" << f3.getMes() << "/" << f3.getAnio() << std::endl;

    if (f2 > f1)
        std::cout << "f2 es posterior a f1" << std::endl;
    else
        std::cout << "f2 NO es posterior a f1" << std::endl;

    if (f1 > f3)
        std::cout << "f1 es posterior a f3" << std::endl;
    else
        std::cout << "f1 NO es posterior a f3 (deberian ser iguales)" << std::endl;

    return 0;
}