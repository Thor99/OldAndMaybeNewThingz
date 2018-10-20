#include <stdio.h>

int main()
{
	int n1, n2, n3;
	printf("Diga o primeiro número: ");
	scanf("%d", &n1);
	
	printf("Diga o SEGUNDO número: ");
	scanf("%d", &n2);
	
	printf("Diga o terceiro número: ");
	scanf("%d", &n3);
	
	if(n1 > n2 && n1 > n3){
		printf("Primeiro numero é maior");
		return 0;
	}
	
	if(n2 > n1 && n2 > n3){
		printf("Segundo numero é maior");
		return 0;
	}
	
	if(n3 > n1 && n3 > n2){
		printf("Terceiro numero é maior");
		return 0;
	}
	
	if(n3 == n1 && n1 == n2 && n3 == n2){
		printf("Numeros iguais.");
		return 0;
	}
	
	



	return 0;

}