#ifndef Tarefa
#define Tarefa

#include <stdio.h>
#include <time.h>

typedef struct tarefa {

    int tipo ; // teste - 1
    char * nome ;
    struct tm data;
    int grau ; //grau conforto 1-lixado 5-confortavel
    int horas_total ; //nr horas total
    int horas_estudadas ; //nr horas estudadas
    
} Tarefa;

Tarefa * tarefa_nova (int tipo, char * nome, struct tm data, int grau, int horas_total, int horas_estudadas) ;
Tarefa * tarefa_clone (struct tarefa * t) ;

#endif