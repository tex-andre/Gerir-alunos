#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**********Todos os Menus Existentes************/


 void menu(LinkedList *l, const char* list_file);
 void menu_gerir_alunos(LinkedList *l);
 void menu_pesquisa(LinkedList *l);
 void menu_importar(LinkedList *l);
 void menu_exportar(LinkedList *l);
 void menu_ver(LinkedList *l);

 void print_menu_header(char* str);
 void print_menu_option(char* str);
 void print_menu_end_line();


 void menu_estatistica(LinkedList *l);
 void menu_remover_alunos(LinkedList *l);
 void menu_editar_aluno(LinkedList *l);
 void define_campos_de_edicao (Aluno* a);




#endif // MENU_H_INCLUDED
