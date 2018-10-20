#include <stdio.h>

int main(){
  int valor;
  int valorBase = 7;
  int valorRange2 = 20;
  int valorRange3 = 140;
  int i;

  scanf("%d", &valor);

  if(valor <= 10){
    printf("%d", valorBase);
  }

  else if(valor >= 11 && valor <= 30){
    printf("%d", (valorBase + (valor - 11) + 1));
  }

  else if(valor >= 31 && valor <= 100){
    printf("%d", valorBase + valorRange2 + ((valor - 31) + 1) * 2);
  }

  else {
    printf("%d", valorBase + valorRange2 + valorRange3 + ((valor - 101) + 1) * 5);
  }

  return 0;
}
