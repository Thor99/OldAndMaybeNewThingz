#include <stdio.h>

int conta_negativos(int* v, int n){
	int negs = 0;
	int i;
	
	for(i = 0; i < n; i++){
		if(v[i] < 0){
			negs++;
		}
	}
	return negs;
}
int main(){
	
	
	int i;
	int v[6] = {0, 3, 5, -3, -2, -8};
	int resultado;
	
	
	
	resultado = conta_negativos(v, 6);
	
	printf("%d", resultado);

	return 666;
}