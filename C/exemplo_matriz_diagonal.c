#include <stdio.h>

int main(){
	int m[60][60];
	int j;
	int i;
	
	for(j = 0; j < 60; j++){
		for(i = 0;i < 60; i++){
			if(i == j){
				m[j][i] = 1;
			}
			else{
				m[j][i] = 0;
			}
		}
	}
	
	for(j = 0; j < 60; j++){
		for(i = 0;i < 60; i++){
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