#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Aluno_H.h"


void pede_dados (char *nome, int* numero, char *mail, int* nota_final){

    fflush(stdin);
    printf("\n\n");
    printf("\t\t\tIntroduza os seguintes dados\t\t\t");
    printf("\n\n\n");
    printf("Nome: ");
    gets(nome);
    printf("Numero: ");
    scanf("%d", numero);
    printf("E-mail: ");
    scanf("%s", mail);
    printf("Nota Final: ");
    scanf("%d", nota_final);

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
    printf("| %s | %d | %s | %d | %s |\n", a->nome, a->numero, a->mail, a->nota_final, a->estado);
}

bool aprovacao(int nota_final){
    return (nota_final >= 10) ? 1 : 0;
}



