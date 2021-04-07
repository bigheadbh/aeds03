#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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

/*
 * Escreva um algoritmo para calcular a 
 * altura de um árvore binária
 */
int CalculaAltura(No *p){
    if (p == NULL)
        return -1;
    else {
        int alturaEsq = CalculaAltura(p->Esq);
        int alturaDir = CalculaAltura(p->Dir);
        int altura = (alturaEsq > alturaDir)? alturaEsq: alturaDir;
        return (altura + 1);
    }
}

/*
 * Escreva um algoritmo que conte o número 
 * de nós de uma árvore binária.
 */
int CalculaQtde(No *p){
    if (p == NULL)
        return 0;
    else{
        int qtdeEsq = CalculaQtde(p->Esq);
        int qtdeDir = CalculaQtde(p->Dir);
        int qtde = qtdeEsq + qtdeDir + 1;
        return qtde;
    }
}

/*
 * Escreva um algoritmo que conte o número 
 * de nós folhas de uma árvore binária.
 */

int CalculaQtdeFolhas(No *p){
    if (p == NULL)
        return 0;
    else {
        int qtdeEsq = CalculaQtdeFolhas(p->Esq);
        int qtdeDir = CalculaQtdeFolhas(p->Dir);
        int qtde = qtdeEsq + qtdeDir;
        if(p->Esq == NULL && p->Dir == NULL)
            qtde = qtde + 1;
        return qtde;
    }
}

/*
 * Escreva um algoritmo que determine o 
 * numero de nos internos.
 */
int CalculaQtdeInternos(No *p){
    if (p == NULL)
        return 0;
    else{
        int qtdeEsq = CalculaQtdeInternos(p->Esq);
        int qtdeDir = CalculaQtdeInternos(p->Dir);
        int qtde = qtdeEsq + qtdeDir;
        if (p->Esq != NULL || p->Dir != NULL)
            qtde = qtde + 1;
        return qtde;
    }
}

/*
 * Escreva um algoritmo que determine se uma 
 * árvore binária é completa ou não.
 */
bool isComplete(No *p){
    bool resp = false;
    int folhas = CalculaQtdeFolhas(p);
    int altura = CalculaAltura(p);
    if(pow(2,altura) == folhas)
        resp = true;

    return resp;
}



#define MAX 10

    int
    main(int argc, char *argv[]){
    No *arvore = NULL;
   
    Registro x;
    /* Insere cada chave na arvore e testa sua integridade apos cada insercao */
    /*for (int i = 0; i < MAX; i++){
        x.chave = rand()%100;
        x.idade = 20 + i;
        Insere(x, &arvore);
    }*/

    x.chave = 15;
    x.idade = 20 + rand()%20;
    Insere(x, &arvore);

    x.chave = 18;
    x.idade = 20 + rand() % 20;
    Insere(x, &arvore);

    x.chave = 7;
    x.idade = 20 + rand() % 20;
    Insere(x, &arvore);

    // caminhamento central
    Central(arvore);
    printf("\n");


    // Pesquisa
    /*x.chave = 5;
    Pesquisa(&x, arvore);
    if(x.chave != -1)
        printf("%d - a idade da chave 5\n", x.idade);
    */

    printf("A altura da árvore eh: %d\n", CalculaAltura(arvore));
    printf("A qtde de nos da árvore eh: %d\n", CalculaQtde(arvore));
    printf("A qtde de nos folhas da árvore eh: %d\n", CalculaQtdeFolhas(arvore));
    printf("A qtde de nos internos na árvore eh: %d\n", CalculaQtdeInternos(arvore));

    if(isComplete(arvore)){
        printf("\nArvore eh completa!!!\n");
    } else {
        printf("\nArvore nao eh completa!!!\n");
    }

    return 0;
}