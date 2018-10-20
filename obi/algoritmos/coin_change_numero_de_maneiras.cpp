#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXC 50
#define MAXV 250

// Given coins of certain denominations and a total, how many ways these coins can be combined to get the total.

using namespace std;

int nMoedas, valorDesejado;
long long int dp[MAXC][MAXV];
vector<int> moedas;

long long int ways(int type, int value){
    if(value == 0){ // Uma maneira, não usar nada.
        return 1;
    }

    if(value < 0 || type == nMoedas){ // Nenhuma maneira ou Já percorremos todas as moedas
        return 0;
    }

    // Já calculamos o estado dessa dp
    if(dp[type][value] != -1){
        return dp[type][value];
    }

    // Total de maneiras se ignoramos o tipo + se incluimos ele.
    return dp[type][value] = ways(type + 1, value) + ways(type, value - moedas[type]);
}

using namespace std;

int main(){
    memset(dp, -1, sizeof(dp));
	scanf("%d %d", &nMoedas, &valorDesejado);
	moedas.reserve(nMoedas);

	for(int i = 0; i < nMoedas; i++){
		int valor;
		scanf("%d", &valor);

		moedas.push_back(valor);
	}

	sort(moedas.begin(), moedas.end());

	printf("%lld\n", ways(0, valorDesejado));
}
