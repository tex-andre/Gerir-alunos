#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED
#include "linkedlist.h"

FILE* escreve_f(const char* local);
FILE* le_f (const char* local);
FILE* escreve_fB(const char* local);
FILE* le_fB(const char *local);
FILE* cria_ponteiros (const char* local);
int export_list(LinkedList* l);
void  export_list_txt(char* destino, LinkedList* l);
void fprint_node_txt (FILE* fp, Aluno *a);
void fprint_tabs_txt (FILE* fp, char* str);
void  export_list_csv(char* destino, LinkedList* l);
void  export_list_html(char* destino, LinkedList* l);

#endif // FILEIO_H_INCLUDED
