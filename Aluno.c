#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Aluno.h"



Aluno* cria_aluno(){

    char nome [30], mail[30];
    short numero;
    unsigned short nota_final;

    pede_dados(nome,&numero,mail,&nota_final);
    Aluno *a = cria_estrutura(nome,numero,mail,nota_final);
   //imprimir_aluno(a);


    return a;
}
void pede_dados (char *nome, int* numero, char *mail, unsigned short* nota_final){

    fflush(stdin);
    printf("\n\n");
    printf("\t\t\tIntroduza os seguintes dados\t\t\t");
    printf("\n\n\n");
    printf("Nome: ");
    gets(nome);
    printf("Numero: ");
    scanf("%d", numero);
    fflush(stdin);
    printf("E-mail: ");
    gets(mail);
    printf("Nota Final: ");
    scanf("%hu", nota_final);

}

Aluno *cria_estrutura(char *nome, int numero, char  *mail, unsigned short nota_final){

    Aluno *a=(Aluno*) malloc(sizeof(Aluno));

    strcpy(a->nome,nome);

    a->numero = numero;

    strcpy(a->mail,mail);

    a->nota_final = nota_final;
    if(aprovacao(nota_final))
        strcpy(a->estado, "Aprovado");
    else
        strcpy(a->estado, "Reprovado");

    return a;
}

bool aprovacao(unsigned short nota_final){
    return (nota_final >= 10) ? 1 : 0;
}

void editar_aluno_by_name(Aluno *a){

    /*******Novo nome do aluno que o user pretende editar*****/

        char *buffer_novo_nome;
        printf("Qual o a novo nome do aluno a que pretende editar?");
        fflush(stdin);
        gets(buffer_novo_nome);
        printf("\n");
        strcpy(a->nome, buffer_novo_nome);

}

void editar_aluno_by_number(Aluno *b){

        int buffer_novo_number;
        printf("Qual o a novo numero do aluno a que pretende editar?");
        fflush(stdin);
        scanf("%d", &buffer_novo_number);
        printf("\n");
        b->numero=buffer_novo_number;

}

void editar_aluno_by_email(Aluno *c){

        char *buffer_novo_email;
        printf("Qual o a novo email do aluno a que pretende editar?");
        fflush(stdin);
        gets(buffer_novo_email);
        printf("\n");
        strcpy(c->mail, buffer_novo_email);


}

int num_aprovados(LinkedList* l){
    //Lista vazia?
    if(l->head == NULL){
        printf("\nERRO: lista vazia!!\n");;
        return 0;
    }
    Node* aux = l->head;
    int num = 0;

    while(aux != NULL){
        if(aprovacao(aux->aluno->nota_final))
            num++;                              //conta elementos da lista aprovados
        aux = aux->next;
    }
    return num;
}

float media_final(LinkedList* l){
    //Lista vazia?
    if(l->head == NULL){
        printf("\nERRO: lista vazia!!\n");;
        return 0;
    }

    float soma = 0;
    float media;
    Node* aux = l->head;

    while(aux != NULL){
        soma += aux->aluno->nota_final;
        aux = aux->next;
    }
    media = (float)soma /length(l);
    return (float)media;
}

