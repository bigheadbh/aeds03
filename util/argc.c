#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    for(int i = 0; i < argc; i++){
        printf("%s\n", argv[i]);
    }

    if(strcmp(argv[1], "hash") == 0){
        printf("Escolheu Hash\n");
    }else if (strcmp(argv[1], "pseq") == 0){
        printf("Escolheu Pesquisa Sequencial\n");
    }else if (strcmp(argv[1], "arvore") == 0){
        printf("Estrutura não implementada.\n");
    }
    return 0;
}
