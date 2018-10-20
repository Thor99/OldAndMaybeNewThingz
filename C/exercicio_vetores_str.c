#include <stdio.h>

int main(void){

	char s[100];
	int x = 0;
	int numero_vogais = 0;
	
	printf("Diga uma frase: ");
	scanf("%99[^\n]", s);
	
	while(s[x] != '\0'){
		if(s[x] == 'a' || s[x] == 'e' || s[x] == 'i' || s[x] == 'o' || s[x] == 'u' || s[x] == 'A' || s[x] == 'E' || s[x] == 'I' || s[x] == 'O' || s[x] == 'U'){
			numero_vogais++;
		}
		
		x++;
	
	}
	
	printf("%d\n", numero_vogais);

	return 666;
}