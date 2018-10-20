#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <map>
#include <sstream>

#define GET1(a) scanf("%d", &a);
#define GET2(a, b) scanf("%d %d", &a, &b);
#define GET3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define FOR(i, x, n) for(int i = x; i < (int) (n); ++i)
#define PB push_back

using namespace std;

vector<int> arr;
vector<int> dp;

int longestNonDecreasingSubsequence(int tam){
    if(tam == 1){
        return 1;
    } else {
        vector<int> dp;
        dp.reserve(tam);

        FOR(i, 0, tam){
            dp.PB(1);
        }

        int longest = 1;

        FOR(i, 1, tam){
            FOR(j, i - 1, i){
                if(arr[i] >= arr[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    longest = max(longest, dp[i]);
                }
            }
        }

        return longest;
    }
}

int main(){
    int n;
    GET1(n);
    arr.reserve(n);

    FOR(i, 0, n){
        int valor;
        GET1(valor);

        arr.PB(valor);
    }

    printf("%d\n", longestNonDecreasingSubsequence(n));
}