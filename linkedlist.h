/**H*********************************************************************
* FILENAME :        linkedlist.h
*
* DESCRIPTION :
*       Library implementing a single Linked List data structure to store
*       integer values - for educational purposes (TP/LEEC/IPT.pt)
*
* STRUCTS :
*       Node
*       LinkedList
*
* PUBLIC FUNCTIONS :
*       LinkedList*     create();
*       void    destroy(LinkedList *l);
*       int     insert_tail(LinkedList *l, int info);
*       int     insert_head(LinkedList *l, int info);
*       int     contains(LinkedList *l, int info);
*       int     remove_node(LinkedList *l, int info);
*       int     peek_head(LinkedList *l);
*       int     peek_tail(LinkedList *l);
*       int     remove_first();
*       int     remove_last();
*       int     length(LinkedList *l);
*       Node*   find(LinkedList *l, int value);
*       void    sort(LinkedList *l);
*       void    reverse(LinkedList *l);
*       void    print_list(LinkedList *l);
*
* AUTHOR :    Renato Panda (renato.panda@ipt.pt) DATE :    13 May 17
*
* CHANGES :
*
* VERSION   DATE        WHO     DETAIL
* 1.0       13May17     panda   Initial implementation
*
*H*/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "Aluno.h"


typedef struct _Node {
    Aluno* aluno;
    struct _Node *prev;
    struct _Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} LinkedList;

LinkedList* create();
void destroy(LinkedList *l);
int insert_tail(LinkedList *l, Aluno* info);
int insert_head(LinkedList *l, Aluno* info);
int contains(LinkedList *l, Aluno* info);
int remove_node(LinkedList *l, int num_aluno);
int remove_node_by_name(LinkedList *l, char *nome_aluno);
Aluno* peek_head(LinkedList *l);
Aluno* peek_tail(LinkedList *l);
int remove_first(LinkedList *l);
int remove_last(LinkedList *l);
int length(LinkedList *l);
Node* find(LinkedList *l);
<<<<<<< HEAD
Node* find_by_name(LinkedList *l, Aluno* info);
Node* find_by_number(LinkedList *l, Aluno* info);
=======
Node* find_by_name(LinkedList *l, char* info);
Node* find_by_number(LinkedList *l, int info);   //done
>>>>>>> master
void sort(LinkedList *l);
void reverse(LinkedList *l);
void print_list(LinkedList *l);
void print_node (Aluno *a);
int num_aprovados(LinkedList* l);
float media_final(LinkedList* l);
void guardar_sair(LinkedList* l, const char* list_file);
LinkedList* find_all_by_name(LinkedList *l, char* info);
LinkedList *find_all_aprovados(LinkedList *l);
LinkedList *find_all_reprovados(LinkedList *l);
void percentagem_aprovados(LinkedList *aprovados, LinkedList *l);
void percentagem_reprovados(LinkedList *reprovados, LinkedList *l);
char* strcasestr(const char* haystack, const char* needle);
void export_list_csv(char* destino, LinkedList* l);
void export_list_html(char* destino, LinkedList* l);
int export_list(LinkedList* l);
void export_list_txt(char* destino, LinkedList* l);
void fprint_node_txt (FILE* fp, Aluno *a);
void fprint_tabs_txt (FILE* fp, char* str);
LinkedList *import_new_list(LinkedList *l);
void input_list_txt(FILE* fp, LinkedList* l);
#endif // LINKEDLIST_H_INCLUDED
