#include "../include/termo.h"

Termo::Termo()
{
    
}

Termo::Termo(std::string termo, long peso)
{
    this->termo = termo;
    this->peso = peso;
}

bool Termo::compararPeloPeso(const Termo &T1, const Termo &T2)
{
    return T2.peso < T1.peso; // Vai ser usada no método de ordenar por pesos da classe listaOrdenada
}

int Termo::compararPeloPrefixo(Termo T1, Termo T2, int r)
{
    // Pega o tamanho mínimo entre r e os tamanhos dos termos
    int tamanho1 = std::min((int)T1.termo.size(), r);
    int tamanho2 = std::min((int)T2.termo.size(), r);

    std::string prefixo1 = T1.termo.substr(0, tamanho1); //Pegando os prefixos que serão comparados até a posição r
    std::string prefixo2 = T2.termo.substr(0, tamanho2);

    if(prefixo1 > prefixo2){ //prefixo 1 vem depois que prefixo 2 no alfabeto
        return 1;
    }
    else if(prefixo1 == prefixo2){
        return 0;
    }
    else{
        return -1; //prefixo1 vem antes
    }
}

bool Termo::operator<(const Termo T2) const
{
    if (termo < T2.termo) //O método que ordena alfabeticamente da classe listaOrdenada vai usar
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &out, const Termo &t)
{
    out << t.termo << " - " << t.peso;
    return out;
}

int Termo::getTamanhoTermo(){
    return this->termo.size();
}

std::string Termo::getTermo() const {
    return termo;
}

void Termo::formatarRespostaComoTitulo() {
    std::istringstream iss(this->termo);
    std::string palavra, respostaFormatada;

    while (iss >> palavra) {
        palavra[0] = std::toupper(palavra[0]);
        for (size_t i = 1; i < palavra.length(); ++i) {
            palavra[i] = std::tolower(palavra[i]);
        }
        if (!respostaFormatada.empty()) {
            respostaFormatada += " ";
        }
        respostaFormatada += palavra;
    }

    this->termo = respostaFormatada;
}

