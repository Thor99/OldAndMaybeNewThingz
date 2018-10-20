#include <stdio.h>

int conta_impares(int* v, int n){
	int i;
	int quant = 0;
	for(i = 0; i < n; i++){
		if(v[i] % 2 != 0){
			quant++;
		}
	}
	
	return quant;
}

int main(){
	int n = 10;
	int i;
	int v[10];
	int resultado;
	
	for(i = 0; i < n; i++){
		v[i] = i; 
	}
	
	resultado = conta_impares(v, 10);
	
	printf("%d", resultado);
	
	
	return 666;
}