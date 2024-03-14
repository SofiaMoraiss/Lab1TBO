#include <stdio.h>

struct numero {
    int n;
    int marcado;
};

typedef struct numero Numero;

int main (){

    int N;
    scanf( "%d", &N);
    Numero lista[N];
    printf("%d\n", N);

    int i = 2, y=2;
    int pos_i=0;

// formando a lista
    for (int x = 0; y<=N; y++, x++){
        lista[x].n=y;
        lista[x].marcado=0;
    }

    for (int x = 0; x<N-1; x++){
        printf("%d\n", lista[x].n);
    }

    while(1){

    // marcando
        for (int x = pos_i+1; x<N-1; x++){
            if (!(lista[x].n % i)){
                if (!lista[x].marcado){
                    lista[x].marcado=1;
                    printf("%d marcado\n", lista[x].n);
                }
            }
        }

    //processando
        int flag=0;
        for (int x = 0; x<N-1; x++){
            if (lista[x].n>i){
                if (!lista[x].marcado){
                    i=lista[x].n;
                    pos_i=x;
                    flag=1;
                    break;
                }
            }
        }
        if (!flag){
            break;
        }
    }

    printf("PRIMOS:\n");
    for (int x = 0; x<N-1; x++){
        if (!lista[x].marcado){
            printf("%d\n", lista[x].n);
        }
    }

}