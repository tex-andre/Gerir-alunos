#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Data.h"


void pede_data(int* dia, int* mes, int* ano){
    do{
        printf("\nIntroduza uma data valida\nAno: ");
        scanf("%d", ano);
        printf("Mes: ");
        scanf("%d", mes);
        printf("Dia: ");
        scanf("%d", dia);

    } while (verifica_data(*dia, *mes, *ano) == false);
}

my_tm* data_atual(){
    // NULL porque antes time()
    //recebia ponteiro onde guardava o tempo,
    //agora retorna diretamente esse valor.
    time_t t = time(NULL);

    // Converte o tempo da variavel t e
    //guarda na estrutura tm
    my_tm* tmp_atual = localtime(&t);
    // Ajusta para a data atual
    tmp_atual->tm_year += 1900;
    tmp_atual->tm_mon += 1;

    return tmp_atual;
}

bool verifica_data(int dia, int mes, int ano){
    if(mes<1 || mes>12)
        return false;
    switch (mes){
        case Fev:
            if(ano%400==0 || (ano%4==0 && ano%100!=0)){
                if (dia<1 || dia>29)
                    return false;
            }else if(dia<1 || dia>28)
                    return false;
            break;
        case (Abr || Jun || Set || Nov):
                if(dia<1 || dia>30)
                    return false;
            break;
        default:
            if(dia<1 || dia>31)
                return false;
    }
    return true;
}
/**********************************************/
data* cria(int dia, int mes, int ano){
    if(verifica_data(dia, mes, ano)==1){
        data* d=malloc(sizeof(data));
        (*d).dia=dia;
        d->mes=mes;
        d->ano=ano;
        return d;
    }
    else {
        printf("\nData invalida!\n");
        return NULL;
    }
}
/**********************************************/
int compara(const data* d1, const data* d2){
    printf("%d", d2->ano);
    if(d1->ano<d2->ano)
        return -1;
    else if(d1->ano>d2->ano)
        return 1;
    else if(d1->mes<d2->mes)
        return -1;
    else if(d1->mes>d2->mes)
        return 1;
    else if(d1->dia<d2->dia)
        return -1;
    else if(d1->dia>d2->dia)
        return 1;
    else
        return 0;
}
/**********************************************/
int dif(const data* d1, const data* d2){
    int dias1, dias2, difDias;

    dias1 = data_em_dias(d1);
    dias2 = data_em_dias(d2);
    difDias = dias2 - dias1;

/*    data* dAux;

    for(i=dAux->mes; (i-d2->mes)<0;i++){
        if(i == Fev){
            if(d1->ano%400==0 || (d1->ano%4==0 && d1->ano%100!=0))
                difDias += 29;
            else
                difDias += 28;
            }
        else if(i==Abr || i==Jun || i==Set || i==Nov)
            difDias += 30;
        else
            difDias +=31; }*/

    return difDias;
}
/**********************************************/
int data_em_dias(const data* d){
    int i, dias = 0, anosBiss = 0;

     for(i=1; i<d->ano; i++)
            if(i%400==0 || (i%4==0 && i%100!=0))
                anosBiss++;
        dias = 365*d->ano + anosBiss + d->dia;

        for(i=1; i < d->mes; i++ ){
            if(i == Fev){
                if(d->ano%400==0 || (d->ano%4==0 && d->ano%100!=0))
                    dias += 29;
                else
                    dias += 28;
                }
            else if(i==Abr || i==Jun || i==Set || i==Nov)
                dias += 30;
            else
                dias +=31;
        }
    return dias;
}
/**********************************************/

void soma (data* d, int dias){
    int i;
    short sinal = 1;

    if(dias < 0)
        sinal = -1; // sinal negativo

    for(i=0; i!=dias; i += 1*sinal)
        if(verifica_data(d->dia + 1*sinal, d->mes, d->ano) == true) //se o dia anterior/seguinte for valido aumenta/diminui dia
            d->dia += 1*sinal;
        else  if(verifica_data(d->dia, d->mes + 1*sinal, d->ano) == true){
            d->mes += 1*sinal;
            d->dia = 1;
        }
        else  if(verifica_data(d->dia, d->mes, d->ano + 1*sinal) == true)
            d->ano += 1*sinal;
}
/**********************************************/
int feriado(const data* d){
    switch(d->mes){
        case Jan:
            if(d->dia == 1) return 1;
                else return 0;
        case Abr:
            if(d->dia == 25) return 1;
                else return 0;
        case Mai:
            if(d->dia == 1) return 1;
                else return 0;
        case Jun:
            if(d->dia == 10) return 1;
                else return 0;
        case Ago:
            if(d->dia == 15) return 1;
                else return 0;
        case Out:
            if(d->dia == 5) return 1;
                else return 0;
        case Nov:
            if(d->dia == 1) return 1;
                else return 0;
        case Dez:
            if(d->dia == 1 || d->dia == 8 || d->dia == 25) return 1;
                else return 0;
        default:
            return 0;
    }

}
