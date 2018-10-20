#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    long int N;
    long int nOperacoes;
    vector<long int> competidores;

    scanf("%ld", &N);

    competidores.push_back(0);

    for(int i = 1; i <= N; i++){
        long int altura;
        scanf("%ld", &altura);
        competidores.push_back(altura);
    }

    scanf("%ld", &nOperacoes);

    while(nOperacoes--){
        int operacao;
        long int posicao;
        long int alturaOuIncremento;

        scanf("%d %ld %ld", &operacao, &posicao, &alturaOuIncremento);

        if(operacao == 1){
            vector<long int>::iterator it = upper_bound(competidores.begin()+1, competidores.begin()+posicao, competidores[posicao] + alturaOuIncremento);
            cout << (it - (competidores.begin()+1)) << "\n";
        }

        else { // operacao == 0
            competidores.insert(competidores.begin() + posicao + 2, alturaOuIncremento); // com + 2, o novo elemento fica atras de posicao
        }
    }
}