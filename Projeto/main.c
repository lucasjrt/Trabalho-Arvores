#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "ABB.h"
#include "AVL.h"
#define DELAY 1500

void menu();

void menu_generica();

void menu_abb();

void menu_avl();
void menu_insere_avl(Avl *a);
void menu_remove_avl(Avl *a);

Aluno cria_aluno(char *nome, int idade, char *curso);
void libera_aluno(Aluno a);

int main() {
    setlocale(LC_ALL, "Portuguese");
    menu();
    //for(int i = 0; i < 32; i++){
        //printf("%d: %c.\n", i, i);
    //}
    return 0;
}

void menu() {
    int opcao;
    do {
        system("cls");
        printf("Selecione o tipo de �rvore a ser usado: \n");
        printf("1 - �rvore gen�rica\n");
        printf("2 - �rvore de busca bin�ria\n");
        printf("3 - �rvore AVL\n");
        scanf("%d", &opcao);
        switch(opcao) {
        case 1:
            //system("cls");
            //menu_generica();
            break;
        case 2:
            //system("cls");
            //menu_abb();
            break;
        case 3:
            system("cls");
            menu_avl();
            break;
        default:
            system("cls");
            printf("Opera��o inv�lida, tente novamente...\n");
            Sleep(DELAY);
        }
    } while (1);
}

void menu_avl() {
    int opcao;
    Avl a = cria_arvore_avl();
    int n;
    do {
        system("cls");
        printf("1 - Inserir um ponto de rede\n");
        printf("2 - Menor trafego\n");
        printf("3 - Quantidade ocioso\n");
        printf("4 - N�mero deriva��o\n");
        printf("5 - Cheia\n");
        printf("6 - N�vel do n�\n");
        printf("7 - Iguais\n");
        printf("8 - Imprimir �rvore\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            menu_insere_avl(&a);
            break;
        case 2:
            system("cls");
            printf("O menor tr�fego da �rvore �: %d\n", get_trafego(menor_trafego_avl(a)));
            Sleep(DELAY);
            break;
        case 3:
            system("cls");
            printf("N�s ociosos: %d\n", qtde_ocioso_avl(a));
            Sleep(DELAY);
            break;
        case 4:
            system("cls");
            printf("N�s de deriva��o da �rvore: %d\n", nro_derivacao_avl(a));
            Sleep(DELAY);
            break;
        case 5:
            system("cls");
            printf("A �rvore %s cheia", cheia_avl(a)?"�":"n�o �");
            Sleep(DELAY);
            break;
        case 6:
            system("cls");
            printf("N�: ");
            scanf("%d", &n);
            printf("N�vel do n� %d: %d\n", n, nivel_no_avl(a, n));
            Sleep(DELAY);
            break;
        case 7:
            system("cls");
            printf("Esta fun��o deve ser testada a n�vel de implementa��o\n");
            Sleep(DELAY * 2);
            break;
        case 8:
            system("cls");
            if(arvore_vazia_avl(a))
                printf("Arvore vazia...");
            else
                exibe_arvore_avl(a);
            putchar('\n');
            system("pause");
            break;
        case 0:
            system("cls");
            printf("Desalocando �rvore e saindo...\n");
            libera_arvore_avl(&a);
            exit(0);
        default:
            system("cls");
            printf("Opera��o inv�lida...\n");
            Sleep(DELAY);
        }
    } while (1);
    if(a)
        libera_arvore_avl(&a);
}

void menu_insere_avl(Arvore *a) {
    char id[20], local[30];
    int capacidade, trafego;
    system("cls");

    printf("Identificador do ponto de rede: ");
    fflush(stdin);
    scanf("%s", id);

    printf("Localiza��o do ponto de rede: ");
    fflush(stdin);
    scanf("%s", local);

    printf("Capacidade do ponto de rede: ");
    fflush(stdin);
    scanf("%d", &capacidade);

    do {
        printf("Tr�fego do ponto de rede: ");
        fflush(stdin);
        scanf("%d", &trafego);
        if(trafego > capacidade)
            printf("N�o � poss�vel o tr�fego de dados ser maior do que a capacidade...\n");
    } while(trafego > capacidade);

    reg_avl r = cria_reg_avl(id, local, capacidade, trafego);

    insere_avl(a, r);
    system("cls");
    printf("Ponto inserido com sucesso!\n");
    printf("Identificador: %s\nCapacidade: %d\n", id, capacidade);
}

void menu_remove_avl(Arvore *a) {
    int elem;
    system("cls");
    fflush(stdin);
    printf("Campo chave do ponto de rede a ser removido: ");
    scanf("%d", &elem);
}
