#include <stdio.h>

int main()
{

	int v[10];
	int i;
	int k;
	
	v[0] = 0;
	v[1] = 1;
	
	for(i = 2; i < 10; i++){
		v[i] = v[i-1] + v[i - 2];
	}
	
	for(k = 0; k < 10; k++){
		printf("%d\n", v[k]);
	}

	return 0;
}