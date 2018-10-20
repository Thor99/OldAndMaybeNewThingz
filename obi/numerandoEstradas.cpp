#include <cstdio>

int main(){
    int nRuas, nInteiros;
    int teste = 1;

    while(scanf("%d %d", &nRuas, &nInteiros) == 2 && (nRuas + nInteiros) != 0){
        if(nRuas <= nInteiros){
            printf("Case %d: 0\n", teste);
        } else { // nInteiros < nRuas
            if(26 * nInteiros < (nRuas - nInteiros)){
                printf("Case %d: impossible\n", teste);
            } else {
                if(nRuas / nInteiros == 0){
                    printf("Case %d: 1\n", teste);
                } else {
                    if(nRuas % nInteiros == 0){
                        printf("Case %d: %d\n", teste, (nRuas - nInteiros) / nInteiros);
                    } else {
                        printf("Case %d: %d\n", teste, ((nRuas - nInteiros) / nInteiros) + 1);
                    }
                }
            }
        }

        teste++;
    }
}