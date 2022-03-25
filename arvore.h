#ifndef arvore_h
#define arvore_h


//estrutura para os nós da árvore
typedef struct raiz Arvore;

//Funções para a manipulação da árvore

//aloca memoria para arvore
Arvore* criaArvoreVazia();

//libera memoria da usada pela arvore
//void liberaArvore(Arvore* raiz);
//void liberaNo(struct NO* no);

//Insere informação na arvore
Arvore* insereArvore(Arvore* esq, Arvore* dir, char* conteudo);

void imprimeArvore(Arvore *raiz);


//funções para manipulçao de arquivo

#endif //arvore_h