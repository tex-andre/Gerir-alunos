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



void imprimir_aluno (Aluno *a){
    //printf("\n| %s | %d | %s | %hu | %s |\n", a->nome, a->numero, a->mail, a->nota_final, a->estado);

}


bool aprovacao(unsigned short nota_final){
    return (nota_final >= 10) ? 1 : 0;
}

int *editar_aluno_by_name(LinkedList*l){
    //Lista vazia?
    if(l->head == NULL)
    {
        printf("\nERRO: lista vazia!!\n");;
        return 0;
    }
    //Node* aux = l->head;

    // Verifica se o Aluno existe na lista ligada

        char buffer_nome[20];
        printf("Qual o a nome do aluno a que pretende editar?");
        fflush(stdin);
        gets(buffer_nome);
        printf("\n");
        Node* resultado=find_by_name(l,buffer_nome);
        if(resultado!= NULL){
            printf("Encontrado com sucesso!!\n");
            menu_editar_aluno(l);
        }
        else
            printf("Nao encontrado...\n");




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

