#include <cstdio>

int main(){
    int nQuestoes;
    int count = 0;
    scanf("%d", &nQuestoes);

    for(int i = 0; i < nQuestoes; i++){
        int countUm = 0;
        for(int j = 0; j < 3; j++){
            int teammate;
            scanf("%d", &teammate);

            if(teammate == 1){
                countUm++;
            }
        }

        if(countUm >= 2){
            count++;
        }
    }

    printf("%d\n", count);
}