#include <stdio.h>
#include <algorithm>
#include <functional>

bool equal(int arr1[5], int arr2[5]){
  int i;

  for(i = 0; i < 5; i++){
    if(arr1[i] != arr2[i]){
      return false;
    }
  }

  return true;
}

int main(){
  int cartas[5];
  int cartasCrescente[5];
  int cartasDecrescente[5];
  int i;

  for(i = 0; i < 5; i++){
    scanf("%d", &cartas[i]);
  }

  for(i = 0; i < 5; i++){
    cartasCrescente[i] = cartas[i];
    cartasDecrescente[i] = cartas[i];
  }

  std::sort(cartasCrescente, cartasCrescente+5); // Ordena em ordem crescente
  std::sort(cartasDecrescente, cartasDecrescente+5, std::greater<int>()); // Ordena em ordem decrescente

  if(equal(cartasCrescente, cartas) == true){ // Checa se o array cartas esta em ordem crescente
    printf("C");
  }

  else if(equal(cartasDecrescente, cartas) == true){ // Checa se o array cartas esta em ordem decrescente
    printf("D");
  }

  else { // Array não esta ordenado
    printf("N");
  }

  return 0;
}
