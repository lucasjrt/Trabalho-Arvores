#include <stdlib.h>
#include <stdio.h>
#include "ArvoreGenerica.h"

struct no{
    int elem;
    Arvore esq, dir;
};

Arvore cria_arvore(int elem) {
    Arvore a = (Arvore) malloc(sizeof(struct no));
    if (!a)
        return NULL;
    a->elem = elem;
    a->esq = NULL;
    a->dir = NULL;
    return a;
}

int insere(Arvore a, Arvore sa) {
    if (a == NULL)
        return -1;
    sa->dir = a->esq;
    a->esq = sa;
    return 1;
}

void exibe_arvore(Arvore a) {
    if (a == NULL) {
        printf("<>");
        return;
    }
    printf("< %d ", a->elem);
    exibe_arvore(a->esq);
    printf("> ");
    exibe_arvore(a->dir);
}

int busca(Arvore a, int elem) {
    if(a == NULL)
        return 0;
    int encontrado = 0;
    if(a->elem == elem)
        return 1;
    encontrado = busca(a->esq, elem);
    if(!encontrado)
        encontrado = busca(a->dir, elem);
    return encontrado;

}

void libera_arvore(Arvore *a) {
    if(*a == NULL)
        return;
    libera_arvore(&(*a)->esq);
    libera_arvore(&(*a)->dir);
    free(*a);
    *a = NULL;
}
