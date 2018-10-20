#include <stdio.h>

int main(void){
	
	char y[6] = {'L', 'Ó', 'U', 'I', 'S', '\0'};
	char j[6] = "LOUIS"; // sempre tem que botar um numero a mais do que a string pois o vetor de char precisa de um espaço obrigatorio para o '\0'
	
	char s[500];
		
	scanf("%499[^\n]", s); //nesse caso o compilador só vai parar ao apertar enter, lendo frases, e o 499 diz que só podera ler 499 digitos
	printf("%s", s);
	return 0;
}