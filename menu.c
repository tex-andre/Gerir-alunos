#include "menu.h"
#include "Aluno.h"

/************************************************
Descri��o:
Menu principal.
*/
void menu(LinkedList *l)
{

    char op;
    do{
        do{
            printf("\n");
            print_menu_header("Gestao de alunos");
            print_menu_option("1) Gerir Lista de Alunos");
            print_menu_option("2) Pesquisa");
            print_menu_option("3) Ver");
            print_menu_option("4) Importar Lista de Alunos");
            print_menu_option("5) Exportar Lista de Alunos");
            print_menu_option("6) Sair e Guardar");
            print_menu_option("7) Sair");
            print_menu_end_line();

            printf("%c%cBem-vindo, introduza a sua opcao: ", 8, 13);
            fflush(stdin);
            op = getc(stdin);
            system("cls");

        }while(op < '0' || op > '7');

        switch (op)
        {

        case '1' :
            menu_gerir_alunos(l);

            break;
        case '2' :
            menu_pesquisa(l);
            break;
        case '3' :
            menu_ver(l);
            break;
        case '4' :
            menu_importar(l);
            break;
        case '5' :
            menu_exportar(l);
            break;
        case '6':
            menu_sair_guardar(l);

        default:
            break;
        }
    }
    while (op != '7');
    printf("Good bye\n");

}

void menu_ver(LinkedList *l)
{
    int op;

    do{
        printf("\n");
        print_menu_header("Menu Ver");
        print_menu_option("1) Ver Lista de Alunos ");
        print_menu_option("2) Ver Lista de Alunos Aprovados");
        print_menu_option("3) Ver Lista de Alunos Reprovados");
        print_menu_option("4) Ver Estatisticas");
        print_menu_option("5) Voltar");
        print_menu_end_line();

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
        find_all_aprovados(l);
        break;
    case '3':
        find_all_reprovados(l);
        break;
    case '4':
        menu_estatistica(l);
        break;
    default:
        break;
    }
}

void menu_estatistica(LinkedList *l){

    int op;

    do{
        printf("\n");
        print_menu_header("Menu Estatisticas");
        print_menu_option("1) Ver Media de Notas Finais ");
        print_menu_option("2) Ver Percentagem de Alunos Aprovados");
        print_menu_option("3) Ver Percentagem de Alunos Reprovados");
        print_menu_option("4) Voltar");
        print_menu_end_line();

        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op< '1' || op> '4');

    switch (op)
    {

    case '1' :
        printf("A media final dos alunos e = %f valores", media_final(l));
        break;
    case '2': ;
        LinkedList *aprovados;
        aprovados=find_all_aprovados(l);
        system("cls");
        percentagem_aprovados(aprovados,l);
        break;
    case '3': ;
        LinkedList *reprovados;
        reprovados=find_all_reprovados(l);
        system("cls");
        percentagem_reprovados(reprovados,l);
        break;
    default:
        break;
    }


}

/************************************************
Descri��o:
Sub-menu para gerir a lista de alunos.
*/

void menu_gerir_alunos(LinkedList *l)
{
    char op;

    do{
        printf("\n");
        print_menu_header("Menu Gerir Alunos");
        print_menu_option("1) Adicionar novo aluno");
        print_menu_option("2) Editar aluno");
        print_menu_option("3) Remover um aluno");
        print_menu_option("4) Voltar");
        print_menu_end_line();

        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op < '1' || op > '4');

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
        // verificar se o aluno que est� a ser inserido j� existe na lista atrav�s da fun��o contains
        // se existir mostra WARNING!!
        //  se n�o existir fun��o guardar na lista ligada!!
        //menu();
        break;
    }
    case '2' :
        menu_editar_aluno(l);
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

/************************************************
Descri��o:
Sub-menu de pesquisa da lista.
*/

void menu_pesquisa(LinkedList *l)
{
    int op;

    do{
        printf("\n");
        print_menu_header("Menu de Pesquisa");
        print_menu_option("1) Pesquisar aluno");
        print_menu_option("2) Pesquisar varios alunos");
        print_menu_option("3) Voltar");
        print_menu_end_line();

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
    case '2' : ;
        char nome[20];
        printf("Qual o a nome do aluno a encontrar?");
        fflush(stdin);
        gets(nome);
        printf("\n");
        LinkedList *resultado=find_all_by_name(l,nome);
        if(resultado!= NULL){
            printf("Foram encontrados estes %ss!!\n", nome);
        }
        else{
            printf("Nao encontrado...\n");
        }
        //find_all_by_name(l,"Andre");
        break;

    case '3':
        break;


    default:
        break;
    }
}

/************************************************
Descri��o:
Sub-menu para importar a lista de um ficheiro externo.
*/

void menu_importar(LinkedList *l)
{
    int op;

    do{
        printf("\n");
        print_menu_header("Menu de Importacao");
        print_menu_option("1) Ver");
        print_menu_option("2) Voltar");
        print_menu_end_line();

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

/************************************************
Descri��o:
Sub-menu para exportar a lista em diferentes formatos.
*/

void menu_exportar(LinkedList *l)
{
    int op;

    do{
        printf("\n");
        print_menu_header("Menu de Importacao");
        print_menu_option("1) Ver todos os alunos existentes");
        print_menu_option("2) Exportar um aluno");
        print_menu_option("3) Voltar");
        print_menu_end_line();

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

/************************************************
Descri��o:
Sub-menu para guardar o conte�do da lista e sair da aplica��o.
*/

void menu_sair_guardar(LinkedList *l){

    int op;

    do{
        printf("\n");
        print_menu_header("Menu Guardar e Sair");
        print_menu_option("3) Voltar");
        print_menu_end_line();

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

/************************************************
Descri��o:
Sub-menu para remover um aluno da lista.
*/

void menu_remover_alunos(LinkedList *l){

    char op;

    do{
        printf("\n");
        print_menu_header("Menu Remover Alunos");
        print_menu_option("1) Nome");
        print_menu_option("2) Numero");
        print_menu_option("3) Voltar");
        print_menu_end_line();

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
            fflush(stdin); // limpa o enter anterior
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
        printf("Qual o num do aluno a remover?");
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

/************************************************
Descri��o:
Apresenta o cabe�alho padr�o para o menu
*/

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
    print_menu_option(" ");         //apresenta uma linha de espa�o  entre header e restante menu
}

/************************************************
Descri��o:
Apresenta uma op��o para o menu padr�o.
*/

void print_menu_option(char* str){
    int width = 7 * 8,              //7 tabs descontando o tab  escrito ao apresentar str
        i;
    size_t str_size = strlen(str);

    printf("%c", 186);              //barra vertical
    printf("\t%s", str);
    for (i = str_size; i <= width; i++) //Imprime espa�os considerando o tamanho de str
        printf(" ");

    printf("%c\n", 186);            //barra vertical
}

/************************************************
Descri��o:
Apresenta a �ltima linha da caixa do menu padr�o.
*/

void print_menu_end_line(){
    int width = 8 * 8,              //8 tabs
        i;
    print_menu_option(" ");         //apresenta uma linha de espa�o entre menu e linha de fundo

    printf("%c", 200);              //canto inferior esquerdo
    for (i = 0; i < width ; i++)
        printf("%c", 205);          //barra superior
    printf("%c\n\n", 188);            //canto inferior direito

}

/************************************************
Descri��o:
Sub-menu para editar um aluno da lista.
*/

void menu_editar_aluno(LinkedList *l)
{
    Aluno *a=find(l);
    if(a!=NULL)
    {

        int op;

        do{
            printf("\n");
            print_menu_header("Quer editar o aluno por:");
            print_menu_option("1) Nome");
            print_menu_option("2) Numero");
            print_menu_option("3) Email");
            print_menu_option("4) Voltar");
            print_menu_end_line();

            printf("%c%cIntroduza a sua opcao: ", 8, 13);
            fflush(stdin);
            op=getc(stdin);
        }
        while(op< '1' || op> '3');

        switch (op)
        {

        case '1' :
            ;
            editar_aluno_by_name(a);
            break;
        case '2':
            ;
            editar_aluno_by_number(a);
            break;
        case '3':
            ;
            editar_aluno_by_email(a);
        default:
            break;
        }
    }
    else
        printf("Aluno nao encontrado");
}
