#include "Subconjunto.h"

struct sub{
  Ponto** pontos;//Conjunto de pontos que pertencem ao subconjunto.
  int numPontos;//Número de pontos que pertencem ao subconjuto.
};

Sub * InicializaSub(int MAX){
  Sub *s = malloc(sizeof(Sub));

  s->pontos = malloc(sizeof(Ponto*)*MAX);
  s->numPontos = 0;

  return s;
}

void Insere(Sub *s, Ponto *p){
  s->pontos[s->numPontos] = p;
  s->numPontos++;
}

void OrdenaSubconjunto(Sub *s){
  OrdenaPontos(s->pontos, s->numPontos);
}

int cmp1(const void *a, const void *b){
  char *p = RetornaNome((*(Sub**)a)->pontos[0]);
  char *q = RetornaNome((*(Sub**)b)->pontos[0]);

  return strcmp(p, q);
}

void OrdenaSubconjuntos(Sub **s, int k){
  qsort(s, k, sizeof(s), cmp1);
}

void Imprime(FILE *f, Sub **s, int k){
  for(int i=0; i<k; i++){
    for(int j=0; j<s[i]->numPontos; j++){
      ImprimePonto(f, s[i]->pontos[j]);
      if(j!=s[i]->numPontos-1){
        fprintf(f,",");
      }
    }
    fprintf(f, "\n");
  }
}

void LiberaSub(Sub *s){
  free(s->pontos);
  free(s);
}