#ifndef  FILE_H
#define  FILE_H

#include <stdio.h>
#include <malloc.h>
#include "primos.h"

struct numero {
    int n;
    char marcado;
    struct numero *prox;
};

Numero * criaListaCrescente (int N, int valInicial){
    Numero * head = (Numero *)malloc(sizeof(Numero));

    if (head == NULL){
        printf("Falha ao alocar!\n");
        return NULL;
    }

    head->n=valInicial;
    head->prox = (Numero *)malloc(sizeof(Numero));
    valInicial++;
    Numero * no=head->prox;

    while (valInicial<N){
        no->n=valInicial;
        no->marcado=0;
        no->prox = (Numero *)malloc(sizeof(Numero));
        no=no->prox;
        valInicial++;
    }
    no->n=valInicial;
    no->marcado=0;

    return head;

}

void printaLista(Numero * head, int flagSoPrimos){
    
    Numero *no = head;
    if (!no){
        return;
    }
    if (flagSoPrimos){
        printf("PRIMOS:\n");
        while (no){
            if (!no->marcado){
                printf("%d\n", no->n);
            }
            if (no->prox){
                no=no->prox;
            }
            else {break;}
        }
        return;
    }
    printf("Lista:\n");
    while (no){
        printf("%d\n", no->n);
        if (no->prox){
            no=no->prox;
        }
        else {break;}
    }

}

void desalocaLista(Numero *head){
    Numero *no = head;
    Numero *next = head->prox;
    while (no){
        if (no->prox){
            next=no->prox;
        }
        free(no);
        no = next;
    }
}
void marcaNumero(Numero * no){
    no->marcado=1;
}

int checaMarca(Numero * no){
    return no->marcado;
}

void marcaLista(int i, Numero * head){
    Numero *no = head;
    while (no){
        if (no->n>i){
            if (!(no->n % i)){
                marcaNumero(no);
            }
        }
        if (no->prox){
            no=no->prox;
        }
        else {break;}
    }
}

int achaNovoI(Numero *head, int i){
    Numero *no = head;
    while (no){
        if (no->n>i){
            if (!checaMarca(no)){
                return no->n;
            }
        }
        if (no->prox){
            no=no->prox;
        }
        else {break;}
    }

    return -1; 
}

#endif 