#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef PONTO
#define PONTO

typedef struct ponto Ponto;

/**
 * @brief Inicializa um ponto com m dimensões contidas no ponteiro "coordenadas" e com nome "nome".
 * 
 * @param coordenadas Ponteiro de float que contém as coordenadas do ponto em cada dimensão.
 * @param m Número de dimensões.
 * @param nome Nome do ponto.
 * @return Ponto* Retorna o ponto preenchido.
 */
Ponto *CriaPonto(float *coordenadas, int m, char *nome);
/**
 * @brief Calcula a distância entre os pontos p1 e p2.
 * 
 * @param p1 Um dos pontos.
 * @param p2 O outro ponto.
 * @return float Distância entre os pontos passados.
 */
float Distancia(Ponto *p1, Ponto *p2);
/**
 * @brief Retorna o nome do ponto "p".
 * 
 * @param p Ponto que se deseja o nome.
 * @return char* Nome do ponto.
 */
char *RetornaNome(Ponto *p);
/**
 * @brief Ordena os pontos contidos em "pontos" em ordem lexicográfica.
 * 
 * @param pontos Pontos que se deseja ordenar lexicograficamente.
 * @param numPontos Número de pontos a serem ordenados.
 */
void OrdenaPontos(Ponto **pontos, int numPontos);
/**
 * @brief Imprime no arquivo "f" o ponto(nome) "p".
 * 
 * @param f Arquivo onde deve ser impresso.
 * @param p Ponto a ser impresso.
 */
void ImprimePonto(FILE *f, Ponto *p);
/**
 * @brief Libera o ponto "p".
 * 
 * @param p Ponto a ser liberado da memória.
 */
void LiberaPonto(Ponto *p);

#endif