#include <stdio.h>

int main(){
  int nTestes, nFeedbacks, i, x;
  int feedback;

  scanf("%d", &nTestes);

  for(i = 0; i < nTestes; i++){
    scanf("%d", &nFeedbacks);

    for(x = 0; x < nFeedbacks; x++){
      scanf("%d", &feedback);

      if(feedback == 1){
        printf("Rolien\n");
      }

      else if(feedback == 2){
        printf("Naej\n");
      }

      else if(feedback == 3){
        printf("Elehcim\n");
      }

      else{
        printf("Odranoel\n");
      }
    }
  }
  return 0;
}
