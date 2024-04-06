#include <stdio.h>
#include "tarefa.h"

typedef struct pessoa {
    char* nome;
    char* classe;
    Tarefa * tarefas;
    int dias[7]; // 1 = segunda, 2 = terça, 3 = quarta, 4 = quinta, 5 = sexta, 6 = sábado, 7 = domingo
} Pessoa;

