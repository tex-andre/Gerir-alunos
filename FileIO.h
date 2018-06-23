#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED
#include "linkedlist.h"

FILE* escreve_f(const char* local);
FILE* le_f (const char* local);
FILE* escreve_fB(const char* local);
FILE* le_fB(const char *local);
FILE* cria_ponteiros (const char* local);
int output_lista(LinkedList* l);
void formato_txt(char* destino, LinkedList* l);
void fprint_node (FILE* fp, Aluno *a);
void fprint_tabs(FILE* fp, char* str);
void formato_csv(char* destino, LinkedList* l);
void formato_html(char* destino, LinkedList* l);

#endif // FILEIO_H_INCLUDED
