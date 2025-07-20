#include <stdio.h>
#include "../include/lista.h"
#include "../include/termo.h"
#include "../include/autoCompletar.h"
#include "../include/listaOrdenada.h"

int main(int argc, char *argv[])
{
    ListaOrdenada<Termo> lista; // Lista ordenada
    AutoCompletar autoCompletar;
    autoCompletar.percorrerArgumentos(argc, argv, lista);
    lista.ordenar();

    std::string resposta;
    std::cout << "Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):" << std::endl;
    std::getline(std::cin, resposta); //Pega a linha toda até o espaço
    while (resposta != "sair")
    {
        Termo tBuscado(resposta, 0);
        tBuscado.formatarRespostaComoTitulo();
        autoCompletar.setVetorTermosPrefixo(lista, tBuscado);
        autoCompletar.exibirVetorTermosPrefixo(autoCompletar.getQuantidadeDeTermosProcurados());
        autoCompletar.esvaziarVetorTermosPrefixo();
        std::cout << "Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):" << std::endl;
        std::getline(std::cin, resposta);
    }

    std::cout << "Encerrando o programa...";
}