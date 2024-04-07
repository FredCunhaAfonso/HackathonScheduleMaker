#include "../header/ScheduleManager.h"
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

char* test_user(){
    // Create a Pessoa object
    Pessoa person;
    person.nome = "John";
    person.nTarefas = 3;

    person.tarefas = malloc(sizeof(Tarefa) * 3);

        // Create some Tarefa objects
    person.tarefas[0].nome = "Matematica";
    person.tarefas[0].horas_total = 3;
    person.tarefas[0].data = (struct tm){.tm_mday = 10, .tm_mon = 3, .tm_year = 2024-1900}; 
    person.tarefas[1].nome = "Ciencias";
    person.tarefas[1].horas_total = 60;
    person.tarefas[1].data = (struct tm){.tm_mday = 12, .tm_mon = 3, .tm_year = 2024-1900}; // 31 Dec 2022
    person.tarefas[2].nome = "Portugues";
    person.tarefas[2].horas_total = 15;
    person.tarefas[2].data = (struct tm){.tm_mday = 15, .tm_mon = 3, .tm_year = 2024-1900}; // 31 Dec 2022


    // Call makeSchedule
    double horas_Hoje = 8;
    Daily* schedule = makeSchedule(horas_Hoje, person);

    // Print the schedule
    char* tasks = calloc(3000, sizeof(char));
    
    for (int i = 0; i < person.nTarefas; i++) {
        if (trunc(schedule[i].horas) == 0) {
            char temp[100]; // Crie uma string temporária para armazenar o resultado formatado
            sprintf(temp, "Hoje nao tens que estudar %s!\n", schedule[i].disciplina);
            strcat(tasks, temp); // Concatene a string formatada à variável tasks
        } else {
            char temp[100]; // Crie uma string temporária para armazenar o resultado formatado
            sprintf(temp, "Task: %s, Hours: %d\n", schedule[i].disciplina, (int)trunc(schedule[i].horas));
            strcat(tasks, temp); // Concatene a string formatada à variável tasks
            //printf("Alone: Task: %s, Hours: %f\n", schedule[i].disciplina, schedule[i].horas);
        }
        //printf("YO\n");
        //printf("String: %s", tasks);
    }


    // Don't forget to free the memory
    //free(schedule);
    return tasks;
}