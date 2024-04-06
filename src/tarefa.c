#include "../header/tarefa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//duncao construtora do struct tarefa
Tarefa * tarefa_nova (int tipo, char * nome, struct tm data, int grau, int horas_total, int horas_estudadas) {
    Tarefa * t = (Tarefa *) malloc (sizeof (Tarefa));
    t->tipo = tipo;
    t->nome = nome;
    t->data = data;
    t->grau = grau;
    t->horas_total = horas_total;
    t->horas_estudadas = horas_estudadas;
    return t;
}

