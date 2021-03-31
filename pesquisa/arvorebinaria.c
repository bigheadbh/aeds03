#include <stdlib.h>
#include <stdio.h>

typedef struct Registro {
    long chave;
    int idade;
} Registro;

typedef struct No{
    Registro Reg;
    struct No* Esq;
    struct No* Dir;
} No;

void Pesquisa(Registro *x, No *p){
    if (p == NULL){
        (*x).chave = -1;
        printf("Erro : Registro nao esta presente na arvore\n");
        return;
    }else if (x->chave < p->Reg.chave) {
        Pesquisa(x, p->Esq);
        return;
    } else if (x->chave > p->Reg.chave){ 
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
    
    if (x.chave < (*p)->Reg.chave){
#ifdef DEBUG
        printf("(ESQ) chave %ld - valor do no %ld\n", x.chave, (*p)->Reg.chave);
#endif // DEBUG
        Insere(x, &(*p)->Esq);
        return;
    } else if (x.chave > (*p)->Reg.chave){
#ifdef DEBUG
        printf("(DIR) chave %ld - valor do no %ld\n", x.chave, (*p)->Reg.chave);
#endif // DEBUG
        Insere(x, &(*p)->Dir);
    } else {
        printf("Erro : Registro ja existe na arvore\n");
    }
}

void Antecessor(No *q, No **r){
    if ((*r)->Dir != NULL){
        Antecessor(q, &(*r)->Dir);
        return;
    }
    q->Reg = (*r)->Reg;
    q = *r;
    *r = (*r)->Esq;
    free(q);
}

void Retira(Registro x, No **p){
    No* Aux;
    if (*p == NULL){
        printf("Erro : Registro nao esta na arvore\n");
        return;
    }
    if (x.chave < (*p)->Reg.chave){
        Retira(x, &(*p)->Esq);
        return;
    }
    if (x.chave > (*p)->Reg.chave){
        Retira(x, &(*p)->Dir);
        return;
    }

    if ((*p)->Dir == NULL){ // nao tenho filho a direita e posso ter ou não a esquerda.
        Aux = *p;
        *p = (*p)->Esq;
        free(Aux);
        return;
    }
    if ((*p)->Esq != NULL){ // o no tem dois filhos.
        Antecessor(*p, &(*p)->Esq);
        return;
    }
    // nao tem filho a esquerda e tem a direita.
    Aux = *p;
    *p = (*p)->Dir;
    free(Aux);
}

void Central(No *p){
    if (p == NULL)
        return;
    Central(p->Esq);
    printf("%ld\t", p->Reg.chave);
    Central(p->Dir);
}

void PreOrdem(No *p){
    if (p == NULL)
        return;
    PreOrdem(p->Esq);
    PreOrdem(p->Dir);
    printf("%ld\t", p->Reg.chave);
}

void PosOrdem(No *p){
    if (p == NULL)
        return;
    printf("%ld\t", p->Reg.chave);
    PosOrdem(p->Esq);
    PosOrdem(p->Dir);
}

#define MAX 10

int main(int argc, char *argv[]){
    No *arvore = NULL;
   
    Registro x;
    /* Insere cada chave na arvore e testa sua integridade apos cada insercao */
    for (int i = 0; i < MAX; i++){
        x.chave = rand()%100;
        x.idade = 20+i;
        Insere(x, &arvore);
#ifdef DEBUG
        printf("Inseriu chave: %ld\n", x.chave);
        getchar();
#endif // DEBUG
    }

    x.chave = 5;
    Pesquisa(&x, arvore);
    if(x.chave != -1)
        printf("%d - a idade da chave 5\n", x.idade);

    printf("[ ");
    Central(arvore);
    printf(" ]\n");

    printf("[ ");
    PosOrdem(arvore);
    printf(" ]\n");

    printf("[ ");
    PreOrdem(arvore);
    printf(" ]\n");
    return 0;
}