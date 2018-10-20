#include <cstdio>
#include <cmath>

/* Tentando achar padrão no papel, percebemos que 4, 25, 81,.. são quadrados perfeitos.
A cada dobra, o numero de papeis dobras. Isso sugere exponenciação na base 2. Depois de testar muito chegamos na equação:
f(x) = ((2 ** x) + 1) ** 2 */

int main(){
	int nDobras;
	long long int resposta;
	int teste=1;

	while(scanf("%d", &nDobras) == 1 & nDobras != -1){
		resposta = (pow(2, nDobras) + 1) * (pow(2, nDobras) + 1);
		printf("Teste %d\n", teste++);
		printf("%lld\n\n", resposta);
	}
}