#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Aluno.h"


/************************************************
Descrição:
Função que pede ao utilizador todos os dados de um novo aluno criando a sua estrutura e devolve o mesmo.
*/
Aluno* cria_aluno(){
    //Variaveis para a estrutura aluno
    char nome [30], mail[30];
    short numero;
    unsigned short nota_final;

    pede_dados(&nome,&numero,&mail,&nota_final);                    //Recolhe os dados do novo aluno a criar
    Aluno *a = cria_estrutura(nome,numero,mail,nota_final);         //cria a estrutura aluno e rotorna-a para a estrutura "a"

    return a;
}
/************************************************
Descrição:
Função que pede ao utilizador todos os dados de um novo aluno
*/
void pede_dados (char *nome, int* numero, char *mail, unsigned short* nota_final){

    fflush(stdin);
    printf("\n\n");
    printf("\t\t\tIntroduza os seguintes dados\t\t\t");
    printf("\n\n\n");
    printf("Nome: ");
    gets(nome);
    printf("Numero: ");
    scanf("%d", numero);
    fflush(stdin);
    printf("E-mail: ");
    gets(mail);
    printf("Nota Final: ");
    scanf("%hu", nota_final);

}
/************************************************
Descrição:
Função que cria a estrutura do aluno.
*/
Aluno *cria_estrutura(char *nome, int numero, char  *mail, unsigned short nota_final){

    Aluno *a=(Aluno*) malloc(sizeof(Aluno));

    strcpy(a->nome,nome);

    a->numero = numero;

    strcpy(a->mail,mail);

    a->nota_final = nota_final;
    if(aprovacao(nota_final))
        strcpy(a->estado, "Aprovado");
    else
        strcpy(a->estado, "Reprovado");

    return a;

}
/************************************************
Descrição:
Função que define o estado do aluno (aprovado/reprovado)
*/
bool aprovacao(unsigned short nota_final){
    return (nota_final >= 10) ? 1 : 0;
}
/************************************************
Descrição:
Função que edita o nome de um aluno e que retorna o mesmo mas com o nome alterado
*/
void editar_aluno_by_name(Aluno *a){

    /*******Novo nome do aluno que o utilizador pretende editar*****/

        char buffer_novo_nome[20];
        printf("Qual o a novo nome do aluno a que pretende editar? ");
        fflush(stdin);
        gets(buffer_novo_nome);
        printf("\n");
        strcpy(a->nome, buffer_novo_nome);
        printf("/---------------------------------------------------------------\\\n");
        printf("|************************* Aluno Alterado **********************|\n");
        printf("|---------------------------------------------------------------|\n");
        print_node(a);
        printf("\\---------------------------------------------------------------/\n");


}
/************************************************
Descrição:
Função que edita o numero de um aluno e que retorna o mesmo mas com o numero alterado
*/
void editar_aluno_by_number(Aluno *a){

    /**********Novo numero do aluno que o utilizador pretende editar****/

        int buffer_novo_number;
        printf("Qual o a novo numero do aluno a que pretende editar? ");
        fflush(stdin);
        scanf("%d", &buffer_novo_number);
        printf("\n");
        a->numero=buffer_novo_number;
        printf("/---------------------------------------------------------------\\\n");
        printf("|************************* Aluno Alterado **********************|\n");
        printf("|---------------------------------------------------------------|\n");
        print_node(a);
        printf("\\---------------------------------------------------------------/\n");


}
/************************************************
Descrição:
Função que edita o email de um aluno e que retorna o mesmo mas com o email alterado
*/
void editar_aluno_by_email(Aluno *a){

    /*******Novo email do aluno que o utilizador pretende editar***/

        char buffer_novo_email[20];
        printf("Qual o a novo email do aluno a que pretende editar? ");
        fflush(stdin);
        gets(buffer_novo_email);
        printf("\n");
        strcpy(a->mail, buffer_novo_email);

        printf("/---------------------------------------------------------------\\\n");
        printf("|************************* Aluno Alterado **********************|\n");
        printf("|---------------------------------------------------------------|\n");
        print_node(a);
        printf("\\---------------------------------------------------------------/\n");

}

void editar_aluno_by_nota(Aluno* a){
    int nova_nota = 0;
        printf("Qual a nova nota do aluno que pretende editar? ");
        fflush(stdin);
        scanf("%d", &nova_nota);
        a->nota_final = nova_nota;
        printf("\n");

        printf("/---------------------------------------------------------------\\\n");
        printf("|************************* Aluno Alterado **********************|\n");
        printf("|---------------------------------------------------------------|\n");
        print_node(a);
        printf("\\---------------------------------------------------------------/\n");

}

