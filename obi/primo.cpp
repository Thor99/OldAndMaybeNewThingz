#include <stdio.h>
#include <math.h>

bool isPrime(int n){
  int limite =(int) ceil(n / 2) + 1;

  if(n != 2){
    if(n % 2 == 0){
      return false;
    }
  }

  if(n == 2 || n == 3){
    return true;
  }

  for(int i = 3; i < limite; i+=2){
    if(n % i == 0){
      return false;
    }
  }

  return true;
}

int main(){
  int n;

  scanf("%d", &n);

  if(isPrime(n) == true){
    printf("sim\n");
  } else {
    printf("nao\n");
  }
  return 0;
}
