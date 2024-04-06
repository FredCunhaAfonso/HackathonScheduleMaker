#include "../header/tarefa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//duncao construtora do struct tarefa
Tarefa * tarefa_nova (int tipo, char * nome, struct tm data, int grau, int horas_total, int horas_estudadas) {
    struct tarefa * t = (struct tarefa *) malloc (sizeof (struct tarefa));
    t->tipo = tipo;
    t->nome = nome;
    t->data = data;
    t->grau = grau;
    t->horas_total = horas_total;
    t->horas_estudadas = horas_estudadas;
    return t;
}

//criar clone de uma tarefa para outra tarefa 
Tarefa * tarefa_clone (struct tarefa * t) {
    struct tarefa * clone = (struct tarefa *) malloc (sizeof (struct tarefa));
    clone->tipo = t->tipo;
    clone->nome = strdup(t->nome);
    clone->data = t->data;
    clone->grau = t->grau;
    clone->horas_total = t->horas_total;
    clone->horas_estudadas = t->horas_estudadas;
    return clone;
}
