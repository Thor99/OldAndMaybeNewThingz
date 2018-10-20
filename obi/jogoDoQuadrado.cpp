#include <cstdio>
#define MAX 201

using namespace std;

int main(){
	int L, C;
	int matriz[MAX][MAX];

	scanf("%d %d", &L, &C);

	for(int i = 0; i < L; i++){
		for(int j = 0; j < C; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	int consultas;

	scanf("%d", &consultas);

	for(int c = 0; c < consultas; c++){
		bool pode = true;
		int inter;
		scanf("%d", &inter);
		
		for(int i = 0; i < inter; i++){
			for(int j = i; j < inter; j++){
				if(matriz[i][j] == 0){
					pode = false;
				}
			}
		}

		if(pode){
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
}