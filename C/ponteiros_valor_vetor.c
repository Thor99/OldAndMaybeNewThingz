#include <stdio.h>

int main(){
	int i;
	int v[5] = {1,2,3,4,5};  
	
	for(i = 0; i < 5; i++){
		printf("%p\n", &v[i]); //endereço de cada elemento do vetor
	}
	
	printf("Endereco de v = %p\n", v); //Endereço de v é o endereço do primeiro elemento
	printf("valor de v = %d\n", *v); //imprimira o valor do primeiro elemento
	
	return 0;
}