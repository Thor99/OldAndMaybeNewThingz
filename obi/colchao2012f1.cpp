#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int alturaPorta, larguraPorta;
	int dimens[3];

	scanf("%d %d %d", &dimens[0], &dimens[1], &dimens[2]);
	scanf("%d %d", &alturaPorta, &larguraPorta);

	sort(dimens, dimens+3); // Sort do menor para o maior

	if((dimens[0] <= larguraPorta && dimens[1] <= alturaPorta) || (dimens[0] <= alturaPorta && dimens[1] <= larguraPorta)){
		printf("S");
	} else {
		printf("N");
	}
}