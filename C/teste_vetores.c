#include <stdio.h>


int main(void){

	float v[5];
	int i;
	float soma = 0;
	
	for(i = 0; i < 5; i++){
		printf("Digite: ");
		scanf("%f", &v[i]);
		soma += v[i];
	}
	
	printf("media = %.02f\n", soma / 5);
	
	return 0;
	
}