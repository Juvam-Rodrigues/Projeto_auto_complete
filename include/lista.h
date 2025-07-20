#ifndef LISTA_H
#define LISTA_H
#include <string>
#include <iostream>
#include <vector>

template <class T>
class Lista
{
protected:
    std::vector<T> lista;

public:
    void inserir(const T &elemento);
    int retornarTamanho() const;
    T operator[](int indice);
    void imprimirLista() const;
};

template <class T>
void Lista<T>::inserir(const T &elemento)
{
    lista.push_back(elemento);
}

template <class T>
int Lista<T>::retornarTamanho() const
{
    return lista.size();
}

template <class T>
T Lista<T>::operator[](int indice)
{
    if (indice > retornarTamanho() - 1)
    { // Pega somente o intervalo válido
        std::cerr << "Índice fora de alcance.";
        std::exit(1); // Para o programa
    }
    return lista[indice];
}

template <class T>
void Lista<T>::imprimirLista() const
{
    std::cout << "Lista: [";
    for (int i = 0; i < retornarTamanho(); i++)
    {
        if (i == retornarTamanho() - 1) // Está no última posição para de colocar vírgula
        {
            std::cout << lista[i] << " - Contador: " << i << "]";
            break;
        }
        std::cout << lista[i] << " - Contador: " << i << std::endl;;
    }
}
#endif