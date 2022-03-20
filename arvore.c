#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

FILE* abreArquivo(char* nome){
    return fopen(nome, "r");
}

void fechaArquivo(FILE* arquivo){
    fclose(arquivo);
}