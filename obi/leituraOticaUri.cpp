#include <cstdio>
#include <vector>

using namespace std;

bool anulada(vector<int> vec){
    int countPreto = 0;
    int countBranco = 0;

    for(int i = 0; i < vec.size(); i++){
        if(vec[i] <= 127){
            countPreto++;
        } else {
            countBranco++;
        }
    }

    if(countPreto != 1){ // Não marcou nenhuma ou marcou mais de uma
        return true;
    }

    return false;
}

const char resposta(vector<int> vec){
    if(vec[0] <= 127){
        return 'A';
    }

    else if(vec[1] <= 127){
        return 'B';
    }

    else if(vec[2] <= 127){
        return 'C';
    }

    else if(vec[3] <= 127){
        return 'D';
    }

    else { // E
        return 'E';
    }
}

int main(){
    int nQuestoes;

    while(scanf("%d", &nQuestoes) == 1 && nQuestoes != 0){
        while(nQuestoes--){
            vector<int> quests;

            for(int i = 0; i < 5; i++){
                int valor;
                scanf("%d", &valor);
                quests.push_back(valor);
            }

            if(anulada(quests)){
                printf("*\n");
            } else {
                printf("%c\n", resposta(quests));
            }
        }
    }
}