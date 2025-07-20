<h1>Projeto auto complete 💬</h1>

<h2>Descrição 🤔</h2>
Este projeto consiste em um sistema de autocompletar em C++ que lê uma lista de termos com seus respectivos pesos (prioridade), ordenando-os e sugerindo palavras com base no prefixo digitado pelo usuário. Ele implementa uma ferramenta que:

<ul>
    <li>Lê uma lista de termos e seus pesos de um arquivo;</li>
    <li>Ordena os termos alfabeticamente e/ou pelo peso;</li>
    <li>Permite ao usuário digitar um prefixo e retorna sugestões de autocompletar; e</li>
    <li>Exibe uma lista dos termos que começam com o prefixo digitado, ordenados pelo peso.</li>
</ul>

<h2>Estruturas e conceitos utilizados 🧑‍💻</h2>

<ul>
    <li><strong>Biblioteca STL:</strong> uso de vetores para listas;</li>
    <li><strong>Templates:</strong> generalização de classes de listas e métodos;</li>
    <li><strong>Herança:</strong> relacionamento entre as classes.</li>
</ul>

<h2>📂 Estrutura de Pastas</h2>
<ul>
    <li>📂 Projeto_auto_complete
        <ul>
            <li>📂 datasets</li>
            <li>📂 include
                <ul>
                    <li>📄 autoCompletar.h</li>
                    <li>📄 lista.h</li>
                    <li>📄 listaOrdenada.h</li>
                    <li>📄 termo.h</li>
                </ul>
            </li>
            <li>📂 src
                <ul>
                    <li>📄 autoCompletar.cpp</li>
                    <li>📄 main.cpp</li>
                    <li>📄 termo.cpp</li>
                </ul>
            </li>
            <li>📄 LICENSE</li>
            <li>📄 Makefile</li>
            <li>📄 README.md</li>
        </ul>
    </li>
</ul>

<h2>🚀 Como usar</h2>
Para executar o programa, utilize o seguinte comando no terminal (cmd/powershell):
Ex:  
<pre><code>.\autocomplete.exe .\datasets\actors_small.txt 10</code></pre>
- O **primeiro argumento** é o caminho para o arquivo de termos (dataset).  
- O **segundo argumento** é a quantidade de sugestões a serem exibidas para cada prefixo digitado.  

Exemplo:  
<pre><code>.\autocomplete.exe .\datasets\imdb.txt 5</code></pre>
Esse comando irá carregar o arquivo `imdb.txt` e exibir até **5 sugestões** para cada prefixo pesquisado.

<h2>Colaboradores: 🤝</h2>
Este projeto foi desenvolvido por:
<ul>
    <li><a href="https://github.com/justofernandes">Justo Fernandes de Oliveira Neto</a></li>
    <li><a href="https://github.com/Juvam-Rodrigues">Juvam Rodrigues do Nascimento Neto</a></li>
    <li><a href="https://github.com/KauaRodrigues03">Kaua das Chagas Rodrigues</a></li>
</ul>
