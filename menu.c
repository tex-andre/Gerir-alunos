#include "menu.h"
#include "Aluno.h"

void menu(LinkedList *l)
{

    char op;
    do{
        printf("\n");
        print_menu_header("Gestao de alunos");
        print_menu_option("1) Gerir Lista de Alunos");
        print_menu_option("2) Pesquisa");
        print_menu_option("3) Importar Lista de Alunos");
        print_menu_option("4) Exportar Lista de Alunos");
        print_menu_option("5) Sair e Guardar");
        print_menu_option("6) Sair");
        print_menu_end_line();

        do{
            printf("%c%cBem-vindo, introduza a sua opcao: ", 8, 13);
            fflush(stdin);
            op = getc(stdin);
            system("cls");

        }while(op < '0' || op > '6');

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
    }
    while (op != '6');
    printf("Good bye");

}

void menu_gerir_alunos(LinkedList *l)
{
    char op;
    printf("\n");
    print_menu_header("Menu Gerir Alunos");
    print_menu_option("1) Adicionar novo aluno");
    print_menu_option("2) Editar aluno");
    print_menu_option("3) Remover um aluno");
    print_menu_option("4) Voltar");
    print_menu_end_line();

    do
    {
        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
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
        editar_aluno_by_name(l);
        break;
    case '3' : {
        //remover_aluno();
        menu_remover_alunos(l);

        break;
    }

    case '4': {
        break;
    }


    default:
        break;
    }

}

void menu_pesquisa(LinkedList *l)
{
    int op;
    printf("\n");
    print_menu_header("Menu de Pesquisa");
    print_menu_option("1) Pesquisar aluno");
    print_menu_option("2) ");
    print_menu_option("3) Voltar");
    print_menu_end_line();

    do
    {
        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op< '1'|| op> '5');

    switch (op)
    {

    case '1' :
        find(l);
        break;
    case '2' :
        // mostrar os alunos que pertencem ao mesmo curso
        break;

    case '3':
        break;


    default:
        break;
    }
}

void menu_importar(LinkedList *l)
{
    int op;
    printf("\n");
    print_menu_header("Menu de Importacao");
    print_menu_option("1) Ver");
    print_menu_option("2) Voltar");
    print_menu_end_line();


    do
    {
        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op< '1' || op> '5');

    switch (op)
    {

    case '1' :
        print_list(l);
        break;
    case '2':
        break;

    default:
        break;
    }
}

void menu_exportar(LinkedList *l)
{
    int op;
    printf("\n");
    print_menu_header("Menu de Importacao");
    print_menu_option("1) Ver todos os alunos existentes");
    print_menu_option("2) Exportar um aluno");
    print_menu_option("3) Voltar");
    print_menu_end_line();

    do
    {
        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op< '1' || op> '5');

    switch (op)
    {

    case '1' :
        break;
    case '2':
        break;

    default:
        break;
    }
}

void menu_sair_guardar(LinkedList *l){

    int op;
    printf("\n");
    print_menu_header("Menu Sair e Guardar");
    print_menu_option("3) Voltar");
    print_menu_end_line();

    do
    {
        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op< '1' || op> '5');

    switch (op)
    {

    case '1' :

        break;
    case '2' :
        // mostrar os alunos que pertencem ao mesmo curso
        break;
    case '3':
        break;

    default:
        break;
    }


}
void menu_remover_alunos(LinkedList *l){

    char op;
    printf("\n");
    print_menu_header("Menu Remover Alunos");
    print_menu_option("1) Nome");
    print_menu_option("2) Numero");
    print_menu_option("3) Voltar");
    print_menu_end_line();

    do
    {
        printf("%c%cDeseja Remover o Aluno por?: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op < '1' || op > '5');

    switch (op)
    {
    case '1': {
            char nome[20];
            printf("Qual o nome do aluno que deseja remover?");
            getchar(); // limpa o enter anterior
            gets(nome);
            find_by_name(l,nome);
            int resultado = remove_node_by_name(l, nome);
            if (resultado == 1)
                printf("Removido com sucesso!!\n");
            else
                printf("Nao encontrado / nao removido...\n");

            //print_list(l);
        break;
    }
    case '2' : ;

        int numero;
        printf("Qual o a num do aluno a remover?");
        scanf("%d", &numero);
        find_by_number(l,numero);
        int resultado = remove_node(l, numero);
        if (resultado == 1)
            printf("Removido com sucesso!!\n");
        else
            printf("Nao encontrado / nao removido...\n");

        //print_list(l);
        break;

    case '3':
        break;


    default:
        break;
    }


}

void menu_find(LinkedList *l){


}


void print_menu_header(char* str){  //Isto ficou mais complicado do que estave previsto!!!
    size_t str_size = strlen(str);
    size_t width = 8 * 8;           // 8 tabs
    int i;

    printf("%c", 201);              //canto superior esquerdo
    for (i = 0; i < width ; i++)
        printf("%c", 205);          //barra superior
    printf("%c\n", 187);            //canto superior direito

    printf("%c", 186);              //barra vertical

    for (i = 0; i < (width/2) - str_size/2; i++)
        printf(" ");
    printf("%s", str);
    for (i = 0; i < (width/2) - (str_size/2) - (str_size%2); i++)
        printf(" ");

    printf("%c\n", 186);            //barra vertical


    printf("%c", 204);              //T deitado para a esquerdo ( nao sei explicar melhor)
    for (i = 0; i < width ; i++)
        printf("%c", 205);          //barra inferior

    printf("%c\n", 185);            //T deitado para a direita
    print_menu_option(" ");         //apresenta uma linha de espaço  entre header e restante menu
}

void print_menu_option(char* str){
    int width = 7 * 8,              //7 tabs descontando o tab  escrito ao apresentar str
        i;
    size_t str_size = strlen(str);

    printf("%c", 186);              //barra vertical
    printf("\t%s", str);
    for (i = str_size; i <= width; i++) //Imprime espaços considerando o tamanho de str
        printf(" ");

    printf("%c\n", 186);            //barra vertical
}

void print_menu_end_line(){
    int width = 8 * 8,              //8 tabs
        i;
    print_menu_option(" ");         //apresenta uma linha de espaço entre menu e linha de fundo

    printf("%c", 200);              //canto inferior esquerdo
    for (i = 0; i < width ; i++)
        printf("%c", 205);          //barra superior
    printf("%c\n\n", 188);            //canto inferior direito

}

void menu_editar_aluno(LinkedList *l)
{

    int op;
    printf("\n");
    print_menu_header("Quer pesquisar o aluno por:");
    print_menu_option("1) Nome");
    print_menu_option("2) Numero");
    print_menu_option("5) Voltar");
    print_menu_end_line();

    do
    {
        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op=getc(stdin);
        system("cls");
    }
    while(op< '1' || op> '5');

    switch (op)
    {

    case '1' :
        Node *aux = l->head;
        char novo_nome[20];
        printf("Qual o novo nome do aluno a que pretende editar?");
        fflush(stdin);
        gets(novo_nome);
        strcpy(aux->aluno->nome,novo_nome);
        break;
    case '2':

        break;

    default:
        break;
    }

}
