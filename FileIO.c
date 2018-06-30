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



