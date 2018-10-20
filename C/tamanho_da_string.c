#include <stdio.h>

int conta_caracteres(char* s){
	int i = 0;
	
	while(s[i] != '\0'){
		i++;
	}
	
	return i;
}

int main(void){
	int n;
	char s[100];
	
	printf("Diga uma frase: ");
	scanf("%99[^\n]", s);
	
	n = conta_caracteres(s);
	
	printf("%d\n", n);
	return 0;
}



