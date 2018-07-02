

typedef struct reg Estrutura;
typedef struct reg *Reg;
typedef struct no No;
typedef struct no *Arv;

Arv cria_arvore();
int arvore_vazia(Arv *arv);
int libera_arvore(Arv *arv);
void exibe_arvore(Arv *a);
void exibe_arvore_por_nome(Arv *a);
void exibe_ordenado(Arv *a);
void exibe_ordenado_por_nome(Arv *a);
void mostrar_registro(Reg r);
No *criar_no();
No *criar_no_temp(char *nome,char *curso,int idade);
int insere_copia_ord(Arv *a,No *no);
int insere_ord(Arv *a,No *no);
int remove_ord(Arv *a,int idade);
void imprimir_arvore(Arv a);
Reg maior(Arv a);
void faixaIdade(Arv a,int *quantidade,int min,int max);
int de_maior(Arv a);
int qtde_alunos(Arv a,int ini,int fim);
void um_filho_recursiva(Arv a,int *quantidade);
int um_filho(Arv a);
int altura_arv(Arv a);
void altura_arv_temp(Arv a,int nivel,int *max);
int completa(Arv a);
int completa_temp(Arv a,Arv a_raiz,int nivel_raiz);
int profundidade_no(Arv a,Reg r);
int profundidade_no_temp(Arv a,Reg r,int nivel);
No *remove_menor(Arv *a);
void juntar_temp(Arv a1,Arv a2,Arv *a3);
Arv juntar(Arv a1,Arv a2);
void mostra_no(No *no);

