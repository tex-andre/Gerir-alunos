#include <stdio.h>
#include <stdlib.h>
#include "Aluno_H.h"
#include "menu.h"
#include <conio.h>

int main(){

    menu();
    system("cls");


    /************Defini��o de Variav�is****************/

    char nome[30], mail[30], estado[11];
    int numero, nota_final;



    /************Cria��o de estrutura****************/

    Aluno *aluno1=cria_aluno();
    imprimir_aluno(aluno1);
    return 0;
} //main




