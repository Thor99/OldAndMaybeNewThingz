#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int nLetrasFavo, tamNomeIni, nTrocas;
string letrasFavoritas;
string nomeInicial;

vector<pair<int, string> > vec; // n, Nome
map<char, int> mapa;

void getQuantLetrasFav(string nome){
	int quant = 0;
	string::iterator it;

	for(int i = 0; i < nome.size(); i++){
		if(mapa.find((char) nome[i]) == mapa.end()){
			it = lower_bound(letrasFavoritas.begin(), letrasFavoritas.end(), (char) nome[i]);

			if(*it == (char) nome[i]){
				quant++;
				mapa[(char) nome[i]] = 1;
			} else {
				mapa[(char) nome[i]] = 0;
			}
		} else {
			quant += mapa[(char) nome[i]];
		}
	}

	vec.push_back(make_pair(quant, nome));
}

int main(){

	scanf("%d %d %d", &nLetrasFavo, &tamNomeIni, &nTrocas);

	vec.reserve(nTrocas + 1);

	cin >> letrasFavoritas;
	cin >> nomeInicial;

	getQuantLetrasFav(nomeInicial);
	sort(letrasFavoritas.begin(), letrasFavoritas.end());

	for(int i = 0; i < nTrocas; i++){
		int quantAgora = vec[i].first;

		char a, b;

		cin >> a;
		cin >> b;

		int ca = count(nomeInicial.begin(), nomeInicial.end(), a);
		int cb = count(nomeInicial.begin(), nomeInicial.end(), b);

		string::iterator it1 = lower_bound(letrasFavoritas.begin(), letrasFavoritas.end(), a);
		string::iterator it2 = lower_bound(letrasFavoritas.begin(), letrasFavoritas.end(), b);

		replace(nomeInicial.begin(), nomeInicial.end(), a, '3');
		replace(nomeInicial.begin(), nomeInicial.end(), b, '4');

		replace(nomeInicial.begin(), nomeInicial.end(), '3', b);
		replace(nomeInicial.begin(), nomeInicial.end(), '4', a);

		if(*it1 == a && *it2 == b){
			quantAgora += 0;
		} else if(*it1 == a && *it2 != b){
			quantAgora -= ca;
			quantAgora += cb;
		} else if(*it1 != a && *it2 == b){
			quantAgora += ca;
			quantAgora -= cb;
		} else { // *it1 != a && *it2 != b
			quantAgora += 0;
		}

		vec.push_back(make_pair(quantAgora, nomeInicial));
	}

	sort(vec.rbegin(), vec.rend());

	cout << vec[0].first << endl;
	cout << vec[0].second << endl;
}