#include <stdio.h>
// poderiamos usar a <math.h> e plotar graficos com funcoes matematicas como sin

int main(){
	int m[60][60];
	int j;
	int i;
	
	for(j = 0; j < 60; j++){
		for(i = 0;i < 60; i++){
			m[j][i] = 0;
		}
	}
	
	for(i = 0; i < 60; i++){
		j = 60/(i + 1); //plotara uma funcao exponencial
		m[60 - j][i] = 1; // ao invés de começar no alto começara embaixo
	}
	
	for(j = 0; j < 60; j++){
		for(i = 0;i < 60; i++){
			if(m[j][i] == 0){
				printf(" ");
			}
			else{
				printf("O");
			}
		}
		
		printf("\n"); // para dar efeito de colunas e linhas no print
	}

	return 666;
}