#include <stdio.h>

int main(){
  int matriz[7][4];
  int menorValor = 100000000;
  int posLinhaMenorValor;
  int posColunaMenorValor;

  for(int i = 0; i < 7; ++i){
    for(int j = 0; j < 4; ++j){
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i = 0; i < 7; ++i){
    for(int j = 0; j < 4; ++j){
      if(matriz[i][j] < menorValor){
        menorValor = matriz[i][j];
        posLinhaMenorValor = i + 1;
        posColunaMenorValor = j + 1;
      }
    }
  }

  printf("Menor valor = %d\n", menorValor);
  printf("Posicao linha = %d\n", posLinhaMenorValor);
  printf("Posicao coluna = %d\n", posColunaMenorValor);

  return 0;
}
