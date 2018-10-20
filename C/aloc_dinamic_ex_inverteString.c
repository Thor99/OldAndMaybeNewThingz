#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverte(char* s) {
	int tamanho = strlen(s);
	char* novaPalavra = malloc(tamanho * sizeof(char));
	int i;
	
	for(i = 0; i < tamanho + 1; i++) {
		novaPalavra[i] = s[tamanho - i - 1];
	}
	novaPalavra[tamanho] = '\0';
	
	return novaPalavra;
}

int main() {
	char s[100];
	char* novaPalavra;
	
	printf("Diga uma palavra: ");
	scanf("%99[^\n]", s);
	
	novaPalavra = inverte(s);
	
	printf("Palavra ao contrário: %s", novaPalavra);
	
	return 0;
}