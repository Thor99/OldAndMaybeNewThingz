#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função rand vai de 0 até RAND_MAX 

int compara(const void* p1, const void* p2){
	int a = *(int*) p1; 
	int b = *(int*) p2; 

	return a - b;  
}

int main(){
	
	int v[1000];
	int i;
	srand(time(NULL));
	for(i = 0; i < 1000; i++){
		v[i] = rand() % 100;
	}
	qsort(v, 1000, sizeof(int), compara);
	
	for(i = 0; i < 1000; i++){
		printf("%d ", v[i]);
	}
	return 0;
}