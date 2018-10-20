#include <cstdio>

int nChamadas = -1; // A chamada do próprio não conta

int fib(int n){
	nChamadas++;

	if(n == 0){
		return 0;
	}

	if(n == 1){
		return 1;
	}

	return fib(n - 1) + fib(n - 2); 
}

int main(){
	int nCasos, numero;

	scanf("%d",&nCasos);

	for(int i = 0; i < nCasos; ++i){
		scanf("%d", &numero);

		printf("fib(%d) = %d calls = %d\n", numero, nChamadas, fib(numero));

		nChamadas = -1; // A chamada do próprio não conta
	}
}