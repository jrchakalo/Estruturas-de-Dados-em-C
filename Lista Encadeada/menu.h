#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "listaencadeada.h"

void exibeMenu(){
    //Variáveis para controle do menu
    int op;
    int result;
    int n=0;
    int lc=0;
    int sob=0;
    //Variável estruturada para lista
    struct dado *l;

    //Menu
    do{
        printf("\t\t Bem Vindo\n");
        printf("\t Ao administrador de lista\n");
        puts("");

        printf("\t O que deseja fazer?\n");
        puts("");

        printf("\t <1> Criar uma lista.\n");
        printf("\t <2> Adicionar um valor ao inicio da lista.\n");
        printf("\t <3> Adicionar um valor ao fim da lista.\n");
        printf("\t <4> Adicionar um valor ordenado a lista.\n");
        printf("\t <5> Remover o primeiro valor da lista.\n");
        printf("\t <6> Remover o ultimo valor da lista.\n");
        printf("\t <7> Remover um valor ordenado da lista.\n");
        printf("\t <8> Mostrar a lista.\n");
        printf("\t <9> Limpar toda a lista.\n");
        printf("\t <0> Sair.\n");

        printf("\t Escolha: ");
        scanf("%d", &op);

        puts("");
        puts("");
        switch(op){
            case 0:
                if(lc == 1){
                    //Limpa a lista e libera struct dado *l antes de fechar o programa.
                    result = limpaLista(&l);
                    free(l);
                }
                printf("\tAte Mais!\n");
                n++;
                break;
            case 1:
                if(lc == 0){
                    result = criaLista(&l);
                    if(result){
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
                    //Da a opção de sobrescrever uma lista.
                    printf("\tJa ah uma lista criada, deseja sobrescrever? <1> Sim <2> Nao \n");
                    printf("\tEscolha: ");
                    scanf("%d", &sob);
                    if(sob == 1){
                        result = criaLista(&l);
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
                    result = insereInicio(&l);
                    if(result == 1){
                        printf("\tValor adicionado com sucesso!\n");
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
                    result = insereFim(&l);
                    if(result == 1){
                        printf("\tValor adicionado com sucesso!\n");
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
                    result = insereOrdenado(&l);
                    if(result == 1){
                        printf("\tValor adicionado com sucesso!\n");
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
                    result = removeInicio(&l);
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
            case 6:
                if(lc == 1){
                    result = removeFim(&l);
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
            case 7:
                if(lc == 1){
                    result = removeOrdenado(&l);
                    if(result == 1){
                        printf("\tValor removido com sucesso!\n");
                        puts("");
                        puts("");
                    }else if(result == 2){
                        printf("\tO numero nao existe na lista!\n");
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
            case 8:
                if(lc == 1){
                    mostraLista(l);
                }else{
                    printf("\tNao existe uma lista!\n");
                    puts("");
                    puts("");
                }
                break;
            case 9:
                if(lc == 1){
                    result = limpaLista(&l);
                    if(result == 1){
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
            default:
                printf("\tOpcao invalida!\n");
                puts("");
                puts("");
                break;
        }

    }while(n==0);
}
#endif // MENU_H_INCLUDED
