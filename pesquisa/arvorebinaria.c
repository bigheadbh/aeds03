#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

typedef long TipoChave;
typedef struct Registro
{
    TipoChave Chave;
    /* outros componentes */
} Registro;

typedef struct No *Apontador;
typedef struct No
{
    Registro Reg;
    Apontador Esq, Dir;
} No;


void Pesquisa(Registro *x, Apontador *p)
{
    if (*p == NULL)
    {
        printf("Erro : Registro nao esta presente na arvore\n");
        return;
    }
    if (x->Chave < (*p)->Reg.Chave)
    {
        Pesquisa(x, &(*p)->Esq);
        return;
    }
    if (x->Chave > (*p)->Reg.Chave)
        Pesquisa(x, &(*p)->Dir);
    else
        *x = (*p)->Reg;
}

void Insere(Registro x, Apontador *p)
{
    if (*p == NULL)
    {
        *p = (Apontador)malloc(sizeof(No));
        (*p)->Reg = x;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave)
    {
        Insere(x, &(*p)->Esq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
        Insere(x, &(*p)->Dir);
    else
        printf("Erro : Registro ja existe na arvore\n");
}

void Inicializa(Apontador *Dicionario)
{
    *Dicionario = NULL;
}

void Antecessor(Apontador q, Apontador *r)
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

void Retira(Registro x, Apontador *p)
{
    Apontador Aux;
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

void Central(Apontador p)
{
    if (p == NULL)
        return;
    Central(p->Esq);
    printf("%ld\n", p->Reg.Chave);
    Central(p->Dir);
}


#define MAX 10

int main(int argc, char *argv[]){

    No *arvore;
    Registro x;
    int i, n;

    Inicializa(&arvore);

    /* Insere cada chave na arvore e testa sua integridade apos cada insercao */
    for (i = 0; i < MAX; i++){
        x.Chave = i+1;
        Insere(x, &arvore);
        printf("Inseriu chave: %ld\n", x.Chave);
    }
    
    return 0;
}