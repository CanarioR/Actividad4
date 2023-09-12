#ifndef ADMINISTRADORA_H
#define ADMINISTRADORA_H

#include <iostream>
#include "neurona.h"
#include <list>

class administradora
{
private:
    struct Nodo
    {
        Neurona dato;
        Nodo* siguiente;
        Nodo(const Neurona& valor) : dato(valor), siguiente(nullptr) {}
    };
    Nodo* cabeza;
public:
    administradora();

    void agregarInicio(Neurona&);
    void agregarFinal(Neurona&);
    std::string mostrar();
};

#endif // ADMINISTRADORA_H
