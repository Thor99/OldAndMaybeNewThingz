#include <stdio.h>

int main(){
  int n, i, tempo, velocidade;
  int dist = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d %d", &tempo, &velocidade);

    dist += tempo * velocidade;
  }

  printf("%d", dist);

  return 0;
}
