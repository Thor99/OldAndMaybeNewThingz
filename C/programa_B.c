#include <stdio.h>
#include "sem.h"

int main()
{
	Sem sb = sem_create("SemaforoB", 0, 1);
	Sem sc = sem_create("SemaforoC", 0, 1);
	Sem sfim = sem_create("Fim", 0, 1);
	
	FILE* f =fopen("saida.txt","at");
	
	
	if(f == NULL){
		printf("Erro ao abrir o arquivo.");
		return 0;
	}
  	sem_down(sb);
	fprintf(f,"B");
	fflush(f);
  	sem_up(sc);

	fclose(f);
	
	sem_down(sfim);

	return 666;															
}