#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>




int main(){
<<<<<<< HEAD
    const char* origem = "Ficheiros\\teste.txt";
    FILE* fp = le_f(origem);

    printf(" O Andre e o Duarte ja dominam o GITHUB \n");

    LinkedList *l = create();
    input_lista(fp, l);
    print_list(l);
    remove_first(l);
    print_list(l);
    remove_last(l);
    print_list(l);
    //menu(l);
    free(fp);
=======
    const char* origem = "Ficheiros\\Participantes.txt";
    const char* list_file = "Ficheiros\\Participantes.dat";
    float media = 0;
    //printf(" O Andre e o Duarte ja dominam o GITHUB \n");

    LinkedList* l = create();

    FILE* fp = le_f(origem);

    input_list_txt(fp, l);
    /********Para editar um aluno pela solução adotada pelo Professor*******/

    menu(l, list_file);

    //export_list(l);
    fclose(fp);
>>>>>>> master
    destroy(l);
    return 0;
} //main
