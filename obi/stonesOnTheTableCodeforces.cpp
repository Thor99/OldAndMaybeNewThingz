#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int N, count=0;
    string str;

    scanf("%d", &N);
    cin >> str;
    
    for(int i = 1; i < N; i++){
        if(str[i] == str[i - 1]){
            count++;
        }
    }

    printf("%d\n", count);
}