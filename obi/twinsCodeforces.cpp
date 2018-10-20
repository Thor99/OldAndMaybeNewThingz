#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> coins;
    int totalSum = 0;
    int somaTwin = 0;
    int minCoins = 0;
    int greaterThanDivide;
    int totalCoins;

    scanf("%d", &totalCoins);

    for(int i  = 0; i < totalCoins; i++){
        int value;
        scanf("%d", &value);

        coins.push_back(value);

        totalSum += coins[i];
    }

    greaterThanDivide = (totalSum / 2) + 1;

    sort(coins.rbegin(), coins.rend());

    for(int i = 0; i < totalCoins; i++){
        somaTwin += coins[i];
        minCoins++;

        if(somaTwin >= greaterThanDivide){
            break;
        }
    }

    printf("%d\n", minCoins);
}