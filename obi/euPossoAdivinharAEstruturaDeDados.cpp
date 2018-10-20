#include <cstdio>
#include <queue> // Fila e Heap
#include <stack> // Pilha

using namespace std;

int main(){
	int nComandos;

	while(scanf("%d", &nComandos) != EOF && nComandos != 0){ // Le até fim do arquivo
		stack<int> pilha;
		queue<int> fila;
		priority_queue<int> heap;

		int comando, valorOuRetorno;
		int isPilha=1, isFila=1, isHeap=1; // De começo, assumimos que são as tres estruturas 

		for(int i = 0; i < nComandos; ++i){
			scanf("%d %d", &comando, &valorOuRetorno);

			if(comando == 1){ // Adiciona algo nas estruturas
				pilha.push(valorOuRetorno);
				fila.push(valorOuRetorno);
				heap.push(valorOuRetorno);
			} else { // Remove algo das estruturas
				if(pilha.top() == valorOuRetorno){ // O retorno foi o esperado, tira da pilha e continua.
					pilha.pop();
				} else { // O retorno não foi o esperado, assumimos que não pode ser mais uma pilha.
					isPilha = 0;
				}

				if(fila.front() == valorOuRetorno){ // O retorno foi o esperado, tira da fila e continua.
					fila.pop();
				} else { // O retorno não foi o esperado, assumimos que não pode ser mais uma fila.
					isFila = 0;
				}

				if(heap.top() == valorOuRetorno){ // O retorno foi o esperado, tira da heap e continua.
					heap.pop();
				} else { // O retorno não foi o esperado, assumimos que não pode ser mais uma heap.
					isHeap = 0;
				}
			}
		}

		if((isPilha + isFila + isHeap) == 0){ // Não é nenhuma das tres
			printf("impossible\n");
		} else if((isPilha + isFila + isHeap) > 1){ // Pode ser mais de uma 
			printf("not sure\n");
		} else { // É uma das tres
			if(isPilha == 1){ // É uma pilha
				printf("stack\n");
			} else if(isFila == 1){ // É uma fila
				printf("queue\n");
			} else { // É uma heap
				printf("priority queue\n");
			}
		}
	}
}
