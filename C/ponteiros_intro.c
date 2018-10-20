#include <stdio.h>

int main(){
	int x = 3;
	int y = 5;
	
	int* p = &x; // cria um ponteiro apontando o endereço de onde a variável x está 
	
	printf("endereço de x = %p / valor de x = %d\n", p, *p); //*p pega o valor que está no endereço que o ponteiro p está apontando  
	
	return 0;
}