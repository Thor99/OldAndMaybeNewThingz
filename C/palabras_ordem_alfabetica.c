#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100];
	char s2[100];
	char s3[100];
	
	printf("diga primeira palavra: ");
	scanf("%99s", s1);
	
	printf("diga o segunda palavra: ");
	scanf("%99s", s2);
	
	printf("diga o terceira palavra: ");
	scanf("%99s", s3);
	
	if(strcmp(s1, s2) < 0 && strcmp(s1, s3) < 0){
		if(strcmp(s2, s3) < 0){
			printf("%s\n %s\n %s\n", s1, s2, s3);
			return 0;
		}
		
		if(strcmp(s2, s3) > 0){
			printf("%s\n %s\n %s\n", s1, s3, s2);
			return 0;
		}
		
	}
	
	if(strcmp(s2, s1) < 0 && strcmp(s2, s3) < 0){
		if(strcmp(s1, s3) < 0){
			printf("%s\n %s\n %s\n", s2, s1, s3);
			return 0;
		}
		
		if(strcmp(s1, s3) > 0){
			printf("%s\n %s\n %s\n", s2, s3, s1);
			return 0;
		}
	}
	
	if(strcmp(s3, s1) < 0 && strcmp(s3, s2) < 0){
		if(strcmp(s1, s2) < 0){
			printf("%s\n %s\n %s\n", s3, s1, s2);
			return 0;
		}
		
		if(strcmp(s1, s2) > 0){
			printf("%s\n %s\n %s\n", s3, s2, s1);
			return 0;
		}
	}
	
	if(strcmp(s3, s2) < 0 && strcmp(s3, s1) < 0){
		if(strcmp(s2, s1) < 0){
			printf("%s\n %s\n %s\n", s3, s2, s1);
			return 0;
		}
		
		if(strcmp(s2, s1) > 0){
			printf("%s\n %s\n %s\n", s3, s1, s2);
			return 0;
		}
	}
		
	if(strcmp(s2, s3) < 0 && strcmp(s2, s1) < 0){
		if(strcmp(s3, s1) < 0){
			printf("%s\n %s\n %s\n", s2, s3, s1);
			return 0;
		}
		
		if(strcmp(s3, s1) > 0){
			printf("%s\n %s\n %s\n", s2, s1, s3);
			return 0;
		}
	}
	
	
	return 0;

}