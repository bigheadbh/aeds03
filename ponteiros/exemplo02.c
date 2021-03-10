#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int item;
    struct Celula * prox;
}Celula;

Celula * novaCelula(int valor){
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->item = valor;
    nova->prox = NULL;
    return nova;
}

typedef struct Lista{
    Celula * primeiro;
    Celula * ultimo;
}Lista;

void inicializar(Lista * lista){
    lista->primeiro = novaCelula(-1);
    lista->ultimo = lista->primeiro;
}

void inserir(Lista *lista, int num){
    lista->ultimo->prox = novaCelula(num);
    lista->ultimo = lista->ultimo->prox;
}

void printLista(Lista *lista){
    Celula * temp = lista->primeiro->prox;
    while(temp != NULL){
        printf("%d \n", temp->item);
        temp = temp->prox;
    }
}

int main(){
    Lista  *lista = (Lista*) malloc(sizeof(Lista));
    printf("%p \t %p\n", lista->primeiro, lista->ultimo);
    inicializar(lista);
    printf("%p \t %p\n", lista->primeiro, lista->ultimo);
    inserir(lista, 10);
    printf("%p \t %p\n", lista->primeiro, lista->ultimo);
    inserir(lista, 5);
    printf("%p \t %p\n", lista->primeiro, lista->ultimo);

    printLista(lista);

    // Pesquisar se existe ou não um elemento na lista????

    return 0;
}