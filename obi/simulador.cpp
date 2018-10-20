#include <cstdio>
#include <vector>

using namespace std;

int main(){
	vector<int> vec;
	int tam, nInstru;

	scanf("%d %d", &tam, &nInstru);

	for(int i = 0; i < tam; ++i){
		vec.push_back(i + 1);
	}

	for(int k = 0; k < nInstru; k++){
		char inst;
		int posInicial, posFinal;

		scanf(" %c %d %d", &inst, &posInicial, &posFinal);

		int dif = posFinal - posInicial;

		if(inst == 'I'){
			for(int i = posInicial - 1; dif != 1; i++){
				int tmp = vec[i];
				vec[i] = vec[i + dif];
				vec[i + dif] = tmp;

				if(dif == 2){
					// Não pode ficar 0, pois se isso ocorrer não terá inversão
					dif = 1;
				} else {
					dif = dif - 2;
				}
			}
		} else {
			long long int soma = 0;

			for(int i = posInicial - 1; i <= posFinal - 1; i++){
				soma += vec[i];
			}

			printf("%lld\n", soma);
		}
	}
}