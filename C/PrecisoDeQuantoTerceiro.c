#include <stdio.h>

int main(){
	float m1, m2, quantoPrecisa;

	printf("Qual foi sua nota no primeiro trimestre: ");
	scanf("%f", &m1);

	printf("Qual foi sua nota no segundo trimestre: ");
	scanf("%f", &m2);

	quantoPrecisa = 21 - (m1 + m2);

	printf("Precisará no terceiro %f", quantoPrecisa);
	return 0;
}