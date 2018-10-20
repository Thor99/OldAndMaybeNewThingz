#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int nComentarios, nAmigos;
    int counter = 0;
    vector<string> frases;

    scanf("%d %d", &nComentarios, &nAmigos);

    cin.ignore();

    for(int i = 0; i < nComentarios; i++){
        string frase;
        getline(cin, frase);

        transform(frase.begin(), frase.end(), frase.begin(), ::tolower);

        frases.push_back(frase);
    }

    for(int i = 0; i < nAmigos; i++){
        char letra;
        int freq;
        scanf(" %c", &letra);
        scanf("%d", &freq);

        for(int j = 0; j < frases.size(); j++){
            int yep = 0;

            for(int k = 0; k < frases[j].size(); k++){
                if(frases[j][k] == tolower(letra)){
                    yep++;
                }
            }

            if(yep >= freq){
                counter++;
                frases.erase(frases.begin() + j);
                break;
            }
        }
    }

    printf("%d\n", counter);
}