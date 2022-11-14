#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "lista.h"

void exibeMenu(){
    int op;
    int result;
    int n=0;
    int lc=0;
    int sob=0;
    struct lista *l;

    do{
        printf("\t\t Bem Vindo\n");
        printf("\t Ao administrador de lista\n");
        puts("");

        printf("\t O que deseja fazer?\n");
        puts("");

        printf("\t <1> Criar uma lista.\n");
        printf("\t <2> Adicionar um valor ao fim da lista.\n");
        printf("\t <3> Remover o ultimo valor da lista.\n");
        printf("\t <4> Limpar toda a lista.\n");
        printf("\t <5> Mostrar a lista.\n");
        printf("\t <0> Sair.\n");

        printf("\t Escolha: ");
        scanf("%d", &op);

        puts("");
        puts("");
        switch(op){
            case 0:
                if(lc == 1){
                    free(l->vetor);
                    free(l);
                }
                printf("\tAte Mais!\n");
                n++;
                break;
            case 1:
                if(lc == 0){
                    l = (struct lista *) malloc (sizeof(struct lista));
                    result = criaLista(l);
                    l->vetor = (int *) malloc (l->tamanho*sizeof(int));
                    if(l && l->vetor){
                        printf("\tLista criada com sucesso!\n");
                        lc++;
                        puts("");
                        puts("");
                    }else{
                        printf("\tOcorreu um erro na criação da lista!\n");
                        puts("");
                        puts("");
                    }
                }else{
                    printf("\tJa ah uma lista criada, deseja sobrescrever? <1> Sim <2> Nao \n");
                    printf("\tEscolha: ");
                    scanf("%d", &sob);
                    if(sob == 1){
                        result = criaLista(l);
                        if(result == 1){
                            printf("\tLista sobrescrita com sucesso!\n");
                            puts("");
                            puts("");
                        }
                    }
                }
                break;
            case 2:
                if(lc == 1){
                    result = insereFim(l);
                    if(result == 1){
                        printf("\tValor adicionado com sucesso!\n");
                        puts("");
                        puts("");
                    }else{
                        printf("\tLista cheia!\n");
                        puts("");
                        puts("");
                    }
                }else{
                    printf("\tNao existe uma lista!\n");
                    puts("");
                    puts("");
                }
                break;
            case 3:
                if(lc == 1){
                    result = removeFim(l);
                    if(result == 1){
                        printf("\tValor removido com sucesso!\n");
                        puts("");
                        puts("");
                    }else{
                        printf("\tLista vazia!\n");
                        puts("");
                        puts("");
                    }
                }else{
                    printf("\tNao existe uma lista!\n");
                    puts("");
                    puts("");
                }
                break;
            case 4:
                if(lc == 1){
                    result = limpaLista(l);
                    if(result > 0){
                        printf("\tLista limpa!\n");
                        puts("");
                        puts("");
                    }
                }else{
                    printf("\tNao existe uma lista!\n");
                    puts("");
                    puts("");
                }
                break;
            case 5:
                if(lc == 1){
                    mostraLista(l);
                }else{
                    printf("\tNao existe uma lista!\n");
                    puts("");
                    puts("");
                }
                break;
            default:
                printf("\tOpcao invalida!\n");
                puts("");
                puts("");
                break;
        }

    }while(n==0);
}
#endif // MENU_H_INCLUDED
