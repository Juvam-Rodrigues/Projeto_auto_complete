#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include <string>
#include <iostream>
#include "listaOrdenada.h"
#include "termo.h"
#include <fstream>
#include <sstream>
#include <cstdlib> // std::atoi

class AutoCompletar : public Termo
{
private:
    ListaOrdenada<Termo> vetorTermosComPrefixo;
    int qtdTermosProcurados;

public:
    AutoCompletar();
    void percorrerArgumentos(int argc, char *argv[], ListaOrdenada<Termo> &lista);
    int buscaBinaria(ListaOrdenada<Termo> &lista, Termo &termo, int inicio, int maiorPosicao);
    void setVetorTermosPrefixo(ListaOrdenada<Termo> &lista, Termo &termo);
    int getQuantidadeDeTermosProcurados();
    void exibirVetorTermosPrefixo(int qtdTermosProcurados);
    void esvaziarVetorTermosPrefixo();
};

#endif