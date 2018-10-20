#include <stdio.h>

int main(){
  int n;
  int i;
  int rodadaAldo;
  int rodadaBeto;
  int somaAldo = 0;
  int somaBeto = 0;
  int nTestes = 1;

  scanf("%d", &n);

  while(n != 0){
    for(i = 0; i < n; i++){
      scanf("%d %d", &rodadaAldo, &rodadaBeto);

      somaAldo += rodadaAldo;
      somaBeto += rodadaBeto;
    }

    if(somaAldo > somaBeto){
      printf("Teste %d\nAldo\n\n", nTestes);
    } else {
      printf("Teste %d\nBeto\n\n", nTestes);
    }

    nTestes+=1;
    scanf("%d", &n);
  }

  return 0;
}
