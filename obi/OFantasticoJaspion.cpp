#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int nTests;
    cin >> nTests;

    while(nTests--){
        map<string, string> dict;
        int nDicionario, nLinhas;
        cin >> nDicionario >> nLinhas;

        for(int i = 0; i < nDicionario; i++){
            string palavra;
            string traducao;

            cin >> palavra;

            cin.ignore();

            getline(cin, traducao);

            dict[palavra] = traducao;
        }

        for(int i = 0; i < nLinhas; i++){
            int primeira = 0;
            string linha;
            string word;
            getline(cin, linha);
            istringstream iss(linha);

            while(iss >> word){
                if(dict.find(word) == dict.end()){
                    if(primeira != 0){
                        cout << " ";
                        cout << word;
                    } else {
                        cout << word;
                    }
                } else {
                    if(primeira != 0){
                        cout << " ";
                        cout << dict[word];
                    } else {
                        cout << dict[word];
                    }
                }
                primeira++;
            }

            if(i != nLinhas -1){
                cout << "\n";
            }
        }

        cout << "\n\n";
    }
}