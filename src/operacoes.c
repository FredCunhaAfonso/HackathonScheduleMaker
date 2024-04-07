#include "user.h"
#include "tarefa.h"
#include "ScheduleManager.h"


void horasEstudadas (int horas,Tarefa* task){
    task -> horas_estudadas += horas;
}