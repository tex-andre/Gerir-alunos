#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>

int main(){
    const char* list_file = "Ficheiros\\Participantes.dat";

    printf("%s", asctime(data_atual()));        //imprime data atual

    LinkedList* l = create();                   // cria lista ligada
    import_list_bin(list_file, l);              // importa lista do ficheiro dat (binario existente

    menu(l, list_file);

    destroy(l);                                 // destroi lista ligada
    return 0;
} //main
