#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define TAM 500000

void printVetor(int vetor[])
{
    printf("[ ");
    for (int i = 0; i < TAM; i++)
        printf("%i, ", vetor[i]);
    printf(" ]\n\n");
}

void preencheVetorRandom(int vetor[])
{
    for (int i = 0; i < TAM; i++)
    {
        vetor[i] = rand() % TAM;
    }
}

void quicksort(int vetor[], int esq, int dir)
{
    int i = esq, j = dir;
    int pivo = vetor[(esq + dir) / 2];
    while (i <= j)
    {
        while (vetor[i] < pivo)
            i++;
        while (vetor[j] > pivo)
            j--;
        if (i <= j)
        {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }
    if (esq < j)
        quicksort(vetor, esq, j);
    if (i < dir)
        quicksort(vetor, i, dir);
}

int main(){
    int vetor[TAM];
    preencheVetorRandom(vetor);
    clock_t begin = clock();
    quicksort(vetor, 0, TAM - 1);
    //printVetor(vetor);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Tempo de execução %g\n", time_spent);
    return 0;
}