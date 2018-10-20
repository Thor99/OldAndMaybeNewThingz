#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int nElems;

int lis(int tam){
    int tamLis = 0;

    vector<int> dp(tam);
    fill(dp.begin(), dp.end(), 1);

    for(int i = 1; i < tam; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                tamLis = max(tamLis, dp[i]);
            }
        }
    }

    return tamLis;
}

int main(){
    scanf("%d", &nElems);

    arr.reserve(nElems);

    for(int i = 0; i < nElems; i++){
        int num;
        scanf("%d", &num);

        arr.push_back(num);
    }

    printf("Tamanho da LIS: %d\n", lis(nElems));
}