#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct no* Arvore;

Arvore cria_vazia();
Arvore cria_arvore(int info, Arvore sae, Arvore sad);
int arvore_vazia(Arvore a);
void libera_arvore(Arvore *a);
int busca(Arvore a, int info);
int remove_folha(Arvore *a, int info);
void exibe_arvore(Arvore a);
int folha(Arvore a);
int altura(Arvore a);
Arvore pai(Arvore a, Arvore sa);
int get_info(Arvore a);

#endif // ARVOREBINARIA_H_INCLUDED
