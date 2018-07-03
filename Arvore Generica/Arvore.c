#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

struct no{
    int inf;
    struct no *esq;
    struct no *dir;
};

struct vetor{
    int inf;
    int qtd_filho;
};

Arv cria_arvore_vazia(){
    Arv a = (Arv) malloc(sizeof(struct no));
    if(a == NULL)
        return NULL;
    a->inf = NULL;
    a->esq = NULL;
    a->dir = NULL;
    return a;
}

Arv cria_arvore(int elem){
    Arv a = (Arv) malloc(sizeof(struct no));
    if(a == NULL)
        return NULL;
    a->inf = elem;
    a->esq = NULL;
    a->dir = NULL;
    return a;
}

int insere(Arv a,Arv nov){
    if(a == NULL)
        return 0;
    nov->dir = a->esq;
    a->esq = nov;
    return 1;
}

void exibe_arvore(Arv a){
    if(a == NULL)
        printf(" ");
    else{
        printf("<");
        printf("%d",a->inf);
        exibe_arvore(a->esq);
        printf(">");
        exibe_arvore(a->dir);
    }
}

int busca(Arv a, int elem){
    int achado;
    if(a == NULL)
        return 0;
    if(a->inf == elem)
        return 1;
    achado = busca(a->esq, elem);
    if(!achado)
        achado = busca(a->dir, elem);
    return achado;
}

void libera_arvore(Arv *a){
    if(*a != NULL){
        libera_arvore((*a)->esq);
        libera_arvore((*a)->dir);
        free(*a);
    }
    *a = NULL;
}

int altura_no(Arv a,int elem){
    Arv b = procura_subArv(a,elem);
    if(b->inf == NULL)
        return -1;
    if(b->dir != NULL)
        b->dir == NULL;
    return altura_arv(b);
}

Arv procura_subArv(Arv a, int elem){
    if(a == NULL)
        return cria_arvore_vazia();
    if(a->inf == elem)
        return a;
    else{
        Arv right = procura_subArv(a->dir,elem);
        if(right->inf == elem)
            return right;
        Arv left = procura_subArv(a->esq,elem);
        if(left->inf == elem)
            return left;
        return cria_arvore_vazia();
    }
}

int altura_arv(Arv a){
    if(a == NULL)
        return -1;
    int alt_esq = altura_arv(a->esq);
    int alt_dir = altura_arv(a->dir);
    if(alt_dir > alt_esq)
        return (alt_dir);
    return (alt_esq+1);
}

int nro_folhas(Arv a){
    int cont = 0;
    if(a == NULL)
        return 0;
    if(a->esq == NULL){
        cont = 1;
    }else{
        cont = nro_folhas(a->esq);
    }
    cont += nro_folhas(a->dir);
    return cont;
}
j
int grau_arv(Arv a){
    if(a == NULL)
        return 0;
    int grau_esq = grau_arv(a->esq);
    int grau_dir = grau_arv(a->dir);
    int grau_atual = grau_no(a);
    if(grau_atual == grau_dir && grau_atual == grau_esq && grau_dir == grau_esq)
        return grau_atual;
    else{
        if(grau_atual > grau_dir && grau_atual > grau_esq)
            return grau_atual;
        else{
            if(grau_dir > grau_esq)
                return grau_dir;
            else{
                if(grau_esq > grau_dir)
                    return grau_esq;
            }
        }
    }
}

int grau_no(Arv a){
    Arv b;
    int cont = 1;
    if(a == NULL)
        return -1;
    b = a->esq;
    if(b == NULL)
        return 0;
    while(b->dir != NULL){
        b = b->dir;
        cont++;
    }
    return cont;
}

int qtd_nos(Arv a, int grau){
    int qtd = 0;
    if(a == NULL)
        return 0;
    int qtd_esq = qtd_nos(a->esq,grau);
    int qtd_dir = qtd_nos(a->dir,grau);
    if(grau_no(a) == grau)
        qtd = 1;
    return (qtd+qtd_dir+qtd_esq);
}

void preorder(Arv a){
    if(a == NULL)
        return;
    printf("%d ",a->inf);
    preorder(a->esq);
    preorder(a->dir);
}

void posordem(Arv a){
    if(a == NULL)
        return;
    posordem(a->esq);
    printf("%d ",a->inf);
    posordem(a->dir);
}


void percorre_nivel(Arv a){
    if(a == NULL)
        return;
    printf("%d ",a->inf);
    percorre_nivel(a->dir);
    percorre_nivel(a->esq);
}
