#include "menu.h"
#include "Aluno.h"

/************************************************
Descrição:
Menu principal.
*/
void menu(LinkedList *l, const char* list_file)
{

    char op;
    LinkedList *nova=create();
    do{
        do{
            printf("\n");
            print_menu_header("Gestao de alunos");
            print_menu_option("1) Gerir Lista de Alunos");
            print_menu_option("2) Pesquisa");
            print_menu_option("3) Ver");
            print_menu_option("4) Importar Lista de Alunos");
            print_menu_option("5) Exportar Lista de Alunos");
            print_menu_option("6) Guardar e Sair");
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
            nova=menu_importar(l);
            l=nova;
            break;
        case '5' :
            menu_exportar(l);
            break;
        case '6':
            guardar_sair(l, list_file);

        default:
            break;
        }
    }
    while (op != '7' && op != '6');
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
Descrição:
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
        break;
    }
    case '2' :
        menu_editar_aluno(l);
        break;
    case '3' : {
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
Descrição:
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
Descrição:
Sub-menu para importar a lista de um ficheiro externo.
*/

LinkedList* menu_importar(LinkedList *l)
{
    int op;
    LinkedList *nova=create();

    do{
        printf("\n");
        print_menu_header("Menu de Importacao");
        print_menu_option("1) Importar Nova Lista");
        print_menu_option("2) Voltar");
        print_menu_end_line();

        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op< '1' || op> '2');

    switch (op)
    {

    case '1' :
        nova=import_new_list(l);
        return nova;
        break;
    case '2':
        break;

    default:
        break;
    }
}

/************************************************
Descrição:
Sub-menu para exportar a lista em diferentes formatos.
*/

void menu_exportar(LinkedList *l)
{
    int op;

    do{
        printf("\n");
        print_menu_header("Menu de Exportacao");
        print_menu_option("1) Exportar Lista de Alunos");
        print_menu_option("2) Voltar");
        print_menu_end_line();

        printf("%c%cIntroduza a sua opcao: ", 8, 13);
        fflush(stdin);
        op = getc(stdin);
        system("cls");
    }
    while(op< '1' || op> '2');

    switch (op)
    {

    case '1' :
        export_list(l);
        break;
    case '2':
        break;

    default:
        break;
    }
}




/************************************************
Descrição:
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
            find_all_by_name(l,nome);
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
        find_all_by_number(l,numero);
        int resultado = remove_node_by_number(l, numero);
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
Descrição:
Apresenta o cabeçalho padrão para o menu
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
    print_menu_option(" ");         //apresenta uma linha de espaço  entre header e restante menu
}

/************************************************
Descrição:
Apresenta uma opção para o menu padrão.
*/

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

/************************************************
Descrição:
Apresenta a última linha da caixa do menu padrão.
*/

void print_menu_end_line(){
    int width = 8 * 8,              //8 tabs
        i;
    print_menu_option(" ");         //apresenta uma linha de espaço entre menu e linha de fundo

    printf("%c", 200);              //canto inferior esquerdo
    for (i = 0; i < width ; i++)
        printf("%c", 205);          //barra superior
    printf("%c\n\n", 188);            //canto inferior direito

}

/************************************************
Descrição:
Sub-menu para editar um aluno da lista.
*/

void menu_editar_aluno(LinkedList *l)
{
    Aluno* a;
    LinkedList *filtrada=find(l);
    int tam_lfiltrada=length(filtrada);

    if(filtrada!=NULL)
    {


        if(tam_lfiltrada>1)
        {
            int indice,i;

            for(i=1; i <= tam_lfiltrada; i++)
                printf("%d) \n",i);

            printf("O que pretende editar? \n");
            scanf("%d",&indice);
            a = posicao_indice(indice,filtrada);
            define_campos_de_edicao(a);

        }
        else         // tam=1 para o caso da lista só ter um elemento a editar
        {
            a = filtrada->head->aluno;
            define_campos_de_edicao(a);
        }
    }
    else
        printf("Aluno nao encontrado");
}

void define_campos_de_edicao (Aluno* a){

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
