#include <stdio.h>

int main(){
	int x = 3;
	int y = 5;
	
	int* p = &x; // cria um ponteiro apontando o endere�o de onde a vari�vel x est� 
	
	printf("endere�o de x = %p / valor de x = %d\n", p, *p); //*p pega o valor que est� no endere�o que o ponteiro p est� apontando  
	
	return 0;
}