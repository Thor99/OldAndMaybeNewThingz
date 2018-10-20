#include <iostream>
#include <cstdio>
#include <cmath>

/* Tempo do guarda = distancia / vguarda
   Tempo do fugitivo = 12.0 / vfugitivo */


using namespace std;

int main() {
    int d = 0, vf = 0, vg = 0;
    double distancia = 0, tf = 0, tg = 0;

    while(scanf("%d %d %d", &d, &vf, &vg) != EOF){
        distancia = sqrt(12 * 12 + d * d); // Pitagoras
        tf = 12.0 / vf;
        tg = distancia / vg;

        if (tf >= tg){
            cout << "S" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }
}