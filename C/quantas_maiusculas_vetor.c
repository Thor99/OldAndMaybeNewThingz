#include <stdio.h>

int conta_maiusculas(char* s){
	int i = 0;
	int counter_for;
	int tamanho = 0;
	int maiusculas = 0;
	while(s[i] != '\0'){
		tamanho += 1;
		i++;
	}
	
	for(counter_for = 0;counter_for < tamanho;counter_for++){
		if(s[counter_for] >= 65 && s[counter_for] <= 90){
			maiusculas += 1;
		}
	}
	
	return maiusculas;
}
int main(){
	
	char s[200];
	int maiusculas;
	
	scanf("%199[^\n]", s);
	
	maiusculas = conta_maiusculas(s);
	
	printf("%d\n", maiusculas);
	
	
	return 666;
}