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



    import_list_bin(list_file, l);


    menu(l, list_file);

    //export_list(l);

    destroy(l);
    return 0;
} //main
