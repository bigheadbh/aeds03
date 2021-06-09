#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Aluno{
    char nome[20];
    char assinatura[20];
}Aluno;

int checkSignature(char *registro, char *assinatura){
    int resp = 0;
    for(int i = 0; i<strlen(registro); i++){
        if(registro[i] != assinatura[i]) resp++;
    }
    return resp;
}



int main(){
    char linha[100];
    int alunos, presencas;
    fgets(linha, 100, stdin);
    alunos = atoi(linha);

    while(alunos > 0){
        //Registro de Alunos
        Aluno registros[alunos];
        for(int i=0; i<alunos; i++){
            fgets(linha, 100, stdin);
            char *temp = strtok(linha, " ");
            strcpy(registros[i].nome, temp);
            temp = strtok(NULL, " \n\r");
            strcpy(registros[i].assinatura, temp);
        }
        
        //Verificando Lista de Presença
        fgets(linha, 100, stdin);
        presencas = atoi(linha);
        int falsas = 0;
        for(int j = 0; j < presencas; j++){
            fgets(linha, 100, stdin);
            char* nome = strtok(linha, " ");
            char* assinatura = strtok(NULL, " \n\r");
            for(int i = 0; i < alunos; i++){
                if(strcmp(registros[i].nome, nome) == 0){
                    if(checkSignature(registros[i].assinatura, assinatura) > 1)
                        falsas++;
                }
            }
        }
        printf("%d\n", falsas);

        fgets(linha, 100, stdin);
        alunos = atoi(linha);
    }

    return 0;
}