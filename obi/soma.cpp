#include <stdio.h>
#include <string.h>
#define N 51

int main(){
  int numeros[51];
  int n, i;
  int soma = 0;

  memset(numeros, 0, sizeof(numeros)); // Predefinindo todos os valores como 0

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &numeros[i]);
    soma += numeros[i];
  }

  printf("%d", soma);

  return 0;
}
