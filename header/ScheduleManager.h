#ifndef SCHEDULEMANAGER
#define SCHEDULEMANAGER

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "tarefa.h"


void horasEstudadas (int horas,Tarefa* task);
double horasEstudo (Tarefa tarefa1);

double dayCount(struct tm data_proxima);
void print_time_t(time_t t);
void sort_tarefas(Tarefa* tarefas, size_t count);
int compare_tarefa(const void* a, const void* b);




#endif