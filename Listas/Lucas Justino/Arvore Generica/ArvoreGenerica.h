#ifndef ARVORE_GENERICA_H_INCLUDED
#define ARVORE_GENERICA_H_INCLUDED

typedef struct no* Arvore;

Arvore cria_arvore(int elem);
int insere(Arvore a, Arvore sa);
void exibe_arvore(Arvore a);
int busca(Arvore a, int elem);
void libera_arvore(Arvore *a);
int altura(Arvore a);
#endif // ARVORE_GENERICA_H_INCLUDED
