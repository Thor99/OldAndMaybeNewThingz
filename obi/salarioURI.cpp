#include <cstdio>

int main(){
	int number, horas;
	float salPorHora;

	scanf("%d", &number);
	scanf("%d", &horas);

	scanf("%f", &salPorHora);

	printf("NUMBER = %d\n", number);

	printf("SALARY = U$ %.2f\n", (salPorHora * horas));
}