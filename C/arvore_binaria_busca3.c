#include <stdio.h>
#include <stdlib.h>

// Arvore binaria de  busca
// Temos a raiz. Os nós da direita sempre são maiores que a raiz e os da esquerda são menores que a raiz.
// Admitimos que não tem elementos repetidos.
// Se estamos buscando um valor maior que a raiz, percorremos a parte direita.
// Se estamos buscando um valor menor que a raiz, percorremos a parte esquerda.
// Acharemos em até log n da base 2 passos o valor. Ou não acharemos.
// Para inserir um elemento temos que achar o pont de inserção.


struct arv{
    int valor;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv; // Arv é um nó

Arv* arv_vazia(){
    return NULL;
}

Arv* cria_arv(int valor, Arv* esq, Arv* dir){
    Arv* no = malloc(sizeof(Arv));
    no->valor = valor;
    no->esq = esq;
    no->dir = dir;

    return no;
}

void imprime_arv(Arv* a){ // imprime (valor esq dir)
    if(a == arv_vazia()){
        printf("-");
        return;
    }

    printf("(%d ", a->valor);
    imprime_arv(a->esq);
    printf(" ");
    imprime_arv(a->dir);
    printf(")");
}

Arv* destroi_arv(Arv* a){
    if(a != arv_vazia()){
        destroi_arv(a->esq);
        destroi_arv(a->dir);
        free(a);
    }

    return arv_vazia();
}

int busca_arv(Arv* a, int valor){
    if(a == arv_vazia()){
        return 0;
    }

    if(a->valor == valor){
        return 1;
    } else {
        if(busca_arv(a->esq, valor) == 1){
            return 1;
        }
        if(busca_arv(a->dir, valor) == 1){
            return 1;
        }
    }

    return 0;
}

Arv* copia(Arv* a1){
    if(a1 == arv_vazia()){
        return NULL;
    } else{
        return cria_arv(a1->valor, copia(a1->esq), copia(a1->dir));
    }
}

Arv* insere_ord(Arv* a, int valor){
    if(a == arv_vazia()){
        a = malloc(sizeof(Arv));
        a->valor = valor;
        a->esq = arv_vazia();
        a->dir = arv_vazia();
        return a;
    }

    if(a->valor > valor){ // Tem que inserir na subarvore esquerda
        a->esq = insere_ord(a->esq, valor);
    } else{ // Tem que inserir na subarvore direita. (a->valor < valor)
        a->dir = insere_ord(a->dir, valor);
    }
    return a;
}

void imprime_ord(Arv* a){
    if (a != NULL) {
        imprime_ord(a->esq);
        printf("%d\n", a->valor);
        imprime_ord(a->dir);
    }
}

int busca_ord(Arv* a, int valor){
    if(a == arv_vazia()){
        return 0;
    }

    if(a->valor < valor){ // Busca na subarvore direita
        return busca_ord(a->dir, valor);
    }

    else if(a->valor > valor){
        return busca_ord(a->esq, valor);
    }

    else{ // a->valor == valor
        return 1;
    }
}

Arv* retira_ord(Arv* a, int valor){
    if (a == arv_vazia()){
        return NULL;
    }

    else if (a->valor > valor){
        a->esq = retira_ord(a->esq, valor);
    }

    else if (a->valor < valor){
        a->dir = retira_ord(a->dir, valor);
    }
    else {
    /* achou o elemento */
        if (a->esq == arv_vazia() && a->dir == arv_vazia()) { /* elemento sem filhos */
            free (a);
            return arv_vazia();
        }

        else if (a->esq == arv_vazia()) {
            /* só tem filho à direita */
            Arv* tmp = a;
            a = a->dir;
            free (tmp);
        }

        else if (a->dir == arv_vazia()) {
            /* só tem filho à esquerda */
            Arv* tmp = a;
            a = a->esq;
            free (tmp);
        }

        else{
            /* filhos a direita e a esquerda*/
             Arv* temp = a->esq;
             while(temp->dir != arv_vazia()){
                temp = temp->dir;
             }
             a->valor = temp->valor;
             temp->valor = valor;
             a->esq = retira_ord(a->esq, valor);
        }
    }

    return a;
}


int main(){
    int i;
    Arv* a = arv_vazia();

    for(i = 0; i < 5; i++){
        a = insere_ord(a, rand() % 100);
    }

    a = retira_ord(a, 83);

    imprime_arv(a);
}