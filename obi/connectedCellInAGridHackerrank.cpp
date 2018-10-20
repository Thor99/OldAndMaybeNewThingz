#include <cstdio>

int vis[10][10]; // Matriz de visitados
int direcoesAdjacentes[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // Manipulações de linhas e colunas pra achar visinhos
int tam;
int matrix[10][10];

void dfs(int i, int j){
  if(vis[i][j] == 1){
    return;
  }

  vis[i][j] = 1;
  tam++; // Achou vizinho

  for(int k = 0; k < 8; ++k){
    int adjI = i + direcoesAdjacentes[k][0]; // Usa o vetor de direcoesAdjacentes pra achar visinhos na diagonal, vertical, horizontal
    int adjJ = j + direcoesAdjacentes[k][1]; // Usa o vetor de direcoesAdjacentes pra achar visinhos na diagonal, vertical, horizontal

    if(matrix[i][j] == matrix[adjI][adjJ]){ // Se o vizinho for 1, roda o dfs nele
      dfs(adjI, adjJ);
    }
  }
}

int main(){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      vis[i][j] = 0;
    }
  }

  int rows, columns;

  scanf("%d", &rows);
  scanf("%d", &columns);

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < columns; ++j){
      int valor;
      scanf("%d", &valor);

      matrix[i][j] = valor;
    }
  }

  int maior = 0;

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < columns; ++j){
      if(matrix[i][j] == 1 && vis[i][j] == 0){ // Não ligar pra 0
        tam = 0; // A cada novo componente, inicializa o tamanho como 0
        dfs(i, j);
        if(tam > maior){ // Tamanho atual é maior que o maior tamanho antigo
          maior = tam;
        }
      }
    }
  }

  printf("%d\n", maior);
}
