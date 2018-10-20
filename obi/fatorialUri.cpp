#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 10000000

using namespace std;

/* Consiste em fazer uma lista de fatoriais que poderão ser usados para se chegar até o valor desejado, e aplicar depois o algoritmo
de coin change, para achar a menor quantidade possível de fatoriais para se chegar ao número de entrada */

int fat(int n){
	if(n == 0){
		return 1;
	} 

	return n * fat(n - 1);
}

int main(){
	int nDesejado;
	int counterFatoriais = 0;
	vector<int> dp;
	vector<int> fats;

	dp.push_back(0);

	scanf("%d", &nDesejado);

	for(int i = 1; i <= nDesejado; ++i) dp.push_back(INF);

	// Só precisamos pegar o fatorial até um número no máximo igual a nDesejado, os outros não servem.
	while(true){
		if(fat(counterFatoriais) <= nDesejado){
			fats.push_back(fat(counterFatoriais));
			counterFatoriais++;
		} else {
			break;
		}
	}

	// Coin change
	sort(fats.begin(), fats.end());
	for(int i = 1; i <= nDesejado; i++){
		for(int j = 0; j < fats.size(); j++){
			if(fats[j] > i){
				break;
			}

			else {
				dp[i] = min(dp[i], dp[i - fats[j]] + 1);
			}
		}
	}

	printf("%d\n", dp[nDesejado]);
}