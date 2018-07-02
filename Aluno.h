#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <stdbool.h>

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
}professor;

Aluno* cria_aluno();
void pede_dados(char *nome, int *numero,char *mail, unsigned short *nota_final);
Aluno *cria_estrutura(char *nome, int numero, char  *mail, unsigned short nota_final);
bool aprovacao(unsigned short nota_final);
void editar_aluno_by_name(Aluno *a);
void editar_aluno_by_number(Aluno *a);
void editar_aluno_by_email(Aluno *a);
void editar_aluno_by_nota(Aluno* a);


#endif // FUNCOES_H_INCLUDED
