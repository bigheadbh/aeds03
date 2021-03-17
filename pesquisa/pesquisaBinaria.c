#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define TAM 50

void printVetor(int vetor[]){
    printf("[ ");
    for (int i = 0; i < TAM; i++)
        printf("%i, ", vetor[i]);
    printf(" ]\n\n");
}

void preencheVetorRandom(int vetor[]){
    for(int i=0; i<TAM; i++){
        vetor[i] = rand()%1000;
    }
}

void preencheVetorCrescente(int vetor[]){
    for(int i=0; i<TAM; i++){
        vetor[i] = i;
    }
}

int pesquisaBinaria(int chave, int vetor[], int esq, int dir){
    int meio = (esq+dir)/2;
#ifdef DEBUG
    printf("%d %d %d %d %d\n", chave, vetor[meio], meio, esq, dir);
#endif // DEBUG
    // encontrei o elemento no vetor
    if(vetor[meio] == chave){ 
#ifdef DEBUG
        printf("Encontrei o elemento pesquisado...\n");
#endif // DEBUG
        return meio;
    }
    // nao encontrei
    if(esq >= dir){
#ifdef DEBUG
        printf("Não encontrei o elemento pesquisado...\n");
#endif // DEBUG
        return -1;
    } else {
        if(vetor[meio] < chave){ // metade da direita
            return pesquisaBinaria(chave, vetor, meio+1, dir);
        } else { // metade da esquerda
            return pesquisaBinaria(chave, vetor, esq, meio-1);
        }
    }
}

void quicksort(int vetor[], int esq, int dir){
    int i = esq, j = dir;
    int pivo = vetor[(esq + dir) / 2];
    while (i <= j) {
        while (vetor[i] < pivo)
            i++;
        while (vetor[j] > pivo)
            j--;
        if (i <= j){
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++; j--;
        }
    }
    if (esq < j)
        quicksort(vetor, esq, j);
    if (i < dir)
        quicksort(vetor, i, dir);
}

int main(){
    int vetor[TAM];
    int chave;
    preencheVetorRandom(vetor);
    printVetor(vetor);
    quicksort(vetor, 0, TAM-1);
    printVetor(vetor);
    printf("Entre com a chave de busca...\n");
    scanf("%i", &chave);
    if (pesquisaBinaria(chave, vetor, 0, TAM - 1) != -1){
        printf("Chave encontrada...\n");
    }
    else{
        printf("Chave não encontrada...\n");
    }
    return 0;
}