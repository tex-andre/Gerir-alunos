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

int editar_aluno (Aluno* a){


}

