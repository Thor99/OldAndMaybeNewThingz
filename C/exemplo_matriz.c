#include <stdio.h>

int main(){
	int m[4][4];
	int j;
	int i;
	
	for(j = 0; j < 4; j++){  // esse for é um padrão para botar valores em matriz
		for(i = 0;i < 4; i++){
			m[j][i] = 0;
		}
	}
		
	m[2][3] = 1; // mudando valores para dar efeito de X e O
	m[1][2] = 1;
	m[0][1] = 1;
	m[2][1] = 1;
	m[3][0] = 1;
	
	for(j = 0; j < 4; j++){
		for(i = 0;i < 4; i++){
			if(m[j][i] == 0){
				printf("X");
			}
			else{
				printf("O");
			}
		}
		
		printf("\n"); // para dar efeito de colunas e linhas no print
	}

	return 666;
}