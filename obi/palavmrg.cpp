#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

const char ordOrNot(string word){
    int ordIfZero = 0;

    transform(word.begin(), word.end(), word.begin(), ::tolower); // Transforma em minusculo para não ter que lidar com maiusculas

    for(int i = 0; i < word.length() - 1; i++){
        if(word[i] >= word[i + 1]){ // Não segue ordem alfabética
            ordIfZero++;
        }
    }

    if(ordIfZero == 0){
        return 'O';
    } else {
        return 'N';
    }
}

int main(){
    int n;
    string word;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> word;

        cout << word + ": " + ordOrNot(word) << endl;
    }

    return 0;
}
