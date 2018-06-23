/*  Biblioteca para manipulação de ficheiros
*
*
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileIO.h"
#include "linkedlist.h"


/************************************************/
FILE* escreve_f(const char* local){
    FILE* ptr = fopen(local, "w");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" criado com sucesso!\n", local);

    return ptr;
}

/************************************************/

FILE* le_f (const char* local){
    FILE* ptr = fopen(local, "r");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" encontrado com sucesso!\n", local);

    return ptr;
}

/************************************************/

FILE* escreve_fB(const char* local){
    FILE* ptr = fopen(local, "wb");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" criado com sucesso!\n", local);

    return ptr;
}

/************************************************/

FILE* le_fB(const char *local){
    FILE* ptr = fopen(local, "rb");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" encontrado com sucesso!\n", local);
    return ptr;
}

/************************************************/

FILE* cria_ponteiros (const char* local){
    int opc;
    FILE* ptr;

    printf("Manipulacao de ficheiros\nOpcoes:\n");
    printf("1: Escrever\n");
    printf("2: Ler\n");
    printf("3: Apagar\n");
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
            break;
        case 4:
            break;
        default:
            ptr = NULL;
            break;
    }
    return ptr;
}

/************************************************/
/*  Esta função copia o conteúdo de um ficheiro de texto existente e guarda-o em
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

/************************************************/

void input_lista(FILE* fp, LinkedList* l){
    char* nome;
    char mail[30];
    int numero;
    unsigned short nota;

    char buffer[80];
    while(!feof(fp)){
        fgets(buffer, 80, fp);
        strtok(buffer, "\n");
        if(buffer[0] != '\n'){
            nome = strtok(buffer, "|");
            numero = atoi(strtok(NULL, "|"));
            strcpy(mail, strtok(NULL, "|"));
            nota = atoi(strtok(NULL, "|"));

        Aluno* a = cria_estrutura(nome, numero, mail, nota);

        insert_tail(l, a);
        }
    }
    printf("\nLista importada com socesso!\n");
}

/************************************************/

int output_lista(LinkedList* l){
    int opc;
    char destino[30] = "Ficheiros\\";
    char file_name[20] = {"0"};

    Node* aux = l->head;

    //lista vazia
    if(aux == NULL)
        return 0;
    printf("\nIntroduza o nome do ficheiro (sem extencao): ");
    scanf("%s", &file_name);
    strcat(destino, file_name);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Formato para guardar o ficheiro:\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\t1. Texto(.txt)\n");
    printf("\t2. Excel(.csv)\n");
    printf("\t3. HTML(.html)\n");
    printf("Opc: ");

    do
        scanf("%d", &opc);
    while(opc < 1 || opc > 3);

    switch(opc){
    case 1:
        strcat(destino, ".txt");
        formato_txt(destino, l);
        break;
    case 2:
        strcat(destino, ".csv");
        formato_csv(destino, l);
        break;
    case 3:
        strcat(destino, ".html");
        formato_html(destino, l);
        break;
    default:
    break;
    }
    return 1;
}

/************************************************/

void formato_txt(char* destino, LinkedList* l){
    Node* aux = l->head;

    FILE* fp = escreve_f(destino);

    fprintf(fp, "/---------------------------------------------------------------\\\n");
    fprintf(fp, "|************** Alunos de Tecnicas de programacao **************|\n");
    fprintf(fp, "| Numero de alunos: %d\t\t\t\t\t\t|\n", length(l));
    fprintf(fp, "|---------------------------------------------------------------|\n");

    while(aux != NULL)
    {
        fprint_node(fp, aux->aluno);
        fprintf(fp, "|---------------------------------------------------------------|\n");
        aux = aux->next;
    }
    fprintf(fp, "\\---------------------------------------------------------------/\n");
    printf("Lista guardada com sucesso!\n");


}

/************************************************/

void fprint_node (FILE* fp, Aluno *a){

    fprintf(fp, "| Nome: %s", a->nome);
    fprint_tabs(fp, a->nome);
    fprintf(fp, "|\n");

    fprintf(fp, "| Numero: %d", a->numero);
    fprintf(fp, "\t\t\t\t\t\t\t|\n");

    fprintf(fp, "| E-mail: %s", a->mail);
    fprint_tabs(fp, a->mail);
    fprintf(fp, "|\n");

    fprintf(fp, "| Nota final:  %d", a->nota_final);
    fprintf(fp, "\t\t\t\t\t\t|\n");

    fprintf(fp, "| Estado: %s", a->estado);
    fprintf(fp, "\t\t\t\t\t\t|\n");

}

/************************************************/

void fprint_tabs(FILE* fp, char* str){
    int i;

    size_t size = strlen(str);

    short tab_num = (size / 8) + 1;

    for (i=0;  (i + tab_num) < 8; i++)
        fprintf(fp, "\t");
}

/************************************************/

void formato_csv(char* destino, LinkedList* l){
    Node* aux = l->head; // Cria nó temporário para aceder aos elementos da lista
    FILE* fp = escreve_f(destino);

    fprintf(fp, "Nome do aluno;Numero;e-mail;Nota final;Estado\n");

    while(aux != NULL){
        fprintf(fp, "%s;%d;%s;%d;%s\n", aux->aluno->nome, aux->aluno->numero, aux->aluno->mail, aux->aluno->nota_final, aux->aluno->estado);
        aux = aux->next;
    }
    printf("Lista guardada com sucesso!\n");

}

/************************************************/

void formato_html(char* destino, LinkedList* l){
    Node* aux = l->head; // Cria nó temporário para aceder aos elementos da lista
    FILE* fp = escreve_f(destino);

    fprintf(fp, "<style>\ntable, th, td {border: 1px solid black;\nborder-collapse: collapse;padding: 5px;}\n</style>");

    fprintf(fp, "\n<img src=\"logo-ipt.png\" alt=\"IPT\" width=\"500\" height=\"119\">"); // Logo do ipt

    fprintf(fp, "<h1>\nLista de alunos\n</h1>");
    fprintf(fp, "<table>\n");

    while(aux != NULL){
        fprintf(fp, "<tr>");

        fprintf(fp, "\n<td><b>Nome:</b> %s</td>", aux->aluno->nome);
        fprintf(fp, "\n<td><b>Numero:</b> %d</td>", aux->aluno->numero);
        fprintf(fp, "\n<td><b>E-mail:</b> %s</td>", aux->aluno->mail);
        fprintf(fp, "\n<td><b>Nota final:</b> %hu</td>", aux->aluno->nota_final);
        fprintf(fp, "\n<td><b>Estado:</b> %s</td>", aux->aluno->estado);

        fprintf(fp, "\n</tr>");
    aux = aux->next;
        }
    fprintf(fp, "\n<table>\n");

    printf("Lista guardada com sucesso!\n");
}
