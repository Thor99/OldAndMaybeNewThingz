#include <iostream>
#include <string>

using namespace std;
long long int fat(int n){
    if(n == 0){
        return 1;
    }

    else{
        return n * fat(n - 1);
    }
}

int main(){
    long long int fats[16];
    string str;

    for(int i = 0; i < 16; i++){
        fats[i] = fat(i);
    }

    while(cin >> str && str != "0"){
        int tam = str.size();

        cout << fats[tam] << endl;
    }
}