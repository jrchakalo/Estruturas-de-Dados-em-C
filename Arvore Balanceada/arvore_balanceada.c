//Autor: José Izaias da Silva Júnior
//Data: 03/06/2022
//Nome do projeto: Exercício 4.3 - AVL Simples
//Versão: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrura da árvore.
struct no{
    struct no *esq;
    int dado;
    struct no *dir;
}*arvore;

//funções do programa.
void mostra_arvorePrefix(struct no*);
void mostra_arvoreInfix(struct no*);
void mostra_arvorePosfix(struct no*);
struct no * criar_arvore(int, struct no*, struct no*);
struct no * insereNo(int, struct no*);
int altura(struct no*);
int alturaX(struct no*);
int alturaY(struct no*);
int contaNo(struct no*);
struct no* limpaArvore(struct no*);

///MAIN

//teste de diferentes árvores no main.
int main(void){
    int alt;

    //Árvore balanceada.
    printf("Inserindo nova arvore...\n");
    arvore = criar_arvore(10, 0, 0);
    arvore = insereNo(5, arvore);
    arvore = insereNo(20, arvore);
    arvore = insereNo(3, arvore);
    arvore = insereNo(7, arvore);
    arvore = insereNo(13, arvore);
    arvore = insereNo(40, arvore);


    printf("Os valores da arvore sao: \n");
    mostra_arvorePrefix(arvore);
    printf("..................\n");
    printf("A arvore ordenada eh: \n");
    mostra_arvoreInfix(arvore);
    printf("..................\n");

    alt = altura(arvore);
    printf("A altura da arvore eh: %d\n", alt);

    printf("..................\n");

    alt = contaNo(arvore);
    printf("Essa arvore tem %d nos.\n", alt);

    printf("..................\n");

    printf("Limpando arvore...\n");
    printf("Os valores da arvore sao: \n");
    arvore = limpaArvore(arvore);
    mostra_arvoreInfix(arvore);

    printf("..................\n");
    puts("");

    //Árvore desbalanceada para direita.
    printf("Inserindo nova arvore...\n");
    arvore = criar_arvore(3, 0, 0);
    arvore = insereNo(5, arvore);
    arvore = insereNo(2, arvore);
    arvore = insereNo(7, arvore);
    arvore = insereNo(8, arvore);
    printf("Os valores da arvore sao: \n");
    mostra_arvorePrefix(arvore);
    printf("..................\n");
    printf("A arvore ordenada eh: \n");
    mostra_arvoreInfix(arvore);
    printf("..................\n");

    alt = altura(arvore);
    printf("A altura da arvore eh: %d\n", alt);

    printf("..................\n");

    alt = contaNo(arvore);
    printf("Essa arvore tem %d nos.\n", alt);

    printf("..................\n");

    printf("Limpando arvore...\n");
    printf("Os valores da arvore sao: \n");
    arvore = limpaArvore(arvore);
    mostra_arvoreInfix(arvore);

    printf("..................\n");
    puts("");

    //Árvore desbalanceada para esquerda.
    printf("Inserindo nova arvore...\n");
    arvore = criar_arvore(8, 0, 0);
    arvore = insereNo(6, arvore);
    arvore = insereNo(10, arvore);
    arvore = insereNo(4, arvore);
    arvore = insereNo(2, arvore);
    printf("Os valores da arvore sao: \n");
    mostra_arvorePrefix(arvore);
    printf("..................\n");
    printf("A arvore ordenada eh: \n");
    mostra_arvoreInfix(arvore);
    printf("..................\n");

    alt = altura(arvore);
    printf("A altura da arvore eh: %d\n", alt);

    printf("..................\n");

    alt = contaNo(arvore);
    printf("Essa arvore tem %d nos.\n", alt);

    printf("..................\n");

    printf("Limpando arvore...\n");
    printf("Os valores da arvore sao: \n");
    arvore = limpaArvore(arvore);
    mostra_arvoreInfix(arvore);

    printf("..................\n");

    return 0;
}

///IMPLEMENTAÇÕES

//mostra os valores da árvore na ordem prefixada.
void mostra_arvorePrefix(struct no *arvore){
    if(!arvore){
        return;
    }
    printf("%d\n", arvore->dado);
    mostra_arvorePrefix(arvore->esq);
    mostra_arvorePrefix(arvore->dir);
}

//mostra os valores da árvore na ordem infixada.
void mostra_arvoreInfix(struct no *arvore){
    if(!arvore){
        return;
    }
    mostra_arvoreInfix(arvore->esq);
    printf("%d\n", arvore->dado);
    mostra_arvoreInfix(arvore->dir);
}

//mostra os valores da árvore na ordem posfixada.
void mostra_arvorePosfix(struct no *arvore){
    if(!arvore){
        return;
    }
    mostra_arvoreInfix(arvore->esq);
    mostra_arvoreInfix(arvore->dir);
    printf("%d\n", arvore->dado);
}

//cria uma árvore a parir de três referências.
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

//insere ordenado na árvore.
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
        //percorre até a folha correspondente.
        //se o dado inserido for menor que o do nó adiciona a esquerda, se for maior adiciona a direita.
        if(dado < raiz->dado){
            raiz->esq = insereNo(dado, raiz->esq);
        }else{
            raiz->dir = insereNo(dado, raiz->dir);
        }

        //balanceamento simples.
        if(alturaX(raiz->esq) > alturaY(raiz->dir)+1){
            struct no *aux;

            aux = raiz->esq;
            raiz->esq = aux->dir;
            aux->dir = raiz;
            raiz = aux;
            printf("Balanceado automaticamente...\n");
        }else if(alturaY(raiz->dir) > alturaX(raiz->esq)+1){
            struct no *aux;

            aux = raiz->dir;
            raiz->dir = aux->esq;
            aux->esq = raiz;
            raiz = aux;
            printf("Balanceado automaticamente...\n");
        }
        return raiz;
    }
}

//calcula a altura da árvore a partir das folhas.
int altura(struct no *raiz){
    int x, y;

    if(raiz == 0){
        return 0;
    }

    //para chegar até as folhas.
    x = altura(raiz->esq);
    y = altura(raiz->dir);
    if(x > y){
        return 1+x;
    }else{
        return 1+y;
    }
}

//calcula a altura da árvore a partir da folha esquerda.
int alturaX(struct no *raiz){
    int x;

    if(raiz == 0){
        return 0;
    }

    //para chegar até a folha.
    x = alturaX(raiz->esq);

    return 1+x;
}

//calcula a altura da árvore a partir da folha direita.
int alturaY(struct no *raiz){
    int y;

    if(raiz == 0){
        return 0;
    }

    //para chegar até a folha.
    y = alturaY(raiz->dir);

    return 1+y;
}

//conta a quantidade de nós de uma árvore.
int contaNo(struct no *raiz){
    int x=0, y=0;

    if(!raiz){
        return 0;
    }

    x = contaNo(raiz->esq);
    y = contaNo(raiz->dir);

    return x+y+1;
}

//limpa a árvore
struct no* limpaArvore(struct no *arvore){
    struct no *aux, *vazio;

    //percorre até a folha.
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

    //liberação da folha.
    aux = arvore;
    arvore = vazio;
    free(aux);
    free(arvore);
    return arvore;
}
