#include "menu.h"
#include "Aluno.h"

void menu(LinkedList *l)
{


    int op;
    do{
    printf("%c", 7);
    printf("\n\n");
    printf("\tWelcome to the most horrifying program ever: Gestao de Alunos de Tecnicas de Programacao\t\t\t");
    printf("\n\n");
    printf("\t\t\t1) Gerir Lista de Alunos\n");
    printf("\t\t\t2) Pesquisa\n %c", 13);
    printf("\t\t\t3) Importar Lista de Alunos\n");
    printf("\t\t\t4) Exportar Lista de Alunos\n");
    printf("\t\t\t5) Sair e Guardar\n");
    printf("\t\t\t6) Sair\n");
    printf("\n\n");

    do
    {
        printf("Bem-vindo, introduza a sua opcao:");
        scanf("%d", &op);
        system("cls");
    }
    while(op<0||op>6);

    switch (op)
    {

    case 1 :
        menu_gerir_alunos(l);

        break;
    case 2 :
        //menu_pesquisa();
        break;
    case 3 :
        //menu_importar();
        break;
    case 4 :
        //menu_exportar();
        break;
    case 5 :
        //menu_sair_guardar();
        break;



    default:
        break;
    }
    }while (op!=6);
    printf("good bye");

}

void menu_gerir_alunos(LinkedList *l)
{

    int op;
    printf("\n\n");
    printf("\t\t\tMenu Gerir Alunos");
    printf("\n\n");
    printf("\t\t\t1) Adicionar novo aluno\n");
    printf("\t\t\t2) Editar aluno\n");
    printf("\t\t\t3) Remover um aluno\n");
    printf("\n\n");

    do
    {
        printf("Introduza a sua opcao:");
        scanf("%d", &op);
        system("cls");
    }
    while(op<1||op>5);

    switch (op)
    {
    case 1: {
        Aluno *a;
        a = cria_aluno();
        if (a != NULL) {
            insert_tail(l, a);
        }
        print_list(l);
           //
        // verificar se o aluno que está a ser inserido já existe na lista através da função contains
        // se existir mostra WARNING!!
        //  se não existir função guardar na lista ligada!!
        //menu();
        break;
    }
    case 2 :
        //editar_aluno();
        break;
    case 3 : {
        //remover_aluno();
        int numero;
        printf("Qual o a num do aluno a remover?");
        scanf("%d", &numero);
        int resultado = remove_node(l, numero);
        if (resultado == 1)
            printf("Removido com sucesso!!\n");
        else
            printf("Nao encontrado / nao removido...\n");

        print_list(l);
        break;
    }
    case 4 :

        break;
    case 5 :

        break;

    default:
        break;
    }

}

void menu_pesquisa()
{

    int op;
    printf("\n\n");
    printf("\t\t\tMenu de Pesquisa");
    printf("\n\n");
    printf("\t\t\t1) Pesquisa\n"); // Temos de decidir o que colocar nos menus
    printf("\t\t\t2) \n");
    printf("\t\t\t3) \n");
    printf("\n\n");


    do
    {
        printf("Introduza a sua opcao:");
        scanf("%d", &op);
        system("cls");
    }
    while(op<1||op>5);

    switch (op)
    {

    case 1 :
        //
        break;
    case 2 :
        // mostrar os alunos que pertencem ao mesmo curso
        break;
    case 3 :

        break;
    case 4 :

        break;
    case 5 :

        break;
        break;

    default:
        break;
    }



}

void menu_importar()
{

    int op;
    printf("\n\n");
    printf("\t\t\tMenu de Importacao");
    printf("\n\n");
    printf("\t\t\t1) Ver\n");
    printf("\t\t\t2) Importar um aluno\n"); // Temos de decidir o que colocar nos menus
    printf("\t\t\t3) \n");
    printf("\n\n");


    do
    {
        printf("Introduza a sua opcao:");
        scanf("%d", &op);
        system("cls");
    }
    while(op<1||op>5);

    switch (op)
    {

    case 1 :
        //
        break;
    case 2 :

        break;
    case 3 :

        break;
    case 4 :

        break;
    case 5 :

        break;
        break;

    default:
        break;
    }



}

void menu_exportar()
{

    int op;
    printf("\n\n");
    printf("\t\t\tMenu de Importacao");
    printf("\n\n");
    printf("\t\t\t1) Ver todos os alunos existentes\n"); // Temos de decidir o que colocar nos menus
    printf("\t\t\t2) Exportar um aluno\n");
    printf("\t\t\t3) \n");
    printf("\n\n");


    do
    {
        printf("Introduza a sua opcao:");
        scanf("%d", &op);
        system("cls");
    }
    while(op<1||op>5);

    switch (op)
    {

    case 1 :
        //
        break;
    case 2 :

        break;
    case 3 :

        break;
    case 4 :

        break;
    case 5 :

        break;
        break;

    default:
        break;
    }

}
