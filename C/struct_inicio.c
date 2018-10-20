#include <stdio.h>

struct Data{
	int dia;
	int mes;
	int ano;
};

int main(){
	struct Data hoje = {30, 4, 2015};
	//hoje.dia = 30;
	//hoje.mes = 4;
	//hoje.ano = 2015;
	printf("%d/%d/%d", hoje.dia, hoje.mes, hoje.ano);
	return 666;
}