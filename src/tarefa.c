
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../header/tarefa.h"

//duncao construtora do struct tarefa
Tarefa * tarefa_nova (int tipo, char * name, struct tm data, int grau, double horas_total, double horas_estudadas) {
    Tarefa * t = malloc (sizeof (Tarefa));
    t->tipo = tipo;
    t->nome = name;
    t->data = data;
    t->grau = grau;
    t->horas_total = horas_total;
    t->horas_estudadas = horas_estudadas;
    return t;
}

