#include <stdio.h>
#include <string.h>

using namespace std;

int quantidade(char* frase){
  int i = 0;
  int indices[150];
  int num = 0;
  int tam = 0;
  int x;

  memset(indices, 0, sizeof(indices));

  while(frase[i] != '\0'){
    tam++;
    i++;
  }

  for(x = 0; x < tam; x++){
    if(indices[frase[x]] == 0){
      if(frase[x] >= 65 && frase[x] <= 90){
        indices[frase[x]]++;
        indices[frase[x] + 32]++;
        num++;
      }

      else if(frase[x] >= 97 && frase[x] <= 122){
        indices[frase[x]]++;
        indices[frase[x] - 32]++;
        num++;
      }
    }
  }

  return num;
}

int main(){
  int n;
  int i;
  char frase[1001];

  scanf("%d\n", &n);

  for(i = 0; i < n; i++){
    scanf("%[^\n]%*c", frase);

    if(quantidade(frase) == 26){
      printf("frase completa\n");
    }

    else if(quantidade(frase) >= 13 && quantidade(frase) < 26){
      printf("frase quase completa\n");
    }

    else{
      printf("frase mal elaborada\n");
    }
  }

  return 0;
}
