#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main(){
    int nPalavras, nDescricoes;
    map<string, int> dict;
    scanf("%d %d", &nPalavras, &nDescricoes);

    while(nPalavras--){
        string str;
        int val;
        cin >> str >> val;

        dict[str] = val;
    }

    cin.ignore();

    string spec;
    int soma = 0;
    int counterPontos = 0;
    while(getline(cin, spec)){
        if(spec == "."){
            printf("%d\n", soma);
            soma = 0;
            if(counterPontos == nDescricoes){
                return 0;
            }
        } else {
            istringstream iss(spec);
            string word;
            while(iss >> word){
                if(dict.find(word) != dict.end()){
                    soma += dict[word];
                }
            }
        }
    }
}

