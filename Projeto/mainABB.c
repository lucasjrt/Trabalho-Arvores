#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int menu_principal(){
    system("cls");
    int opcao;
    printf("1 - Criar uma nova arvore\n");
    printf("2 - Inserir aluno\n");
    printf("3 - Mostrar arvore\n");
    printf("4 - Mostrar arvore ordenado (por idade)\n");
    printf("5 - Remover aluno\n");
    printf("6 - Retornar o aluno mais velho\n");
    printf("7 - Retornar a quantidade de alunos de maiores\n");
    printf("8 - Mostrar quantidade de alunos que estao em um faixa de idade\n");
    printf("9 - Verificar se a arvore eh completa ou nao\n");
    printf("10 - Mostrar a altura da arvore\n");
    printf("11 - Juntar duas arvores (Para isso sera necessario inserir dados para outra arvore)\n");
    printf("12 - Procurar se existe alguem com determinada idade\n");
    printf("13 - Sair\n");
    scanf("%d",&opcao);
    return opcao;
}
int main(){

    Arv a[10];
    int quantidade_arvores = 0;
    int i,opcao=0,opcao2,opcao3,opcao4,check;

    while(opcao!=13){
        opcao = menu_principal();
        if(opcao<1||opcao>12)printf("Opcao invalida\n");
        if(opcao==1){
            if(quantidade_arvores<10){
                a[quantidade_arvores] = cria_arvore();
                quantidade_arvores++;
                printf("Cadastro criado com sucesso\n");
            }
            else printf("Erro, nao eh possivel criar mais nenhum cadastro\n");
        }
        if(opcao == 2){
            if(quantidade_arvores>1){
                printf("Em qual cadastro deseja inserir esse novo aluno? (Digite o numero referente ao cadastro)\n");
                    for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                        exibe_arvore_por_nome(&(a[i]));
                        printf("\n");
                    }
                    printf("Numero do cadastro: ");
                    scanf("%d",&opcao2);
                    if(opcao2>=0&&opcao2<=quantidade_arvores){
                        No *no = criar_no();
                        if(insere_ord(&(a[opcao2]),no)){
                            mostra_no(no);
                        }else printf("Erro na insercao\n");
                    }
                    else printf("Cadastro digitado nao existe\n");
            }
            else {
                if(quantidade_arvores==1){
                    No *no = criar_no();
                    insere_ord(&(a[0]),no);
                    mostra_no(no);
                }
                else {
                    printf("Erro, nao existe cadastro para se inserir um aluno\n");
                }
            }
        }
        if(opcao==3){
            if(quantidade_arvores>1){
                for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                }
                printf("Qual cadastro deseja mostrar? ");
                fflush(stdin);
                scanf("%d",&opcao2);
                if(opcao2>=0&&opcao2<quantidade_arvores){
                    exibe_arvore_por_nome(&(a[opcao2]));
                }
                else printf("Cadastro digitado nao existe\n");
            }
            else{
                if(quantidade_arvores==1){
                    exibe_arvore_por_nome(&(a[0]));
                }
                else printf("Nao existe cadastro para mostrar\n");
            }
        }
        if(opcao==4){
            if(quantidade_arvores>1){
                for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                }
                printf("Qual cadastro deseja mostrar ordenado? ");
                fflush(stdin);
                scanf("%d",&opcao2);
                if(opcao2>=0&&opcao2<quantidade_arvores){
                    exibe_ordenado_por_nome(&(a[opcao2]));
                    printf("\n");
                }
                else printf("Cadastro digitado nao existe\n");
            }
            else{
                if(quantidade_arvores==1){
                    exibe_arvore_por_nome(&(a[0]));
                }
                else printf("Nao existe cadastro para mostrar\n");
            }
        }
        if(opcao==5){
            if(quantidade_arvores>1){
                for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                }
                printf("Qual cadastro deseja remover um aluno? ");
                scanf("%d",&opcao2);
                if(opcao2>=0&&opcao2<quantidade_arvores){
                    exibe_arvore_por_nome(&(a[opcao2]));
                    printf("Digite a idade que deseja remover: ");
                    scanf("%d",&opcao3);
                    check = remove_ord(&(a[opcao2]),opcao3);
                    if(check ==1)printf("Removido com sucesso\n");
                    else printf("Erro na remocao\n");
                }
                else printf("Cadastro digitado nao existe\n");
            }
            else{
                if(quantidade_arvores==1){
                    exibe_arvore_por_nome(&(a[0]));
                    printf("Digite a idade que deseja remover: ");
                    scanf("%d",&opcao2);
                    check = remove_ord(&(a[0]),opcao2);
                    if(check ==1)printf("Removido com sucesso\n");
                    else printf("Erro na remocao\n");
                }
                else printf("Nao existe cadastro para mostrar\n");
            }
        }
        if(opcao==6){
            if(quantidade_arvores==1){
                Reg r;
                r = maior(a[0]);
                printf("O aluno mais velho cadastrado eh\n");
                mostrar_registro(r);
            }
            else{
                if(quantidade_arvores==0)printf("Erro, nenhum cadastro existente\n");
                else{
                    for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                    }
                    printf("Qual cadastro deseja analisar? ");
                    scanf("%d",&opcao2);
                    if(opcao2>=0&&opcao2<quantidade_arvores){
                        Reg r;
                        printf("O aluno mais velho cadastrado eh\n");
                        r = maior(a[opcao2]);
                        mostrar_registro(r);
                    }
                    else printf("Cadastro digitado nao existe\n");
                }
            }
        }
        if(opcao==7){
            if(quantidade_arvores==0)printf("Erro, nenhum cadastro existente\n");
            else {
                if(quantidade_arvores==1)printf("A quantidade de alunos de maiores eh %d",de_maior(a[0]));
                else{
                    for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                    }
                    printf("Qual cadastro deseja analisar? ");
                    scanf("%d",&opcao2);
                    if(opcao2>=0&&opcao2<quantidade_arvores){
                        printf("A quantidade de alunos de maior eh %d\n",de_maior(a[opcao2]));
                    }
                    else printf("Cadastro digitado nao existe\n");
                }
            }
        }
        if(opcao==8){
            if(quantidade_arvores==0)printf("Erro, nenhum cadastro existente\n");
            else{
                if(quantidade_arvores==1){
                    printf("Qual eh a faixa de idade procurada? (Ex: 19 23) ");
                    scanf("%d%d",&opcao2,&opcao3);
                    printf("A quantidade de alunos na faixa de %d a %d eh %d\n",opcao2,opcao3,qtde_alunos(a[0],opcao2,opcao3));
                }
                else {
                    for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                    }
                    printf("Qual cadastro deseja analisar? ");
                    scanf("%d",&opcao2);
                    if(opcao2>=0&&opcao2<quantidade_arvores){
                        printf("Qual eh a faixa de idade procurada? (min max)");
                        scanf("%d%d",&opcao3,&opcao4);
                        printf("A quantidade de alunos na faixa de %d a %d eh %d\n",opcao3,opcao4,qtde_alunos(a[opcao2],opcao3,opcao4));
                    }
                    else printf("Cadastro digitado nao existe\n");
                }
            }
        }
        if(opcao==9){
            if(quantidade_arvores==0)printf("Erro, nenhum cadastro existente\n");
            else{
                if(quantidade_arvores==1){
                    if(completa(a[0]))printf("A arvore eh completa\n");
                    else printf("A arvore eh incompleta\n");
                }
                else {
                    for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                    }
                    printf("Qual cadastro deseja analisar? ");
                    scanf("%d",&opcao2);
                    if(opcao2>=0&&opcao2<quantidade_arvores){
                        if(completa(a[opcao2]))printf("A arvore eh completa\n");
                        else printf("A arvore eh incompleta\n");
                    }
                    else printf("Cadastro digitado nao existe\n");
                }
            }
        }
        if(opcao==10){
            if(quantidade_arvores==0)printf("Erro, nenhum cadastro existente\n");
            else{
                if(quantidade_arvores==1){
                    printf("A altura da arvore eh %d\n",altura_arv(a[0]));
                }
                else {
                    for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                    }
                    printf("Qual cadastro deseja analisar? ");
                    scanf("%d",&opcao2);
                    if(opcao2>=0&&opcao2<quantidade_arvores){
                        printf("A altura da arvore eh %d\n",altura_arv(a[opcao2]));
                    }
                    else printf("Cadastro digitado nao existe\n");
                }
            }
        }
        if(opcao==11){
            if(quantidade_arvores<2)printf("Voce deve ter no minimo 2 cadastros craidos para fazer a juncao\n");
            else {
                for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                    }
                    printf("Quais cadastros deseja analisar? (Ex: 1 2)");
                    scanf("%d%d",&opcao2,&opcao3);
                    if(opcao2>=0&&opcao2<quantidade_arvores&&opcao3>=0&&opcao3<quantidade_arvores){
                        a[quantidade_arvores] = juntar(a[opcao2],a[opcao3]);
                        quantidade_arvores++;
                    }
                    else printf("Cadastro digitado nao existe\n");
            }
        }
        if(opcao==12){
            if(quantidade_arvores==0)printf("Erro, nenhum cadastro existente\n");
            else{
            if(quantidade_arvores==1){
                    printf("Qual eh a idade que deseja procurar\n");
                    scanf("%d",&opcao3);
                    if(busca_bin(a[0],opcao3))printf("O valor foi encontrado\n");
                    else printf("O valor nao foi encontrado\n");
                }
                else {
                    for(i=0;i<quantidade_arvores;i++){
                        printf("Cadastro %d:\n",i);
                    }
                    printf("Qual cadastro deseja analisar? ");
                    scanf("%d",&opcao2);
                    if(opcao2>=0&&opcao2<quantidade_arvores){
                        printf("Qual eh a idade que deseja procurar\n");
                        scanf("%d",&opcao3);
                        if(busca_bin(a[opcao2],opcao3))printf("O valor foi encontrado\n");
                        else printf("O valor nao foi encontrado\n");
                    }
                    else printf("Cadastro digitado nao existe\n");
                }

            }
        }




        fflush(stdin);
        printf("Tecla algo para continuar...");
        getchar();
    }
    return 0;
}

