#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "ABB.h"

struct dados {
    char nome[20];
    int idade;
    char curso[15];
};

struct no {
    Aluno aluno;
    Arvore sad, sae;
};

Arvore cria_vazia() {
    Arvore a = (Arvore) malloc(sizeof(struct no));
    if(a == NULL)
        return NULL;
    a->sae = NULL;
    a->sad = NULL;
    return a;
}

Arvore cria_arvore(Aluno aluno, Arvore sae, Arvore sad) {
    Arvore a = (Arvore) malloc(sizeof(struct no));
    if(a == NULL)
        return NULL;
    a->aluno = aluno;
    a->sae = sae;
    a->sad = sad;
    return a;
}

int arvore_vazia(Arvore a) {
    if(a->sae == NULL && a->sad == NULL)
        return 1;
    return 0;
}

void libera_arvore(Arvore *a) {
    if(arvore_vazia(*a) == NULL)
        return;
    libera_arvore(&(*a)->sae);
    libera_arvore(&(*a)->sad);
    free(*a);
}

int existe(Arvore a, Aluno elem) {
    int encontrado = 0;
    if(a->aluno == elem)
        return 1;
    if(!arvore_vazia(a->sae))
        encontrado = existe(a->sae, elem);
    if(!arvore_vazia(a->sad) && !encontrado)
        encontrado = existe(a->sad, elem);
    return encontrado;
}

int remove_folha(Arvore *a, Aluno aluno) {
    int encontrado = 0;
    if(!arvore_vazia(*a)) {
        if((*a)->aluno == aluno) {
            free(a);
            return 1;
        } else {
            if(!arvore_vazia((*a)->sae))
                encontrado = remove_folha(&(*a)->sae, aluno);
            if(!arvore_vazia((*a)->sad) && !encontrado)
                encontrado = remove_folha(&(*a)->sad, aluno);
            return encontrado;
        }
    } else {
        printf("Erro, nao é possível remover uma folha de uma árvore vazia\n");
        return 0;
    }
    return 1;
}

void print_arvore(Arvore a) {
    if(!arvore_vazia(a))
        printf("%d < ", a->aluno->idade);
    if(!arvore_vazia(a->sae))
        print_arvore(a->sae);
    printf(", ");
    if(!arvore_vazia(a->sad))
        print_arvore(a->sad);
    printf(">");
}

Aluno maior(Arvore a) {
    Aluno aluno = (Aluno) malloc(sizeof(struct dados));
    return aluno;
}

int de_maior(Arvore a){
    return 0;
}

int qtde_alunos(Arvore a, int ini, int fim){
    return 0;
}

int um_filho(Arvore a) {
    return 1;
}

int completa (Arvore a) {
    return 1;
}

Arvore juntar (Arvore a1, Arvore a2) {
    return a1;
}

char *get_nome(Aluno a) {
    return a->nome;
}

int get_idade(Aluno a) {
    return a->idade;
}

char *get_curso(Aluno a) {
    return a->curso;
}

void set_nome(Aluno a, char *nome) {
    strcpy(a->nome, nome);
}

void set_idade(Aluno a, int idade) {
    a->idade = idade;
}

void set_curso(Aluno a, char *curso) {
    strcpy(a->curso, curso);
}

int bytes_struct_dados() {
    return sizeof(struct dados);
}

Arvore *get_sae_add(Arvore a) {
    return &(a->sae);
}

Arvore *get_sad_add(Arvore a) {
    return &(a->sad);
}

Aluno get_aluno(Arvore a) {
    return a->aluno;
}
