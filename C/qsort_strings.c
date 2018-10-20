#include <stdio.h>
#include <stdlib.h>

// void qsort(int* v, int n, int tam, int (*compara)(const void*, const void*));

int compara_string(const void* a, const void* b){
	//char** ps1 = (char**)a; // transforma a em char** e atribui ao ponteiro de s1 (ps1) 
	//char* s1 = *ps1; // Conteúdo de s1 é o conteúdo de ps1, que no caso é um vetor, então s1 é do tipo char*
	//char** ps2 = (char**)b; // transforma b em char** e atribui ao ponteiro de s2 (ps2) 
	//char* s2 = *ps2; // Conteúdo de s2 é o conteúdo de ps2, que no caso é um vetor, então s2 é do tipo char*
	
	char* s1 = (char*) a; // No nosso caso de matrizes fazemos desse jeito.
	char* s2 = (char*) b; // No nosso caso de matrizes fazemos desse jeito.
	
	return strcmp(s1, s2); // Imprime em ordem alfabética
	//return -(strcmp(s1, s2)); // Imprime em ordem alfabética contrária
}

 int main(){
	int i;
	char s[5][100] = {"z", "www.louis","doglixo", "def", "freips"}; // Vetor de tamanho cinco que aceitas palavras até 99 (5 palavras de até 99)
	qsort(s, 5, sizeof(char) * 100, compara_string);
	
	for(i = 0; i < 5; i++){
		printf("%s\n", s[i]);
	}
	return 0;
}