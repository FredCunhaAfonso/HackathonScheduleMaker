#include <stdio.h>
#include <user.h>
#include "../header/tarefa.h"
#include "../header/user.h"

//funcao construtora do struct user
Pessoa * pessoa_nova (char* nome, char* classe, Tarefa * tarefas, int dias[7]) {
    Pessoa * p = (Pessoa *) malloc (sizeof (Pessoa));
    p->nome = nome;
    p->classe = classe;
    p->tarefas = tarefas;
    for (int i = 0; i < 7; i++) {
        p->dias[i] = dias[i];
    }
    return p;
}

