#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"
struct registro{
    int chave, idade;
    float salario;
    char nome[100];
};
struct no{
    reg inf;
    struct no *sae;
    struct no *sad;
};
Arv cria_arvore(){
    return NULL;
}
int arvore_vazia(Arv a){
    if(a == NULL)
        return 1;
    else
        return 0;
}
void libera_arvore(Arv *a){
    if(!arvore_vazia(*a)){
        libera_arvore(&(*a)->sae);
        libera_arvore(&(*a)->sad);
        free(*a);
    }
    *a = NULL;
}
void exibe_arvore(Arv a){
    if(arvore_vazia(a)){
        printf("<>");
        return;
    }
    printf("<");
    printf("%d",a->inf->chave);
    exibe_arvore(a->sae);
    exibe_arvore(a->sad);
    printf(">");
}
void exibe_ordenado(Arv a){
    if(!arvore_vazia(a)){
        exibe_ordenado(a->sae);
        printf("%d",a->inf->chave);
        exibe_ordenado(a->sad);
    }
}
int insere_ord(Arv *a, reg elem){
    if(a == NULL)
        return 0;
    if(arvore_vazia(*a)){
        Arv no = (Arv) malloc(sizeof(struct no));
        if(no == NULL)
            return 0;
        no->inf = elem;
        no->sae = NULL;
no->sad = NULL;
        *a = no;
        return 1;
    }
    if(elem->chave > (*a)->inf->chave)
        return insere_ord(&(*a)->sae, elem);
    else
        return insere_ord(&(*a)->sad, elem);
}
int remove_ord(Arv *a, int chave){
    if(a == NULL || arvore_vazia(*a))
        return 0;
    if(chave > (*a)->inf->chave)
        return remove_ord(&(*a)->sad,chave);
    else{
        if(chave < (*a)->inf->chave)
            return remove_ord(&(*a)->sae,chave);
        else{
            if((*a)->sae == NULL && (*a)->sad == NULL){
                free(*a);
                *a == NULL;
                return 1;
            }else{
                if((*a)->sae != NULL && (*a)->sad == NULL){
                    Arv aux = *a;
                    *a = (*a)->sae;
                    free(aux);
                    return 1;
                }else{
                    if((*a)->sae == NULL && (*a)->sad != NULL){
                        Arv aux = *a;
                        *a = (*a)->sad;
                        free(aux);
                        return 1;
                    }else{
                        Arv aux = (*a)->sae;
                        while((*a)->sad != NULL){
                            aux = aux->sad;
                        }
                        reg temp = (*a)->inf;
                        (*a)->inf = aux->inf;
                        aux->inf = temp;
                        return remove_ord(&(*a)->sae,chave);
                    }
                }
            }
        }
    }
}
Arv busca_bin(Arv a, int chave) {
    if(arvore_vazia(a))
        return NULL;
    if(a->inf->chave == chave)
        return a;
    else{
        if(chave > a->inf->chave)
            return busca_bin(a->sad,chave);
        else
            return busca_bin(a->sae,chave);
    }
}
