#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    string line;
    map<string, int> assassinos; // (nome, numero de mortes)
    map<string, int> assassinados; // (nome, inutil)

    cout << "HALL OF MURDERERS\n";

    while(getline(cin, line)){
        string word;
        istringstream iss(line);
        int primeiroOuSegundo = 1;

        while(iss >> word){
            if(primeiroOuSegundo == 1){
                if(assassinados.find(word) == assassinados.end()){ // Se não foi assassinado
                    if(assassinos.find(word) == assassinos.end()){ // Novo assassino
                        assassinos[word] = 1;
                    } else { // Assasino mata mais um
                        assassinos[word]++;
                    }
                }
            } else {
                assassinados[word] = 1;

                if(assassinos.find(word) != assassinos.end()){ // Se ta na lista de assassinos
                    assassinos.erase(word);
                }
            }

            primeiroOuSegundo++;
        }
    }

    map<string, int>::iterator it;
    for(it = assassinos.begin(); it != assassinos.end(); it++){
        cout << (*it).first << " " << (*it).second << "\n";
    }
}