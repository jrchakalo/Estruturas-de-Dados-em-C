//Autor: Jos� Izaias da Silva J�nior
//Data: 26/05/2022
//Nome do projeto: Exerc�cio 4.1 - �rvore Ordenada
//Vers�o: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrura da �rvore.
struct no{
    struct no *esq;
    int dado;
    struct no *dir;
}*arvore;

//fun��es do programa.
void mostra_arvore(struct no*);
void mostra_arvoreOrdenado(struct no*);
struct no * criar_arvore(int, struct no*, struct no*);
struct no * insereNo(int, struct no*);
int altura(struct no*);
int contaNo(struct no*);
int ehBalanceada(struct no*);
struct no* limpaArvore(struct no*);

///MAIN

//teste de diferentes �rvores no main.
int main(void){
    int alt;

    arvore = criar_arvore(10, 0, 0);
    arvore = insereNo(5, arvore);
    arvore = insereNo(20, arvore);
    arvore = insereNo(3, arvore);
    arvore = insereNo(7, arvore);
    arvore = insereNo(13, arvore);
    arvore = insereNo(40, arvore);


    printf("Os valores da arvore sao: \n");
    mostra_arvore(arvore);
    printf("..................\n");
    printf("A arvore ordenada eh: \n");
    mostra_arvoreOrdenado(arvore);
    printf("..................\n");

    alt = altura(arvore);
    printf("A altura da arvore eh: %d\n", alt);

    printf("..................\n");

    alt = contaNo(arvore);
    printf("Essa arvore tem %d nos.\n", alt);

    printf("..................\n");

    printf("Essa arvore eh balanceada? ");
    alt = ehBalanceada(arvore);
    if(alt == 1){
        printf("Sim!\n");
    }else{
        printf("Nao!\n");
    }

    printf("..................\n");

    printf("Limpando arvore...\n");
    printf("Os valores da arvore sao: \n");
    arvore = limpaArvore(arvore);
    mostra_arvoreOrdenado(arvore);

    printf("..................\n");
    puts("");
    printf("Inserindo nova arvore...\n");
    arvore = criar_arvore(1, 0, 0);
    arvore = insereNo(2, arvore);
    arvore = insereNo(3, arvore);
    arvore = insereNo(4, arvore);
    arvore = insereNo(5, arvore);
    arvore = insereNo(6, arvore);
    arvore = insereNo(7, arvore);
    printf("Os valores da arvore sao: \n");
    mostra_arvore(arvore);
    printf("..................\n");
    printf("A arvore ordenada eh: \n");
    mostra_arvoreOrdenado(arvore);
    printf("..................\n");

    alt = altura(arvore);
    printf("A altura da arvore eh: %d\n", alt);

    printf("..................\n");

    alt = contaNo(arvore);
    printf("Essa arvore tem %d nos.\n", alt);

    printf("..................\n");

    printf("Essa arvore eh balanceada? ");
    alt = ehBalanceada(arvore);
    if(alt == 1){
        printf("Sim!\n");
    }else{
        printf("Nao!\n");
    }

    printf("..................\n");

    printf("Limpando arvore...\n");
    printf("Os valores da arvore sao: \n");
    arvore = limpaArvore(arvore);
    mostra_arvoreOrdenado(arvore);

    printf("..................\n");
    puts("");
    printf("Inserindo nova arvore...\n");
    arvore = criar_arvore(4, 0, 0);
    arvore = insereNo(2, arvore);
    arvore = insereNo(1, arvore);
    arvore = insereNo(3, arvore);
    arvore = insereNo(6, arvore);
    arvore = insereNo(5, arvore);
    arvore = insereNo(7, arvore);
    printf("Os valores da arvore sao: \n");
    mostra_arvore(arvore);
    printf("..................\n");
    printf("A arvore ordenada eh: \n");
    mostra_arvoreOrdenado(arvore);
    printf("..................\n");

    alt = altura(arvore);
    printf("A altura da arvore eh: %d\n", alt);

    printf("..................\n");

    alt = contaNo(arvore);
    printf("Essa arvore tem %d nos.\n", alt);

    printf("..................\n");

    printf("Essa arvore eh balanceada? ");
    alt = ehBalanceada(arvore);
    if(alt == 1){
        printf("Sim!\n");
    }else{
        printf("Nao!\n");
    }

    printf("..................\n");

    printf("Limpando arvore...\n");
    printf("Os valores da arvore sao: \n");
    arvore = limpaArvore(arvore);
    mostra_arvoreOrdenado(arvore);

    return 0;
}

///IMPLEMENTA��ES

//mostra os valores da �rvore conforme inseridos.
void mostra_arvore(struct no *arvore){
    if(!arvore){
        return;
    }
    printf("%d\n", arvore->dado);
    mostra_arvore(arvore->esq);
    mostra_arvore(arvore->dir);
}

//mostra os valores da �rvore ordenados.
void mostra_arvoreOrdenado(struct no *arvore){
    if(!arvore){
        return;
    }
    mostra_arvoreOrdenado(arvore->esq);
    printf("%d\n", arvore->dado);
    mostra_arvoreOrdenado(arvore->dir);
}

//cria uma �rvore a parir de tr�s refer�ncias.
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

//insere ordenado na �rvore.
struct no * insereNo(int dado, struct no *raiz){
    if(!raiz){
        struct no *aux = (struct no*) malloc (sizeof(struct no));
        if(!aux){
            printf("Arvore nao alocada.");
            return 0;
        }
        aux->dado = dado;
        aux->esq = 0;
        aux->dir = 0;
        return aux;
    }else{
        //percorre at� a folha correspondente.
        //se o dado inserido for menor que o do n� adiciona a esquerda, se for maior adiciona a direita.
        if(dado < raiz->dado){
            raiz->esq = insereNo(dado, raiz->esq);
        }else{
            raiz->dir = insereNo(dado, raiz->dir);
        }
    }
}

//calcula a altura da �rvore a partir das folhas.
int altura(struct no *raiz){
    int x, y;

    if(raiz == 0){
        return 0;
    }

    //para chegar at� as folhas.
    x = altura(raiz->esq);
    y = altura(raiz->dir);
    if(x > y){
        return 1+x;
    }else{
        return 1+y;
    }

}

//conta a quantidade de n�s de uma �rvore.
int contaNo(struct no *raiz){
    int x, y;

    if(!raiz){
        return 0;
    }

    //percorre at� a folha e soma 1 nas n�o nulas.
    x = altura(raiz->esq);
    if(x){
        x = x+1;
    }
    y = altura(raiz->dir);
    if(y){
        y = y+1;
    }

    //se a �rvore tiver lados desiguais:
    if(x != y){
        return x+y;
    }

    //se n�o:
    return x+y+1;
}

//verifica se a �rvore � balanceada.
int ehBalanceada(struct no *raiz){
    int x, y;

    if(raiz == 0){
        return 0;
    }

    x = altura(raiz->esq);
    y = altura(raiz->dir);

    if(x == y || x == y-1 || y == x-1){
        return 1;
    }else{
        return 0;
    }
}

//limpa a �rvore
struct no* limpaArvore(struct no *arvore){
    struct no *aux, *vazio;

    //percorre at� a folha.
    if(arvore->esq != 0){
        aux = limpaArvore(arvore->esq);
        arvore->esq = aux;
    }

    if(arvore->dir != 0){
        aux = limpaArvore(arvore->dir);
        arvore->dir = aux;
    }

    //ponteiro vazio, para ter algo para apontar.
    vazio = criar_arvore(0, 0, 0);

    //libera��o da folha.
    aux = arvore;
    arvore = vazio;
    free(aux);
    return arvore;
}



