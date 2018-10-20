#include <stdio.h>


float calcPi(int n){
	float pi;
	int i;
	float soma = 0;
	for(i = 0; i < n; i++){
		if(i % 2 == 0){
			soma += 1.0 / (2.0 * i + 1.0);
		}
		else{
			soma += -1.0 / (2.0 * i + 1.0);
		}
	}
	pi = 4 * soma;
	return pi;
}
int main(){
	int n;
	float pi;
	
	printf("Diga o n: ");
	scanf("%d", &n);
	pi = calcPi(n);
	printf("%f", pi);
	return 0;
}