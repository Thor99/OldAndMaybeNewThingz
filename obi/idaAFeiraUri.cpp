#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){
    int testes;
    cin >> testes;

    while(testes--){
        map<string, float> produtos; // (produto, preco)
        int nTotalProdutos;
        int nProdutosComprar;
        float total = 0.0;
        cin >> nTotalProdutos;

        for(int i = 0; i < nTotalProdutos; i++){
            string nome;
            float preco;

            cin >> nome >> preco;

            produtos[nome] = preco;
        }

        cin >> nProdutosComprar;

        for(int i = 0; i < nProdutosComprar; i++){
            string produto;
            int quantidade;

            cin >> produto >> quantidade;

            total += produtos[produto] * quantidade;
        }

        printf("R$ %.2f\n", total);
    }
}