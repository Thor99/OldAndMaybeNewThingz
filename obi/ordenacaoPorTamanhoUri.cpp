#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; i++){
        vector<pair<int, pair<int, string> > > vec; // (tamanho, (posicao, str))
        string str;
        getline(cin, str);

        istringstream ss(str);
        string word;

        int pos = 50;
        while(ss >> word){
            vec.push_back(make_pair(word.size(), make_pair(pos, word)));
            pos--;
        }

        // Sort por tamanho, decrescente, e se houver empate, mantém a posição inicial
        sort(vec.rbegin(), vec.rend());

        int tam = vec.size();
        for(int i = 0; i < tam; i++){
            if(i == tam - 1){
                cout << vec[i].second.second << "\n";
            } else {
                cout << vec[i].second.second << " ";
            }
        }
    }
}