#include "WeightedQU.h"
#include "Aresta.h"
#include <stdio.h>
#include <stdlib.h> 

void Algoritmo(QU *Q, int N, Aresta **a, int k){
  int numArestasLigadas = 0;

  for(int i=0; i < ((N*(N-1))/2); i++){
    if(UF_union(Q, IndiceP1(a[i]), IndiceP2(a[i]))){
      numArestasLigadas++;
    }
    if(numArestasLigadas == N-k){
      break;
    }
  }
}