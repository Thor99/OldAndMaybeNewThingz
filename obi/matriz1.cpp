#include <stdio.h>

int main(){
  int matriz[2][3];
  int soma = 0;
  int quantPares = 0;

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 3; ++j){
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 3; ++j){
      if(matriz[i][j] % 2 == 0){
        soma += matriz[i][j];
        quantPares++;
      }
    }
  }

  printf("%.1f\n", (float) soma / quantPares);
  return 0;
}
