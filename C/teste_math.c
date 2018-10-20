#include <stdio.h>
#include <math.h>

int main(){

	float a;
	float b;
	float c;
	float resultado_unico;
	float result1;
	float result2;
	float delta;
	
	printf("fala o a: ");
	scanf("%f", &a);
	
	printf("fala o b: ");
	scanf("%f", &b);
	
	printf("fala o c: ");
	scanf("%f", &c);
	
	if(a == 0){
		printf("Não é de segundo grau.");
	} else{
		delta = (b * b) - (4 * a * c);
		if(delta == 0){
			resultado_unico = -b / 2 * a;
			printf("Um resultado: %f", resultado_unico);
		}else{
			result1 = (-b + sqrt(delta)) / 2 * a;
			result2 = (-b - sqrt(delta)) / 2 * a;
			printf("Primeiro resultado: %f\n", result1);
			printf("Segundo resultado: %f", result2);
		}
	}
	
	return 0;

}