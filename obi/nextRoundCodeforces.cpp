#include <cstdio>

using namespace std;

int main(){
    int participantes[51];
    int nParticipantes, pos;
    int classificados = 0;

    scanf("%d %d", &nParticipantes, &pos);

    for(int i = 1; i <= nParticipantes; i++){
        scanf("%d", &participantes[i]);
    }

    for(int i = 1; i <= nParticipantes; i++){
        if(participantes[i] >= participantes[pos] && participantes[i] > 0){
            classificados++;
        }
    }

    printf("%d\n", classificados);
}