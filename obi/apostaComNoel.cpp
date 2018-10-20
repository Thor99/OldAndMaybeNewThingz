#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int mdc(int x, int y){
    int maior = max(x, y);
    int menor = min(x, y);

    if(maior % menor == 0){
        return menor;
    }

    return mdc(menor, maior % menor);
}

int main(){
    int n1, n2;
    vector<int> mdcs;
    while(scanf("%d %d", &n1, &n2) != EOF){
        int resultMdc = mdc(n1, n2);

        mdcs.push_back(resultMdc);

        if(resultMdc > 5){
            printf("Noel\n");
        } else {
            printf("Gnomos\n");
        }
    }

    reverse(mdcs.begin(), mdcs.end());

    for(int i = 0; i < mdcs.size(); i++){
        printf("%d ", mdcs[i]);
    }

    printf("\n");
}