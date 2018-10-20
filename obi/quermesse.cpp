#include <stdio.h>
#include <string.h>
#define N 10000

int main(){
  int guests[N], n, nTests=1;
  memset(guests, -1, sizeof(guests));

  while(scanf("%d", &n) == 1 && n != 0){
    printf("Teste %d\n", nTests++);

    for(int i = 0; i < n; i++){
      scanf("%d", &guests[i]);
    }

    for(int i = 0; i < n; i++){
      if(i + 1 == guests[i]){
        printf("%d\n", guests[i]);
      }
    }

    printf("\n");
  }
  return 0;
}
