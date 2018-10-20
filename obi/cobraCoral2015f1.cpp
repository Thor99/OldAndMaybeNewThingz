#include <cstdio>

int main(){
	int seq[4];

	scanf("%d %d %d %d", &seq[0], &seq[1], &seq[2], &seq[3]);

	if(seq[0] == seq[2] || seq[1] == seq[3]){
		printf("V");
	} else {
		printf("F");
	}
}