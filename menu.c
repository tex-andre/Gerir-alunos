#include "menu.h"
#include "Aluno.h"

void menu(LinkedList *l)
{

    char op;
    do{

    printf("\n\n");
    printf("\tWelcome to the most horrifying program ever: Gestao de Alunos de Tecnicas de Programacao\t\t\t");
    printf("\n\n");
    printf("\t\t\t1) Gerir Lista de Alunos\n");
    printf("\t\t\t2) Pesquisa\n");
    printf("\t\t\t3) Importar Lista de Alunos\n");
    printf("\t\t\t4) Exportar Lista de Alunos\n");
    printf("\t\t\t5) Sair e Guardar\n");
    printf("\t\t\t6) Sair\n");
    printf("\n\n");

    do
    {
        printf("Bem-vindo, introduza a sua opcao:");
        fflush(stdin);
        scanf("%c", &op);
        system("cls");
    }
    while(op < '0' || op > '6');

    switch (op)
    {

    case '1' :
        menu_gerir_alunos(l);

        break;
    case '2' :
        menu_pesquisa(l);
        break;
    case '3' :
        menu_importar(l);
        break;
    case '4' :
        menu_exportar(l);
        break;
    case '5' :
        menu_sair_guardar(l);
        break;



    default:
        break;
    }
    }while (op != '6');
    printf("Good bye");

}

void menu_gerir_alunos(LinkedList *l)
{
    char op;

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
        fflush(stdin);
        scanf("%c", &op);
        system("cls");
    }
    while(op < '1' || op > '5');

    switch (op)
    {
    case '1': {
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
    case '2' :
        //editar_aluno();
        break;
    case '3' : {
        //remover_aluno();
        menu_remover_alunos(l);

        break;
    }

    default:
        break;
    }

}

void menu_pesquisa(LinkedList *l)
{

    int op;
    printf("\n\n");
    printf("\t\t\tMenu de Pesquisa");
    printf("\n\n");
    printf("\t\t\t1) Pesquisar aluno\n"); // Temos de decidir o que colocar nos menus
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
        find(l);
        break;
    case 2 :
        // mostrar os alunos que pertencem ao mesmo curso
        break;

    default:
        break;
    }



}

void menu_importar(LinkedList *l)
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

void menu_exportar(LinkedList *l)
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

void menu_sair_guardar(LinkedList *l){

    int op;
    printf("\n\n");
    printf("\t\t\tMenu Sair e Guardar");
    printf("\n\n");
    printf("\t\t\t1) \n"); // Temos de decidir o que colocar nos menus
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
void menu_remover_alunos(LinkedList *l){

    char op;

    printf("\n\n");
    printf("\t\t\tMenu Remover Alunos");
    printf("\n\n");
    printf("\t\t\t1) Nome\n");
    printf("\t\t\t2) Numero\n");
    printf("\n\n");

    do
    {
        printf("Deseja Remover o Aluno por?:");
        fflush(stdin);
        scanf("%c", &op);
        system("cls");
    }
    while(op < '1' || op > '5');

    switch (op)
    {
    case '1': {
        #warning TODO (tex#1#): não consigo remover um aluno por nome será que consegues dar uma olhadela ao que fiz??
            char nome[20];
            printf("Qual o nome do aluno que deseja remover?");
             getchar(); // limpa o enter anterior
            gets(nome);
            int resultado = remove_node_by_name(l, nome);
            if (resultado == 1)
                printf("Removido com sucesso!!\n");
            else
                printf("Nao encontrado / nao removido...\n");

            print_list(l);
        break;
    }
    case '2' : ;

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

    default:
        break;
    }


}

void menu_find(LinkedList *l){


}
