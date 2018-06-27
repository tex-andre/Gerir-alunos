#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**********Todos os Menus Existentes************/


 void menu(LinkedList *l);
 void menu_gerir_alunos(LinkedList *l);
 void menu_pesquisa(LinkedList *l);
 void menu_importar(LinkedList *l);
 void menu_exportar(LinkedList *l);
 void menu_remover_alunos(LinkedList *l);
 void menu_sair_guardar(LinkedList *l);
 void menu_find(LinkedList *l);
 void print_menu_header(char* str);
 void print_menu_option(char* str);
 void print_menu_end_line();


#endif // MENU_H_INCLUDED
