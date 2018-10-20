#include <stdio.h>

int menor_valor(int* v, int n){
	int menor = v[0];
	int i;

	for(i = 0; i < n; i++){
		if(v[i] < menor){
			menor = v[i];
		}

	}
	return menor;
}
int main(){



	int i;
	int v[6] = {0, 3, -55, -3, -2, -8};
	int resultado;



	resultado = menor_valor(v, 6);

	printf("%d", resultado);

	return 666;
}