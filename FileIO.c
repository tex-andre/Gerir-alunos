/*******************************************************\
*   Biblioteca para manipula��o de ficheiros            *
*   associados ao trabalho de t�cnicas de programa��o   *
*                                                       *
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileIO.h"
#include "linkedlist.h"

/************************************************
Descri��o:
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
Descri��o:
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
Descri��o:
Retorna um ponteiro FILE para escrita bin�ria "wb"
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
Descri��o:
Retorna um ponteiro FILE para leitura bin�ria "rb"
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
Descri��o: */

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
Descri��o:
Esta fun��o copia o conte�do de um ficheiro de texto existente e guarda-o em
outro ficheiro de  texto numa localiza��o defenida pelo  utilizador.
A fun��o  recebe a localiza��o do ficheiro de origem e a localiza��o do ficheiro
a modificar.*/

int copia_ficheiro(const char* origem, const char* destino){
    FILE* fp_leitura = le_f(origem);    // Cria ponteiro para aceder ao ficheiro origem em modo de leitura

    fseek(fp_leitura, 0, SEEK_END);     // Faz a contagem do n�mero de  caracteres existentes no ficheiro
    size_t size = ftell(fp_leitura);    // de origem indo para o fim do ficheiro e  usando a fun��o ftell()
    fseek(fp_leitura, 0, SEEK_SET);

    char* buffer = (char*) malloc(size);    // Cria uma string e aloca mem�ria com o n�mero de caract�res do ficheiro.
    fread(buffer, 1, size, fp_leitura);     // L� todo o conte�do do ficheiro e guarda em buffer.
    buffer[size-1] = '\0';                  // Define o �ltimmo caracter da string como '\0', de modo a terminar a string
                                            // corretamente.

    FILE* fp_escrita = escreve_f(destino);  // Cria ponteiro para aceder ao ficheiro destino em modo de escrita.
    fwrite(buffer, size, 1, fp_escrita);    // Escreve conte�do do buffer no novo ficheiro.

    fclose(fp_escrita);
    fclose(fp_leitura);
    free(buffer);
   return 1;
}



