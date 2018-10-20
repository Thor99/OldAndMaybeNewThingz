#include <stdio.h>

void f(int* p){
	*p = 2 * (*p);
}

int main(){
	int n;
	scanf("%d", &n);
	f(&n); //pega o valor de n e dobra
	printf("%d", n);
	
	return 0;
}