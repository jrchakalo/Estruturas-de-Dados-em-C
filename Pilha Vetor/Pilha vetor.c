//Autor: Jos� Izaias da Silva J�nior
//Data: 28/04/2022
//Nome do projeto: Exerc�cio 3.1 - Pilha Vetor
//Vers�o: 1.0

#include <stdio.h>
#include <stdlib.h>

//Tipo estruturado para pilha
struct pilha{
    int dado[20];
    int ctrl;
    int tam;
};

void push(struct pilha *p);
void pop(struct pilha *p);
void topo(struct pilha *p);
void construtor(struct pilha *p);
void destrutor(struct pilha *p);

//Inser��o de elemento na pilha
void push(struct pilha *p){
    int valor;

    //Verifi��o se a pilha est� cheia
    if((p->ctrl) == (p->tam-1)){
        printf("Pilha cheia!\n");
        return;
    }

    printf("Digite o valor: ");
    scanf("%d", &valor);

    //Se a pilha estiver vazia
    if(p->ctrl == -1){
        p->dado[0] = valor;
        p->ctrl = p->ctrl+1;
        return;
    }

    //Inser��o
    for(int i=p->ctrl; i >= 0; i--){
        p->dado[i+1] = p->dado[i];
    }

    p->dado[0] = valor;
    p->ctrl = p->ctrl+1;
    return;
}

//Remo��o de elemento pilha
void pop(struct pilha *p){

    //Verifica��o se a pilha est� vazia
    if(p->ctrl == -1){
        printf("Pilha vazia!\n");
        return;
    }

    //Remo��o
    for(int i=0; i<p->ctrl; i++){
        p->dado[i] = p->dado[i+1];
    }
    p->ctrl = p->ctrl - 1;
    return;
}

//Impress�o do elemento que est� no topo da pilha
void topo(struct pilha *p){

    //Verifica��o se a pilha est� vazia
    if(p->ctrl == -1){
        printf("Pilha vazia!\n");
        return;
    }

    //Impress�o
    printf("O valor do topo da pilha eh: %d\n", p->dado[0]);
    return;
}

//Construtor da pilha
void construtor(struct pilha *p){
    p->ctrl = -1;
    p->tam = 20;
}

//Destrutor da pilha
void destrutor(struct pilha *p){
    p->ctrl = -1;
}

int main(void){
    struct pilha p;

    //Teste dos metodos
    construtor(&p);

    topo(&p);

    push(&p);
    push(&p);
    push(&p);

    topo(&p);

    pop(&p);

    topo(&p);

    destrutor(&p);

    topo(&p);

    return 0;
}
