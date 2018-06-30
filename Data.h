#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int ano;
}data;

typedef struct tm my_tm;

enum meses {Jan=1, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez};

void pede_data(int* dia, int* mes, int* ano);
my_tm* data_atual();
bool verifica_data(int dia, int mes, int ano);
data* cria(int dia, int mes, int ano);
int compara(const data* d1, const data* d2);
int dif(const data* d1, const data* d2);
int data_em_dias(const data* d);
void soma (data* d, int dias);
int feriado(const data* d);

#endif // DATA_H_INCLUDED
