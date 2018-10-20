#include <stdio.h>

int main() {
  int x1, x2, y1, y2, n, xm, ym, menorX, menorY, maiorX, maiorY;
  int numeroMeteoros = 0;
  int nTestes = 0;
  int i = 0;

  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  while((x1 + x2 + y1 + y2) != 0){
    scanf("%d", &n);

    i = 0;

    while(i < n){
      scanf("%d %d", &xm, &ym);

      if(x1 > x2){
        maiorX = x1;
        menorX = x2;
      } else {
        maiorX = x2;
        menorX = x1;
      }

      if(y1 > y2){
        maiorY = y1;
        menorY = y2;
      } else {
        maiorY = y2;
        menorY = y1;
      }

      if(xm >= menorX && xm <= maiorX && ym >= menorY && ym <= maiorY){
        numeroMeteoros += 1;
      }

      i += 1;
    }

    printf("Teste %d\n", nTestes + 1);
    printf("%d\n", numeroMeteoros);
    printf("\n");

    nTestes += 1;
    numeroMeteoros = 0;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  }

  return 0;
}
