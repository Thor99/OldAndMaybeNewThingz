#include <stdio.h>

int main(){
	int x = 3;
	int y = 5;
	
	int* px = &x; // cria um ponteiro apontando o endere�o de onde a vari�vel x est� 
	int* py = &y; // cria um ponteiro apontando o endere�o de onde a vari�vel y est�
	
	printf("Diferenca de bytes entre os dois ponteiros: %d", (int)py - (int)px);   //Mostra a diferen�a de bytes entre os 2 ponteiros  / int ocupa 4 slots na memoria
	
	return 0;
}