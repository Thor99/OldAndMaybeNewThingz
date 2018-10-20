#include <stdio.h>

int main(){
	int x = 3;
	int y = 5;
	
	int* px = &x; // cria um ponteiro apontando o endereço de onde a variável x está 
	*px = 7; //muda o valor no endereço do ponteiro p
	
	printf("%d", x);  
	
	return 0;
}