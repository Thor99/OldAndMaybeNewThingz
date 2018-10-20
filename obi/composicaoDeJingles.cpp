#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

double calcular(char c){
    if(c == 'W') return 1.00;
	else if(c == 'H') return 0.5;
	else if(c == 'Q') return 0.25;
	else if(c == 'E') return 0.125;
	else if(c == 'S') return 0.0625;
	else if(c == 'T') return 0.03125;
	else return 0.015625;
}

int main(){
    string musica;
    while(true){
        cin >> musica;

        if(musica[0] == '*'){
            break;
        }

        int tam = musica.size();
        int counter = 0;
        double soma = 0;
        for(int i = 0; i < tam; i++){
            if(musica[i] == '/'){
                if(soma == 1.00){
                    counter++;
                    soma = 0;
                }
            } else {
                soma += calcular(musica[i]);
            }
        }

        printf("%d\n", counter);
    }
}