#include <iostream>
#include <map>

using namespace std;

/*
- Chaves podem se repetir, e valor também.

- Dois tipos de iterador, de chave e de valor.
*/

int main(){
    multimap<string, int> m;
    m.insert(make_pair("thor", 3));
    auto it = m.find("thor");
    cout << "chave: " << (*it).first << endl;
    cout << "valor: " << (*it).second << endl;
}