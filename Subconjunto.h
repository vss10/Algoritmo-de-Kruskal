#include "Ponto.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef SUB_H
#define SUB_H

typedef struct sub Sub;

/**
 * @brief Inicializa um subconjunto com no máximo "MAX" elementos.
 * 
 * @param MAX Limite de elementos do subconjunto.
 * @return Sub* Subconjuntos inicializado.
 */
Sub * InicializaSub(int MAX);
/**
 * @brief Insere o ponto "p" no subconjunto "s".
 * 
 * @param s Subconjunto que deseja-se inserir o ponto.
 * @param p Ponto a ser inserido.
 */
void Insere(Sub *s, Ponto *p);
/**
 * @brief Ordena o subconjunto "s" lexicograficamente.
 * 
 * @param s Subconjunto a ser ordenado.
 */
void OrdenaSubconjunto(Sub *s);
/**
 * @brief Ordena um conjunto de subconjuntos lexicograficamente de acordo com o primeiro elemento de cada subconjunto.
 * 
 * @param s Conjunto de subconjuntos a serem ordenados.
 * @param k Número de subconjuntos.
 */
void OrdenaSubconjuntos(Sub **s, int k);
/**
 * @brief Imprime no arquivo "file" os "k" subconjuntos presentes em "s".
 * 
 * @param f Arquivo onde será realizado a impressão.
 * @param s Conjunto de subconjuntos.
 * @param k Número de subconjuntos.
 */
void Imprime(FILE *f,Sub **s, int k);
/**
 * @brief Libera o subconjunto "s".
 * 
 * @param s Subconjunto a ser liberado.
 */
void LiberaSub(Sub *s);

#endif