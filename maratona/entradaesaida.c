#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ehPalindromo(char linha[]){
    int flag = 1;
    int tam = strlen(linha);
    for(int i = 0; i < tam/2 ; i++){
        if(linha[i] != linha[tam - 1 - i]){
            flag = 0;
            i = tam;
        }
    }
    return flag;
}

int main(){
    char linha[100];
    scanf("%[^\n]s", linha);
    while(strcmp(linha, "FIM") != 0){
        if(ehPalindromo(linha) == 1)
            printf("SIM\n");
        else
            printf("NAO\n");
        scanf(" %[^\n]s", linha);
    }
    return 0;
}

