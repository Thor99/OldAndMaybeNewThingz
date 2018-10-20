#include <stdio.h>

int main(){
  int n, latas, copos;
  int soma = 0;

  scanf("%d\n", &n);

  for(int i = 0; i < n; i++){
    scanf("%d %d", &latas, &copos);

    if(latas > copos){
      soma += copos;
    }
  }

  printf("%d\n", soma);
  return 0;
}
