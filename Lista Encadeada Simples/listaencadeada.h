#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//Estrutura da lista
struct dado{
    int numero;
    struct dado *prox;
};

//Cria a Lista
int criaLista(struct dado **l){
    *l = 0;

    return 1;
}

//Remove do inicio
int removeInicio(struct dado **l){
    //Verifica se a lista está vazia
    if(!*l){
        return 0;
    }
    struct dado *auxl;
    auxl = *l;
    *l = auxl->prox;
    free(auxl);

    return 1;
}

//Remove do fim
int removeFim(struct dado **l){
    //Verifica se a lista está vazia.
    if(!*l){
        return 0;
    }
    struct dado *auxl, *x1;
    auxl = *l;

    //Se so tem um valor na lista executa a função remove inicio para remover o único elemento.
    if(auxl->prox == 0){
        int val = removeInicio(l);
        return val;
    }

    //Percorre a lista ate o ultimo valor
    while(auxl->prox->prox != 0){
        auxl = auxl->prox;
    }

    //Libera da memoria o ultimo valor da lista.
    x1 = auxl->prox;
    auxl->prox = x1->prox;
    free(x1);

    return 1;
}

//Remove ordenadamente
int removeOrdenado(struct dado **l){
    //Verifica se a lista está vazia.
    if(!*l){
        return 0;
    }
    struct dado *auxl, *x1;
    auxl = *l;
    int num;

    printf("\tInsira o numero que deseja remover: ");
    scanf("%d", &num);

    //Se o numero que se deseja excluir for o primeiro
    //executa a função remove inicio para remover o valor.
    if((*l)->numero == num){
        int val = removeInicio(l);
        return val;
    }

    //Percorre a lista para achar o numero
    while((auxl->prox != 0) && (auxl->prox->numero != num)){
        auxl = auxl->prox;
    }

    //Se o numero constar na lista, faz a remoção, se não, retorna um valor diferente.
    if(auxl->prox != 0){
        x1 = auxl->prox;
        auxl->prox = x1->prox;
        free(x1);
    }else{
        return 2;
    }

    return 1;
}

//Limpa a lista
int limpaLista(struct dado **l){
    while(*l!=0){
        removeInicio(l);
    }

    return 1;
}


//Mostra lista
void mostraLista(struct dado *l){
    int j=1;
    if(!l){
        printf("\tLista vazia!\n");
        puts("");
        puts("");
        return;
    }
    for(struct dado *i = l; i != 0; i = i->prox, j++){
        printf("\tValor numero %d da lista: %d\n", j, i->numero);
    }
    puts("");
}

//Insere no inicio
int insereInicio(struct dado **l){
    struct dado *auxl;

    criaLista(&auxl);
    auxl = (struct dado *) malloc (sizeof(struct dado));
    if(!auxl){
        printf("\tLista não alocada!\n");
        return 0;
    }
    printf("\tInsira o numero: ");
    scanf("%d", &auxl->numero);

    auxl->prox = *l;
    *l = auxl;

    return 1;
}

//Insere no fim
int insereFim(struct dado **l){
    struct dado *auxl, *x1;

    criaLista(&auxl);
    auxl = (struct dado *) malloc (sizeof(struct dado));
    if(!auxl){
        printf("\tLista não alocada!\n");
        return 0;
    }
    printf("\tInsira o numero: ");
    scanf("%d", &auxl->numero);
    auxl->prox = 0;

    //Se a lista estiver vazia, insere no começo.
    if(!*l){
        *l = auxl;
        return 1;
    }

    x1 = *l;
    //Percorre a lista até o ultimo elemento.
    while(x1->prox != 0){
        x1 = x1->prox;
    }
    //Adiciona no ultimo elemento.
    x1->prox = auxl;

    return 1;
}


//Insere ordenadamente
int insereOrdenado(struct dado **l){
    struct dado *auxl, *x1;

    criaLista(&auxl);
    auxl = (struct dado *) malloc (sizeof(struct dado));
    if(!auxl){
        printf("\tLista não alocada!\n");
        return 0;
    }
    printf("\tInsira o numero: ");
    scanf("%d", &auxl->numero);

    //Se o valor inserido for o primeiro ou o menor.
    if((!*l) || (auxl->numero < (*l)->numero)){
        auxl->prox = *l;
        *l = auxl;
        return 1;
    }

    x1 = *l;
    //Se o valor não for nulo ou for maior que o proximo da lista, vamos percorrer a lista.
    while((x1->prox != 0) && (auxl->numero > x1->prox->numero)){
        x1 = x1->prox;
    }
    //Quando o laço for quebrado, encontramos o lugar para inserir o numero.
    auxl->prox = x1->prox;
    x1->prox = auxl;

    return 1;
}

#endif // LISTA_H_INCLUDED
