#ifndef USER
#define USER

#include <stdio.h>
#include <stdlib.h>
#include "ScheduleManager.h"

typedef struct pessoa {
    char* nome;
    char* classe;
    Tarefa * tarefas;
    int nTarefas;
    int dias[7]; // 0 = domingo, 1 = segunda, 2 = terça, 3 = quarta, 4 = quinta, 5 = sexta, 6 = sábado
} Pessoa;

char* test_user();
Pessoa * pessoa_nova (char* nome, char* classe, Tarefa * tarefas, int dias[7]);

Daily* makeSchedule (double horas_Hoje , Pessoa person);

#endif