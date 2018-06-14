/*  Biblioteca para manipulação de ficheiros
*
*
*
*
*/

#include <stdio.h>
#include "FileIO.h"
#include "linkedlist.h"


/************************************************/
FILE* escreve_f(const char* local){
    FILE* ptr = fopen(local, "w");
    if(ptr == NULL){
        printf("\nErro a aceder ao ficheiro!\n");
        exit(1);
    }else
        printf("\nFicheiro \"%s\" encontrado com sucesso!\n", local);

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
        printf("\nFicheiro \"%s\" encontrado com sucesso!\n", local);

    return ptr;
}

/************************************************/

FILE* le_fB(const char local){
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
    int i;
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
    int i = 5;
    char buffer[30];
    while(!feof(fp)){
        fgets(buffer, 30, fp);
        strtok(buffer, "\n");
        Aluno* a = cria_estrutura(buffer, i, "aluno@ipt.pt", rand() %21);

        i--;

        insert_tail(l, a);
    }
}

/************************************************/

int output_lista(char* destino, LinkedList* l){
    int opc;

    FILE* fp = escreve_f(destino);
    Node* aux = l->head;

    //lista vazia
    if(aux == NULL)
        return 0;
    printf("Formato para guardar o ficheiro:\n");
    printf("\t1. Texto(.txt)\n");
    printf("\t2. Excel(.csv)\n");
    printf("\t3. HTML(.html)\n");
    printf("Opc: ");

    do
        scanf("%d", &opc);
    while(opc < 1 || opc > 2);

    switch(opc){
    case 1:
        formato_txt(fp, l);
        break;
    case 2:
        formato_csv(fp, l);
        break;
    case 3:
        formato_html(fp, l);
        break;
    }
    return 1;
}

/************************************************/

void formato_txt(FILE* fp, LinkedList* l){
    Node* aux = l->head;

    fprintf(fp, "Nome do aluno | Numero | e-mail | Nota final | Estado\n");

    while(aux != NULL){
        fprintf(fp, "%s | %d | %s | %d | %s\n", aux->aluno->nome, aux->aluno->numero, aux->aluno->mail, aux->aluno->nota_final, aux->aluno->estado);
        aux = aux->next;
    }
    printf("Ficheiro guardado com sucesso!\n");

    free(aux);
}

/************************************************/

void formato_csv(FILE* fp, LinkedList* l){
    Node* aux = l->head; // Cria nó temporário para aceder aos elementos da lista

    fprintf(fp, "Nome do aluno;Numero;e-mail;Nota final;Estado\n");

    while(aux != NULL){
        fprintf(fp, "%s;%d;%s;%d;%s\n", aux->aluno->nome, aux->aluno->numero, aux->aluno->mail, aux->aluno->nota_final, aux->aluno->estado);
        aux = aux->next;
    }
    printf("Ficheiro guardado com sucesso!\n");
    free(aux);
}

/************************************************/

void formato_html(FILE* fp, LinkedList* l){
    Node* aux = l->head;

    free(aux);
}
