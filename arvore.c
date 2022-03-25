#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct raiz{
  char* palavra;
  struct raiz* esq;
  struct raiz* dir;
} ;
/*------------------------------------------------
Funções para manipulação da árvore binária
------------------------------------------------*/
//Função que aloca a memória para a árvore
Arvore* criaArvoreVazia(){
  return NULL;
}

/*
//funções para liberar a memória alocada para a arvore
void liberaArvore(Arvore* raiz){
  //Verifica se a raiz é nula, caso não seja puxa a função liberaNo e libera a raiz
  if(raiz == NULL){
    return;
  }
  liberaNo(*raiz);
  free(raiz);
}*/

/*
void liberaNo(struct NO* no){
  //verifica se o nó é nulo
  if(no == NULL){
    return;
  }
  /*caso não seja nulo percorre recursivamente os nós da     direita e da esquerda, quando encontra um nó sem         
  subárvore, faz a liberação do mesmo.*//*
  liberaNo(no->dir);
  liberaNo(no->esq);
  free(no);
  no = NULL;
}*/ 

Arvore* insereArvore(Arvore* esq, Arvore* dir, char* conteudo){
    Arvore* aux = (Arvore*)malloc(sizeof(Arvore));
    aux->palavra = strdup(conteudo);
    aux->esq = esq;
    aux->dir = dir;
    return aux;
}

void imprimeArvore(Arvore *raiz){
  if(raiz != NULL){
    printf("<%s", raiz->palavra);
    imprimeArvore(raiz->esq);
    imprimeArvore(raiz->dir);
    printf(">");
  }
  else{
    printf("<>");
  }
}


/*--------------------------------------------------------
FILE* abreArquivo(char* nome){
    return fopen(nome, "r");
}

void fechaArquivo(FILE* arquivo){
    fclose(arquivo);
}*/


/* Parsing
  Os operandos sempre serão raizes, e eles irão realizar 
a sua operação com os valores da subarevores esquerda e direita


Começa a ler a linha, caso seja um parenteses o programa 
cria um novo nó interno, ao chegar em um numero ele começa a voltar e preencher os nós



*/