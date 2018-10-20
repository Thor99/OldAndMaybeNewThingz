#include <stdio.h>

int main(){
  int n, j1, j2, i;
  char nome1[11];
  char nome2[11];
  int nTests = 1;

  scanf("%d\n", &n);

  while(n != 0){
    scanf("%[^\n]%*c", nome1);
    scanf("%[^\n]%*c", nome2);

    printf("Teste %d\n", nTests);
    for(i = 0; i < n; i++){
      scanf("%d %d\n", &j1, &j2);

      if((j1 + j2) % 2 == 0){
        printf("%s\n", nome1);
      } else {
        printf("%s\n", nome2);
      }
    }

    printf("\n");
    nTests++;
    scanf("%d\n", &n);
  }
  return 0;
}
