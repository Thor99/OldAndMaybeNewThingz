#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    map<int, pair<char, int> > quebraCabeca; // (numeroEsquerda, (letra, numeroDireita))
    for(int i = 0; i < t; ++i)
    {
        int esquerda, direita;
        char letra;
        cin >> esquerda >> letra >> direita;
        quebraCabeca[esquerda] = make_pair(letra, direita);
    }
    int numeroAProcurar = 0;
    for(int i = 0; i < t; ++i)
    {
        map<int, pair<char, int> >::iterator it = quebraCabeca.find(numeroAProcurar);
        cout << (*it).second.first;
        numeroAProcurar = (*it).second.second;
    }

    cout << endl;
}
