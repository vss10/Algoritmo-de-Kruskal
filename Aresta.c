#include "Aresta.h"

struct aresta{
  int i1;//Índice do primeiro ponto.
  int i2;//Índice do segundo ponto.
  float distancia;//Distância entre os pontos. 
};

int IndiceP1(Aresta *a){
  return a->i1;
}

int IndiceP2(Aresta *a){
  return a->i2;
}

Aresta *InicializaAresta(Ponto **p, int i1, int i2){
  Aresta *a = malloc(sizeof(Aresta));

  a->i1 = i1;
  a->i2 = i2;
  a->distancia = Distancia(p[i1], p[i2]);

  return a;
}

int comp(const void *a, const void *b){
  float a1 = (*(Aresta**)a)->distancia;
  float a2 = (*(Aresta**)b)->distancia;

  return (a1>a2) - (a2>a1);
}

void OrdenaArestas(Aresta **a, int num){
  qsort(a, num, sizeof(*a), comp);
}

void LiberaAresta(Aresta *a){
  free(a);
}