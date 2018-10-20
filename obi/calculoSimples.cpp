#include <cstdio>

int main(){
	int f1, quant1, n2, f2, quant2;
	float p2, p1;

	scanf("%d %d %f", &f1, &quant1, &p1);
	scanf("%d %d %f", &f2, &quant2, &p2);

	printf("VALOR A PAGAR: R$ %.2f\n", (quant1 * p1) + (quant2 * p2));
}