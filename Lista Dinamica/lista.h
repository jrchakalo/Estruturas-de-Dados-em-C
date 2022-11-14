#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//Estrutura da lista
struct lista{
    int ctrl;
    int tamanho;
    int *vetor;
};

//Cria a Lista
int criaLista(struct lista *l){
    int tam=0;

    printf("\tDigite o tamanho da lista que voce quer criar: ");
    scanf("%d", &tam);

    l->ctrl = -1;
    l->tamanho = tam;

    return 1;
}

//Limpa a lista
int limpaLista(struct lista *l){
    l->ctrl = -1;

    return 1;
}

//Mostra lista
void mostraLista(struct lista *l){
    if(l->ctrl!=-1){
        for(int i=0; i<=l->ctrl; i++){
            printf("\tO valor do termo %d eh: %d\n", i+1, l->vetor[i]);
        }
        puts("");
        puts("");
    }else{
        printf("\tA lista esta vazia!\n");
        puts("");
        puts("");
    }
}

//Insere no fim
int insereFim(struct lista *l){
    int valor;

    //Verificação de lista cheia
    if(l->ctrl == l->tamanho-1){
        return 0;
    }

    printf("\tDigite o valor a ser inserido no fim: ");
    scanf("%d", &valor);

    l->vetor[l->ctrl+1] = valor;
    l->ctrl = l->ctrl + 1;

    return 1;
}

//Remove do fim
int removeFim(struct lista *l){

    //Verifica se a lista está vazia
    if(l->ctrl == -1){
        return 0;
    }

    l->ctrl = l->ctrl - 1;

    return 1;
}

#endif // LISTA_H_INCLUDED
