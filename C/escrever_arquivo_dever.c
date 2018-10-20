#include <stdio.h>
#include <string.h>

int main(){
	FILE* f = fopen("famb2.txt", "at");
	char sa[50];
	char sb[50];
	char sc[50];
	
	int i;
	int ta;
	int tb;
	int tc;
	
	printf("Primeira palavra: ");
	scanf("%49s", sa);
		
	printf("Fale: ");
	scanf("%49s", sb);
	
	printf("Fale: ");
	scanf("%49s", sc);
	
	ta = strlen(sa);
	tb = strlen(sb);
	tc = strlen(sc);
	
	
	fprintf(f, "%s ", sa);
	fprintf(f, "%d\n", ta); 
	
	fprintf(f, "%s ", sb);
	fprintf(f, "%d\n", tb);

	fprintf(f, "%s ", sc);
	fprintf(f, "%d\n", tc);
	
	fflush(f); 
	
	fclose(f);
	fclose(f);
	
	return 666;
}