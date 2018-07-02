#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED
#include "linkedlist.h"

FILE* escreve_f(const char* local);
FILE* le_f (const char* local);
FILE* escreve_fB(const char* local);
FILE* le_fB(const char *local);
FILE* cria_ponteiros (const char* local);
int copia_ficheiro(const char* origem, const char* destino);
#endif // FILEIO_H_INCLUDED
