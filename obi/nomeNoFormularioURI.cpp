#include <iostream>
#include <string>

using namespace std;

int main(){
    string nome;
    getline(cin, nome);
    if(nome.size() <= 80){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}