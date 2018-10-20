#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int N;

    scanf("%d", &N);

    while(N--){
        float nPessoas;
        float soma = 0.0;
        float mediaDaTurma;
        float quantAcimaDaMedia = 0;
        vector<float> pessoas;

        scanf("%f", &nPessoas);
        for(int i = 0; i < nPessoas; i++){
            float media;
            scanf("%f", &media);

            soma += media;

            pessoas.push_back(media);
        }

        mediaDaTurma = soma / nPessoas;

        for(int i = 0; i < nPessoas; i++){
            if(pessoas[i] > mediaDaTurma){
                quantAcimaDaMedia++;
            }
        }

        printf("%.3f%%\n", (100 * quantAcimaDaMedia) / nPessoas);
    }
}