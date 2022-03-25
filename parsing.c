#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "parsing.h"


Arvore* criaArvore(FILE* pArquivo){
  char palavra[10];
  palavra[0] = fgetc(pArquivo);

  if(isdigit(palavra[0])){
    palavra[1] = fgetc(pArquivo);
    int i = 1;
    for(; isdigit(palavra[i]); i++){
      palavra[i+1] = fgetc(pArquivo); 
    }
    palavra[i] = '\0'; 
    return insereArvore(criaArvoreVazia(), criaArvoreVazia(), palavra);
  }
  
    //Caso passe do primeiro caso sempre será um (
    Arvore* noEsq = criaArvore(pArquivo);
		palavra[0] = fgetc(pArquivo);
    //pode ser que aqui seja o encerramento da expressão então farei essa verificação
    if(palavra[0] == '\n' || palavra[0] == EOF){
    return noEsq;
    }   
    
    palavra[1] = '\0';
    //usando o fgetc para consumir o ( antes do 3
    fgetc(pArquivo);
    Arvore* noDir = criaArvore(pArquivo);
    //consumindo o parenteses de fechamento depois do 3 e antes da multiplicação
    fgetc(pArquivo);

    //retornando tudo num nó só
    return insereArvore(noEsq, noDir, palavra);
}
/*
2 - b - nesse caso só pode ser um '('
2 - b - 1 - então tu chama a função recursivamente, salvando o resultado em uma variavel.
2 - b - 2 - apos a execução da chamada recursiva vc só tem 2 possibilidade: a expressão acabou e o proximo caractere é um espaço em branco ou o proximo caractere é a operação
2 - b - 2 - a -  se for um espaço em branco, tu pega arvore que tu obteve até o momento e retorna ela
2 - b - 2 - b - nesse caso é uma operação e tu deve guardar ela
2 - b - 2 - b - 2 - descarte o caractere de '(' do segundo numero da expressão
2 - b - 2 - b - 3 - chame a função recursivamente, salvando o resultado em uma variavel
2 - b - 2 - b - 4 - descarte o caractere de ')' que vem na proxima leitura (esse é o fechamento com o '(' do passo 2-b)
2 - b - 2 - b - 5 - agora basta criar um nó, salvar nele a operação obtida e anexar a sub-arvore da esquerda (passo 2 - b - 1) e anexar a sub-arvore da direita (passo 2 - b - 2 - b - 3)
2 - b - 2 - b - 6 - retorne o nó criado no passo anterior
   */