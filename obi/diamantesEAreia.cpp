#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// Número de diamantes é o mínimo entre o total de '<' e o total de '>'

int main(){
    int N;
    cin >> N;

    while(N--){
        int total = 0;
        string minastr;
        stack<char> pilha;

        cin >> minastr;

        for(int i = 0; i < minastr.size(); i++){
            if(minastr[i] == '<'){
                pilha.push(minastr[i]);
            } else {
                if(minastr[i] == '>' && pilha.size() != 0){
                    if(pilha.top() == '<'){
                        pilha.pop();
                        total++;
                    }
                }
            }
        }

        cout << total << endl;

    }
}