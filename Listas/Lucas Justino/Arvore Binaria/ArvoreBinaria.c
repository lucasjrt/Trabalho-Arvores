#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBinaria.h"

struct no {
    int info;
    Arvore sae, sad;
};

Arvore cria_vazia() {
    return NULL;
}

Arvore cria_arvore(int info, Arvore sae, Arvore sad) {
    Arvore a = (Arvore) malloc(sizeof(struct no));
    a->info = info;
    a->sae = sae;
    a->sad = sad;
    return a;
}

int arvore_vazia(Arvore a) {
    if (a == NULL)
        return 1;
    return 0;
}

void libera_arvore(Arvore *a) {
    if(arvore_vazia(*a))
        return;
    libera_arvore(&(*a)->sae);
    libera_arvore(&(*a)->sad);
    free(*a);
    *a = NULL;
}

int busca(Arvore a, int info) {
    if (a->info == info)
        return 1;

    int encontrado = 0;
    if(!arvore_vazia(a->sae))
        encontrado = busca(a->sae, info);
    if(!arvore_vazia(a->sad) && !encontrado)
        encontrado = busca(a->sad, info);
    return encontrado;
}

int remove_folha(Arvore *a, int info) {
    if(arvore_vazia(*a))
       return 0;
    if((*a)->info == info && folha(*a)) {
        free(*a);
        return 1;
    }
    remove_folha(&(*a)->sae, info);
    remove_folha(&(*a)->sad, info);
    return 0;
}

int folha(Arvore a) {
    if(arvore_vazia(a->sae) && arvore_vazia(a->sad))
        return 1;
    return 0;
}

void exibe_arvore(Arvore a) {
    if(arvore_vazia(a)) {
        printf("<>");
        return;
    }
    printf("< %d ", a->info);
    exibe_arvore(a->sae);
    printf(", ");
    exibe_arvore(a->sad);
    printf(" >");
}

int altura(Arvore a) {
    if(arvore_vazia(a))
        return -1;
    int altEsq = altura(a->sae);
    int altDir = altura(a->sad);
    if(altEsq > altDir)
        return altEsq + 1;
    return altDir + 1;
}

Arvore pai(Arvore a, Arvore sa) {
    if(a == sa || a == NULL || sa == NULL)
        return NULL;
    if(a->sae == sa || a->sad == sa)
        return a;
    Arvore res;
    res = pai(a->sae, sa);
    if(!arvore_vazia(res))
        return res;
    return pai(a->sad, sa);
}

int get_info(Arvore a) {
    if(a == NULL)
        return NULL;
    return a->info;
}
