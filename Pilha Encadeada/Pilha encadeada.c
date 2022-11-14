//Autor: José Izaias da Silva Júnior
//Data: 28/04/2022
//Nome do projeto: Exercício 3.2 - Pilha Encadeada
//Versão: 1.0

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

//Inserção de elemento na pilha
void push(struct pilha **p){
    struct pilha *aux;

    construtor(&aux);
    aux = (struct pilha *) malloc (sizeof(struct pilha));
    //Verifica se a pilha foi alocada
    if(!aux){
        printf("Pilha não alocada!\n");
        return;
    }
    printf("Insira o numero: ");
    scanf("%d", &aux->dado);

    //Inserção
    aux->prox = *p;
    *p = aux;

    return;
}

//Remoção de elemento da pilha
void pop(struct pilha **p){

    //Verifica se a pilha está vazia
    if(!*p){
        return;
    }
    struct pilha *aux;

    //Remoção
    aux = *p;
    *p = aux->prox;
    free(aux);

    return;
}

//Impressão do elemento que está no topo da pilha
void topo(struct pilha *p){

    //Verifica se a pilha está vazia
    if(!p){
        printf("Pilha vazia!\n");
        return;
    }

    //Impressão
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
