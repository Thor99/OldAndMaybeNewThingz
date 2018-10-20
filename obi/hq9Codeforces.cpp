#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    bool printa = false;
    string str;
    getline(cin, str);

    int tam = str.size();

    for(int i = 0; i < tam; i++){
        if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9'){
            printa = true;
            break;
        }
    }

    // if printa == true -> YES, else -> NO
    printa ? printf("YES\n") : printf("NO\n");
}