#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "parsing.h"

int main(){
  FILE* pArquivo;
	pArquivo = fopen("entrada.txt", "r");
	if(pArquivo == NULL){
		printf("Erro ao abrir o arquivo");
		exit(1);
	}
	while(!feof(pArquivo)){
		Arvore* arv = criaArvore(pArquivo);
		imprimeArvore(arv);
		printf("\n");
	}
return 0;
}
