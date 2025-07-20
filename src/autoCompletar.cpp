#include "../include/autoCompletar.h"

AutoCompletar::AutoCompletar()
{
}

void AutoCompletar::percorrerArgumentos(int argc, char *argv[], ListaOrdenada<Termo> &lista)
{

    if (argc != 3)
    {
        std::cerr << "Quantidade de elementos informada errada.";
        std::exit(1); // Para o programa
    }
    std::string caminhoData = argv[1];
    qtdTermosProcurados = std::atoi(argv[2]);

    std::ifstream arq(caminhoData);

    if (!arq.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoData << "\n";
        std::exit(1); // Para o programa
    }

    std::string linha;

    while (std::getline(arq, linha))
    {
        std::istringstream ss(linha);
        long peso;
        std::string nome;

        ss >> peso;
        std::getline(ss >> std::ws, nome); // pega o nome com espaços

        Termo termo(nome, peso);
        lista.inserir(termo);
    }
    arq.close();
}

int AutoCompletar::buscaBinaria(ListaOrdenada<Termo> &lista, Termo &termo, int inicio, int maiorPosicao)
{
    if (inicio > maiorPosicao)
    { // Deu erro saia
        return -1;
    }

    int meio = (inicio + maiorPosicao) / 2;
    int resultado = compararPeloPrefixo(termo, lista[meio], termo.getTamanhoTermo());

    if (resultado == 0)
    {
        // Achou uma ocorrência: tenta achar uma mais à esquerda
        int esquerda = buscaBinaria(lista, termo, inicio, meio - 1);

        if (esquerda != -1)
        {
            return esquerda; // Achou ocorrência mais à esquerda
        }
        else
        {
            return meio; // Essa é a primeira ocorrência
        }
    }
    else if (resultado == 1) // O termo que buscamos é maior que o que tá no meio
    {
        return buscaBinaria(lista, termo, meio + 1, maiorPosicao);
    }
    else
    {
        return buscaBinaria(lista, termo, inicio, meio - 1);
    }
}

void AutoCompletar::setVetorTermosPrefixo(ListaOrdenada<Termo> &lista, Termo &termo)
{
    int contadorDeOcorrencia = buscaBinaria(lista, termo, 0, lista.retornarTamanho() - 1); // Primeira ocorrencia
    if (contadorDeOcorrencia == -1)
    {
        std::cerr << "Elemento não encontrado..." << std::endl;
        return;
    }
    while ((lista[contadorDeOcorrencia].compararPeloPrefixo(termo, lista[contadorDeOcorrencia], termo.getTamanhoTermo()) == 0))
    {
        vetorTermosComPrefixo.inserir(lista[contadorDeOcorrencia]);
        contadorDeOcorrencia++;
    }

    vetorTermosComPrefixo.ordenar(Termo::compararPeloPeso); // Ordenando pelo peso
}
int AutoCompletar::getQuantidadeDeTermosProcurados()
{
    return qtdTermosProcurados;
}
void AutoCompletar::exibirVetorTermosPrefixo(int qtdTermosProcurados)
{
    int qtdExibida;
    if (qtdTermosProcurados > vetorTermosComPrefixo.retornarTamanho())
    {
        qtdExibida = vetorTermosComPrefixo.retornarTamanho();
    }
    else
    {
        qtdExibida = qtdTermosProcurados;
    }
    for (int i = 0; i < qtdExibida; i++)
    {
        std::cout << vetorTermosComPrefixo[i] << std::endl;
    }
    std::cout << std::endl;
}

void AutoCompletar::esvaziarVetorTermosPrefixo()
{
    vetorTermosComPrefixo.limpar();
}