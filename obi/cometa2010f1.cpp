#include <cstdio>

int main(){
  int ano;

  scanf("%d", &ano);

  for(int i = ano + 1; ; ++i){
    if((i - 1986) % 76 == 0){
      printf("%d", i);
      break;
    }
  }
}
