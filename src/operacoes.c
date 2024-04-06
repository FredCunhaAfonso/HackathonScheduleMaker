#include "../header/user.h"
#include "../header/tarefa.h"

void horas_p_grau (struct tarefa * t) {

    int total = 30 ;
    
    if (t->grau == 1) {
        t->horas_total = total ;
    }
    if (t->grau == 2) {
        t->horas_total = total - 0.2 * total ;
    }
    if (t->grau == 3) {
        t->horas_total = total - 0.3 * total ;
    }
    if (t->grau == 4) {
        t->horas_total = total - 0.4 * total ;
    }
    if (t->grau == 5) {
        t->horas_total = total - 0.5 * total ;
    }
}

void introduct_tarefa (struct pessoa * p , struct tarefa * t) {

    int i = 0;
    while (p->tarefas[i].nome != NULL) {
        i++ ;
    }
    p->tarefas[i] = tarefa_clone(t);
}
