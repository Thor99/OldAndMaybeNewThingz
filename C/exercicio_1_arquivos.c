#include <stdio.h>

int main(void){
	
	float total = 0;
	float valor;
	int n = 0;

	FILE* f = fopen("exercicio1.txt", "rt");
	
	if(f == NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	while(fscanf(f, "%f", &valor) > 0){ //lerá os numeros flutuantes do arquivo até acabar
		total += valor;
		n++;
	}
	
	printf("%f", total / n);
	fclose(f);
	
	return 666;
}