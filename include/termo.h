#ifndef TERMO_H
#define TERMO_H
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>


class Termo {

    private:
        std::string termo;
        long peso;

        public:
        // construtor padrão
        Termo();

        // construtor parametrizado pelo termo e pelo peso
        Termo(std::string termo, long peso);

        int getTamanhoTermo();

        std::string getTermo() const;

        // compara o peso de dois objetos Termo
        // se o peso de T1 for menor que o de T2, retorna true;
        // caso contrário, retorna false;
        static bool compararPeloPeso(const Termo &T1, const Termo &T2);

        // compara os dois termos por ordem alfabética, usando somente os r primeiros caracteres
        // se a ordem de T1 e T2 estiver de forma decrescente em relação ao prefixo com r caracteres, retorna 1;
        // se T1 e T2 tiverem o mesmo prefixo com r caracteres, retorna 0;
        // caso contrário, retorna -1;
        static int compararPeloPrefixo(Termo T1, Termo T2, int r);

        // sobrecarrega o operador "<" para a classe Termo
        // T1 < T2 se o termo de T1 é menor que o de T2 (comparação de strings)
        bool operator<(const Termo T2) const;

        // sobrecarrega o operador "<<" para a classe Termo. Note que é um método friend
        friend std::ostream& operator<<(std::ostream &out, const Termo& t);

        //tratar entrada para transformar a primeira letra em Maiúscula
        void formatarRespostaComoTitulo();

};


#endif