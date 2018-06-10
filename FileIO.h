#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

#include "linkedlist.h"

FILE* escreve_f(const char* local);
FILE* le_f (const char* local);
FILE* escreve_fB(const char* local);
FILE* le_fB(const char local);
FILE* cria_ponteiros (const char* local);
int output_lista(char* destino, LinkedList* l);
void formato_txt(FILE* fp, LinkedList* l);
void formato_csv(FILE* fp, LinkedList* l);
void formato_html(FILE* fp, LinkedList* l);

#endif // FILEIO_H_INCLUDED
