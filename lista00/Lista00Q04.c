
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Celula{
    int num;
    struct Celula *prox;
} Celula;

typedef struct Lista{
    Celula *Primeiro, *Ultimo;
} Lista;

Celula *novaCelula(int num){
    Celula *temp = (Celula *)malloc(sizeof(Celula));
    temp->num = num;
    temp->prox = NULL;
    return temp;
}

void inicializar(Lista *l1){
    l1->Primeiro = novaCelula(-1);
    l1->Ultimo = l1->Primeiro;
}

void inserir(Lista *l1, int num){
    l1->Ultimo->prox = novaCelula(num);
    l1->Ultimo = l1->Ultimo->prox;
}

int retirar(Lista *l1){
    int resp = -1;
    if (l1->Primeiro != l1->Ultimo){
        Celula *temp = l1->Primeiro;
        l1->Primeiro = l1->Primeiro->prox;
        temp->prox = NULL;
        resp = l1->Primeiro->num;
    }
    return resp;
}

void printItens(Lista *l1)
{
    Celula *temp = l1->Primeiro->prox;
    while (temp != NULL)
    {
        printf("%d \t", temp->num);
        temp = temp->prox;
    }
}

void intercalaListas(Lista *l1, Lista *l2){
    Lista *l3 = (Lista) malloc(sizof(Lista));

    int num1 = retirar(l1);
    int num2 = retirar(l2);

    while(num1 != -1 && num2 != -1){
        inserir(l3, num1);
        inserir(l3, num2);
        int num1 = retirar(l1);
        int num2 = retirar(l2);
    }

    while(num1 != -1){
        inserir(l3, num1);
        int num1 = retirar(l1);
    }

    while(num2 != -1){
        inserir(l3, num2);
        int num2 = retirar(l2);
    }
}



int main(){
    

    return 0;
}