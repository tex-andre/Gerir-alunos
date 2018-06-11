#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <stdbool.h>

typedef struct {
    char nome[30];
    short numero;
    char mail[30];
    short nota_final;
    char estado[11];

}Aluno;

typedef struct {
    char nome [30];
    short numero;
    char e_mail [30];

#warning TODO (tex#1#): struct professor: turmas que tem ou disciplinas?

}professor;

void pede_dados(char *nome, int *numero,char *mail, int *nota_final);
Aluno *cria_estrutura(char *nome, int numero, char  *mail, int nota_final);
void imprimir_aluno (Aluno *a);
bool aprovacao(int nota_final);
//Aluno *editar_aluno (Linkedlist *l, Aluno *a);	
//Aluno/**??**/ *remover_aluno (Linkedlist *l, Aluno *a);

#endif // FUNCOES_H_INCLUDED
