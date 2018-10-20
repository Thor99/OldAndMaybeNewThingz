#include <cstdio>
#include <cmath>

int main(){
	int nTestes=1, n;

	while(scanf("%d", &n) == 1 && n != 0){
		long long int result = pow(2, n) - 1;

		printf("Teste %d\n", nTestes++);

		printf("%lld\n\n", result);
	}
}