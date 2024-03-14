typedef struct numero Numero;

Numero * criaListaCrescente (int N, int valInicial);
void printaLista(Numero * head, int flagSoPrimos);
int achaNovoI(Numero *head, int i);
void marcaLista(int i, Numero * head);
void desalocaLista(Numero *head);