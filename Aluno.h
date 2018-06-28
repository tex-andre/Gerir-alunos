#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <stdbool.h>
#include "linkedlist.h"





typedef struct {
    char nome[30];
    int numero;
    char mail[30];
    unsigned short nota_final;
    char estado[11];
}Aluno;

typedef struct {
    char nome [30];
    int numero;
    char e_mail [30];

#warning TODO (tex#1#): struct professor: turmas que tem ou disciplinas?

}professor;

Aluno* cria_aluno();
void pede_dados(char *nome, int *numero,char *mail, unsigned short *nota_final);
Aluno *cria_estrutura(char *nome, int numero, char  *mail, unsigned short nota_final);
void imprimir_aluno (Aluno *a);
bool aprovacao(unsigned short nota_final);
int editar_aluno_by_name(LinkedList*l);


#endif // FUNCOES_H_INCLUDED
