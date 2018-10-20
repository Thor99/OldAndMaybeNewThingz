#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    string arv;
    float membros = 0;
    map<string, float> mapa; // (Nome, aparicoes)

    scanf("%d", &N);
    cin.ignore();

    for(int i = 0; i < N; i++){
        while(getline(cin, arv)){
            if(arv == ""){
                // Map já ordena pra voce em ordem crescente, a partir da chave
                for(map<string, float>::iterator it = mapa.begin(); it != mapa.end(); ++it){
                    cout << (*it).first << " ";
                    printf("%.4f\n", ((*it).second * 100) / membros);
                }

                printf("\n");

                mapa.clear();
                membros = 0;
            } else {
                if(arv != ""){
                    if(mapa.find(arv) == mapa.end()){
                        mapa[arv] = 1;
                    } else {
                        mapa[arv]++;
                    }

                    membros++;
                }
            }
        }
    }

    // Map já ordena pra voce em ordem crescente, a partir da chave
    for(map<string, float>::iterator it = mapa.begin(); it != mapa.end(); ++it){
        cout << (*it).first << " ";
        printf("%.4f\n", ((*it).second * 100) / membros);
    }
}