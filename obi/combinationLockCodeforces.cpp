#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int n;
    string um;
    string dois;
    int counter = 0;

    scanf("%d", &n);

    cin >> um;
    cin >> dois;

    for(int i = 0; i < n; i++){
        int first = um[i] - '0';
        int second = dois[i] - '0';

        if(first > second){
            if(first - second > 5){
                counter += (10 + second) - first;
            } else {
                counter += first - second;
            }
        }

        else if(second > first){
            if(second - first > 5){
                counter += (10 + first) - second;
            } else {
                counter += second - first;
            }
        }

        else {
            counter += 0;
        }
    }

    printf("%d\n", counter);
}