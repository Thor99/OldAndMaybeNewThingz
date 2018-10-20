#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string equacao;
    while(getline(cin, equacao)){
        stack<char> pilha;

        for(int i = 0; i < equacao.size(); i++){
            if(equacao[i] == '('){
                pilha.push(equacao[i]);
            } else {
                if(equacao[i] == ')' && pilha.size() != 0){
                    pilha.pop();
                } else if(equacao[i] == ')' && pilha.size() == 0){
                    pilha.push(equacao[i]);
                }
            }
        }

        if(pilha.size() == 0){
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }
}