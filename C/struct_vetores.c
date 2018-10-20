#include <stdio.h>

struct Data{
	int dia;
	int mes;
	int ano;
};

int main(){
	int i;
	struct Data datas[5];
	datas[0].dia = 3;
	datas[0].mes = 5;
	datas[0].ano = 1999;
	
	datas[1].dia = 3;
	datas[1].mes = 6;
	datas[1].ano = 1999;
	
	datas[2].dia = 9;
	datas[2].mes = 5;
	datas[2].ano = 1974;
	
	for(i = 0; i < 3; i++){
		printf("%d/%d/%d\n", datas[i].dia, datas[i].mes, datas[i].ano);
	}
	
	
	return 666;
}