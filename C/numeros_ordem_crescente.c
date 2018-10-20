#include <stdio.h>

int main()
{
	int n1, n2, n3;
	int p1,p2,p3;
	
	printf("Diga o primeiro numero: ");
	scanf("%d", &n1);
	
	printf("Diga o segundo numero: ");
	scanf("%d", &n2);
	
	printf("Diga o terceiro numero: ");
	scanf("%d", &n3);
	
	if(n1 > n2){
		if(n2 > n3){
			printf("%d\n %d\n %d\n", n3, n2, n1);
			return 0;
		}
		
		if(n3 > n2){
			printf("%d\n %d\n %d\n", n2, n3, n1);
			return 0;
		}
		
	}
	
	if(n2 > n1){
		if(n1 > n3){
			printf("%d\n %d\n %d\n", n3, n1, n2);
			return 0;
		}
		
		if(n3 > n1){
			printf("%d\n %d\n %d\n", n1, n3, n2);
			return 0;
		}
	}
	
	if(n3 > n1){
		if(n1 > n2){
			printf("%d\n %d\n %d\n", n2, n1, n3);
			return 0;
		}
		
		if(n2 > n1){
			printf("%d\n %d\n %d\n", n1, n2, n3);
			return 0;
		}
	}
	
	if(n3 > n2){
		if(n2 > n1){
			printf("%d\n %d\n %d\n", n2, n1, n3);
			return 0;
		}
		
		if(n1 > n2){
			printf("%d\n %d\n %d\n", n2, n1, n3);
			return 0;
		}
	}
		
	if(n2 > n3){
		if(n3 > n1){
			printf("%d\n %d\n %d\n", n1, n3, n2);
			return 0;
		}
		
		if(n1 > n3){
			printf("%d\n %d\n %d\n", n3, n1, n2);
			return 0;
		}
	}
	
	if(n3 == n1 && n1 == n2 && n3 == n2){
		printf("Numeros iguais.");
		return 0;
	}
	
	return 0;

}