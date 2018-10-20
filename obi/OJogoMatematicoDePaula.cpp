#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    cin.ignore();

    while(n--){
        string str;
        getline(cin, str);

        int primeiro = str[0] - '0';
        int ultimo = str[2] - '0';

        if(primeiro == ultimo){
            printf("%d\n", primeiro * ultimo);
        } else {
            if(isupper(str[1])){
                printf("%d\n", -primeiro + ultimo);
            } else {
                printf("%d\n", primeiro + ultimo);
            }
        }
    }
}