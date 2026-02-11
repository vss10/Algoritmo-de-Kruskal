#include <stdio.h>
#include <stdlib.h>
#include "Aresta.h"
#include "Subconjunto.h"

#ifndef QU_H
#define QU_H

typedef struct qu QU;
/**
 * @brief Inicializa o struct "qu" com o tamanho "size" de elementos.
 * 
 * @param size Número de elementos que o conjunto vai apresentar.
 * @return QU* Struct inicializado.
 */
QU * UF_init(int size);
/**
 * @brief Encontra o pai do elemento "i".
 * 
 * @param Q Struct QU.
 * @param i Elemento que se deseja encontrar o pai.
 * @return int Índice do pai de "i".
 */
int UF_find(QU *Q, int i);
/**
 * @brief Realiza a união de "p" com "q".
 * 
 * @param Q Struct QU.
 * @param p Índice do primeiro elemento.
 * @param q Índice do segundo elemento.
 * @return int Retorna 0 caso eles já pertençam ao mesmo conjunto e 1 caso contrário.
 */
int UF_union(QU *Q, int p, int q);
/**
 * @brief Função responsável por separar os pontos em subconjuntos disjuntos, ordenar os elementos deles lexicograficamente individualmente e em seguida ordenar lexicograficamente conjuntamente de acordo com o primeiro elemento de cada subconjunto. Por fim imprime-se os subconjuntos.
 * 
 * @param q Struct QU.
 * @param p Pontos que serão distribuidos nos subconjuntos.
 * @param k Número de subconjuntos disjuntos.
 * @param N Número de pontos.
 * @param f Arquivo onde os subconjuntos deverão ser impressos.
 */
void ImprimeSubconjuntos(QU *q, Ponto **p, int k, int N, FILE *f);
/**
 * @brief Libera o struct "Q" e seus membros internos.
 * 
 * @param Q Struct a ser liberado.
 */
void LiberaQU(QU *Q);

#endif