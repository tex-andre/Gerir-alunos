#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Aluno_H.h"


Aluno *cria_aluno (){

    char nome[30], mail[30];
    int numero, nota_final;
    fflush(stdin);
    printf("\n\n");
    printf("\t\t\tIntroduza os seguintes dados\t\t\t");
    printf("\n\n\n");
    printf("Nome: ");
    gets(nome);
    printf("Numero: ");
    scanf("%d", &numero);
    printf("Mail: ");
    scanf("%s", &mail);
    printf("Nota Final: ");
    scanf("%d", &nota_final);

    cria_estrutura(nome,numero,mail,nota_final);

}

Aluno *cria_estrutura(char *nome, int numero, char  *mail, int nota_final){

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

    printf("************************");
    printf("\n");
        printf("Nome do Aluno: %s ", a->nome);
        printf("\n");
        printf("Numero do Aluno: %d ", a->numero);
        printf("\n");
        printf("Mail do Aluno: %s ", a->mail);
        printf("\n");
        printf("Nota Final do Aluno: %d ", a->nota_final);
        printf("\n");
        printf("Estado do Aluno: %s", a->estado);
        printf("\n");

}

bool aprovacao(int nota_final){
    return (nota_final >= 10) ? 1 : 0;
}



