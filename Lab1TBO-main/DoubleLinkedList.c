#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct no {
    int n;
    struct no * prox;
    struct no * ant;
};

typedef struct no no;

void InicializaLista(int N, no * head){
    no * node=head;
    no * next; //= (no *)malloc(sizeof(no));
    for(int i =1; i<=N; i++){
        node->n=i;
        next = node->prox;
        next->ant=node;
        node = next;
    }
}

void ImprimeLista(int N, no * head){
    no * node=head;
    no * next; //= (no *)malloc(sizeof(no));
    for(int i =1; i<=N; i++){
        printf("%d\n", node->n);
        next = node->prox;
        next->ant=node;
        node = next;
    }
}
