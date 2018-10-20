#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    set<char> letras;
    string str;
    cin >> str;

    int tam = str.size();

    for(int i = 0; i < tam; i++){
        letras.insert(str[i]);
    }

    if(letras.size() % 2 != 0){
        cout << "IGNORE HIM!" << endl;
    } else {
        cout << "CHAT WITH HER!" << endl;
    }
}