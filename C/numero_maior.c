#include <stdio.h>

int main()
{
	int n1, n2, n3;
	printf("Diga o primeiro n�mero: ");
	scanf("%d", &n1);
	
	printf("Diga o SEGUNDO n�mero: ");
	scanf("%d", &n2);
	
	printf("Diga o terceiro n�mero: ");
	scanf("%d", &n3);
	
	if(n1 > n2 && n1 > n3){
		printf("Primeiro numero � maior");
		return 0;
	}
	
	if(n2 > n1 && n2 > n3){
		printf("Segundo numero � maior");
		return 0;
	}
	
	if(n3 > n1 && n3 > n2){
		printf("Terceiro numero � maior");
		return 0;
	}
	
	if(n3 == n1 && n1 == n2 && n3 == n2){
		printf("Numeros iguais.");
		return 0;
	}
	
	



	return 0;

}