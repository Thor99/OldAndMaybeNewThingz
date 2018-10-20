#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int quant;

	while(scanf("%d", &quant) == 1 && quant != 0){
		float saldoBolsa = 0.0;

		// Max_heap para compras e Min_heap para vendas para a bolsa ter o maior lucro possível
		priority_queue<float> heapCompras;
		priority_queue<float, vector<float>, greater<float> > heapVendas;

		for(int i = 0; i < quant; ++i){
			char tipo;
			float valor;

			scanf(" %c %f", &tipo, &valor); // Dei esse espaço porque os inputs estavam vindo zuados

			if(tipo == 'C'){
				heapCompras.push(valor);

				if(!(heapVendas.empty())){
					if(heapCompras.top() >= heapVendas.top()){ // Pode haver uma transação
						saldoBolsa += abs(heapCompras.top() - heapVendas.top());
						heapCompras.pop(); // Não irá mais participar de transações, remove da heap
						heapVendas.pop(); // Não irá mais participar de transações, remove da heap
					}
				}
			} else {
				heapVendas.push(valor);

				if(!(heapCompras.empty())){ // Pode haver uma transação
					if(heapVendas.top() <= heapCompras.top()){
						saldoBolsa += abs(heapCompras.top() - heapVendas.top());
						heapVendas.pop(); // Não irá mais participar de transações, remove da heap
						heapCompras.pop(); // Não irá mais participar de transações, remove da heap
					}
				}
			}
		}

		printf("%.2f\n", saldoBolsa);
	}
}