//Autor: Jos� Izaias da Silva J�nior
//Data: 28/04/2022
//Nome do projeto: Exerc�cio 3.2 - Pilha Encadeada
//Vers�o: 1.0

#include <stdio.h>
#include <stdlib.h>

//Tipo estruturado para pilha
struct pilha{
    int dado;
    struct pilha *prox;
};

void push(struct pilha **p);
void pop(struct pilha **p);
void topo(struct pilha *p);
void construtor(struct pilha **p);
void destrutor(struct pilha **p);

//Inser��o de elemento na pilha
void push(struct pilha **p){
    struct pilha *aux;

    construtor(&aux);
    aux = (struct pilha *) malloc (sizeof(struct pilha));
    //Verifica se a pilha foi alocada
    if(!aux){
        printf("Pilha n�o alocada!\n");
        return;
    }
    printf("Insira o numero: ");
    scanf("%d", &aux->dado);

    //Inser��o
    aux->prox = *p;
    *p = aux;

    return;
}

//Remo��o de elemento da pilha
void pop(struct pilha **p){

    //Verifica se a pilha est� vazia
    if(!*p){
        return;
    }
    struct pilha *aux;

    //Remo��o
    aux = *p;
    *p = aux->prox;
    free(aux);

    return;
}

//Impress�o do elemento que est� no topo da pilha
void topo(struct pilha *p){

    //Verifica se a pilha est� vazia
    if(!p){
        printf("Pilha vazia!\n");
        return;
    }

    //Impress�o
    printf("O valor do topo da pilha eh: %d\n", p->dado);
    return;
}

//Construtor da pilha
void construtor(struct pilha **p){
    *p = 0;
}

//Destrutor da pilha
void destrutor(struct pilha **p){
    while(*p!=0){
        pop(p);
    }

    return;
}

int main(void){
    struct pilha *p;

    //Teste dos metodos
    construtor(&p);

    topo(p);

    push(&p);
    push(&p);
    push(&p);

    topo(p);

    pop(&p);

    topo(p);

    destrutor(&p);

    topo(p);

    return 0;
}
