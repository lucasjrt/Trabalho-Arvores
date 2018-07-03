#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "AVL.h"

struct registro {
    char identificador[20], local[30];
    int capacidade, trafego;
};

struct no {
    reg_avl registro;
    Avl sad, sae;
    int fb;
};

Avl cria_arvore_avl() {
    return NULL;
}

int arvore_vazia_avl(Avl a) {
    return a == NULL;
}

int insere_avl(Avl *a, reg_avl registro) {
    int *bal = (int*) malloc(sizeof(int));
    *bal = 0;
    return _insere_avl(a, registro, bal);
}

int _insere_avl(Avl *a, reg_avl registro, int *bal) {
    if (a == NULL)
        return 0;
    if(arvore_vazia_avl(*a)) {
        Avl novo = (Avl) malloc(sizeof(struct no));
        novo->registro = registro;
        novo->sae = NULL;
        novo->sad = NULL;
        novo->fb = 0;
        *a = novo;
        *bal = 1;
    } else if(registro->trafego <= (*a)->registro->trafego) {
        _insere_avl(&(*a)->sae, registro, bal);
        if(*bal) {
            if((*a)->fb == 1) {
                balancear_esq(a);
                *bal = 0;
            } else if ((*a)->fb == 0)
                (*a)->fb = 1;
            else {
                (*a)->fb = 0;
                *bal = 0;
            }

        }
    } else {
        _insere_avl(&(*a)->sad, registro, bal);
        if(*bal) {
            if((*a)->fb == -1) {
                balancear_dir(a);
                *bal = 0;
            } else if(!(*a)->fb)
                (*a)->fb = -1;
            else {
                (*a)->fb = 0;
                *bal = 0;
            }
        }
    }
    return 1;
}

Avl busca_bin_avl(Avl a, int trafego) {
    if(arvore_vazia_avl(a))
        return NULL;
    if(a->registro->trafego == trafego)
        return a;
    if(trafego < a->registro->trafego)
        return busca_bin_avl(a->sae, trafego);
    else
        return busca_bin_avl(a->sad, trafego);
}

/*
int remove_avl(Avl *a, int chave) {
    int *bal = (int*) malloc(sizeof(int));
    *bal = 0;
    return _remove_avl(a, chave, bal);
}

int _remove_avl(Avl *a, int trafego, int *bal) {
    if (a == NULL || arvore_vazia_avl(*a))
        return 0;
    if(trafego == (*a)->registro->trafego && arvore_vazia_avl(*a->sae) && arvore_vazia_avl((*a)->sad)) { // Nó folha
        free(*a);
        *a = NULL;
        *bal = 1;
    } else if(trafego < (*a)->registro->trafego) {
        _remove_avl(&(*a)->sae, registro, bal);
        if(*bal) {
            if((*a)->fb == 1) {
                balancear_dir(a);
                *bal = 0;
            } else if ((*a)->fb == 0)
                (*a)->fb = 1;
            else {
                (*a)->fb = 0;
                *bal = 0;
            }

        }
    } else {
        _remove_avl(&(*a)->sad, registro, bal);
        if(*bal) {
            if((*a)->fb == -1) {
                balancear_esq(a);
                *bal = 0;
            } else if(!(*a)->fb)
                (*a)->fb = -1;
            else {
                (*a)->fb = 0;
                *bal = 0;
            }
        }
    }
    return 1;
}*/

/*int remove_avl(Avl *a, int trafego) {
    if(a == NULL || arvore_vazia_avl(*a)) //arvore vazia
        return 0;
    if(trafego < (*a)->registro->trafego) {
        return remove_avl(&(*a)->sae, trafego);
    } else if( trafego > (*a)->registro->trafego){
        return remove_avl(&(*a)->sad, trafego);
    } else { //Encontrou o nó
        if(arvore_vazia_avl((*a)->sae) && arvore_vazia_avl((*a)->sad)) { //Nó é folha
            free(*a);
            *a = NULL;
            return 1;
        } else if(!arvore_vazia_avl((*a)->sae) && arvore_vazia_avl((*a)->sad)) { //Um filho à esquerda
            Avl aux = *a;
            *a = (*a)->sae;
            free(aux);
            return 1;
        } else if(arvore_vazia_avl((*a)->sae) && !arvore_vazia_avl((*a)->sad)) { //Um filho à direita
            Avl aux = *a;
            *a = (*a)->sad;
            free(aux);
            return 1;
        } else { //Dois filhos
            if((*a)->fb = 1) {

            }
        }
    }
    return 1;
}*/


void exibe_arvore_avl(Avl a) {
    if(a == NULL) {
        printf("<>");
        return;
    }
    printf("%d", a->registro->trafego);
    printf(" <");
    exibe_arvore_avl(a->sae);
    printf(", ");
    exibe_arvore_avl(a->sad);
    printf(">");
}

void libera_arvore_avl(Avl *a) {
    if(arvore_vazia_avl(*a))
		return NULL;
	libera_arvore_avl(&(*a)->sae);
	libera_arvore_avl(&(*a)->sad);
	free((*a)->registro);
	free(*a);
	*a = NULL;
}

int rot_esq(Avl *a) {
    if(a == NULL || *a == NULL)
        return 0;
    Avl temp = (*a)->sad;
    (*a)->sad = temp->sae;
    temp->sae = *a;
    (*a)->fb = 0;
    temp->fb = 0;
    *a = temp;
    return 1;
}

int rot_dir(Avl *a) {
    if(a == NULL || *a== NULL)
        return 0;
    Avl temp = (*a)->sae;
    (*a)->sae = temp->sad;
    temp->sad = *a;
    (*a)->fb = 0;
    temp->fb = 0;
    *a = temp;
    return 1;
}

int rot_dir_esq(Avl *a) {
    if(*a == NULL || (*a)->sae == NULL)
        return 0;
    Avl filho_esq = (*a)->sae;

    Avl neto_dir = filho_esq->sad;
    filho_esq->sad = neto_dir->sae;
    neto_dir->sae = filho_esq;
    (*a)->sae = neto_dir->sad;
    neto_dir->sad = *a;

    if(neto_dir->fb == -1) {
        (*a)->fb = 0;
        filho_esq->fb = 1;
    } else if(neto_dir->fb == 1) {
        (*a)->fb = -1;
        filho_esq->fb = 0;
    } else {
        (*a)->fb = 0;
        filho_esq->fb = 0;
    }
    neto_dir->fb = 0;
    *a = neto_dir;
    return 1;
}

int rot_esq_dir(Avl *a) {
    if(*a == NULL || (*a)->sad == NULL)
        return 0;
    Avl filho_dir = (*a)->sad;
    Avl neto_esq = filho_dir->sae;
    filho_dir->sae = neto_esq->sad;
    neto_esq->sad = filho_dir;

    (*a)->sad = neto_esq->sae;
    neto_esq->sae = *a;

    if(neto_esq->fb == -1) {
        (*a)->fb = 1;
        filho_dir->fb = 0;
    } else if(neto_esq->fb == 1) {
        (*a)->fb = 0;
        filho_dir->fb = -1;
    } else {
        (*a)->fb = 0;
        filho_dir->fb = 0;
    }
    neto_esq->fb = 0;
    *a = neto_esq;
    return 1;
}

int balancear_esq(Avl *a) {
    if((*a)->sae->fb > 0)
        return rot_dir(a);
    return rot_dir_esq(a);
}

int balancear_dir(Avl *a) {
    if((*a)->sad->fb < 0)
        return rot_esq(a);
    return rot_esq_dir(a);
}

char* get_identificador(Avl a) {
    return a->registro->identificador;
}

int get_trafego(reg_avl reg) {
    return reg->trafego;
}

reg_avl cria_reg_avl(char *id, char *local, int capacidade, int trafego) {
    reg_avl r = (reg_avl) malloc(sizeof(struct registro));
    strcpy(r->identificador, id);
    strcpy(r->local, local);
    r->capacidade = capacidade;
    r->trafego = trafego;
    return r;
}

int exibe_arvore_avl_2d(Avl a) {
    char s[20][255];
    int i;
    for(i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " "); //limpa a matriz

    _exibe_arvore_avl_2d(a, 0, 0, 0, s);

    for(i = 0; i < 20; i ++)
        printf("%s\n", s[i]); //imprime a matriz com o conteúdo
    return 1;
}

int _exibe_arvore_avl_2d(Avl a, int eh_esquerda, int deslocamento, int profundidade, char s[20][255]) {
    if(a == NULL) {
        return 0;
    }
    char b[20];
    int largura = 5; //largura minima do traço de filhos
    int i;

    sprintf(b, "(%3d)", a->registro->trafego); //preenche o nó a ser desenhado

    int esquerda = _exibe_arvore_avl_2d(a->sae, 1, deslocamento                     , profundidade + 1, s); //recursão
    int direita  = _exibe_arvore_avl_2d(a->sad, 0, deslocamento + esquerda + largura, profundidade + 1, s); //recursão

    for(i = 0; i < largura; i++)
        s[2 * profundidade][2 * deslocamento + esquerda + i] = b[i]; //atribui o nó a ser desenhado na matriz que será impressa na tela

    if(profundidade && eh_esquerda) {
        for(i = 0; i < largura + direita; i++)
            s[2 * profundidade - 1][deslocamento + esquerda + largura / 2 + i] = '-'; //hífen entre os '+'

        s[2 * profundidade - 1][deslocamento + esquerda + largura / 2] = 'a';
        s[2 * profundidade - 1][deslocamento + esquerda + largura + direita + largura / 2] = 'b';
    } else if(profundidade && !eh_esquerda) {
        for(i = 0; i < esquerda + largura; i++)
            s[2 * profundidade - 1][deslocamento - largura / 2 + i] = '-';

        s[2 * profundidade - 1][deslocamento + esquerda + largura / 2] = '+';
        s[2 * profundidade - 1][deslocamento - largura / 2 - 1] = '+';
    }

    return 1;
}

reg_avl menor_trafego_avl(Avl a) {
    if(a->sae == NULL)
        return a->registro;
    return menor_trafego_avl(a->sae);
}

int qtde_ocioso_avl(Avl a) {
    int n = 0;
    if(arvore_vazia_avl(a))
        return 0;
    n += qtde_ocioso_avl(a->sae);
    n += qtde_ocioso_avl(a->sad);
    if(a->registro->capacidade / 2 > a->registro->trafego)
        return n+1;
    return n;
}

int nro_derivacao_avl(Avl a) {
    int n = 0;
    if(arvore_vazia_avl(a))
        return 0;
    n += nro_derivacao_avl(a->sae);
    n += nro_derivacao_avl(a->sad);
    if(!arvore_vazia_avl(a->sae) || !arvore_vazia_avl(a->sad))
        return n+1;
    return n;
}

int altura_avl(Avl a) {
    if(arvore_vazia_avl(a))
        return -1;
    int altEsq = altura_avl(a->sae);
    int altDir = altura_avl(a->sad);
    if(altEsq > altDir)
        return altEsq + 1;
    return altDir + 1;
}

int num_nos_avl(Avl a) {
    if(arvore_vazia_avl(a))
        return -1;
    int n = 1 + num_nos_avl(a->sae);
    n += 1 + num_nos_avl(a->sad);
    return n + 1;
}

int nivel_no_avl(Avl a, int elem) {
    if(arvore_vazia_avl(a))
        return -1;
    if(elem == a->registro->trafego)
        return 0;
    if(elem < a->registro->trafego)
        return 1 + (nivel_no_avl(a->sae, elem));
    if(elem > a->registro->trafego)
        return 1 + (nivel_no_avl(a->sad, elem));
    return -1;
}

int cheia_avl(Avl a) {
    return num_nos_avl(a) == (pow(2, altura_avl(a)) -1) ? 1: 0;
}

int iguais(Avl a1,Avl a2) {
    if(a1->registro->capacidade != a2->registro->capacidade || a1->registro->identificador != a2->registro->identificador || a1->registro->local != a2->registro->local || a1->registro->trafego != a2->registro->trafego){
        return 0;
    } else {
        int ok_esq=1, ok_dir=1;
        if((a1->sae != NULL && a2->sad == NULL) || (a1->sae == NULL && a2->sad != NULL)) {
            return 0;
        }
        if(a1->sae != NULL) {
            ok_esq = iguais(a1->sae,a2->sae);
        }
        if(a1->sad != NULL) {
            ok_dir = iguais(a1->sad,a2->sad);
        }
        return (ok_esq == 1 && ok_dir == 1) ? 1 : 0;
    }
}
