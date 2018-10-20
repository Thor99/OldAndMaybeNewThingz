#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int nBancos, nDebs;

	while(scanf("%d %d", &nBancos, &nDebs) == 2 && nBancos != 0){
		vector<int> bancos;
		bool salvos = true;

		bancos.push_back(0); // Vamos indexar de 1 a nBancos

		for(int i = 1; i <= nBancos; i++){
			int val;
			scanf("%d", &val);

			bancos.push_back(val);
		}

		for(int i = 0; i < nDebs; i++){
			int b1, b2, valor;
			scanf("%d %d %d", &b1, &b2, &valor);

			bancos[b1] -= valor;
			bancos[b2] += valor;
		}

		for(int i = 1; i <= nBancos; i++){
			if(bancos[i] < 0){
				salvos = false;
				break;
			}
		}

		if(salvos){
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
}