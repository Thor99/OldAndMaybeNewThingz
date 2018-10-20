#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

/* Ano pode ter mais de 1000 digitos... */

bool bissexto(int ano){
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0){
        return true;
    }

    return false;
}

bool huluculu(int ano){
    if(ano % 15 == 0){
        return true;
    }

    return false;
}

bool bulukulu(int ano){
    if(bissexto(ano) && ano % 55 == 0){
        return true;
    }

    return false;
}

int main(){
    int ano;
    while(scanf("%d", &ano) != EOF){
        queue<string> q;

        if(bissexto(ano)){
            q.push("This is leap year.");
        }

        if(huluculu(ano)){
            q.push("This is huluculu festival year.");
        }

        if(bulukulu(ano)){
            q.push("This is bulukulu festival year.");
        }

        if(q.empty()){
            printf("This is an ordinary year.\n");
        } else {
            while(!(q.empty())){
                cout << q.front() << endl;
                q.pop();
            }
        }

        printf("\n");
    }
}