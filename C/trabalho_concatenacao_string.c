#include <stdio.h>
#include <string.h>

int main(){
	int s1T;
	int s2T;
	int n1;
	int n2;
	char s1[100];
	char s2[100];
	char s3[200];
	
	printf("Diga uma palavra: ");
	scanf("%99s", s1);
	s1T = strlen(s1);
	
	printf("Diga outra: ");
	scanf("%99s", s2);
	s2T = strlen(s2);
	
	for(n1 = 0; n1 < s1T ;n1++){
		s3[n1] = s1[n1]; 
	}
	for(n2 = s1T; n2 < s2T + s1T ;n2++){
		s3[n2] = s2[n2 - s1T]; 
	}
	
	s3[s1T + s2T] = '\0';
	
	printf("%s", s3);
	
	return 0;
}