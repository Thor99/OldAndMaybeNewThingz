#include <iostream>
#include <unordered_set>

using namespace std;

/*
-Armazena valores, e para buscar voce usa o próprio valor como chave.

-Valores são unicos no set.

-inserir, remover, buscar: O(1)
*/

int main(){
    unordered_set<int> seti;
    seti.insert(1);
    seti.insert(1);
    seti.insert(2);
    seti.insert(1);
    seti.insert(3);
    seti.erase(3);

    if(seti.count(1)){
        cout << "1 esta aqui\n";
    }

    for(unordered_set<int>::iterator it = seti.begin(); it != seti.end(); ++it)
    {
        cout << *it << endl;
    }
}