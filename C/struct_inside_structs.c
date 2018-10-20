#include <stdio.h>
#include <string.h>

struct Data{
	int dia;
	int mes;
	int ano;
};

struct Aniv{
	char nome[50];
	struct Data data;
};

int main(){
	struct Aniv thor; // = {"Thor", {3, 6, 1999}}; , para já iniciar com valores
	strcpy(thor.nome, "Thor");
	thor.data.dia = 3;
	thor.data.mes = 6;
	thor.data.ano = 1999;
	printf("%s\nNascido em %d/%d/%d", thor.nome, thor.data.dia, thor.data.mes, thor.data.ano);
	return 666;
}