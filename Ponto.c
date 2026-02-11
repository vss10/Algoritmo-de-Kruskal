#include "Ponto.h"

struct ponto{
  float *coordenadas;//Vetor que contém as coordenadas em cada uma das "m" dimensões.
  int m;//Número de dimensões.
  char *nome;//Nome do ponto.
};

Ponto *CriaPonto(float *coordenadas, int m, char *nome){
  Ponto *p = malloc(sizeof(Ponto));
  float *n = malloc(sizeof(float)*m);

  for(int i=0; i<m; i++){
    n[i] = coordenadas[i];
  }
  
  p->coordenadas = n;
  p->m = m;
  p->nome = nome;

  return p;
}

char *RetornaNome(Ponto *p){
  return p->nome;
}

float Distancia(Ponto *p1, Ponto *p2){
  float dist = 0;

  for(int i=0; i<p1->m; i++){
    dist += pow(p1->coordenadas[i]-p2->coordenadas[i], 2);
  }

  dist = sqrt(dist);

  return dist;
}

int cmp(const void *a, const void *b){
  char *p = (*(Ponto**)a)->nome;
  char *q = (*(Ponto**)b)->nome;

  return strcmp(p, q);  
}

void OrdenaPontos(Ponto **pontos, int numPontos){
  qsort(pontos, numPontos, sizeof(*pontos), cmp);
}

void ImprimePonto(FILE *f, Ponto *p){
  fprintf(f, "%s", p->nome);
}

void LiberaPonto(Ponto *p){
  free(p->coordenadas);
  free(p->nome);
  free(p);
}