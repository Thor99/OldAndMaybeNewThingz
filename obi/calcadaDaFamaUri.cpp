#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > cameras; // (ini, fim)
int tam, nCameras, nEstrelas, teste=1;

int busca_bin(int valor){
    int ini = 0, fim = nCameras-1;

    while(ini <= fim){
        int meio = (ini + fim) / 2;

        if(valor >= cameras[meio].first && valor <= cameras[meio].second){
            return meio;
        }


        else if(valor > cameras[meio].second){
            ini = meio + 1;
        }

        else { // valor < cameras[meio].first
            fim = meio - 1;
        }
    }

    return -1;
}

int main(){
    int testes;
    scanf("%d", &testes);

    while(testes--){
        int camerasCobertas=0;

        scanf("%d %d", &tam, &nCameras);

        cameras.reserve(nCameras);

        for(int i = 0; i < nCameras; i++){
            int ini, fim;
            scanf("%d %d", &ini, &fim);

            cameras.push_back(make_pair(ini, fim));
        }

        sort(cameras.begin(), cameras.end());

        scanf("%d", &nEstrelas);

        for(int i = 0; i < nEstrelas; i++){
            int pos;
            scanf("%d", &pos);

            if(busca_bin(pos) != -1){
                camerasCobertas++;
            }
        }

        printf("Caso #%d: %d\n", teste, camerasCobertas);

        teste++;
        cameras.clear();
    }
}