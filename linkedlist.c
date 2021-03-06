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
#include <string.h>


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
    n->prev = NULL;
    // lista vazia
    if (l->head == NULL)
    {
        l->head = n;
        l->tail = n;

    }
    else
    {
        n->prev = l->tail;
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
    n->prev = NULL;
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
    // Enquanto n�o for o �ltimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL){
        if(strcmpi(aux->aluno->nome, info->nome) == 0 &&
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


int remove_node_by_number(LinkedList *l, int num_aluno)
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
                // 3:Lista com v�rios elementos
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
            // 4:se � o ultimo valor da lista
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
                aux1->next->prev = aux;
                free(aux1);
            }
            return 1;
        }
        else
            // 6:valor n�o existe
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

        aux = find_by_name(l, nome_aluno);
        // valor no inicio
        if (aux == l->head)
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
                // 3:Lista com v�rios elementos
                l->head = l->head->next;
                l->head->prev = NULL;
                free(aux);
            }
            return 1;
        }

            // 4:se � o ultimo valor da lista
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
                aux1->next->prev = aux;
                free(aux1);
            }
            return 1;
        }

            // 6:valor n�o existe
            return 0;

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
*           21May18 Andr�   Completing function
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
            l->head->prev = NULL;
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
*           21May18 Andr�   Completing function
*
*/

int remove_last(LinkedList* l)
{
     Node *aux;

     // 1:Lista vazia?
    if (l->head == NULL)
        return 0;
    else{
        aux = l->tail;

        // Se a lista tem 1 elemento...
        if (l->head == l->tail){
            l->head = NULL;
            l->tail = NULL;
        }
        else{ // Mais do que um elemento.
            aux->prev->next = NULL;
            l->tail = aux->prev;
        }
        //liberta mem�ria da estrutura e do n�.
            free(aux->aluno);
            free(aux);
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
*           21May18 Andr�   Completing function
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
    contador++; // conta n� head

    while(aux->next != NULL){// enquanto n�o for o �ltimmo elemento
        contador++; //conta
        aux = aux->next; //avan�a para o pr�ximo n� da lista
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
*           21May18 Andr�   Completing function
*
*/

LinkedList* find(LinkedList *l)
{
    LinkedList *resultado;
     LinkedList* resultado_num;
    int op;
    printf("\n");
    print_menu_header("Menu de Pesquisa Alunos");
    print_menu_option("1) Nome");
    print_menu_option("2) Numero");
    print_menu_end_line();


    do
    {
        printf("%c%cDeseja Pesquisar o Aluno por?: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op<'1'||op>'2');

    switch (op)
    {

    case '1' : ;
        char nome[20];
        printf("Qual o a nome do aluno a encontrar?");
        fflush(stdin);
        gets(nome);
        printf("\n");
        resultado = find_all_by_name(l,nome);
        if(resultado!= NULL){
            printf("encontrado com sucesso!!\n");
            printf("\n");
            return resultado;
        }
        else{
            printf("Nao encontrado...\n");
            printf("\n");
            return NULL;
        }

        break;
    case '2' : ;
        int numero;
        printf("Qual o a numero do aluno a encontar?");
        scanf(" %d", &numero);
        printf("\n");
       resultado_num = find_all_by_number(l, numero);
        if (resultado_num != NULL){
            printf("Aluno encontrado com sucesso!!\n");
            printf("\n");
            return resultado_num;
        }
        else{
            printf("O Aluno nao foi encontrado...\n");
            printf("\n");
            return NULL;
        }
        break;
    default:
        break;
    }


}


Node* find_by_name(LinkedList *l, char* info){

    Node* aux;

    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;

    // Enquanto n�o for o �ltimmo elemento e nao for
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

    // Enquanto n�o for o �ltimmo elemento e nao for
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
LinkedList* find_all_by_name(LinkedList *l, char* info){

    LinkedList *f=create();

    Node* aux;

    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;

    // Enquanto n�o for o �ltimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL)
    {
        char* ptr = strcasestr(aux->aluno->nome,info);
        if(ptr != NULL){
            printf("/---------------------------------------------------------------\\\n");
            printf("|************************ Aluno Encontrados ********************|\n");
            printf("|---------------------------------------------------------------|\n");
            print_node(aux->aluno);
            printf("\\---------------------------------------------------------------/\n");
            insert_tail(f,aux->aluno);
        }

        aux = aux->next;

        //printf(" Nome: %s\n", info->nome); // apenas um teste
    }
    if (length(f)== 0)
        return NULL;
    else
        return f;

}

LinkedList* find_all_by_number(LinkedList *l, int info)
{

    LinkedList *f=create();

    Node* aux;

    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;

    // Enquanto n�o for o �ltimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL)
    {
        if(aux->aluno->numero==info)
        {
            printf("/---------------------------------------------------------------\\\n");
            printf("|************************ Aluno Encontrados ********************|\n");
            printf("|---------------------------------------------------------------|\n");
            print_node(aux->aluno);
            printf("\\---------------------------------------------------------------/\n");
            insert_tail(f,aux->aluno);
        }

        aux = aux->next;

        //printf(" Nome: %s\n", info->nome); // apenas um teste
    }
    if (length(f)== 0)
        return NULL;
    else
        return f;

}
char* strcasestr(const char* haystack, const char* needle) {
    size_t i, j;

    /* Edge case: The empty string is a substring of everything. */
    if (!needle[0]) return (char*) haystack;

    /* Loop over all possible start positions. */
    for (i = 0; haystack[i]; i++) {
        bool matches = true;
        /* See if the string matches here. */
        for (j = 0; needle[j]; j++) {
            /* If we're out of room in the haystack, give up. */
            if (!haystack[i + j]) return NULL;

            /* If there's a character mismatch, the needle doesn't fit here. */
            if (tolower((unsigned char)needle[j]) !=
                tolower((unsigned char)haystack[i + j])) {
                matches = false;
                break;
            }
        }
        if (matches) return (char *)(haystack + i);
    }
    return NULL;
}


LinkedList *find_all_aprovados(LinkedList *l){

    LinkedList *aprovados=create();

    Node *aux;
    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;

    // Enquanto n�o for o �ltimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL)
    {
        if(aprovacao(aux->aluno->nota_final) == 1){
            printf("/---------------------------------------------------------------\\\n");
            printf("|************************ Aluno Encontrado *********************|\n");
            printf("|---------------------------------------------------------------|\n");
            print_node(aux->aluno);
            printf("\\---------------------------------------------------------------/\n");
            insert_tail(aprovados,aux);
        }

        aux = aux->next;

        //printf(" Nome: %s\n", info->nome); // apenas um teste
    }
    if (length(aprovados)== 0)
        return NULL;
    else
        return aprovados;

}




LinkedList *find_all_reprovados(LinkedList *l){

    LinkedList *reprovados=create();

    Node *aux;
    aux = l->head;
    //lista vazia?
    if(l->head == NULL)
        return 0;

    // Enquanto n�o for o �ltimmo elemento e nao for
    // encontrado o elemento, precorre a lista
    while (aux != NULL)
    {
        if(aprovacao(aux->aluno->nota_final) == 0){
            printf("/---------------------------------------------------------------\\\n");
            printf("|************************ Aluno Encontrado *********************|\n");
            printf("|---------------------------------------------------------------|\n");
            print_node(aux->aluno);
            printf("\\---------------------------------------------------------------/\n");
            insert_tail(reprovados,aux);
        }

        aux = aux->next;

        //printf(" Nome: %s\n", info->nome); // apenas um teste
    }
    if (length(reprovados)== 0)
        return NULL;
    else
        return reprovados;

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
*           21May18 Andr�   Completing function
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
*           21May18 Andr�   Exit if the linked list is empty
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

    printf("| E-mail:%s", a->mail);
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


int num_aprovados(LinkedList* l){
    //Lista vazia?
    if(l->head == NULL){
        printf("\nERRO: lista vazia!!\n");;
        return 0;
    }
    Node* aux = l->head;
    int num = 0;

    while(aux != NULL){
        if(aprovacao(aux->aluno->nota_final))
            num++;                              //conta elementos da lista aprovados
        aux = aux->next;
    }
    return num;
}

float media_final(LinkedList* l){
    //Lista vazia?
    if(l->head == NULL){
        printf("\nERRO: lista vazia!!\n");;
        return 0;
    }

    float soma = 0;
    float media;
    Node* aux = l->head;

    while(aux != NULL){
        soma += aux->aluno->nota_final;
        aux = aux->next;
    }
    media = (float)soma /length(l);
    return media;
}


void guardar_sair(LinkedList* l, const char* list_file){
    if(l->head == NULL){
        printf("\nERRO: lista vazia!!\n");;
        return 0;
    }

    int* terminator = '\0';                    //He will be back trust me!
    FILE* fp = escreve_fB(list_file);
    Node* aux = l->head;

    while(aux != NULL){
        fwrite(aux->aluno, sizeof(Aluno), 1, fp);
        aux = aux->next;
    }
    fflush(fp);
    //fwrite(terminator, sizeof(char), 1, fp);
    printf("Lista guardada com sucesso! %c", 7);
}

void percentagem_aprovados(LinkedList *aprovados, LinkedList *l){

    printf("A percentagem de aprovacao e de: %f por cento",(((float)length(aprovados)/length(l))*100));
}

void percentagem_reprovados(LinkedList *reprovados, LinkedList *l){

    printf("A percentagem de reprovacao e de: %f por cento",(((float)length(reprovados)/length(l))*100));
}

/************************************************
Descri��o:
Importa uma lista atrav�s do ponteiro fp para FILE
e guarda o conte�do numa lista.
*/

void input_list_txt(const char* origem, LinkedList* l){
    // Vari�veis da estrutura Aluno
    char* nome;
    char mail[30];
    int numero;
    unsigned short nota;
    FILE* fp = le_f(origem);

    char buffer[80]; // buffer tempor�rio

    while(!feof(fp)){
        fgets(buffer, 80, fp);
        strtok(buffer, "\n");       // Retira "\n" do fim da string lida
        if(buffer[0] != '\n'){      // Previne a utiliza��o de uma string composta apenas por "\n",
                                    // relacionado com a forma de escrita de cada n� da lista.
            nome = strtok(buffer, "|");
            numero = atoi(strtok(NULL, "|")); // "|" : Caracter e de separa��o
            strcpy(mail, strtok(NULL, "|"));
            nota = atoi(strtok(NULL, "|"));

        // Cria estrutura Aluno com dados lidos e incere na lista
        Aluno* a = cria_estrutura(nome, numero, mail, nota);

        insert_tail(l, a);
        }
    }
    printf("\nLista importada com sucesso!\n");

}

/************************************************
Descri��o:

*/

void import_list_bin(const char* list_file, LinkedList* l){
    FILE* fp = le_fB(list_file);

    while(1){
        Aluno* a = (Aluno*) malloc(sizeof(Aluno));

        fread(a, sizeof(Aluno), 1, fp);
        if(feof(fp))
            break;
        insert_tail(l, a);
    }

    //free(a);

    fclose(fp);
}


void import_new_list(LinkedList *l){

    int opc;
    char destino[30] = "Ficheiros\\";
    char file_name[20] = {"0"}; // nome do ficheiro para guardar lista

    Node* aux = l->head;

    //lista vazia?
    if(aux == NULL)
        return 0;

    printf("\nIntroduza o nome do ficheiro (sem extensao): ");

    scanf("%s", &file_name);        // l� nome do ficheiro
    strcat(destino, file_name);     // adiciona o nome do ficheiro � directoria de destino

    print_menu_header("Formato do ficheiro:");
    print_menu_option("1. Texto(.txt)");
    print_menu_option("2. Binario(.dat)");
    print_menu_end_line();

    do{
        printf("%c%cOpcao: ", 8, 13);
        fflush(stdin);
        opc = getc(stdin);
    }while(opc < '1' || opc > '2');

    switch(opc){
    case '1':
        clear_list(l); // Formato de texto
        strcat(destino, ".txt");
        input_list_txt(destino, l);
        break;
    case '2':
        clear_list(l);
        strcat(destino,".dat");
        import_list_bin(destino, l);

    default:
    break;
    }

}

void clear_list(LinkedList* l){

    Node *aux;
    aux = l->head;
    while(l->head != l->tail)
    {
        remove_last(l);
    }
}

/************************************************
Descri��o:
Exporta a lista para diferentes formatos predefinidos
que o utilizador pode escolher.
*/

int export_list(LinkedList* l){
    int opc;
    char destino[30] = "Ficheiros\\";
    char file_name[20] = {"0"}; // nome do ficheiro para guardar lista

    Node* aux = l->head;

    //lista vazia?
    if(aux == NULL)
        return 0;

    printf("\nIntroduza o nome do ficheiro (sem extencao): ");

    scanf("%s", &file_name);        // l� nome do ficheiro
    strcat(destino, file_name);     // adiciona o nome do ficheiro � directoria de destino

    print_menu_header("Formato para guardar o ficheiro:");
    print_menu_option("1. Texto(.txt)");
    print_menu_option("2. Excel(.csv)");
    print_menu_option("3. HTML(.html)");
    print_menu_end_line();

    do{
        printf("%c%cOpcao: ", 8, 13);
        fflush(stdin);
        opc = getc(stdin);
    }while(opc < '1' || opc > '3');

    switch(opc){
    case '1':                 // Formato de texto
        strcat(destino, ".txt");
        export_list_txt(destino, l);
        break;
    case '2':                 // Formato csv
        strcat(destino, ".csv");
        export_list_csv(destino, l);
        break;
    case '3':                 // Formato HTML
        strcat(destino, ".html");
        export_list_html(destino, l);
        break;
    default:
    break;
    }
    return 1;
}

/************************************************
Descri��o:
Exporta a lista em formato de texto
*/

void export_list_txt(char* destino, LinkedList* l){
    Node* aux = l->head;

    FILE* fp = escreve_f(destino);

    fprintf(fp, "/---------------------------------------------------------------\\\n");
    fprintf(fp, "|************** Alunos de Tecnicas de programacao **************|\n");
    fprintf(fp, "| Numero de alunos: %d\t\t\t\t\t\t|\n", length(l));
    fprintf(fp, "|---------------------------------------------------------------|\n");

    while(aux != NULL)
    {
        fprint_node_txt(fp, aux->aluno);
        fprintf(fp, "|---------------------------------------------------------------|\n");
        aux = aux->next;
    }
    fprintf(fp, "\\---------------------------------------------------------------/\n");
    printf("Lista guardada com sucesso!\n");
    fclose(fp);
}

/************************************************
Descri��o:
Escreve o conte�do da estrutura Aluno de um n� para
o ficheiro de texto.
*/

void fprint_node_txt (FILE* fp, Aluno *a){

    fprintf(fp, "| Nome: %s", a->nome);
    fprint_tabs(fp, a->nome);           // escreve o n�mero de tabs correcto para uma string
                                        // de modo a estar formatado
    fprintf(fp, "|\n");
    fprintf(fp, "| Numero: %d", a->numero);
    fprintf(fp, "\t\t\t\t\t\t\t|\n");

    fprintf(fp, "| E-mail: %s", a->mail);
    fprint_tabs(fp, a->mail);
    fprintf(fp, "|\n");                 // Insere caracter separador

    fprintf(fp, "| Nota final:  %d", a->nota_final);
    fprintf(fp, "\t\t\t\t\t\t|\n");

    fprintf(fp, "| Estado: %s", a->estado);
    fprintf(fp, "\t\t\t\t\t\t|\n");

}

/************************************************
Descri��o:
Escreve o n�mero de tabs correcto para uma string
de modo a que a informa��o esteja formatada.
*/

void fprint_tabs(FILE* fp, char* str){
    int i;

    size_t size = strlen(str);

    short tab_num = (size / 8) + 1;

    for (i=0;  (i + tab_num) < 8; i++)
        fprintf(fp, "\t");
}

/************************************************
Descri��o:
Exporta lista em formato csv.
*/

void export_list_csv(char* destino, LinkedList* l){
    Node* aux = l->head; // Cria n� tempor�rio para aceder aos elementos da lista
    FILE* fp = escreve_f(destino);

    fprintf(fp, "Nome do aluno;Numero;e-mail;Nota final;Estado\n");

    while(aux != NULL){
        fprintf(fp, "%s;%d;%s;%d;%s\n", aux->aluno->nome, aux->aluno->numero, aux->aluno->mail, aux->aluno->nota_final, aux->aluno->estado);
        aux = aux->next;
    }
    printf("Lista guardada com sucesso!\n");

}

/************************************************
Descri��o:
Exporta lista em formato HTML.
*/

void export_list_html(char* destino, LinkedList* l){
    Node* aux = l->head;                // Cria n� tempor�rio para aceder aos elementos da lista
    FILE* fp = escreve_f(destino);      // ponteiro para escrita em texto

    //titulo da p�gina
    fprintf(fp, "<head>\n<title>Lista de Alunos</title>\n</head>\n");
    // Formata��o da tabela
    fprintf(fp, "<style>\ntable, th, td {border: 1px solid black;\nborder-collapse: collapse;padding: 5px;}\n</style>");
    // imagem do logo do ipt
    fprintf(fp, "\n<img src=\"http://portal2.ipt.pt/img/logo.png\" alt=\"IPT Logo\" width=\"348\" height=\"65\">\n");
    // Header
    fprintf(fp, "<h1>Lista de alunos</h1>\n");

    // Cria uma tabela para escrever a lista de alunos
    fprintf(fp, "<table>");
    // Headers de cada coluna
    fprintf(fp, "\n<td><b>Nome:</b></td>");
    fprintf(fp, "\n<td><b>Numero:</b></td>");
    fprintf(fp, "\n<td><b>E-mail:</b></td>");
    fprintf(fp, "\n<td><b>Nota final:</b></td>");
    fprintf(fp, "\n<td><b>Estado:</b></td>");

    while(aux != NULL){
        fprintf(fp, "<tr>");
        // conte�do da tabela
        fprintf(fp, "\n<td>%s</td>", aux->aluno->nome);
        fprintf(fp, "\n<td>%d</td>", aux->aluno->numero);
        fprintf(fp, "\n<td>%s</td>", aux->aluno->mail);
        fprintf(fp, "\n<td>%hu</td>", aux->aluno->nota_final);
        fprintf(fp, "\n<td>%s</td>", aux->aluno->estado);

        fprintf(fp, "\n</tr>");
    aux = aux->next;
        }
    fprintf(fp, "\n</table>\n");

    printf("Lista guardada com sucesso!\n");
}

Node* posicao_indice(int indice, LinkedList *l)
{

    if(l->head == NULL || indice == 0)
    {
        printf("\nERRO: lista vazia!!\n");;
        return 0;
    }

    Node *aux;
    aux=l->head;

    int i=1;

    while(aux!=NULL && i<indice)
    {
        aux=aux->next;
        i++;
    }
    return aux->aluno;
}

