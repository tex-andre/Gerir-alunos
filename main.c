#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>

int main(){
    const char* participantes = "Ficheiros\\Participantes.txt";
    const char* teste ="Ficheiros\\Destino.txt";
    LinkedList* l = create();
    FILE* fp = le_f(participantes);

    input_lista(fp, l);

    print_list(l);

    output_lista(teste, l);

    destroy(l);
    return 0;
} //main




