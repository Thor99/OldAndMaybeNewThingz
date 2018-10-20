#include <cstdio>
#define MAX 100001 // Máximo de elementos é 100000

int pai[MAX]; // pai[i] = pai do elemento i.
int peso[MAX]; // peso[i] = Distância de i para o descendente do elemento i que está mais longe dele.
int quantidade[MAX]; // quantidade[i] = Quantidade de descendentes que o patriarca i tem.

// Funções do union-find

// função find: retorna o patriarca de um elemento x
int find(int x){
    if(pai[x] == x){ // Se X é o patriarca, retorna ele mesmo
        return x;
    } else {
        // Se não, devo olhar o patriarca de seu pai.
        return pai[x] = find(pai[x]);
        // Salva o valor do patriarca de seu pai em pai[x], otimizando o código para evitar chamadas repetidas.
    }
}

// função join: faz a união dos conjuntos dos elementos x e y
void join(int x, int y){
    // como só vamos unir os patriarcas só precisamos trabalhar com eles
    // e fazemos cada um dos elementos receber o valor de sue patriarca
	x = find(x);
	y = find(y);

	// agora x e y são os patriarcas dos conjuntos que desejamos unir

	// se eles forem o mesmo patriarca
	if(x == y) return; // então os conjuntos já estão unidos e retornamos

	// O patriarca com peso menor será o filho do patriarca com peso maior.
	if(peso[x] < peso[y]){
        pai[x] = y; // faço x ser filho do y
        quantidade[y] += quantidade[x]; // e atualizo o número de descendentes de y

        // Não precisa atualizar o peso, pois o peso[y] > peso[x]
    }

	if(peso[x] > peso[y]){
        pai[y] = x; // faço y ser filho do x
        quantidade[x] += quantidade[y]; // e atualizo o número de descendentes de x

        // Não precisa atualizar o peso, pois o peso[x] > peso[y]
    }

	// se os dois tiverem o mesmo peso
	if(peso[x] == peso[y]){

		// escolho um qualquer para ser o novo patriarca
		pai[x] = y;

		// e guardo que seu peso aumentará um uma unidade
		peso[y]++;

        // e atualizo o seu número de descendentes
        quantidade[y] += quantidade[x];
	}
}

int main(){
    int nElementos, nOperacoes;
    scanf("%d %d", &nElementos, &nOperacoes);

    // inicializo todos os elementos como pais de si mesmos.
    for(int i = 1; i <= nElementos; i++){
        pai[i] = i;
        quantidade[i] = 1;
    }

    for(int i = 0; i < nOperacoes; i++){
        char operacao;
        int el1, el2;

        scanf(" %c %d %d", &operacao, &el1, &el2);

        // Se a operação for 'F', faz a fusão entre el1 e el2
        // Se a operação for 'Q', verifica o número de elementos do conjunto de el1 e el2.
        // Se não, verifica se eles pertencem ao mesmo conjunto.

        if(operacao == 'F'){
            join(el1, el2);
        }

        else if(operacao == 'Q'){
            printf("EL1: %d\n", quantidade[el1]);
            printf("EL2: %d\n", quantidade[el2]);
        }

        else {
            if(find(el1) == find(el2)){
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
    }
}