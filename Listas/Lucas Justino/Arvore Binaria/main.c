#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
    Arvore a, b, c, d, e, f, g, h;
    d = cria_arvore(25, cria_vazia(), cria_vazia());
    g = cria_arvore(5, cria_vazia(), cria_vazia());
    h = cria_arvore(2, cria_vazia(), cria_vazia());
    f = cria_arvore(40, cria_vazia(), cria_vazia());
    c = cria_arvore(39, cria_vazia(), f);
    e = cria_arvore(-3, g, h);
    b = cria_arvore(10, d, e);
    a = cria_arvore(50, b, c);
    exibe_arvore(a);
    putchar('\n');
    printf("Pai do 25: %d", get_info(pai(a, d)));
    return 0;
}
