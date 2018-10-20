#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    while(getline(cin, word)){
        int tam = word.size();
        int estado = 0;

        /* Fazemos um padrão para sempre que o estado for par, trocar por maiuscula, e se for impar, minuscula.
        Com isso, ao final, teremos uma sentença dançante. */

        for(int i = 0; i < tam; i++){
            // Ve se é uma letra
            if(isalpha(word[i])){
                if(estado % 2 == 0){ // Transforma a letra em maiuscula
                    word[i] = toupper(word[i]);
                } else { // Transforma a letra em minuscula
                    word[i] = tolower(word[i]);
                }

                estado++;
            }
        }

        cout << word << endl;
    }
}