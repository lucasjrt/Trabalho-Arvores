#include <stdio.h>
#include <stdlib.h>
#include "ArvoreGenerica.h"

int main() {
    Arvore A, B, C, D, E, F, G, H, I;
    A = cria_arvore(1);
    B = cria_arvore(2);
    C = cria_arvore(3);
    D = cria_arvore(4);
    E = cria_arvore(5);
    F = cria_arvore(6);
    G = cria_arvore(7);
    H = cria_arvore(8);
    I = cria_arvore(9);
    insere(F, I);
    insere(F, H);
    insere(C, F);
    insere(C, E);
    insere(D, G);
    insere(A, D);
    insere(A, C);
    insere(A, B);
    exibe_arvore(A);
    return 0;
}
