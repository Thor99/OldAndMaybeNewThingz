#include <cstdio>
#include <cmath>

bool isPrime(int n){
  int limite = (int) ceil(sqrt(n)) + 1; // Ceil serve para arredondar para cima. Sqrt serve para tirar a raiz quadrada.


  if(n % 2 == 0 || n == 1){
     return false;
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
    int N, M;
    long long int p1, p2;
    scanf("%d %d", &N, &M);

    for(int i = N; i >= 2; i--){
        if(isPrime(i)){
            p1 = i;
            break;
        }
    }

    for(int i = M; i >= 2; i--){
        if(isPrime(i)){
            p2 = i;
            break;
        }
    }

    printf("%lld\n", p1 * p2);
}