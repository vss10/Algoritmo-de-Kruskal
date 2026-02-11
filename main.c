#include "Ponto.h"
#include "WeightedQU.h"
#include "Aresta.h"

#define MAX 300

extern void Algoritmo(QU *Q, int N, Aresta **a, int k);

int main(int argc, char *argv[]){

  FILE *file;
  file = fopen(argv[1],"r");
  int m=0, i=0, pos=0, k = atoi(argv[2]);
  char* linha = NULL, *aux, *nome;
  float *coordenadas = malloc(sizeof(float)*MAX);
  Ponto **pontos = malloc(sizeof(Ponto*)*MAX);
  size_t tamanho = 0;
  ssize_t leitura;
  QU *Q;
  
  while (1){
    leitura = getline(&linha, &tamanho, file);

    if(leitura < 0){
      break;
    }
      
    aux = strtok(linha, ",");
    nome = strdup(aux);
    
    while(aux!=NULL){
      if(m!=0 && m%MAX==0){
        coordenadas = realloc(coordenadas, sizeof(float)*2*m);
      }
      aux = strtok(NULL, ",");
      if(aux != NULL){
        coordenadas[m] = atof(aux);
        m++;
      }
    }
    
    pontos[i] = CriaPonto(coordenadas, m, nome);

    i++;
    
    if(i%MAX==0){
      pontos = realloc(pontos, sizeof(Ponto*)*2*i);
    }
    m=0;
  }

  Aresta **Y = malloc(sizeof(Aresta*)*((i-1)*i)/2);
  
  free(linha); 
  free(coordenadas);
  fclose(file);


  for(int j=0; j<i; j++){
    for(int k=0; k<j; k++){
      Y[pos] = InicializaAresta(pontos, j, k);
      pos++;
    }
  }

  OrdenaArestas(Y, (i*(i-1))/2);

  Q = UF_init(i);
  
  Algoritmo(Q, i, Y, k);

  file = fopen(argv[3], "w");
  
  if(pontos != NULL){ 
    ImprimeSubconjuntos(Q, pontos, k, i, file);
  }

  for(int j=0; j<i; j++){
    LiberaPonto(pontos[j]);
  }
  for(int j=0; j<(i*(i-1))/2; j++){
    LiberaAresta(Y[j]);
  }
  fclose(file);
  free(Y);
  free(pontos);
  LiberaQU(Q);
  
  return 0;
}