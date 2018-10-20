#include <stdio.h>
#include <stdlib.h>

struct arv{
    long int valor;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* arv_vazia(){
    return NULL;
}

Arv* insere_ord(Arv* a, int valor)
{
    if (a==arv_vazia())
    {
        a = malloc(sizeof(Arv));
        a->valor = valor;
        a->esq = arv_vazia();
        a->dir = arv_vazia();
        return a;
    }
    if(a->valor > valor)
    {
        a->esq = insere_ord(a->esq,valor);
    }
    else
    {
        a->dir = insere_ord(a->dir,valor);
    }
    return a;
}


long int valor_pai(Arv* a, long int x){
    if(a == arv_vazia()){
        return 0;
    } else {
        if(a->esq != NULL && a->esq->valor == x){
            return a->valor;
        }

        if(a->dir->valor == x && a->dir != NULL){
            return a->valor;
        }

        if(x > a->valor && a->dir != NULL){
            return valor_pai(a->dir, x);
        }

        if(x < a->valor && a->esq != NULL){
            return valor_pai(a->esq, x);
        }
    }
}

int main(){
    Arv* a = arv_vazia();
    long int nValores;
    long int nConsultas;
    long int i, j;
    long int valor;
    long int indice;
    long int valorPai;
    long int arr[100001];
    scanf("%ld", &nValores);

    for(i = 1; i <= nValores; i++){
        scanf("%ld", &arr[i]);

        a = insere_ord(a, arr[i]);

    }

    scanf("%ld", &nConsultas);

    for(j = 0; j < nConsultas; j++){
        scanf("%ld", &indice);

        valorPai = valor_pai(a, arr[indice]);
        printf("%ld ", valorPai);
    }
}