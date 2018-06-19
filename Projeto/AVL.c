#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "AVL.h"

struct registro {
    char identificador[20];
    int capacidade;
};

struct no {
    reg registro;
    Arvore sad, sae;
};

Arvore cria_vazia_avl() {
    Arvore a = (Arvore) malloc(sizeof(struct no));
    a->sae = NULL;
    a->sad = NULL;
    return a;
}

Arvore cria_arvore_avl(reg registro, Arvore sae, Arvore sad) {
    Arvore a = (Arvore) malloc(sizeof(struct no));
    a->registro = registro;
    a->sae = sae;
    a->sad = sad;
    return a;
}

int arvore_vazia_avl(Arvore a) {
    if(a == NULL)
        return 1;
    return 0;
}

void libera_arvore_avl(Arvore *a) {
    if(!arvore_vazia_avl(*a)) {
        libera_arvore_avl(&(*a)->sae);
        libera_arvore_avl(&(*a)->sad);
        free(a);
    }
}

int busca_avl(Arvore a, reg elem) {
    int encontrado = 0;
    if(a->registro == elem)
        return 1;
    if(!arvore_vazia_avl(a->sae))
        encontrado = busca_avl(a->sae, elem);
    if(!arvore_vazia_avl(a->sad) && !encontrado)
        encontrado = busca_avl(a->sad, elem);
    return encontrado;
}

int remove_folha_avl(Arvore *a, reg registro) {
    int encontrado = 0;
    if(!arvore_vazia_avl(*a)) {
        if((*a)->registro == registro) {
            free(a);
            return 1;
        } else {
            if(!arvore_vazia_avl((*a)->sae))
                encontrado = remove_folha_avl(&(*a)->sae, registro);
            if(!arvore_vazia_avl((*a)->sad) && !encontrado)
                encontrado = remove_folha_avl(&(*a)->sad, registro);
            return encontrado;
        }
    } else {
        return -1;
    }
    return 1;
}

void print_arvore_avl(Arvore a) {
    if(!arvore_vazia_avl(a))
        printf("%d < ", a->registro->capacidade);
    if(!arvore_vazia_avl(a->sae))
        print_arvore_avl(a->sae);
    printf(", ");
    if(!arvore_vazia_avl(a->sad))
        print_arvore_avl(a->sad);
    printf(">");
}
