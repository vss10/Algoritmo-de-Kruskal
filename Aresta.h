#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

#ifndef ARESTA_H
#define ARESTA_H

typedef struct aresta Aresta;

/**
 * @brief Retorna o índice de um dos pontos da aresta.
 * 
 * @param a Aresta
 * @return int Corresponde ao índice de um dos pontos da aresta.
 */
int IndiceP1(Aresta *a);
/**
 * @brief Retorna o índice de um dos pontos da aresta.
 * 
 * @param a Aresta
 * @return int Corresponde ao índice de um dos pontos da aresta.
 */
int IndiceP2(Aresta *a);
/**
 * @brief Inicializa uma aresta com os pontos de índice "i1" e "i2" pertencentes a "p" e calcula seu comprimento.
 * 
 * @param p Ponteiro de ponteiro de pontos que contém todos os pontos lidos.
 * @param i1 Índice do primeiro ponto da aresta.
 * @param i2 Índice do segundo ponto da aresta.
 * @return Aresta* Retorna a aresta preenchida.
 */
Aresta *InicializaAresta(Ponto **p, int i1, int i2);
/**
 * @brief Ordena em ordem crescente o ponteiro de ponteiro "a" de arestas. 
 * 
 * @param a Ponteiro de ponteiro contendo todas as possíveis arestas.
 * @param num Número de arestas.
 */
void OrdenaArestas(Aresta **a, int num);
/**
 * @brief Libera o ponteiro do struct aresta.
 * 
 * @param a Aresta a ser liberada.
 */
void LiberaAresta(Aresta *a);

#endif