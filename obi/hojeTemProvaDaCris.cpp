#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int nAlunos, nTrocas, teste=1;

	while(scanf("%d %d", &nAlunos, &nTrocas) == 2 && nAlunos != 0){
		printf("Instancia %d\n", teste);

		vector<string> nomes;
		int trocas = 0;

		for(int i = 0; i < nAlunos; i++){
			string s;
			cin >> s;

			nomes.push_back(s);
		}

		if(nTrocas == nAlunos){
			sort(nomes.begin(), nomes.end());
		} else {
			for(int i = 0; i < nAlunos; i++){
				for(int j = 0; j < nAlunos; j++){
					if(trocas < nTrocas){
						if(nomes[i] > nomes[j]){
							string st = nomes[i];
							nomes[i] = nomes[j];
							nomes[j] = st;
							trocas++;
						} 
					}
				}
			}
		}

		for(int i = 0; i < nAlunos; i++){
			cout << nomes[i] << " ";
		}

		cout << "\n\n";

		teste++;
	}
}
