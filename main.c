#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "menu.h"
#include "FileIO.h"
#include <conio.h>




int main(){
    const char* origem = "Ficheiros\\Participantes.txt";
    float media = 0;
    //printf(" O Andre e o Duarte ja dominam o GITHUB \n");

    LinkedList* l = create();
    FILE* fp = le_f(origem);

    input_list(fp, l);
    /********Para editar um aluno pela solu��o adotada pelo Professor*******/


    //menu(l);





    menu(l);
    print_list(l);
    //find(l);





    printf("%f\n", media_final(l));
    media = media_final(l);
    printf("%f", media);
    //export_lista(l);



    destroy(l);
    return 0;
} //main




