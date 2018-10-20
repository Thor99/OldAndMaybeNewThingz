#include <stdio.h>
#include <string.h>

struct Data{
	int dia;
	int mes;
	int ano;
};

struct Aniv{
	char nome[100];
	struct Data data;
};


int main(){
	char nome[100];
	struct Aniv anivs[5];
	int i;
	int mes_usuario;
	FILE* f = fopen("exercicio_struct.txt", "rt");
	
	if(f == NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	for(i = 0; i < 5; i++){
		fscanf(f, "%s %d/%d/%d", anivs[i].nome, &anivs[i].data.dia, &anivs[i].data.mes, &anivs[i].data.ano);
	}
	
	printf("Diga o mes que voce quer saber quem faz aniver: ");
	scanf("%d", &mes_usuario);
	
	for(i = 0; i < 5; i++){
		if(anivs[i].data.mes == mes_usuario){
			printf("%s: %d/%d/%d\n", anivs[i].nome, anivs[i].data.dia, anivs[i].data.mes, anivs[i].data.ano);
		}
	}
	
	fclose(f);
	
	return 666;
}