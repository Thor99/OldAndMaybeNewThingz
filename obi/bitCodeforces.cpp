#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int variavel=0, nQueries;
    scanf("%d", &nQueries);

    while(nQueries--){
        string str;
        cin >> str;

        if(str.substr(0, 2) == "++" || str.substr(1, 2) == "++"){
            variavel++;
        } else {
            variavel--;
        }
    }

    printf("%d\n", variavel);
}