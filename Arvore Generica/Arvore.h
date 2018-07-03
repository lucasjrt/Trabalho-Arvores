#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct no* Arv;
typedef struct vetor* vetor;

Arv cria_arvore_vazia();
Arv cria_arvore(int elem);
int insere(Arv a,Arv nov);
void exibe_arvore(Arv a);
int busca(Arv a, int elem);
void libera_arvore(Arv *a);
int altura_no(Arv a,int elem);
Arv procura_subArv(Arv a, int elem);
int altura_arv(Arv a);
int nro_folhas(Arv a);
int grau_arv(Arv a);
int qtd_nos(Arv a, int grau);
void preorder(Arv a);
void posordem(Arv a);
void percorre_nivel(Arv a);

#endif // ARVORE_H_INCLUDED
