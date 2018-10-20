#include <iostream>
#include <set>

using namespace std;

/*
-Armazena valores, e para buscar voce usa o próprio valor como chave.

-Valores são unicos no set.

-Objetivo: saber se um número esta no conjunto ou não

-inserir, remover, buscar: O(log n)
*/

int main()
{
    set<int> seti;
    seti.insert(1);
    seti.insert(1);
    seti.insert(2);
    seti.insert(1);
    seti.insert(3);
    seti.erase(3);

    if(seti.count(1)){
        cout << "1 esta aqui\n";
    }

    for(set<int>::iterator it = seti.begin(); it != seti.end(); ++it)
    {
        cout << *it << endl;
    }
}