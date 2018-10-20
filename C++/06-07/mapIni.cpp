#include <iostream>
#include <map>

using namespace std;

/*
-Map: chave -> valor
    -ex: nome de usario -> telefone

-map utiliza uma arvore binária de busca

-inserir, remover, buscar: O(log n)
*/

int main()
{
    map<string, int> m;
    m.insert(make_pair("vitor frango", 666));
    m["sampaio"] = 24;
    cout << m["vitor frango"] << endl;
    cout << m["sampaio"] << endl;
}