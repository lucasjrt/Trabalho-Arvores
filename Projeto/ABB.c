
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include"ABB.h"


struct reg{
    char nome[30],curso[30];
    int idade,nivel;
};

struct no{
   Reg reg;
   struct no *sae,*sad;
};

Arv cria_arvore(){
    return NULL;
}

int arvore_vazia(Arv *arv){
    if (arv!=NULL){
        if((*arv)==NULL){
            return 1;
        }
        else return 0;
    }
    else return -1;
}

int libera_arvore(Arv *arv){
    if(arv!=NULL){
        if(arvore_vazia(arv)==0){
            libera_arvore(&((*arv)->sae));
            libera_arvore(&((*arv)->sad));
            free((*arv)->reg);
            free(*arv);
            *arv = NULL;
        }
    }
    return 0;
}

void exibe_arvore(Arv *a){
    if(arvore_vazia(a)==1){
        printf("<>");
        return;
    }
    printf("<");
    printf("%d",(*a)->reg->idade);
    exibe_arvore(&((*a)->sae));
    exibe_arvore(&((*a)->sad));
    printf(">");
}

void exibe_arvore_por_nome(Arv *a){
    if(a!=NULL){
        if(arvore_vazia(a)==1){
            return;
        }
        printf("%s (%d)\n",(*a)->reg->nome,(*a)->reg->idade);
        exibe_arvore_por_nome(&((*a)->sae));
        exibe_arvore_por_nome(&((*a)->sad));
    }

}
void exibe_ordenado(Arv *a){
    if (a!=NULL){
        if(arvore_vazia(a)==0){
            exibe_ordenado(&((*a)->sae));
            printf("%s (%d)\n",(*a)->reg->nome,(*a)->reg->idade);
            exibe_ordenado(&((*a)->sad));
        }
    }
}
void exibe_ordenado_por_nome(Arv *a){
    if (a!=NULL){
        if(arvore_vazia(a)==0){
            exibe_ordenado_por_nome(&((*a)->sae));
            printf("%s (%d)\n",(*a)->reg->nome,(*a)->reg->idade);
            exibe_ordenado_por_nome(&((*a)->sad));
        }
    }
}

void mostrar_registro(Reg r){
    printf("%s\n",r->nome);
    printf("%s\n",r->curso);
    printf("%d\n",r->idade);
}

No *criar_no(){
    No *no;
    no = (No*)malloc(sizeof(No));
    if(no==NULL)return NULL;
    no->reg = (Reg) malloc(sizeof(struct reg));
    if(no->reg==NULL)return NULL;
    //no = (No*)malloc(sizeof(No));
    printf("Digite o nome: ");
    scanf("%s",no->reg->nome);
    printf("Digite o curso: ");
    scanf("%s",no->reg->curso);
    printf("Digite a idade: ");
    scanf("%d",&(no->reg->idade));
    no->sad = NULL;
    no->sae = NULL;
    no->reg->nivel=0;
    return no;
}

No *criar_no_temp(char *nome,char *curso,int idade){
    No *no;
    no = (No*)malloc(sizeof(No));
    if(no==NULL)return NULL;
    no->reg = (Reg) malloc(sizeof(struct reg));
    if(no->reg==NULL)return NULL;
    strcpy(no->reg->nome,nome);
    strcpy(no->reg->curso,curso);
    no->reg->idade = idade;
    no->sad = NULL;
    no->sae = NULL;
    no->reg->nivel=0;
    return no;
}
int insere_copia_ord(Arv *a,No *no){
    No *novoNo;
    novoNo = (No*)malloc(sizeof(No));
    if(novoNo==NULL)return -1;
    novoNo->reg = (Reg)malloc(sizeof(struct reg));
    if(novoNo->reg==NULL)return -1;
    novoNo->sae = NULL;
    novoNo->sad = NULL;
    novoNo->reg->idade = no->reg->idade;
    strcpy(novoNo->reg->curso,no->reg->curso);
    strcpy(novoNo->reg->nome,no->reg->nome);
    return insere_ord(a,novoNo);
}
int insere_ord(Arv *a,No *no){
    if(a!= NULL){
        if(arvore_vazia(a)){
            *a = no;
            return 1;
        }
        else {
            if(no->reg->idade<=(*a)->reg->idade){///printf("E menor ou igual que o q ja existe\n");
                no->reg->nivel++;
                return insere_ord(&(*a)->sae,no);
            }
            else { ///printf("E maior que o q ja existe\n");
                no->reg->nivel++;
                return insere_ord(&(*a)->sad,no);
            }
        }
    }
    return 0;
}

int remove_ord(Arv *a,int idade){
    if(a!=NULL){ ///Se o ponteiro passado para arvore nao e NULL
        if(arvore_vazia(a)==0){///Se a arvore nao for vazia
            if(idade>(*a)->reg->idade){ ///maior
                return remove_ord(&(*a)->sad,idade);
            }
            else {
                if (idade<(*a)->reg->idade){ ///menor
                    return remove_ord(&(*a)->sae,idade);
                }
                else {
                    if((*a)->sae==NULL&&(*a)->sad==NULL){ ///Achou o elemento e ele nao tem filhos
                        free((*a)->reg);
                        free(*a);
                        *a = NULL;
                        return 1;
                    }
                    else {
                        if((((*a)->sae==NULL)||((*a)->sad==NULL))){ ///Achou o elemento e ele tem 1 filho
                            if((*a)->sad==NULL){    ///Tem filho apenas a esquerda
                                No *aux;
                                aux = *a;
                                *a = (*a)->sae;
                                free(aux->reg);
                                free(aux);
                                return 1;
                            }
                            else {  ///Tem filho apenas a direita
                                No *aux;
                                aux = *a;
                                *a = (*a)->sad;
                                free(aux->reg);
                                free(aux);
                                return 1;
                            }
                        }
                        else{ ///Tem filho a direita e a esquerda
                            No *aux;
                            aux = (*a)->sae;
                            while(aux->sad!=NULL){  ///Encontra o maior filho a esquerda do no que vai ser removido
                                aux = aux->sad;
                            }
                            Reg reg;
                            reg = (*a)->reg;
                            (*a)->reg = aux->reg;
                            aux->reg = reg;
                            return remove_ord(&(*a)->sae,idade);
                        }
                    }
                }
            }
        }
        return 0;
    }
    return 0;
}


void imprimir_arvore(Arv a){
    int espacosTotais,pular;
    int nivelAvr = 4;
    espacosTotais = pow(2,nivelAvr)*4;

    int i;
    int nivelDoNo = 0;
    pular = espacosTotais/2;
    for (int k=0;k<=nivelAvr;k++,nivelDoNo++){
        for(i=0;i<pow(2,nivelDoNo);i++){
            for(int j=0;j<pular-2;j++){
                printf(" ");
            }

            printf("%2d",40);
            //elem++;
            //a = a->sae;
            for(int j=0;j<pular;j++){
                printf(" ");
            }

        }
        pular = pular/2;
        printf("\n\n\n");
    }
}

Reg maior(Arv a){
    if(arvore_vazia(&a)==0){
        while(a->sad != NULL){
            a = a->sad;
        }
        return a->reg;
    }
    return NULL;
}

void faixaIdade(Arv a,int *quantidade,int min,int max){
    if(arvore_vazia(&a)==0){
        if(a->reg->idade>=min && a->reg->idade<=max)(*quantidade)++;
        faixaIdade(a->sae,quantidade,min,max);
        faixaIdade(a->sad,quantidade,min,max);
    }
}

int de_maior(Arv a){
    int quantidade=0;
    faixaIdade(a,&quantidade,18,INT_MAX);
    return quantidade;
}

int qtde_alunos(Arv a,int ini,int fim){
    int quantidade=0;
    if(ini<=fim){
        faixaIdade(a,&quantidade,ini,fim);
        return quantidade;
    }
    else return -1;
}

void um_filho_recursiva(Arv a,int *quantidade){
    if(arvore_vazia(&a)==0){
        if((a->sae == NULL || a->sad == NULL)&&(a->sae != NULL || a->sad != NULL))(*quantidade)++;
        um_filho_recursiva(a->sae,quantidade);
        um_filho_recursiva(a->sad,quantidade);
    }
}
int um_filho(Arv a){
    int quantidade=0;
    um_filho_recursiva(a,&quantidade);
    return quantidade;
}

int altura_arv(Arv a){
    int nivel=0;
    altura_arv_temp(a,0,&nivel);
    return nivel;
}

void altura_arv_temp(Arv a,int nivel,int *max){
    if(arvore_vazia(&a)==0){
        if(nivel>*max){ ///Se o nivel atual for maior que o maior nivel registrado atribui o maior ao nivel
            *max = nivel;
        }
        altura_arv_temp(a->sae,(nivel+1),max);
        altura_arv_temp(a->sad,(nivel+1),max);
    }
}

int completa(Arv a){
    return completa_temp(a,a,altura_arv(a));
}
int completa_temp(Arv a,Arv a_raiz,int nivel_raiz){
    if(arvore_vazia(&a)==0){
        //printf("Esta verificando o No %d\n",a->reg->idade);
        if(a->sad!=NULL||a->sae!=NULL){///Eh No intermediario
            if(a->sae==NULL||a->sad==NULL){ ///Nao tem numero maximo de filhos
                printf("Nao tem o maximo de filhos, arvore eh incompleta em %d\n",a->reg->idade);
                return 0;
            }
        }
        else { ///Eh no folha
            if(profundidade_no(a_raiz,a->reg)+1<altura_arv(a_raiz)){///Eh um No folha que nao ocupa o ultimo e nem o penultimo nivel da arvore
                printf("A arvore eh incompleta em %d pois nivel da arvore = %d e nivel no = %d\n",a->reg->idade,nivel_raiz,profundidade_no(a_raiz,a->reg));
                return 0;
            }
        }
        int retorno;
        retorno = completa_temp(a->sae,a_raiz,nivel_raiz); ///Retorna 1 se a subarvore esquerda eh completa, 0 caso contrario
        if(retorno == 0)return 0; ///Caso ele tenha detetado que nao eh completa ja retorna
        return completa_temp(a->sad,a_raiz,nivel_raiz); ///Retorna 1 se a subarvore direita eh completa, 0 caso contrario
    }
    return 1; ///Ate o momento a arvore eh completa
}

int profundidade_no(Arv a,Reg r){
    int profundidade;
    profundidade = profundidade_no_temp(a,r,0);
    //printf("A profundidade do No %d eh %d\n",r->idade,profundidade);
    return profundidade;
}
int profundidade_no_temp(Arv a,Reg r,int nivel){
    if(arvore_vazia(&a)==0){
        if(a->reg->idade == r->idade && a->reg->nome == r->nome && a->reg->curso == r->curso)return nivel;
        int retorno;
        retorno = profundidade_no_temp(a->sae,r,nivel+1); ///Retorna o nivel caso tenho encontrado o No, -1 caso contrario
        if(retorno!=-1)return retorno;
        retorno = profundidade_no_temp(a->sad,r,nivel+1);
        if(retorno!=-1)return retorno;
    }
    return -1;
}

No *remove_menor(Arv *a){
    if(a!=NULL){
        if(arvore_vazia(a)==0){
            if((*a)->sae!=NULL){
                return remove_menor(&(*a)->sae);
            }
            else {
                if((*a)->sad==NULL){
                    No *no;
                    no = *a;
                    *a = NULL;
                    return no;
                }
                else {
                    No *no;
                    no = *a;
                    *a = (*a)->sad;
                    no->sae = NULL;
                    no->sad = NULL;
                    return no;
                }
            }
        }
        return NULL;
    }
    return NULL;
}


void juntar_temp(Arv a1,Arv a2,Arv *a3){
    if(a1!=NULL && a2!=NULL){
        juntar_temp(a1->sae,a2->sae,a3);
        insere_copia_ord(a3,a1);
        insere_copia_ord(a3,a2);
        juntar_temp(a1->sad,a2->sad,a3);
    }
    else {
        if(a1!=NULL && a2==NULL){
            juntar_temp(a1->sae,a2,a3);
            insere_copia_ord(a3,a1);
            juntar_temp(a1->sad,a2,a3);
        }
        else {
            if(a2!=NULL && a1==NULL){
                juntar_temp(a1,a2->sae,a3);
                insere_copia_ord(a3,a2);
                juntar_temp(a1,a2->sad,a3);
            }
        }
    }
}

Arv juntar(Arv a1,Arv a2){
    Arv a3;
    a3 = cria_arvore();
    juntar_temp(a1,a2,&a3);
    return a3;
}



void mostra_no(No *no){
    if(no != NULL){
        printf("Nome: %s\n",no->reg->nome);
        printf("Idade %d\n",no->reg->idade);
        printf("Curso %s\n",no->reg->curso);
    }
}


int busca_bin(Arv a,int idade){
    if(a==NULL)return 0;
    if(a->reg->idade == idade){
        return 1;
    }
    if(busca_bin(a->sae,idade))return 1;
    return busca_bin(a->sad,idade);
    return 0;
}
