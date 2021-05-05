#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TOTAL_TAM 100
#define TAM_BUFFER 500

typedef struct Registro{
    char palavra[20];
    int freq;
} Registro;

/*
 * Executa o quicksort no vetor de palavras
 */
void quicksort(Registro vetor[], int esq, int dir){
    int i = esq, j = dir;
    char *pivo = vetor[(esq + dir) / 2].palavra;
    while (i <= j){
        while (strcasecmp(vetor[i].palavra,pivo) < 0)
            i++;
        while (strcasecmp(vetor[j].palavra, pivo) > 0)
            j--;
        if (i <= j){
            char temp [20];
            strcpy(temp, vetor[i].palavra);
            strcpy(vetor[i].palavra, vetor[j].palavra);
            strcpy(vetor[j].palavra, temp);
            i++;
            j--;
        }
    }
    if (esq < j)
        quicksort(vetor, esq, j);
    if (i < dir)
        quicksort(vetor, i, dir);
}

/*
 * Executa a pesquisa sequencial
 * @return -1 se não encontrou o elemento ou 
 * retorna a posição do vetor que contém a palavra
 */
int pesquisaSequencial(char chave[], Registro vetor[], int n){
    int resp = -1;
    for(int i = 0; i < n; i++){
        if(strcasecmp(vetor[i].palavra, chave) == 0){
            resp = i; //guarda posição do vetor
            i = n;
        }
    }
    return resp;
}

/*
 * Executa a pesquisa sequencial
 */
void pseq(char *nomeArquivo){
    char linha[TAM_BUFFER];
    Registro vetor[TOTAL_TAM];
    int n = 0;

    //Abre o arquivo
    FILE *fp = fopen(nomeArquivo, "a+r");
    if(fp != NULL){
        while(!feof(fp)){
            fgets(linha, 100, fp);
            linha[strcspn(linha, "\n\r")] = '\0';
            if(strlen(linha) > 0){
                char *aux = strtok(linha, " ");
                while(aux != NULL){
                    //Executa a pesquisa da palavra
                    int pos = pesquisaSequencial(aux, vetor, n);
                    if(pos >= 0){ //Palavra existe no vetor
                        vetor[pos].freq++;
                    } else {//Inserir palara novo vetor
                        strcpy(vetor[n].palavra, aux);
                        vetor[n].freq = 1;
                        n++;
                    }
                    aux = strtok(NULL, " ");
                }
            }
        }
        fclose(fp);

        quicksort(vetor, 0, n);

        //imprimir lista de palavras
        for(int i=0; i<n; i++)
            printf("word: %s freq: %d\n", vetor[i].palavra, vetor[i].freq);
    }

}

/*
 * void main
 */ 
int main(int argc, char *argv[]){
    if (strcmp(argv[1], "pseq") == 0){
        pseq(argv[2]);
    }else if (strcmp(argv[1], "pbinaria") == 0){
        printf("Escolheu Pesquisa Binária\n");
    }else if (strcmp(argv[1], "arvore") == 0){
        printf("Estrutura não implementada.\n");
    }else if (strcmp(argv[1], "hash") == 0){
        printf("Escolheu Hash\n");
    }
    return 0;
}
