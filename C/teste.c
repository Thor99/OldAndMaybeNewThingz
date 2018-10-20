#include <stdio.h>

int main()
{
 int i;
 int x;
 int soma = 1;
 
 printf("Digite um numero: ");
 scanf("%d", &i);
 
 x = i;
 
 while(x > 1)
 {
	soma *= x;
	x--;
 }
 
 printf("%d", soma);
 return 0;
}
