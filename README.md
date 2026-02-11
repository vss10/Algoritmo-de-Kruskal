Trabalho Prático 1 - Técnicas de Busca e Ordenação
**ALUNOS:** Victor Soares, Eduardo Perim e André Nemer
**DISCIPLINA:** Técnicas de Busca e Ordenação- 2023/1

**1. Introdução:**
Neste documento, será descrito o processo de criação de um algoritmo de
agrupamento, utilizando conceitos como Kruskal e Minimum Spanning Tree. Haverá
informações acerca das estruturas de dados utilizadas, das principais funções implementadas
e de algumas decisões do processo criativo. Além disso, serão apresentados os resultados
referentes à análise de complexidade e tempo de execução do código em questão, estando
explicitados em tabelas.

**2. Metodologia:**
No algoritmo produzido, foram utilizadas quatro estruturas de dados distintas, sendo
elas os “structs” Ponto, Aresta, Subconjunto e QU.
O “struct” Ponto tem como função armazenar as informações retiradas do arquivo de
entrada, como o nome de cada ponto e suas respectivas coordenadas, e é utilizado para
calcular as distâncias entre esses pontos armazenados.
É composto por um vetor de float “coordenadas” que é utilizado para salvar as
coordenadas de um determinado ponto, um número inteiro “m” que representa a quantidade
de dimensões/coordenadas do ponto e uma string “nome” que é o nome desse ponto.
Essa estrutura foi utilizada na “main” como um vetor de pontos “pontos” com
tamanho inicial capaz de armazenar 300 pontos distintos, sendo possível aumentar essa
quantidade com o uso de “realloc” caso necessário.
O “struct” Aresta tem como função armazenar as distâncias entre pontos e quais são
esses pontos, e é utilizado para gerar a Minimum Spanning Tree.
É composto por dois int “i1” e “i2”, cada um representando o índice de um ponto, e
um float “distancia” que é utilizado para salvar a distância entre esses pontos.
Essa estrutura foi utilizada na “main” como um vetor de arestas “Y” com um tamanho
determinado por ((n° de pontos - 1) * n° de pontos)/2, que armazena todas as combinações
dois a dois entre os pontos disponibilizados.O “struct” Subconjunto tem como função armazenar os pontos de cada conjunto da
árvore gerada pelo algoritmo, assim como a quantidade de pontos presente nesse conjunto.
Será utilizado para ordenar e imprimir as informações de saída.
É composto por um vetor de pontos “pontos” com os pontos pertencentes ao
subconjunto , e um int “numPontos” com a quantidade de pontos presente no subconjunto.
Essa estrutura foi utilizada na “main” por meio da função “ImprimeSubconjuntos”
para organizar os pontos nos subconjuntos e imprimi-los, tendo tamanho “k” , visto que foi
definido por linha de comando que seriam “k” subconjuntos.
O “struct” QU é equivalente aos componentes do Weighted Quick Union, que foi o
algoritmo escolhido com base em sua eficiência, tendo como função realizar operações de
busca e conexão de componentes de uma estrutura.
É composto por um inteiro “N”, um vetor de inteiros “id” e um vetor de inteiros “sz”,
que representam o número total de pontos a serem analisados, os índices de ponto “pai” de
cada um dos N pontos e o número de pontos que possuem o mesmo índice “pai”.
É utilizado na main como um ponteiro “Q” , que foi inicializado com o número total
de pontos disponibilizados na entrada, e utilizado em operações de “union” e “find” para
agrupar os pontos.
No que se refere às funções utilizadas no programa, as seguintes se destacam quanto à
sua importância:

- float Distancia(Ponto *p1, Ponto *p2);
- void OrdenaArestas(Aresta **a, int num);
- extern void Algoritmo(QU *Q, int N, Aresta **a, int k);
- void ImprimeSubconjuntos(QU *Q, Ponto **p, int k, int N, FILE *f);

A função “Distancia” recebe dois ponteiros de struct Ponto e utiliza o vetor de
coordenadas de cada Ponto para calcular a distância entre eles, segundo a fórmula da
distância euclidiana. Tem como retorno um float, sendo ele a distancia entre dois pontos.

A função “OrdenaArestas” recebe um vetor de struct Aresta e um int “num”, sendo
eles as arestas calculadas entre todos os pontos e a quantidade de arestas que foram
calculadas, respectivamente. Por meio da função “qsort”, esse vetor de arestas é ordenado de
forma crescente.

A função “Algoritmo” recebe um ponteiro de QU “Q”, um int “N”, um vetor de struct
Aresta e um int “k”, sendo a estrutura de quick-union contendo os índices dos pontos, a
quantidade de pontos existentes, um vetor de arestas ordenado e o número de grupos que
serão formados pelo algoritmo. A função “UF_init” inicializa o vetor de pontos e seu
respectivos “pais” com tamanho “N” e por meio da função “UF_union”, é verificado se dois
pontos pertencem ao mesmo subconjunto, caso não pertençam, são adicionados a um mesmo
subconjunto e a função retorna 1. Vale ressaltar que caso já pertençam ao mesmo subconjunto
a função retorna 0. Quando a "UF_union" retorna 1, a variável "numArestasLigadas" é
incrementada até que seja (N-k), pois essa é a mínima quantidade de ligações necessárias
para formar “k” conjuntos.

A função “ImprimeSubconjuntos” recebe um ponteiro de QU “Q”, um vetor de
struct Ponto , um int “k”,um int “N” e um arquivo “f”, sendo a estrutura de quick-union
contendo os índices dos pontos, um vetor com todos os pontos, a quantidade de grupos que
serão impressos, a quantidade de pontos existentes e um arquivo de saída no formato “.txt”. É
criada uma variável “s" do tipo subconjunto com tamanho “k” é um vetor de inteiros
“idGrupos” de tamanho “k” que é inicializado com o valor -1 em todas as posições do vetor.
É feita uma verificação utilizando os índices “pais” de cada ponto com a função “UF_find” e
a função de busca “bsearch”, onde cada índice “pai” é adicionado a “idGrupos” caso a busca
binária retorne “NULL” e o vetor é novamente ordenado com auxílio da “qsort”. Em
sequência, os pontos são inseridos nos “k” subconjuntos de acordo com seus respectivos
índices “pais”. Os “k” subconjuntos são ordenados de forma alfabética de acordo com os
nomes de seus pontos e eles são impressos no arquivo de saída no formato solicitado por
meio da função “Imprime”. A função é finalizada liberando toda a memória que havia sido
alocada.
