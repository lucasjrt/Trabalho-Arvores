#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct registro* reg;
typedef struct no* Arv;
int arvore_vazia(Arv a);
void libera_arvore(Arv *a);
void exibe_arvore(Arv a);
void exibe_ordenado(Arv a);
int insere_ord(Arv *a, reg elem);
int remove_ord(Arv *a, int chave);
Arv busca_bin(Arv a, int chave);

#endif // ARVORE_H_INCLUDED
