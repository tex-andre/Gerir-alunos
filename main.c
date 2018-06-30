#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>




int main(){
    const char* origem = "Ficheiros\\Participantes.txt";
    const char* list_file = "Ficheiros\\Participantes.dat";


    LinkedList* l = create();

    FILE* fp = le_f(origem);

    input_list_txt(fp, l);
    /********Para editar um aluno pela solução adotada pelo Professor*******/

    menu(l, list_file);

    //export_list(l);
    fclose(fp);
    destroy(l);
    return 0;
} //main
