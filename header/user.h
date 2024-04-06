#ifndef user
#define user


#include <stdio.h>
#include "tarefa.h"

typedef struct pessoa {
    char* nome;
    char* classe;
    Tarefa * tarefas;
    int nTarefas;
    int dias[7]; // 0 = domingo, 1 = segunda, 2 = terça, 3 = quarta, 4 = quinta, 5 = sexta, 6 = sábado
} Pessoa;

#endif