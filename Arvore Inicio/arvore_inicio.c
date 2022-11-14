//Autor: José Izaias da Silva Júnior
//Data: 18/05/2022
//Nome do projeto: Exercício 4.0 - Árvore
//Versão: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    struct no *esq;
    int dado;
    struct no *dir;
}*arvore;

void mostra_arvore(struct no*);
struct no * criar_arvore(int, struct no*, struct no*);
//struct no * insereNo(int, struct no*, struct no*);
struct no* limpaArvore(struct no*);


int main(void){
    int dado;
    struct no *aux;

    arvore = criar_arvore(6, criar_arvore(5,0,0), criar_arvore(7,0,0));
    aux = criar_arvore(2, criar_arvore(1,0,0), criar_arvore(3,0,0));
    arvore = criar_arvore(4, aux, arvore);

    mostra_arvore(arvore);

    printf("..................\n");

    arvore = limpaArvore(arvore);
    mostra_arvore(arvore);


    return 0;
}

void mostra_arvore(struct no *arvore){
    if(!arvore){
        return;
    }
    printf("%d\n", arvore->dado);
    mostra_arvore(arvore->esq);
    mostra_arvore(arvore->dir);
}

struct no * criar_arvore(int dado, struct no *esq, struct no *dir){
    struct no *aux;

    aux = (struct no*) malloc(sizeof(struct no));

    if(!aux){
        printf("Arvore nao alocada.\n");
        return NULL;
    }

    aux->dado = dado;
    aux->esq = esq;
    aux->dir = dir;

    return aux;
};

struct no* limpaArvore(struct no *arvore){
    struct no *aux, *vazio;

    if(arvore->esq != 0){
        aux = limpaArvore(arvore->esq);
        arvore->esq = aux;
    }

    if(arvore->dir != 0){
        aux = limpaArvore(arvore->dir);
        arvore->dir = aux;
    }

    vazio = criar_arvore(0, 0, 0);

    aux = arvore;
    arvore = vazio;
    free(aux);
    return arvore;
}



