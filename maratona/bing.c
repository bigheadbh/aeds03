/*
    4 5 10
    3 10 8 7 2
    4 1 7 10 9
    9 1 5 3 6
    6 8 1 5 7
    7 3 5 6 1 9 2 10 4 8
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char linha[50];
    int cartelas, colunas, numeros;
    fgets(linha, 50, stdin);
    cartelas = atoi(strtok(linha, " "));
    colunas = atoi(strtok(NULL, " "));
    numeros = atoi(strtok(NULL, " "));

    int Matriz[cartelas][colunas];
    for(int i = 0; i < cartelas; i++){
        fgets(linha, 50, stdin);
        Matriz[i][0] = atoi(strtok(linha, " "));
        for(int j = 1; j < colunas; j++){
            Matriz[i][j] = atoi(strtok(NULL, " \n\r"));
        }
    }

    fgets(linha, 50, stdin);
    int num = atoi(strtok(linha, " "));
    for(int k = 0; k < numeros; k++){
        int linha = -1;
        for(int i = 0; i < cartelas; i++){
            linha = i;
            for(int j = 0; j < colunas; j++){
                if(Matriz[i][j] == num)
                    Matriz[i][j] = - 1;
                if(Matriz[i][j] != -1)
                    linha = -1; 
            }
            if(linha != -1)
                printf("%d\n", linha+1);
        }

        if(k < numeros -1){
            num = atoi(strtok(NULL, " "));
        }
    }

    /*for(int i = 0; i < cartelas; i++){
        for(int j = 0; j < colunas; j++)
            printf("%d\t", Matriz[i][j]);
        printf("\n");
    }*/

    return 0;
}