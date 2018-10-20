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

int main(){
    int nAlunos, nPuzzles;
    vector<int> puzzles;
    vector<int> dp;
    GET2(nAlunos, nPuzzles);

    FOR(i, 0, nPuzzles){
        int valor;
        GET1(valor);

        puzzles.PB(valor);
    }

    sort(puzzles.begin(), puzzles.end());

    FOR(i, 0, nPuzzles - (nAlunos - 1)){
        int val = puzzles[i + (nAlunos - 1)] - puzzles[i];
        dp.PB(val);
    }

    sort(dp.begin(), dp.end());

    printf("%d\n", dp[0]);
}