#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

//Tipo estruturado para pilha
struct pilha{
    int dado;
    struct pilha *prox;
};

void push(struct pilha **p, int dado);
int pop(struct pilha **p);
void topo(struct pilha *p);
void construtor(struct pilha **p);
void destrutor(struct pilha **p);

//Inser��o de elemento na pilha
void push(struct pilha **p, int dado){
    struct pilha *aux;

    //construtor(&aux);
    aux = (struct pilha *) malloc (sizeof(struct pilha));
    //Verifica se a pilha foi alocada
    if(!aux){
        printf("Pilha n�o alocada!\n");
        return;
    }
    /*printf("Insira o numero: ");
    scanf("%d", &aux->dado);*/

    aux->dado = dado;

    //Inser��o
    aux->prox = *p;
    *p = aux;

    return;
}

//Remo��o de elemento da pilha
int pop(struct pilha **p){
    int retorn;

    //Verifica se a pilha est� vazia
    if(!*p){
        return -1;
    }
    struct pilha *aux;

    //Remo��o
    aux = *p;
    *p = aux->prox;
    retorn = aux->dado;
    free(aux);

    return retorn;
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
    int limpa;

    while(*p!=0){
        limpa = pop(p);
    }

    return;
}

#endif // PILHA_H_INCLUDED
