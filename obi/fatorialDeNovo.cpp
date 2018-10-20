#include <cstdio>

int numeroDeDigitos(int x){
    if(x > 0 && x <= 9){
        return 1;
    }

    else if(x >= 10 && x <= 99){
            return 2;
    }

    else if(x >= 100 && x <= 999){
            return 3;
    }

    else if(x >= 1000 && x <= 9999){
            return 4;
    }

    else {
        return 5;
    }
}

int fat(int n){
    if(n == 0){
        return 1;
    }

    return n * fat(n - 1);
}

int main(){
    int numeroEmACM;
    while(scanf("%d", &numeroEmACM) == 1 && numeroEmACM != 0){
        int fatori = 1;
        long long int numeroBaseDez = 0;
        int digito;
        int digitos = numeroDeDigitos(numeroEmACM);
        for(int i = 0; i < digitos; i++){ // Pega digitos do ultimo até o primeiro
            digito = numeroEmACM % 10;
            numeroEmACM = numeroEmACM / 10;
            numeroBaseDez += digito * fat(fatori);
            fatori++;
        }

        printf("%lld\n", numeroBaseDez);
    }
}