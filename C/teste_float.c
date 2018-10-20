#include <stdio.h>

int main(){

	float x;
	float y;
	float z;
	float result;
	
	printf("First: \n");
	scanf("%f", &x);
	
	printf("Second: \n");
	scanf("%f", &y);
	
	printf("Third: \n");
	scanf("%f", &z);
	
	result = (x + y + z) / 3;
	
	printf("%f\n", result);
	
	
	return 0;

}