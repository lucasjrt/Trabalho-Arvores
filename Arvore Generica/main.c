#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main()
{
    Arv a,b,c,d,e,f,g,h,i,j,k;
    a = cria_arvore(1);
    b = cria_arvore(2);
    c = cria_arvore(3);
    d = cria_arvore(4);
    e = cria_arvore(5);
    f = cria_arvore(6);
    g = cria_arvore(7);
    h = cria_arvore(8);
    i = cria_arvore(9);
    j = cria_arvore(10);
    k = cria_arvore(11);

    insere(i,k);
    insere(i,j);
    insere(f,i);
    insere(f,h);
    insere(c,f);
    insere(c,e);
    insere(d,g);
    insere(a,d);
    insere(a,c);
    insere(a,b);

    menu(a);
    return 0;
}

void menu(Arv a){
    int continua = 1;
    do{
        printf("\n\n");
        system("pause");
        int elem,number,escolha,grau;
        printf("\n\n--------------------------MENU------------------------\n\n");
        printf("Escolha uma das opcoes!!!!\n");
        printf("1 - Percorrer na pre-ordem.\n");
        printf("2 - Percorrer na pos-ordem.\n");
        printf("3 - Percorrer em largura.\n");
        printf("4 - Quantidade de nos folhas.\n");
        printf("5 - Grau da arvore.\n");
        printf("6 - Quantos nos tem tal grau.\n");
        printf("7 - Altura dum no.\n");
        printf("8 - Sair.\n\n");
        printf("Sua escolha eh: ");
        scanf("%d",&escolha);

        switch(escolha){
        case 1:
            printf("Arvore pecorrida usando a pre-ordem: \n");
            preorder(a);
            break;
        case 2:
            printf("Arvore pecorrida usando a pos-ordem: \n");
            posordem(a);
            break;
        case 3:
            printf("Arvore pecorrida usando a pecorrimento por nivel: \n");
            percorre_nivel(a);
            break;
        case 4:
            printf("A arvore tera: %d nos folhas",nro_folhas(a));
            break;
        case 5:
            printf("A arvore tem grau %d",grau_arv(a));
            break;
        case 6:
            printf("Qual grau voce escolhe: ");
            scanf("%d",&grau);
            printf("Ha %d nos que possuem grau %d",qtd_nos(a,grau),grau);
            break;
        case 7:
            printf("Qual no vc deseja sabe a sua altura: ");
            scanf("%d",&elem);
            printf("A altura eh: %d",altura_no(a,elem));
            break;
        case 8:
            continua = 0;
            break;
        }
    }while(continua);
}
