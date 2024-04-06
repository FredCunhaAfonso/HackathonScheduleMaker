#ifndef tarefa
#define tarefa

#include <stdio.h>
#include <time.h>

typedef struct tarefa {

    int tipo ; // teste - 1
    char * nome ;
    struct tm data;
    int grau ; //grau conforto 
    double horas_total ; //nr horas total
    double horas_estudadas ; //nr horas estudadas
    
} Tarefa;

typedef struct daily {

    char* disciplina;
    double horas;
} Daily;

Tarefa * tarefa_nova (int tipo, char * nome, struct tm data, int grau, double horas_total, double horas_estudadas) ;

#endif