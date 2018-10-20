#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);

	int quant2 = 0;
	int quant3 = 0;
	int quant4 = 0;
	int quant5 = 0;

	for(int i = 0; i < N; i++){
		int val;
		scanf("%d", &val);

		if(val % 2 == 0){
			quant2++;
		}

		if(val % 3 == 0){
			quant3++;
		}

		if(val % 4 == 0){
			quant4++;
		}

		if(val % 5 == 0){
			quant5++;
		}
	}

	printf("%d Multiplo(s) de 2\n", quant2);
	printf("%d Multiplo(s) de 3\n", quant3);
	printf("%d Multiplo(s) de 4\n", quant4);
	printf("%d Multiplo(s) de 5\n", quant5);

}