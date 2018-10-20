#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) == 1 && N != 0){
        queue<int> Q;

        for(int i = 1; i <= N; i++){
            Q.push(i);
        }

        printf("Discarded cards: ");
        while(Q.size() >= 2){
            int primeira = Q.front();
            Q.pop();

            int mandaPraBase = Q.front();
            Q.pop();

            Q.push(mandaPraBase);

            if(Q.size() < 2){
                printf("%d", primeira);
            } else {
                printf("%d, ", primeira);
            }
        }

        printf("\n");

        printf("Remaining card: %d\n", Q.front());
    }
}