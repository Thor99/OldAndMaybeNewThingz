#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int nFuncs, nClientes;
	scanf("%d %d", &nFuncs, nClientes);

	vector<pair<int, int> > funcionarios;
	vector<int> clientes;
	vector<int> tempo;

	for(int i = 1; i <= nFuncs; i++){
		int tempoPorProduto;

		funcionarios.push_back(i, tempoPorProduto);
	}

	for(int i = 0; i < nClientes; i++){
		int nProdutos;
		clientes.push_back(nProdutos);
	}

	for(int i = 0; i < nFuncs; i++){
		tempo.push_back(clientes[i] * funcionarios[i]);
	}

	sort(tempo.begin(), tempo.end()){

	}
}