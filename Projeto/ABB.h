#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

typedef struct dados* Aluno;
typedef struct no* Arvore;

Arvore cria_vazia(); //Cria uma Arvore vazia
Arvore cria_arvore(Aluno a, Arvore sae, Arvore sad); //Cria uma arvore
int arvore_vazia(Arvore a); //Verifica se uma Arvore e vazia
void libera_arvore(Arvore *a); //Desaloca cada espaço da arvore
int existe(Arvore a, Aluno elem);
int remove_folha(Arvore *a, Aluno aluno);
void print_arvore(Arvore a);


Aluno maior(Arvore a); // Aluno mais velho
int de_maior(Arvore a); // Alunos idade > 18
int qtde_alunos(Arvore a, int ini, int fim); // Idade entre ini e fim
int um_filho(Arvore a); // Qtd nó da ABB que possuem apenas 1 filho;
int completa (Arvore a); // Verifica se a ABB é completa
Arvore juntar (Arvore a1, Arvore a2); // Retorna uma Arvore que é a intercalação de a1 e a2
char *get_nome(Aluno a);
int get_idade(Aluno a);
char *get_curso(Aluno a);
void set_nome(Aluno a, char *nome);
void set_idade(Aluno a, int idade);
void set_curso(Aluno a, char *curso);
int bytes_struct_dados();
Arvore *get_sae_add(Arvore a);
Arvore *get_sad_add(Arvore a);
Aluno get_aluno(Arvore a);

#endif // ABB_H_INCLUDED
