#include <stdio.h>

int menoresQue128(int vet[5]){ // Quantas questões com valor de preenchimento < 128
  int quantidade = 0;
  int i;

  for(i = 0; i < 5; i++){
    if(vet[i] < 128){
      quantidade++;
    }
  }

  return quantidade;
}

int menorNumero(int vet[5]){ // O menor valor de preenchimento entre as questoes
  int menorValor = 255;
  int i;

  for(i = 0; i < 5; i++){
    if(vet[i] < menorValor){
      menorValor = vet[i];
    }
  }

  return menorValor;
}

char* resposta(int vet[5], int menor){ // Resposta do problema
  if(vet[0] == menor){
    return "A";
  }

  else if(vet[1] == menor){
    return "B";
  }

  else if(vet[2] == menor){
    return "C";
  }

  else if(vet[3] == menor){
    return "D";
  }

  else {
    return "E";
  }
}
bool anulada(int vet[5]){ // Se não tiver nenhuma marcada ou mais de uma, a resposta é anulada
  if(menoresQue128(vet) == 0 || menoresQue128(vet) > 1){
    return true;
  }

  return false;
}

int main(){
  int questoes[5];
  int n;
  int i, x;
  int menorValor;

  scanf("%d", &n);

  while(n != 0){ // Ate o numero de questoes ser zero, roda
    for(i = 0; i < n; i++){ // Itera pelo numero de questoes
      for(x = 0; x < 5; x++){ // Preenche as questoes
        scanf("%d", &questoes[x]);
      }

      if(anulada(questoes) == false){
        menorValor = menorNumero(questoes);

        printf("%s\n", resposta(questoes, menorValor));

      } else {
        printf("*\n");
      }
    }

    scanf("%d", &n);
  }

  return 0;
}
