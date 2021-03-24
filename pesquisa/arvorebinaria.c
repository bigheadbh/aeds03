#include <stdlib.h>
#include <stdio.h>

typedef struct Registro {
    long Chave;
    int idade;
} Registro;

typedef struct No{
    Registro Reg;
    struct No* Esq;
    struct No* Dir;
} No;


void Pesquisa(Registro *x, No *p){
    if (p == NULL){
        printf("Erro : Registro nao esta presente na arvore\n");
        return;
    }
    if (x->Chave < p->Reg.Chave) {
        Pesquisa(x, p->Esq);
        return;
    } else if (x->Chave > p->Reg.Chave){ 
        Pesquisa(x, p->Dir);
    } else {
        *x = p->Reg;
    }
}

void Insere(Registro x, No **p) {
    if (*p == NULL) {
        *p = (No*)malloc(sizeof(No));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave){
        Insere(x, &(*p)->Esq);
        return;
    } else if (x.Chave > (*p)->Reg.Chave){
        Insere(x, &(*p)->Dir);
    } else {
        printf("Erro : Registro ja existe na arvore\n");
    }
}

void Antecessor(No *q, No **r)
{
    if ((*r)->Dir != NULL)
    {
        Antecessor(q, &(*r)->Dir);
        return;
    }
    q->Reg = (*r)->Reg;
    q = *r;
    *r = (*r)->Esq;
    free(q);
}

void Retira(Registro x, No **p)
{
    No* Aux;
    if (*p == NULL)
    {
        printf("Erro : Registro nao esta na arvore\n");
        return;
    }
    if (x.Chave < (*p)->Reg.Chave)
    {
        Retira(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
    {
        Retira(x, &(*p)->Dir);
        return;
    }
    if ((*p)->Dir == NULL)
    {
        Aux = *p;
        *p = (*p)->Esq;
        free(Aux);
        return;
    }
    if ((*p)->Esq != NULL)
    {
        Antecessor(*p, &(*p)->Esq);
        return;
    }
    Aux = *p;
    *p = (*p)->Dir;
    free(Aux);
}

void Central(No *p)
{
    if (p == NULL)
        return;
    Central(p->Esq);
    printf("%ld\n", p->Reg.Chave);
    Central(p->Dir);
}

#define MAX 5

int main(int argc, char *argv[]){
    No *arvore = NULL;
   
    Registro x;

    /* Insere cada chave na arvore e testa sua integridade apos cada insercao */
    for (int i = 0; i < MAX; i++){
        x.Chave = i+1;
        x.idade = 20+i;
        Insere(x, &arvore);
        printf("Inseriu chave: %ld\n\n", x.Chave);
    }

    x.Chave = 5;
    Pesquisa(&x, arvore);
    printf("%d - a idade da chave 5\n", x.idade);

    return 0;
}