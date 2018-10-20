#include <stdio.h>
#include <string.h>
#define N 210
#define N2 101

int main(){
  int notas[N];
  int notasPossiveis[N2];
  int numerosMaisRecorrentes[N2];
  int i, numeroAlunos;
  int maxAppearences = 0;
  int maiorNumero = 0;

  memset(notasPossiveis, 0, sizeof(notasPossiveis));
  memset(numerosMaisRecorrentes, -1, sizeof(numerosMaisRecorrentes));

  scanf("%d\n", &numeroAlunos);

  for(i = 0; i < numeroAlunos; i++){
    scanf("%d", &notas[i]);
  }

  for(i = 0; i < numeroAlunos; i++){ // o indice é a nota, e ve quantas vezes ela aparece
    notasPossiveis[notas[i]]++;
  }

  for(i = 0; i < 101; i++){ // Ve o maior numero de vezes que aparece
    if(notasPossiveis[i] > maxAppearences){
      maxAppearences = notasPossiveis[i];
    }
  }

  for(i = 0; i < 101; i++){ // Ve os numeros que apareceram mais vezes, e põe num array
    if(notasPossiveis[i] == maxAppearences){
      numerosMaisRecorrentes[i] = i;
    }
  }

  for(i = 0; i < 101; i++){ // Dentre os numeros mais recorrentes, pegar o maior
    if(numerosMaisRecorrentes[i] != -1){
      if(numerosMaisRecorrentes[i] > maiorNumero){
        maiorNumero = numerosMaisRecorrentes[i];
      }
    }
  }

  printf("%d\n", maiorNumero);

  return 0;
}
