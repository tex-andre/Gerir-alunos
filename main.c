#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>

int main(){
    const char* origem = "Ficheiros\\Participantes.txt";
    const char* destino ="Ficheiros\\Destino.txt";

    LinkedList* l = create();
    FILE* fp = le_f(origem);

    input_lista(fp, l);

    menu(l);

    output_lista(destino, l);

    destroy(l);
    return 0;
} //main




