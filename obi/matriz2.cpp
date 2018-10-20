#include <stdio.h>

int main(){
  int matriz[5][5];
  int somaQuartaLinha = 0;
  int somaDiagonalPrincipal = 0;
  int somaDiagonalSecundaria = 0;
  int somaTodosOsElementos = 0;


  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < 5; ++j){
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int j = 0; j < 5; ++j){
    somaQuartaLinha += matriz[3][j];
  }

  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < 1; ++j){
      somaDiagonalPrincipal += matriz[i][i];
    }
  }

  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < 1; ++j){
      somaDiagonalSecundaria += matriz[i][4 - i];
    }
  }

  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < 5; ++j){
      somaTodosOsElementos += matriz[i][j];
    }
  }

  printf("Soma da quarta linha = %d\n", somaQuartaLinha);
  printf("Soma da diagonal principal = %d\n", somaDiagonalPrincipal);
  printf("Soma da diagonal secundária = %d\n", somaDiagonalSecundaria);
  printf("Soma de todos os elementos = %d\n", somaTodosOsElementos);

  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < 5; ++j){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
