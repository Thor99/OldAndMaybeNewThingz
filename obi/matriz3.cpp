#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
  string produto;
  int quant;
  float matriz[4][1];

  matriz[0][0] = 5.30;
  matriz[1][0] = 6.00;
  matriz[2][0] = 3.20;
  matriz[3][0] = 2.50;

  cin >> produto;
  cin >> quant;

  if(produto == "Arroz"){
    printf("%.2f\n", matriz[0][0] * quant);
  }

  else if(produto == "Feijao"){
    printf("%.2f\n", matriz[1][0] * quant);
  }

  else if(produto == "Trigo"){
    printf("%.2f\n", matriz[2][0] * quant);
  }

  else if(produto == "Sal"){
    printf("%.2f\n", matriz[3][0] * quant);
  }

  return 0;
}
