
#include "../header/Hackathon.h"
#include "../header/tarefa.h"
#include "../header/user.h"


int compare_tarefa(const void* a, const void* b) {
    Tarefa* tarefaA = (Tarefa*) a;
    Tarefa* tarefaB = (Tarefa*) b;

    // Convert struct tm to time_t for comparison
    time_t timeA = mktime(&tarefaA->data);
    time_t timeB = mktime(&tarefaB->data);

    // Compare the two times
    if (timeA < timeB) return -1;
    if (timeA > timeB) return 1;
    return 0;
}

void sort_tarefas(Tarefa* tarefas, size_t count) {
    qsort(tarefas, count, sizeof(Tarefa), compare_tarefa);
}

void print_time_t(time_t t) {
    struct tm *tm = localtime(&t);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);

    printf("%s\n", buffer);
}

double dayCount(struct tm data_proxima) {
    time_t agora = time(NULL); // Get the current time

    // Convert the struct tm to time_t
    time_t t_data_proxima = mktime(&data_proxima);

    // Calculate the difference in seconds
    double diferenca = difftime(t_data_proxima, agora);

    // Convert the difference to days and return it
    return diferenca / (60 * 60 * 24);
}

double horasEstudo (Tarefa tarefa1){

    double diasRestantes = dayCount (tarefa1.data);
    return (tarefa1.horas_total-tarefa1.horas_estudadas)/diasRestantes;
}

Daily* makeSchedule (double horas_Hoje , Pessoa person){

    printf("SAFE\n\n");
    
    Daily* tarefasDiarias = malloc(person.nTarefas * sizeof(Daily));

    for (int i = 0 ; i < person.nTarefas; i++){
        tarefasDiarias[i].disciplina = person.tarefas[i].nome;
        
        if (horas_Hoje > 0 && horasEstudo (person.tarefas[i]) > horas_Hoje){
            tarefasDiarias[i].horas = horas_Hoje;
        }
        else if (horas_Hoje > 0) tarefasDiarias[i].horas = horasEstudo (person.tarefas[i]);
        
        horas_Hoje = horas_Hoje - horasEstudo (person.tarefas[i]);
    }
    printf("SAFE\n\n");

    return tarefasDiarias;
}


void test_user(){
    // Create a Pessoa object
    Pessoa person;
    person.nome = "John";
    person.nTarefas = 3;

    person.tarefas = malloc(sizeof(Tarefa) * 3);


        // Create some Tarefa objects
    person.tarefas[0].nome = strdup("Math");
    person.tarefas[0].horas_total = 3;
    person.tarefas[0].data = (struct tm){.tm_mday = 10, .tm_mon = 3, .tm_year = 2024-1900}; 
    person.tarefas[1].nome = strdup("Ciencias");
    person.tarefas[1].horas_total = 60;
    person.tarefas[1].data = (struct tm){.tm_mday = 12, .tm_mon = 3, .tm_year = 2024-1900}; // 31 Dec 2022
    person.tarefas[2].nome = strdup("Portugues");
    person.tarefas[2].horas_total = 15;
    person.tarefas[2].data = (struct tm){.tm_mday = 15, .tm_mon = 3, .tm_year = 2024-1900}; // 31 Dec 2022


    printf("SAFE XD\n\n");

    // Call makeSchedule
    double horas_Hoje = 8;
    Daily* schedule = makeSchedule(horas_Hoje, person);

    // Print the schedule
    for (int i = 0; i < person.nTarefas ; i++) {
    printf("olaola  %d\n",i);
        if (trunc(schedule[i].horas) == 0) {
            printf ("hoje nao tens que estudar yupiiii!!!\n");
        }
        else {
            printf("Task: %s, Hours: %f\n", schedule[i].disciplina, trunc(schedule[i].horas));
        }
    }
    // Don't forget to free the memory
    free(schedule);

}