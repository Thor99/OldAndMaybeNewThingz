#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int nTests;
    scanf("%d", &nTests);

    for(int t = 0; t < nTests; t++){
        int valorTotal, quant;
        vector<pair<int, int> > vec; // Pair {custo, index}

        scanf("%d", &valorTotal);
        scanf("%d", &quant);

        vec.push_back(make_pair(0, 0)); // Index 0 não é usado

        for(int i = 1; i <= quant; i++){
            int custo;
            scanf("%d", &custo);

            vec.push_back(make_pair(custo, i));
        }

        // Sort crescente
        sort(vec.begin(), vec.end());

        for(int i = 1; i <= vec.size(); i++){
            int valIni = vec[i].first;
            int acharValor = valorTotal - valIni;

            pair<int, int> pii = make_pair(acharValor, -1);
            vector<pair<int, int> >::iterator it;
            vector<pair<int, int> >::iterator it2;

            if(i == 1){
                it2 = lower_bound(vec.begin() + (i + 1), vec.end(), pii); // Procura os elementos depois de i

                // Não pode ser igual ao que it2 aponta e it2->first tem que ser igual a acharValor
                if(it2 != vec.end() && (*it2).first == acharValor){
                    printf("%d %d\n", min(vec[i].second, (*it2).second), max(vec[i].second, (*it2).second));
                    break;
                }
            }

            else if(i == vec.size()){
                // Procura os elementos entre o indice 1 e i - 1 (o segundo parametro é intervalor aberto)
                it = lower_bound(vec.begin() + 1, vec.begin() + i, pii);

                // Não pode ser igual ao que it aponta e it->first tem que ser igual a acharValor
                if(it != vec.begin() + i && (*it).first == acharValor){
                    printf("%d %d\n", min(vec[i].second, (*it).second), max(vec[i].second, (*it).second));
                    break;
                }
            }

            else {
                // Procura os elementos entre o indice 1 e i - 1 (o segundo parametro é intervalor aberto)
                it = lower_bound(vec.begin() + 1, vec.begin() + i, pii);

                // Procura os elementos depois de i
                it2 = lower_bound(vec.begin() + (i + 1), vec.end(), pii);

                // Não pode ser igual ao que it aponta e it->first tem que ser igual a acharValor
                if(it != vec.begin() + i && (*it).first == acharValor){
                    printf("%d %d\n", min(vec[i].second, (*it).second), max(vec[i].second, (*it).second));
                    break;
                } else {
                    // Não pode ser igual ao que it2 aponta e it2->first tem que ser igual a acharValor
                    if(it2 != vec.end() && (*it2).first == acharValor){
                        printf("%d %d\n", min(vec[i].second, (*it2).second), max(vec[i].second, (*it2).second));
                        break;
                    }
                }
            }
        }
    }
}