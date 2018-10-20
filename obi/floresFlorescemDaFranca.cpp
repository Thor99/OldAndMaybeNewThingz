#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string frase;
    while(getline(cin, frase) && frase != "*"){
        string word;
        stringstream ss(frase);
        vector<string> palavras;
        bool tautograma = true;

        for(int i = 0; ss >> word; i++){ // pega cada palavra da frase e adiciona num vetor
            palavras.push_back(word);
        }

        char letra = tolower(palavras[0][0]);

        for(int i = 0; i < palavras.size(); i++){ // Ve se a primeira letra de todas as palavras são iguais
            if(tolower(palavras[i][0]) != letra){
                tautograma = false;
                break;
            }
        }

        if(tautograma){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}