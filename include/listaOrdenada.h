#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <string>
#include <iostream>
#include <algorithm>
#include "lista.h"
#include "termo.h"

template <class T>
class ListaOrdenada : public Lista<T>
{
public:
    void ordenar()
    {
        std::sort(this->lista.begin(), this->lista.end());
    }

    void ordenar(bool (*comparador)(const T &, const T &))
    {
        std::sort(this->lista.begin(), this->lista.end(), comparador);
    }

    void reverter()
    {
        std::reverse(this->lista.begin(), this->lista.end());
    }

    void limpar()
    {
        this->lista.clear();
    }
};

#endif