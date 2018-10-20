#include <stdio.h>

int main(){
	int n;
	int i;
	int quant = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i <= n; i++){
		if(i % 2 != 0){
			quant += 1;
		}
	}
	
	printf("%d\n", quant);
	return 666;
}