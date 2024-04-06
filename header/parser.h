#include <stdio.h>

#ifndef PARSER_H
#define PARSER_H

FILE * get_user_files(char *);
void set_user_file(char * username, int * quantidade_de_tempo_disponivel, char ** disciplinas, char ** date, double * horas, int quantidade_disciplinas);
void print_user_file(char * username);

#endif