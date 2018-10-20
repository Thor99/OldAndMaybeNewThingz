#include <iostream>
#include <unordered_map>

using namespace std;

/*
- Usa tabela hash

- O armazenamento é feito usando a função matemática hash:
    - Entrada: chave
    - Saida: Hash (valor numérico)
    - Colisão de hash: função hash retorna o mesmo valor para duas entradas diferentes
        - Se isso ocorrer, a chave vai percorrendo os indices até achar o primeiro indice vazio, e insere ela no indice.
        - Na hora de buscar, irá buscar no indice que já estava ocupado, mas ocorreria o mesmo na hora de inserir, ia andando nos
        indices até achar a chave
-Todas as operações são O(1)
*/

int main()
{
    unordered_map<string, int> m;
    m.insert(make_pair("vitor frango", 666));
    m["sampaio"] = 24;
    cout << m["vitor frango"] << endl;
    cout << m["sampaio"] << endl;
}