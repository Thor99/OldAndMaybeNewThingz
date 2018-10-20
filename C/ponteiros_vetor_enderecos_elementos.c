#include <stdio.h>

int main(){
	int i;
	int v[5];  
	
	for(i = 0; i < 5; i++){
		printf("%p\n", &v[i]); //endereço de cada elemento do vetor
	}
	
	printf("Endereco de v = %p\n", v); //Endereço de v é o endereço do primeiro elemento
	
	return 0;
}