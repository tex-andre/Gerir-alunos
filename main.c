#include <stdio.h>
#include <stdlib.h>
#include "Aluno_H.h"
#include "menu.h"
#include <conio.h>

int main(){

    menu();
    system("cls");


    /************Definição de Variavéis****************/

    char nome[30], mail[30], estado[11];
    int numero, nota_final;



    /************Criação de estrutura****************/

    Aluno *aluno1=cria_aluno();
    imprimir_aluno(aluno1);
    return 0;
} //main




