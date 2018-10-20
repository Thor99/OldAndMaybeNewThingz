#include <stdio.h>

int fat(int n){
  if(n <= 1){
    return 1;
  }

  return n * fat(n - 1);
}
int main(){
  int n;

  scanf("%d", &n);

  printf("%d", fat(n));
  return 0;
}
