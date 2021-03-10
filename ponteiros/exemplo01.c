#include<stdio.h>
#include<stdlib.h>

#define TAM 7

int main(){
    int tamanho;
    printf("Entre com a quantidade de elementos\n");
    scanf("%d", &tamanho);

    int *vetor01 = NULL;
    printf("%p   %p\n", vetor01, &vetor01);
    vetor01 = (int*) malloc(sizeof(int)*tamanho);
    printf("%p   %p\n", vetor01, &vetor01);

    if(vetor01 != NULL){ // check malloc error?
        int *temp = vetor01;
        for (int i = 0; i < tamanho; i++){
            vetor01[i] = i;
            printf("%p \t %d\n", temp, *temp);
            temp++;
        }
        free(vetor01);
        vetor01 = NULL;
    }
    return 0;
}