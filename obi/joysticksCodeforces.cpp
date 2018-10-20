#include <cstdio>
using namespace std;

int main(){
    int j1, j2;
    bool currentJ1 = false, currentJ2 = false;
    int tempo;
    scanf("%d %d", &j1, &j2);

    for(tempo = -1; ; tempo++){
        if((j1 == 0 || j2 == 0) || (j1 == 1 && j2 == 1)){
            break;
        }

        if(tempo == -1){
            if(j1 < j2){
                currentJ1 = true;
            } else {
                currentJ2 = true;
            }
        } else {
            if(currentJ1){
                j1 += 1;
                j2 -= 2;
            } else {
                j2 += 1;
                j1 -= 2;
            }

            if(j1 < j2){
                currentJ1 = true;
                currentJ2 = false;
            } else {
                currentJ2 = true;
                currentJ1 = false;
            }
        }
    }


    printf("%d\n", (tempo == -1) ? 0 : tempo);
}