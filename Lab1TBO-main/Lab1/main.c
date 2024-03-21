#include <stdio.h>
#include "primos.h"

typedef struct numero Numero;

int main (){

    int N;
    scanf( "%d", &N);
    int i = 2, y=2;
    int pos_i=0;

// formando a lista
    Numero * lista_head = criaListaCrescente(N, i);

    printaLista(lista_head, 0);

    while(i>=0){

    // marcando
        marcaLista(i, lista_head);

    //processando
        i = achaNovoI(lista_head, i);
    }

    printaLista(lista_head, 1);

    desalocaLista(lista_head);

}