#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define TAM 50

bool pesquisaSequencial(int vetor[], int chave){
    int resp = false;
    for(int i=0; i<TAM; i++){
        if(vetor[i] == chave){
            resp = true;
            i = TAM;
        }
    }
    return resp;
}

void printVetor(int vetor[]){
    printf("[ ");
    for (int i = 0; i < TAM; i++)
        printf("%i, ", vetor[i]);
    printf(" ]\n\n");
}

int main(){
    int vetor[TAM];
    for(int i=0; i<TAM; i++){
        vetor[i] = rand()%TAM;
    }
    int chave;
    printVetor(vetor);
    printf("Entre com a chave de busca...\n");
    scanf("%i", &chave);
    if(pesquisaSequencial(vetor, chave) == true){
        printf("Chave encontrada...\n");
    } else {
        printf("Chave não encontrada...\n");
    }
    return 0;
}