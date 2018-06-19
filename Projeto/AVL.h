#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct registro* reg;
typedef struct no* Arvore;

Arvore cria_vazia_avl(); //Cria uma Arvore vazia
Arvore cria_arvore_avl(reg a, Arvore sae, Arvore sad); //Cria uma arvore
int arvore_vazia_avl(Arvore a); //Verifica se uma Arvore e vazia
void libera_arvore_avl(Arvore *a); //Desaloca cada espaço da arvore
int existe_avl(Arvore a, reg elem);
int remove_folha_avl(Arvore *a, reg aluno);
void print_arvore_avl(Arvore a);

#endif // AVL_H_INCLUDED
