#include <stdio.h>

int main()
{

	int v[10];
	int i;
	int k;
	int j;
	int pares = 0;
	
	v[0] = 0;
	v[1] = 1;
	
	for(i = 2; i < 10; i++){
		v[i] = v[i-1] + v[i - 2];
	}
	for(j = 0; j < 10; j++){
		if(v[j] % 2 == 0){
			pares += 1;
		}
	}
	for(k = 0; k < 10; k++){
		printf("%d\n", v[k]);
	}
	
	printf("Pares: %d", pares);

	return 0;
}