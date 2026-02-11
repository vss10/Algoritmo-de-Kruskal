#include "WeightedQU.h"

struct qu{
  int N;//Número de elementos.
  int *id;//Representa o pai do elemento colocado no índice escolhido.
  int *sz;//Número de elementos da árvore com raiz no índice escolhido.
};

QU * UF_init(int size){
  QU *Q = malloc(sizeof(QU));
  
  Q->N = size;
  Q->id = malloc(sizeof(int)*Q->N);
  Q->sz = malloc(sizeof(int)*Q->N);

  for (int i = 0; i < Q->N; i++) {
    Q->id[i] = i;
    Q->sz[i] = 0;
  }

  return Q;
}

int UF_find(QU *Q, int i){
  while (i != Q->id[i]) {
    Q->id[i] = Q->id[Q->id[i]];
    i = Q->id[i];
  }
  return i;
}

int UF_union(QU *Q, int p, int q){
 
  int i = UF_find(Q,p); 
  int j = UF_find(Q,q); 

  if (i == j) 
    return 0;
  if(Q->sz[i] < Q->sz[j]){ 
    Q->id[i] = j; Q->sz[j] += Q->sz[i];
  }
  else{ 
    Q->id[j] = i; Q->sz[i] += Q->sz[j];
  }

  return 1;
}

static int compar(const void *i, const void *j){
  int p = *((int*)i), q = *((int*)j);
  
  return (p>q) - (p<q);
}

void ImprimeSubconjuntos(QU *Q, Ponto **p, int k, int N, FILE *f){
  int numGrupo=0, *idGrupos = malloc(sizeof(int)*k), aux=0, dif;
  Sub **s = malloc(sizeof(Sub*)*k);
  
  for(int i=0; i<k; i++){
    s[i] = InicializaSub(N);
    idGrupos[i] = -1;
  }

  for(int i=0; i<N; i++){
    aux = UF_find(Q, i);
    
    if(bsearch(&aux, &idGrupos[0], k, sizeof(int), compar)==NULL){
      for(int j=0; j<k;j++){
        if(idGrupos[j]<0){
          idGrupos[j] = aux;
          break;
        }
      }
      numGrupo++;
      qsort(&idGrupos[0], k, sizeof(*idGrupos), compar);
    }

    if(numGrupo == k){
      break;
    }
  }

  aux = 0;
  
  for(int i=0; i<k; i++){
    for(int j=0; j<N; j++){
      if(aux == N){
        break;
      }
      if(UF_find(Q, j) == idGrupos[i]){
        Insere(s[i], p[j]);
        aux++;
      }
    }
    if(aux == N){
      break;
    }
  }

  for(int i=0; i<k; i++){
    OrdenaSubconjunto(s[i]);
  }
  OrdenaSubconjuntos(s, k);
  
  Imprime(f, s, k);

  for(int i=0; i<k; i++){
    LiberaSub(s[i]);
  }
  free(idGrupos);
  free(s);
}

void LiberaQU(QU *Q){
  free(Q->id);
  free(Q->sz);
  free(Q);
}