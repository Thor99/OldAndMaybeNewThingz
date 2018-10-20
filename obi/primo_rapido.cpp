#include <stdio.h>
#include <math.h>

bool isPrime(int n){
  int limite = (int) ceil(sqrt(n)) + 1; // Ceil serve para arredondar para cima. Sqrt serve para tirar a raiz quadrada. 

  if(n != 2){
    if(n % 2 == 0){ // Se o número é divisível por 2, obviamente não é primo.
      return false;
    }
  }

  if(n == 2 || n == 3){ // 2 e 3 são primos
    return true;
  }

  for(int i = 3; i < limite; i+=2){ // Já vimos os pares, vamos ver os impares.
    if(n % i == 0){
      return false;
    }
  }

  return true;
}

int main(){
  int n, times;

  scanf("%d", &times);

  for(int i = 0; i < times; i++){
      scanf("%d", &n);

      if(isPrime(n) == true){
        printf("Prime\n");
      } else {
        printf("Not Prime\n");
      }
  }

  return 0;
}
