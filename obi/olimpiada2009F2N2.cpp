#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Pais{
    int id, ouros, pratas, bronzes;
};

bool comp(Pais p1, Pais p2){
    if(p1.ouros != p2.ouros){
        return p1.ouros > p2.ouros;
    }

    if(p1.pratas != p2.pratas){
        return p1.pratas > p2.pratas;
    }

    if(p1.bronzes != p2.bronzes){
        return p1.bronzes > p2.bronzes;
    }

    return p1.id < p2.id;
}

int main(){
    int nPaises, nModalidades;
    scanf("%d %d", &nPaises, &nModalidades);

    vector<Pais> paises;
    paises.reserve(nPaises + 1);

    for(int i = 1; i <= nPaises; i++){
        Pais pais;
        pais.id = i;
        pais.ouros = 0;
        pais.pratas = 0;
        pais.bronzes = 0;
        paises.push_back(pais);
    }

    for(int i = 0; i < nModalidades; i++){
        int ouro, prata, bronze;
        scanf("%d %d %d", &ouro, &prata, &bronze);

        paises[ouro - 1].ouros += 1;
        paises[prata - 1].pratas += 1;
        paises[bronze - 1].bronzes += 1;
    }

    sort(paises.begin(), paises.end(), comp);

    for(vector<Pais>::iterator it = paises.begin(); it != paises.end(); ++it){
        printf("%d ", (*it).id);
    }
}