#include <cstdio>
#include <algorithm>

using namespace std;

int mdc(int x, int y){
    if(max(x, y) % min(x, y) == 0){
        return min(x, y);
    }

    return mdc(y, max(x, y) % min(x, y));
}


int main(){
    int testes;

    scanf("%d", &testes);

    for(int t = 0; t < testes; t++){
        int n1, d1, n2, d2;
        char operacao, inuteis1, inuteis2;
        int resuln1, resuln2, resuld1, resuld2;

        scanf("%d", &n1);
        scanf(" %c", &inuteis1);
        scanf("%d", &d1);
        scanf(" %c", &operacao);
        scanf("%d", &n2);
        scanf(" %c", &inuteis2);
        scanf("%d", &d2);

        if(operacao == '+'){
            resuln1 = (n1 * d2 + n2 * d1);
            resuld1 = d1 * d2;

            if(resuln1 % mdc(resuln1, resuld1) == 0 && resuld1 % mdc(resuln1, resuld1) == 0){
                resuln2 = resuln1 / mdc(resuln1, resuld1);
                resuld2 = resuld1 / mdc(resuln1, resuld1);
            } else {
                resuln2 = resuln1;
                resuld2 = resuld1;
            }
        }

        else if(operacao == '*'){
            resuln1 = n1 * n2;
            resuld1 = d1 * d2;

            if(resuln1 % mdc(resuln1, resuld1) == 0 && resuld1 % mdc(resuln1, resuld1) == 0){
                resuln2 = resuln1 / mdc(resuln1, resuld1);
                resuld2 = resuld1 / mdc(resuln1, resuld1);
            } else {
                resuln2 = resuln1;
                resuld2 = resuld1;
            }
        }

        else if(operacao == '/'){
            resuln1 = n1 * d2;
            resuld1 = n2 * d1;

            if(resuln1 % mdc(resuln1, resuld1) == 0 && resuld1 % mdc(resuln1, resuld1) == 0){
                resuln2 = resuln1 / mdc(resuln1, resuld1);
                resuld2 = resuld1 / mdc(resuln1, resuld1);
            } else {
                resuln2 = resuln1;
                resuld2 = resuld1;
            }
        }

        else { // -
            resuln1 = (n1 * d2 - n2 * d1);
            resuld1 = d1 * d2;

            if(resuln1 % mdc(resuln1, resuld1) == 0 && resuld1 % mdc(resuln1, resuld1) == 0){
                resuln2 = resuln1 / mdc(resuln1, resuld1);
                resuld2 = resuld1 / mdc(resuln1, resuld1);

                if(resuld2 < 0){
                    resuld2 = abs(resuld2);
                    resuln2 = -(abs(resuln2));
                }

            } else {
                resuln2 = resuln1;
                resuld2 = resuld1;
            }
        }

        printf("%d/%d = %d/%d\n", resuln1, resuld1, resuln2, resuld2);
    }
}