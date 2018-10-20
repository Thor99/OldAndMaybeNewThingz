#include <cstdio>

int main(){
  int nLeituras, capacidadeMaxima;
  int nPessoas=0;
  bool ultrapassou=false;

  scanf("%d %d", &nLeituras, &capacidadeMaxima);

  for(int i = 0; i < nLeituras; i++){
    int sairam, entraram;
    scanf("%d %d", &sairam, &entraram);

    nPessoas += entraram;
    nPessoas -= sairam;

    if(nPessoas > capacidadeMaxima){
      ultrapassou = true;
    }
  }

  if(ultrapassou){
    printf("S");
  } else {
    printf("N");
  }
}
