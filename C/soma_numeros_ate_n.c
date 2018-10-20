#include <stdio.h>

int main(){
	int n;
	int i;
	int soma = 0;
	scanf("%d", &n);
	for(i = 1; i <= n;i++){
		soma += i;
	}
	
	printf("%d\n", soma);
	return 666;
}