#include <stdio.h>
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

Daily* makeSchedule (double horas_Hoje , Pessoa person){
        
        Daily* tarefasDiarias = malloc(person.nTarefas * sizeof(Daily));

        for (int i = 0 ; i < person.nTarefas; i++){
            tarefasDiarias[i].disciplina = person.tarefas[i].nome;
            
            if (horas_Hoje > 0 && horasEstudo (person.tarefas[i]) > horas_Hoje){
                tarefasDiarias[i].horas = horas_Hoje;
            }
            else if (horas_Hoje > 0) tarefasDiarias[i].horas = horasEstudo (person.tarefas[i]);
            
            horas_Hoje = horas_Hoje - horasEstudo (person.tarefas[i]);
        }

        return tarefasDiarias;
    }



