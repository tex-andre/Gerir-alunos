#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>

int main(){
    const char* origem = "Ficheiros\\Participantes.txt";

    printf(" O Andre e o Duarte ja dominam o GITHUB \n");

    LinkedList* l = create();
    FILE* fp = le_f(origem);


    input_lista(fp, l);

    //menu(l);

    output_lista(l);

    destroy(l);
    return 0;
} //main




