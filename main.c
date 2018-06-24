#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>

int main(){
    const char* origem = "Ficheiros\\teste.txt";
    FILE* fp = le_f(origem);

    printf(" O Andre e o Duarte ja dominam o GITHUB \n");

    LinkedList *l = create();
    input_lista(origem, l);
    print_list(l);
    remove_first(l);
    print_list(l);
    remove_last(l);
    print_list(l);
    //menu(l);
    free(fp);
    destroy(l);
    return 0;
} //main




