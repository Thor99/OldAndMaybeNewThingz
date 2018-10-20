#include <stdio.h>

int main(void){
	
	char s[100];
	FILE* f = fopen("famb.txt", "rt");
	
	if(f == NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	fscanf(f, "%99[^\n]", s);
	printf("%s\n", s);
	fclose(f);
	
	return 666;
}