#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>




int main(){
    const char* origem = "Ficheiros\\Participantes.txt";
    const char* list_file = "Ficheiros\\Participantes.dat";
    float media = 0;
    //printf(" O Andre e o Duarte ja dominam o GITHUB \n");

    LinkedList* l = create();

    FILE* fp = le_f(origem);

    input_list_txt(fp, l);
    /********Para editar um aluno pela solu��o adotada pelo Professor*******/

    //inport_list_bin(list_file, l);

    menu(l, list_file);
    print_list(l);
    //find(l);

    printf("%f\n", media_final(l));
    media = media_final(l);
    printf("%f", media);
    //export_list(l);
    //fclose(fp);
    destroy(l);
    return 0;
} //main




