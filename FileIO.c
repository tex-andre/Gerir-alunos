/*******************************************************\
*   Biblioteca para manipulação de ficheiros            *
*   associados ao trabalho de técnicas de programação   *
*                                                       *
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileIO.h"
#include "linkedlist.h"

/************************************************
Descrição:
Retorna um ponteiro FILE para escrita de texto "w"
*/

FILE* escreve_f(const char* local){
    FILE* ptr = fopen(local, "w");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" criado com sucesso!\n", local);

    return ptr;
}

/************************************************
Descrição:
Retorna um ponteiro FILE para leitura de texto "r"
*/

FILE* le_f (const char* local){
    FILE* ptr = fopen(local, "r");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" encontrado com sucesso!\n", local);

    return ptr;
}

/************************************************
Descrição:
Retorna um ponteiro FILE para escrita binária "wb"
*/

FILE* escreve_fB(const char* local){
    FILE* ptr = fopen(local, "wb");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" criado com sucesso!\n", local);

    return ptr;
}

/************************************************
Descrição:
Retorna um ponteiro FILE para leitura binária "rb"
*/

FILE* le_fB(const char *local){
    FILE* ptr = fopen(local, "rb");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" encontrado com sucesso!\n", local);
    return ptr;
}

/************************************************
Descrição: */

FILE* cria_ponteiros (const char* local){
    int opc;
    FILE* ptr;

    printf("Manipulacao de ficheiros\nOpcoes:\n");
    printf("1: Escrever\n");
    printf("2: Ler\n");
    printf("3: Apagar (Em construcao)\n");
    printf("4: Copiar ficheiro\n");
    printf("Escolha: ");
    do
        scanf("%d", &opc);
    while(opc<1 || opc>5);
    switch (opc){
        case 1:
            ptr = escreve_f(local);
            break;
        case 2:
            ptr = le_f(local);
            break;
        case 3:
            //Em falta
            break;
        case 4:
            //Em falta: pedir diretorias ao utilizador
            //copia_ficheiro(origem, destino);
            break;
        default:
            ptr = NULL;
            break;
    }
    return ptr;
}

/************************************************
Descrição:
Esta função copia o conteúdo de um ficheiro de texto existente e guarda-o em
outro ficheiro de  texto numa localização defenida pelo  utilizador.
A função  recebe a localização do ficheiro de origem e a localização do ficheiro
a modificar.*/

int copia_ficheiro(const char* origem, const char* destino){
    FILE* fp_leitura = le_f(origem);    // Cria ponteiro para aceder ao ficheiro origem em modo de leitura

    fseek(fp_leitura, 0, SEEK_END);     // Faz a contagem do número de  caracteres existentes no ficheiro
    size_t size = ftell(fp_leitura);    // de origem indo para o fim do ficheiro e  usando a função ftell()
    fseek(fp_leitura, 0, SEEK_SET);

    char* buffer = (char*) malloc(size);    // Cria uma string e aloca memória com o número de caractéres do ficheiro.
    fread(buffer, 1, size, fp_leitura);     // Lê todo o conteúdo do ficheiro e guarda em buffer.
    buffer[size-1] = '\0';                  // Define o últimmo caracter da string como '\0', de modo a terminar a string
                                            // corretamente.

    FILE* fp_escrita = escreve_f(destino);  // Cria ponteiro para aceder ao ficheiro destino em modo de escrita.
    fwrite(buffer, size, 1, fp_escrita);    // Escreve conteúdo do buffer no novo ficheiro.

    fclose(fp_escrita);
    fclose(fp_leitura);
    free(buffer);
   return 1;
}

/************************************************
Descrição:
Importa uma lista através do ponteiro fp para FILE
e guarda o conteúdo numa lista.
*/

void input_list(FILE* fp, LinkedList* l){
    // Variáveis da estrutura Aluno
    char* nome;
    char mail[30];
    int numero;
    unsigned short nota;

    char buffer[80]; // buffer temporário

    while(!feof(fp)){
        fgets(buffer, 80, fp);
        strtok(buffer, "\n");       // Retira "\n" do fim da string lida
        if(buffer[0] != '\n'){      // Previne a utilização de uma string composta apenas por "\n",
                                    // relacionado com a forma de escrita de cada nó da lista.
            nome = strtok(buffer, "|");
            numero = atoi(strtok(NULL, "|")); // "|" : Caracter e de separação
            strcpy(mail, strtok(NULL, "|"));
            nota = atoi(strtok(NULL, "|"));

        // Cria estrutura Aluno com dados lidos e incere na lista
        Aluno* a = cria_estrutura(nome, numero, mail, nota);

        insert_tail(l, a);
        }
    }
    printf("\nLista importada com sucesso!\n");
}

/************************************************
Descrição:
Exporta a lista para diferentes formatos predefinidos
que o utilizador pode escolher.
*/

int export_list(LinkedList* l){
    int opc;
    char destino[30] = "Ficheiros\\";
    char file_name[20] = {"0"}; // nome do ficheiro para guardar lista

    Node* aux = l->head;

    //lista vazia?
    if(aux == NULL)
        return 0;

    printf("\nIntroduza o nome do ficheiro (sem extencao): ");

    scanf("%s", &file_name);        // lê nome do ficheiro
    strcat(destino, file_name);     // adiciona o nome do ficheiro à directoria de destino

    print_menu_header("Formato para guardar o ficheiro:");
    print_menu_option("1. Texto(.txt)");
    print_menu_option("2. Excel(.csv)");
    print_menu_option("3. HTML(.html)");
    print_menu_end_line();

    do{
        printf("%c%cOpcao: ", 8, 13);
        fflush(stdin);
        opc = getc(stdin);
    }while(opc < '1' || opc > '3');

    switch(opc){
    case '1':                 // Formato de texto
        strcat(destino, ".txt");
        export_list_txt(destino, l);
        break;
    case '2':                 // Formato csv
        strcat(destino, ".csv");
        export_list_csv(destino, l);
        break;
    case '3':                 // Formato HTML
        strcat(destino, ".html");
        export_list_html(destino, l);
        break;
    default:
    break;
    }
    return 1;
}

/************************************************
Descrição:
Exporta a lista em formato de texto
*/

void export_list_txt(char* destino, LinkedList* l){
    Node* aux = l->head;

    FILE* fp = escreve_f(destino);

    fprintf(fp, "/---------------------------------------------------------------\\\n");
    fprintf(fp, "|************** Alunos de Tecnicas de programacao **************|\n");
    fprintf(fp, "| Numero de alunos: %d\t\t\t\t\t\t|\n", length(l));
    fprintf(fp, "|---------------------------------------------------------------|\n");

    while(aux != NULL)
    {
        fprint_node_txt(fp, aux->aluno);
        fprintf(fp, "|---------------------------------------------------------------|\n");
        aux = aux->next;
    }
    fprintf(fp, "\\---------------------------------------------------------------/\n");
    printf("Lista guardada com sucesso!\n");


}

/************************************************
Descrição:
Escreve o conteúdo da estrutura Aluno de um nó para
o ficheiro de texto.
*/

void fprint_node_txt (FILE* fp, Aluno *a){

    fprintf(fp, "| Nome: %s", a->nome);
    fprint_tabs(fp, a->nome);           // escreve o número de tabs correcto para uma string
                                        // de modo a estar formatado
    fprintf(fp, "|\n");
    fprintf(fp, "| Numero: %d", a->numero);
    fprintf(fp, "\t\t\t\t\t\t\t|\n");

    fprintf(fp, "| E-mail: %s", a->mail);
    fprint_tabs(fp, a->mail);
    fprintf(fp, "|\n");                 // Insere caracter separador

    fprintf(fp, "| Nota final:  %d", a->nota_final);
    fprintf(fp, "\t\t\t\t\t\t|\n");

    fprintf(fp, "| Estado: %s", a->estado);
    fprintf(fp, "\t\t\t\t\t\t|\n");

}

/************************************************
Descrição:
Escreve o número de tabs correcto para uma string
de modo a que a informação esteja formatada.
*/

void fprint_tabs(FILE* fp, char* str){
    int i;

    size_t size = strlen(str);

    short tab_num = (size / 8) + 1;

    for (i=0;  (i + tab_num) < 8; i++)
        fprintf(fp, "\t");
}

/************************************************
Descrição:
Exporta lista em formato csv.
*/

void export_list_csv(char* destino, LinkedList* l){
    Node* aux = l->head; // Cria nó temporário para aceder aos elementos da lista
    FILE* fp = escreve_f(destino);

    fprintf(fp, "Nome do aluno;Numero;e-mail;Nota final;Estado\n");

    while(aux != NULL){
        fprintf(fp, "%s;%d;%s;%d;%s\n", aux->aluno->nome, aux->aluno->numero, aux->aluno->mail, aux->aluno->nota_final, aux->aluno->estado);
        aux = aux->next;
    }
    printf("Lista guardada com sucesso!\n");

}

/************************************************
Descrição:
Exporta lista em formato HTML.
*/

void export_list_html(char* destino, LinkedList* l){
    Node* aux = l->head;                // Cria nó temporário para aceder aos elementos da lista
    FILE* fp = escreve_f(destino);      // ponteiro para escrita em texto

    //titulo da página
    fprintf(fp, "<head>\n<title>Lista de Alunos</title>\n</head>\n");
    // Formatação da tabela
    fprintf(fp, "<style>\ntable, th, td {border: 1px solid black;\nborder-collapse: collapse;padding: 5px;}\n</style>");
    // imagem do logo do ipt
    fprintf(fp, "\n<img src=\"http://portal2.ipt.pt/img/logo.png\" alt=\"IPT Logo\" width=\"348\" height=\"65\">\n");
    // Header
    fprintf(fp, "<h1>Lista de alunos</h1>\n");

    // Cria uma tabela para escrever a lista de alunos
    fprintf(fp, "<table>");
    // Headers de cada coluna
    fprintf(fp, "\n<td><b>Nome:</b></td>");
    fprintf(fp, "\n<td><b>Numero:</b></td>");
    fprintf(fp, "\n<td><b>E-mail:</b></td>");
    fprintf(fp, "\n<td><b>Nota final:</b></td>");
    fprintf(fp, "\n<td><b>Estado:</b></td>");

    while(aux != NULL){
        fprintf(fp, "<tr>");
        // conteúdo da tabela
        fprintf(fp, "\n<td>%s</td>", aux->aluno->nome);
        fprintf(fp, "\n<td>%d</td>", aux->aluno->numero);
        fprintf(fp, "\n<td>%s</td>", aux->aluno->mail);
        fprintf(fp, "\n<td>%hu</td>", aux->aluno->nota_final);
        fprintf(fp, "\n<td>%s</td>", aux->aluno->estado);

        fprintf(fp, "\n</tr>");
    aux = aux->next;
        }
    fprintf(fp, "\n<table>\n");

    printf("Lista guardada com sucesso!\n");
}
