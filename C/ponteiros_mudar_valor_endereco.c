#include <stdio.h>

int main(){
	int x = 3;
	int y = 5;
	
	int* px = &x; // cria um ponteiro apontando o endere�o de onde a vari�vel x est� 
	*px = 7; //muda o valor no endere�o do ponteiro p
	
	printf("%d", x);  
	
	return 0;
}