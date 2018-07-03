#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct registro* reg_avl;
typedef struct no* Avl;

Avl cria_arvore_avl();
int arvore_vazia_avl(Avl a);
int insere_avl(Avl *a, reg_avl registro);
int _insere_avl(Avl *a, reg_avl registro, int *bal);
int remove_avl(Avl *a, int trafego);
Avl busca_bin_avl(Avl a, int trafego);
void exibe_arvore_avl(Avl a);
void exibe_ordenado_avl(Avl a);
void libera_arvore_avl(Avl *a);

int rot_dir(Avl *a);
int rot_esq(Avl *a);
int rot_dir_esq(Avl *a);
int rot_esq_dir(Avl *a);

int balancear_esq(Avl *a);
int balancear_dir(Avl *a);

//Funções do trabalho
reg_avl menor_trafego_avl(Avl a);
int qtde_ocioso_avl(Avl a);
int nro_derivacao_avl(Avl a);
int cheia_avl(Avl a);
int nivel_no_avl(Avl a, int elem);
int iguais_avl(Avl a1, Avl a2);

char* get_identificador(Avl a);
int get_capacidade(Avl a);
int get_trafego(reg_avl a);

reg_avl cria_reg_avl(char *id, char *local, int capacidade, int trafego);

int exibe_arvore_avl_2d(Avl a);
int _exibe_arvore_avl_2d(Avl a, int esquerda, int deslocamento, int profundidade, char s[20][255]);

#endif // AVL_H_INCLUDED
