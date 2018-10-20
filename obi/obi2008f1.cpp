#include <cstdio>
#define MAXN 1000

int main(){
	int N, minimo, passaram=0;

	scanf("%d %d", &N, &minimo);

	for(int i = 0; i < N; ++i){
		int f1, f2;
		scanf("%d %d", &f1, &f2);

		if(f1 + f2 >= minimo){
			passaram++;
		}
	}

	printf("%d", passaram);
}