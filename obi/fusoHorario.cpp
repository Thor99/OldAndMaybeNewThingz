#include <cstdio>

int main(){
	int saida, tempo, fuso;

	scanf("%d %d %d", &saida, &tempo, &fuso);

	if(saida + tempo + fuso > 24){
		printf("%d\n", (saida + tempo + fuso) - 24);
	}

	else if(saida + tempo + fuso < 0){
		printf("%d\n", (saida + tempo + fuso) + 24);
	}

	else if(saida + tempo + fuso == 24){
		printf("0\n");
	}

	else {
		printf("%d\n", (saida + tempo + fuso));
	}
}