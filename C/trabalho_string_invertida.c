#include <stdio.h>
#include <string.h>

int main(){
	int t;
	char s[100];
	int n;
	
	printf("Diga uma palavra: ");
	scanf("%99[^\n]", s);
	
	t = strlen(s) - 1;
	
	for(n = t; n+1 > 0; n--){
		printf("%c", s[n]);
	}
	
	return 0;
}