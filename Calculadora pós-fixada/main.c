//Autor: José Izaias da Silva Júnior
//Data: 03/05/2022
//Nome do projeto: Exercício 4 - Calculadora pós-fixada
//Versão: 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(void){
    struct pilha *p;
    char val[10];
    int result=0, a, b;

    construtor(&p);

    do{
        printf("Digie o valor ou operando: ");
        scanf("%s", val);

        if(strcmp(val, ".") == 0){
            topo(p);
            break;
        }else if(strcmp(val, "+") == 0 || strcmp(val, "-") == 0 || strcmp(val, "*") == 0 || strcmp(val, "/") == 0){
            b = pop(&p);
            a = pop(&p);

            if(strcmp(val, "+") == 0){
                result = a+b;
            }else if (strcmp(val, "-") == 0){
                result = a-b;
            }else if(strcmp(val, "*") == 0){
                result = a*b;
            }else if(strcmp(val, "/") == 0){
                result = a/b;
            }

            push(&p, result);
            topo(p);
        }else{
            result = atoi(val);
            push(&p, result);
        }
    }while(p);

    return 0;
}
