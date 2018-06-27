/**H*********************************************************************
* FILENAME :        linkedlist.c
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
* AUTHOR :    Renato Panda (renato.pansystem("cls");da@ipt.pt) DATE :    13 May 17
*
* CHANGES :
*
* VERSION   DATE        WHO     DETAIL
* 1.0       13May17     panda   Initial implementation
*
*H*/

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include "menu.h"
#include "string.h"


/**F*****************************************************************
* NAME :            LinkedList* create()
*
* DESCRIPTION :     Creates an empty LinkedList
*
* PARAMETERS :
*       none
*
* RETURN :
*       LinkedList *l (a struct)
*
* PROCESS :
*                   [1]  Allocates memory needed by the structure
*                   [2]  Sets head and tail pointers to NULL
*                   [3]  Returns the address (pointer) to the struct
*
* NOTES :           It should be deleted with the destroy() function
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*
*/
LinkedList* create()
{
    LinkedList* l = (LinkedList*)malloc(sizeof(LinkedList));
    l->head = NULL;
    l->tail = NULL;
    return l;
}



/**F*****************************************************************
* NAME :            void destroy(LinkedList *l)
*
* DESCRIPTION :     Destroys (frees memory!) a LinkedList structure
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the structure to be deleted
*
* RETURN :
*       none
*
* PROCESS :
*                   [1]  For each Node in the LinkedList
*                   [2]     Remove the node from the list (updates list head address)
*                   [3]     Free the memory used by the node
*                   [4]  Free the memory of the Linked List (parent structure)
*
* NOTES :
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*
*/
void destroy(LinkedList *l)
{
    Node *aux;
    aux = l->head;
    while(aux != NULL)
    {
        l->head = l->head->next;
        free(aux->aluno);
        free(aux);
        aux = l->head;
    }
    free(l);
}


/**F*****************************************************************
* NAME :            int insert_tail(LinkedList *l, int info)
*
* DESCRIPTION :     Insert a new value at the end of the Linked List
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*       int info        -> integer value to inserted
*
* RETURN :
*       Type:   int                    Error code:
*       Values: 1                      value inserted correctly
*               0                      error (creating the node)
*
* PROCESS :
*                   [1]  Create a new Node* and store the value, set its next element to NULL
*                   [2]  If list is empty, add node and update head and tail pointers
*                   [3]  Else, add node and update the last node and the list tail pointer
*
* NOTES :
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*/
int insert_tail(LinkedList *l, Aluno* info)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->aluno = (Aluno*)malloc(sizeof(Aluno));

    if (n == NULL || n->aluno == NULL)
        return 0;

    if(contains(l, info)){
        printf("\nERRO: Este aluno ja existe na lista, nao foi adicionado!\n");
        return 0;
    }

    n->aluno = info;
    n->next = NULL;
    // lista vazia
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        l->tail->next = n;
        l->tail = n;
    }
    return 1;
}



/**F*****************************************************************
* NAME :            int insert_head(LinkedList *l, int info)
*
* DESCRIPTION :     Insert a new value at the beginning of the Linked List
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*       int info        -> integer value to inserted
*
* RETURN :
*       Type:   int                    Error code:
*       Values: 1                      value inserted correctly
*               0                      error (creating the node)
*
* PROCESS :
*                   [1]  Create a new Node* and store the new value, set Node->next element to be the node currently at beginning
*                   [2]  If list is empty, add node and update head and tail pointers
*                   [3]  Else, add node and update the list head pointer
*
* NOTES :
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*
*/
int insert_head(LinkedList *l, Aluno* info)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->aluno = (Aluno*)malloc(sizeof(Aluno));

    if (n == NULL || n->aluno == NULL)
        return 0;

    if(contains(l, info)){
        printf("\nERRO: Este aluno ja existe na lista, nao foi adicionado!\n");
        return 0;
    }

    n->aluno = info;
    n->next = NULL;
    // lista vazia
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        n->next = l->head;
        l->head = n;
    }
    return 1;
}



/**F*****************************************************************
* NAME :            int contains(LinkedList *l, int info)
*
* DESCRIPTION :     Checks if a value exists in the Linked List
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*       int info        -> integer value to check
*
* RETURN :
*       Type:   int                    Error code:
*       Values: 1                      value exists in the list
*               0                      the value was not found
*
* PROCESS :
*                   [1]  For each node in the list check if the value is the one we are looking for and return 1 if true
*
* NOTES :
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*
*/
int contains(LinkedList *l, Aluno* info)
{
    Node *aux = l->head;
    //Lista vazia?
    if(l->head == NULL)
        return 0;
    // Enquanto não for o últimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL){
        if(strcmp(aux->aluno->nome, info->nome) == 0 &&
           aux->aluno->numero == info->numero)   //Compara nome  e numero
            return 1;

        aux = aux->next;
    }

    if (aux == NULL)
        return 0;
    else
        return 1;
}



/**F*****************************************************************
* NAME :            int remove_node(LinkedList *l, int info)
*
* DESCRIPTION :     Removes a value from the Linked List by is number
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*       int num_aluno        -> integer value to be removed
*
* RETURN :
*       Type:   int                    Error code:
*       Values: 1                      value was removed successfully
*               0                      value not found/not removed
*
* PROCESS :
*                   [1]  Iterate over the list of nodes, remove the node and free memory if the value is found
*
* NOTES :           There are 6 possible conditions covered here:
*                       1 - The list is empty (no node to remove)
*                       2 - The value is the first node AND the list has only one element
*                       3 - The value is the first node AND the list has many values
*                       4 - The value is the last nod
*                       5 - The value is in the middle
*                       6 - The value is NOT present
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*
*/

//#warning TODO (tex#1#): Em  falta


int remove_node(LinkedList *l, int num_aluno)
{
    Node *aux, *aux1;
    // 1:Lista vazia
    if (l->head == NULL)
        return 0;
    else
    {
        aux = l->head;
        // valor no inicio
        if (aux->aluno->numero == num_aluno)
        {
            // 2:Lista com um elemento
            if (l->head == l->tail)
            {
                l->head = NULL;
                l->tail = NULL;
                free(aux);
            }
            else
            {
                // 3:Lista com vários elementos
                l->head = l->head->next;
                free(aux);
            }
            return 1;
        }
        // Vai procurar o valor
        while (aux->next != NULL && aux->next->aluno->numero != num_aluno)
            aux = aux->next;
        // se o valor existe
        if (aux->next != NULL)
        {
            // 4:se é o ultimo valor da lista
            if (aux->next == l->tail)
            {
                l->tail = aux;
                free(aux->next);
                l->tail->next = NULL;
            }
            else
            {
                // 5:esta no meio da lista
                aux1 = aux->next;
                aux->next = aux->next->next;
                free(aux1);
            }
            return 1;
        }
        else
            // 6:valor não existe
            return 0;
    }
}

/**F*****************************************************************
* NAME :            int remove_node(LinkedList *l, int info)
*
* DESCRIPTION :     Removes a value from the Linked List by is number
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*       int num_aluno        -> integer value to be removed
*
* RETURN :
*       Type:   int                    Error code:
*       Values: 1                      value was removed successfully
*               0                      value not found/not removed
*
* PROCESS :
*                   [1]  Iterate over the list of nodes, remove the node and free memory if the value is found
*
* NOTES :           There are 6 possible conditions covered here:
*                       1 - The list is empty (no node to remove)
*                       2 - The value is the first node AND the list has only one element
*                       3 - The value is the first node AND the list has many values
*                       4 - The value is the last nod
*                       5 - The value is in the middle
*                       6 - The value is NOT present
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*
*/

//#warning TODO (tex#1#): Em  falta


int remove_node_by_name(LinkedList *l, char *nome_aluno)
{
    Node *aux, *aux1;
    // 1:Lista vazia
    if (l->head == NULL)
        return 0;
    else
    {
        aux = l->head;
        // valor no inicio
        if (strcmpi(aux->aluno->nome,nome_aluno)==0)
        {
            // 2:Lista com um elemento
            if (l->head == l->tail)
            {
                l->head = NULL;
                l->tail = NULL;
                free(aux);
            }
            else
            {
                // 3:Lista com vários elementos
                l->head = l->head->next;
                free(aux);
            }
            return 1;
        }
        // Vai procurar o valor
        while (aux->next != NULL && strcmpi(aux->next->aluno->nome,nome_aluno)!=0)
            aux = aux->next;
        // se o valor existe
        if (aux->next != NULL)
        {
            // 4:se é o ultimo valor da lista
            if (aux->next == l->tail)
            {
                l->tail = aux;
                free(aux->next);
                l->tail->next = NULL;
            }
            else
            {
                // 5:esta no meio da lista
                aux1 = aux->next;
                aux->next = aux->next->next;
                free(aux1);
            }
            return 1;
        }
        else
            // 6:valor não existe
            return 0;
    }
}



/**F*****************************************************************
* NAME :            int peek_head(LinkedList *l)
*
* DESCRIPTION :     Get the first value in the list (at the head position)
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       int             <- value in the head node
*
* PROCESS :
*                   [1]  Access first node and return its value
*
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*           7Jun18  Andre   Update function to verify if list is empty
*
*/
Aluno* peek_head(LinkedList *l)
{
    if(l->tail == NULL)
        return NULL;
    return l->head->aluno;
}


/**F*****************************************************************
* NAME :            int peek_tail(LinkedList *l)
*
* DESCRIPTION :     Get the last value in the list (at the tail position)
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       int             <- value in the tail node
*
* PROCESS :
*                   [1]  Access the last node and return its value
*
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code
*           7Jun18  Andre   Update function to verify if list is empty
*/
Aluno* peek_tail(LinkedList *l)
{
    if(l->tail == NULL)
        return NULL;
    return l->tail->aluno;
}

/**F*****************************************************************
* NAME :            int remove_first()
*
* DESCRIPTION :     Remove the first value in the list (at the head position)
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       Type:   int                    Error code:
*       Values: 1                      value was removed successfully
*               0                      value not found/not removed
*
* PROCESS :
*                   [1]  Access the first node
*                   [2]  Change head to next node
*                   [3]  Delete original head
*
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           21May18 André   Completing function
*
*/

int remove_first(LinkedList *l)
{
    Node *aux;
    // 1:Lista vazia
    if (l->head == NULL)
        return 0;
    else{
        aux = l->head;
        // Lista com 1 elemento
        if (l->head == l->tail){
            l->head = NULL;
            l->tail = NULL;
        }
        else
            l->head = l->head->next;
    free(aux->aluno);
    free(aux);
    }
    return 1;
}

/**F*****************************************************************
* NAME :            int remove_last()
*
* DESCRIPTION :     Remove the last value in the list (at the tail position)
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       Type:   int                    Error code:
*       Values: 1                      value was removed successfully
*               0                      value not found/not removed
*
* PROCESS :
*                   [1]  Access the first node
*                   [2]  Irerate over the list to the last node
*                   [3]  Elect previous node as tail
*                   [4]  Delete original tail
*
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           21May18 André   Completing function
*
*/

int remove_last(LinkedList* l)
{
     Node *aux1, *aux2;

    aux1 = l->head;
    aux2 = l->head->next;
     // 1:Lista vazia?
    if (l->head == NULL)
        return 0;
    else{
        // Se a lista tem 1 elemento...
        if (l->head == l->tail){
            l->head = NULL;
            l->tail = NULL;
            //liberta memória da estrutura e do nó.
            free(aux1->aluno);
            free(aux1);
        }
        else{ // Mais do que um elemento.
            while (aux2->next != NULL){
                aux1 = aux1->next;
                aux2 = aux2->next;
            }
            //aux1 passa a ser a nova tail
            aux1->next =NULL;
            l->tail = aux1;
            //free da tail anterior (aux2)
            free(aux2->aluno);
            free(aux2);
        }
    }
    return 1;
}

/**F*****************************************************************
* NAME :            int length()
*
* DESCRIPTION :     Returns the total number of nodes in list
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       Type:   int
*       Value: Number of nodes in list
*
*
* PROCESS :
*                   [1]  Access the first node
*                   [2]  Irerate over the list to the last node
*                   [3]  Count node
*                   [4]  return length
*
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           21May18 André   Completing function
*
*/

int length(LinkedList *l)
{
    int  contador = 0;
    Node* aux;

    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;
    contador++; // conta nó head

    while(aux->next != NULL){// enquanto não for o últimmo elemento
        contador++; //conta
        aux = aux->next; //avança para o próximo nó da lista
    }
    return contador;
}

/**F*****************************************************************
* NAME :            int length()
*
* DESCRIPTION :     Returns the total number of nodes in list
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       Type:   int
*       Value: Number of nodes in list
*
*
* PROCESS :
*                   [1]  Access the first node
*                   [2]  Irerate over the list to the last node
*                   [3]  Count node
*                   [4]  return length
*
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           21May18 André   Completing function
*
*/

Node* find(LinkedList *l)
{
    int op;
    printf("\n");
    print_menu_header("Menu de Pesquisa Alunos");
    print_menu_option("1) Nome");
    print_menu_option("2) Numero");
    print_menu_option("3) Voltar");
    print_menu_end_line();


    do
    {
        printf("%c%cDeseja Pesquisar o Aluno por?: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op<'1'||op>'5');

    switch (op)
    {

    case '1' : ;
        char nome[20];
        printf("Qual o a nome do aluno a encontrar?");
        getchar();
        gets(nome);
        printf("\n");
        Node *resultado=find_by_name(l,nome);
        if(resultado!= NULL)
            printf("encontrado com sucesso!!\n");
        else
            printf("Nao encontrado...\n");

        break;
    case '2' : ;
        int numero;
        printf("Qual o a numero do aluno a encontar?");
        scanf(" %d", &numero);
        printf("\n");
        Node* resultado_num = find_by_number(l, numero);
        if (resultado_num != NULL)
            printf("Aluno encontrado com sucesso!!\n");
        else
            printf("O Aluno nao foi encontrado...\n");
        break;
    case '3' :

        break;
    case '4' :

        break;
    case '5' :

        break;
        break;

    default:
        break;
    }


}

/***strcmp(aux->aluno->nome, info->nome) != 0)   //Compara nome
            return 0;
        else if(aux->aluno->numero != info->numero)     //Compara numero
            return 0;***/

Node* find_by_name(LinkedList *l, char* info){

    Node* aux;

    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;

    // Enquanto não for o últimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL)
    {
        if(strcmpi(aux->aluno->nome, info) == 0){
            printf("/---------------------------------------------------------------\\\n");
            printf("|************************ Aluno Encontrado *********************|\n");
            printf("|---------------------------------------------------------------|\n");
            print_node(aux->aluno);
            printf("\\---------------------------------------------------------------/\n");
            return aux;
        }

        aux = aux->next;

        //printf(" Nome: %s\n", info->nome); // apenas um teste
    }
    if (aux == NULL)
        return NULL;
    else
        return aux;

}


Node* find_by_number(LinkedList *l, int info){

    Node* aux;

    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;

    // Enquanto não for o últimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL)
    {
        if(aux->aluno->numero == info){
            printf("/---------------------------------------------------------------\\\n");
            printf("|************************ Aluno Encontrado *********************|\n");
            printf("|---------------------------------------------------------------|\n");
            print_node(aux->aluno);
            printf("\\---------------------------------------------------------------/\n");
            return aux;
        }

        aux = aux->next;
        //printf("Numero: %d\n", info->numero);

    }
    if (aux == NULL)
        return NULL;
    else
        return aux;

}
/**F*****************************************************************
* NAME :            int length()
*
* DESCRIPTION :     Returns the total number of nodes in list
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       Type:   int
*       Value: Number of nodes in list
*
*
* PROCESS :
*                   [1]  Access the first node
*                   [2]  Irerate over the list to the last node
*                   [3]  Count node
*                   [4]  return length
*
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           21May18 André   Completing function
*
*/
void sort(LinkedList *l)
{
    int i;
    int n = length(l);

    Node* aux = NULL;
    Aluno* temp = NULL;
    for (i=0; i < n; i++){
        aux = l->head;
        while(aux->next != NULL){
            if(aux->aluno->numero > aux->next->aluno->numero){
                temp = aux->aluno;
                aux->aluno = aux->next->aluno;
                aux->next->aluno = temp;
            }

            aux = aux->next;
        }
    }
}

void reverse(LinkedList *l)
{
    //TODO
}



/**F*****************************************************************
* NAME :            void print_list(LinkedList *l)
*
* DESCRIPTION :     Prints the content of a given linkedlist
*
* INPUTS :
*       LinkedList *l   -> Memory address (pointer) of the list
*
* RETURN :
*       none
*
* PROCESS :
*                   [1]  Print the LinkedList parent struct
*                   [2]  For each node in the linked list print its details

* NOTES :
*
* CHANGES :
* REF NO    DATE    WHO     DETAIL
*           13May17 panda   Original Code

* REF NO    DATE    WHO     DETAIL
*           21May18 André   Exit if the linked list is empty
*
*/
void print_list(LinkedList *l)
{
    if(l->head == NULL){
        printf("\nLinked List is empty!\n");
        exit(1);
    }

    Node *aux = l->head;

    printf("/---------------------------------------------------------------\\\n");
    printf("|************** Alunos de Tecnicas de programacao **************|\n");
    printf("| Numero de alunos: %d\t\t\t\t\t\t|\n", length(l));
    printf("|---------------------------------------------------------------|\n");

    while(aux != NULL)
    {
        print_node(aux->aluno);
        printf("|---------------------------------------------------------------|\n");
        aux = aux->next;
    }
    printf("\\---------------------------------------------------------------/\n");
}


void print_node (Aluno *a){

    printf("| Nome: %s", a->nome);
    print_tabs(a->nome, 8);
    printf("|\n");

    printf("| Numero: %d", a->numero);
    printf("\t\t\t\t\t\t\t|\n");

    printf("| E-mail: %s", a->mail);
    print_tabs(a->mail, 8);
    printf("|\n");

    printf("| Nota final:  %d", a->nota_final);
    printf("\t\t\t\t\t\t|\n");

    printf("| Estado: %s", a->estado);
    printf("\t\t\t\t\t\t|\n");

}

void print_tabs(char* str, int tab_count){
    int i;

    size_t size = strlen(str);

    short tab_num = (size / 8) + 1;

    for (i=0;  (i + tab_num) < tab_count; i++)
        printf("\t");
}
