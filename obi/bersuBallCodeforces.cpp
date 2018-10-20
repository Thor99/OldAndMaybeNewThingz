#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int nBoys, nGirls;
    priority_queue<int> boys;
    priority_queue<int> girls;

    scanf("%d", &nBoys);

    for(int i = 0; i < nBoys; i++){
        int valor;
        scanf("%d", &valor);

        boys.push(valor);
    }

    scanf("%d", &nGirls);

    for(int i = 0; i < nGirls; i++){
        int valor;
        scanf("%d", &valor);

        girls.push(valor);
    }

    int counter = 0;

    while(!boys.empty() && !girls.empty()){
        int XY = boys.top();
        int XX = girls.top();

        if(abs(XY - XX) <= 1){
            boys.pop();
            girls.pop();

            counter++;
        } else {
            if(XY > XX){
                boys.pop();
            } else {
                girls.pop();
            }
        }
    }

    printf("%d\n", counter);
}