#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int main(){
	int nCasas;
	int teste = 1;

	while(scanf("%d", &nCasas) == 1 && nCasas != 0){
		printf("Cidade# %d:", teste);

		// Organiza consumo médio por imóvel do menor valor para o maior
		map<int, int> mapa; // Consumo medio, Numero de moradores
		int nMoradores, consumoTotalImovel;
		long long int soma_moradores=0, soma_consumo_total=0;

		for(int i = 0; i < nCasas; i++){
			scanf("%d %d", &nMoradores, &consumoTotalImovel);

			soma_moradores += nMoradores;
			soma_consumo_total += consumoTotalImovel;

			// Caso duas casas tenham consumos iguais, soma o numero de moradores
			map<int, int>::iterator it;
			it = mapa.find((consumoTotalImovel / nMoradores));

			if(it == mapa.end()){
				mapa[(consumoTotalImovel / nMoradores)] = nMoradores;
			} else {
				it->second += nMoradores;
			}
		}

		map<int, int>::iterator itx;

		for(itx = mapa.begin(); itx != mapa.end(); itx++){
			printf("%d-%d ", (*itx).second, (*itx).first); // nMoradores-consumoMedio
		}

		// Essa parte de baixo eu peguei do uri forum, porque o toolkit gera saidas com um centesimo de diferença do meu codigo anterior:
		// printf("Consumo medio: %.2lf m3.\n\n", (double) soma_consumo_total / soma_moradores);
		double int_part;
        int frac_part;
        frac_part = (int) (modf ((double)soma_consumo_total/soma_moradores, &int_part) *100);
         
        if(frac_part < 10){
            printf("\nConsumo medio: %d.0%d m3.\n\n", (int)int_part, (int)frac_part);
        }
        else{
            printf("\nConsumo medio: %d.%d m3.\n\n", (int)int_part, (int)frac_part);
        }

		teste++;
	}
}