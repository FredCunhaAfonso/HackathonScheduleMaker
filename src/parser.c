#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/parser.h"


//////////////////////////////////////////////////////////////////////
static FILE *create_user_file(char * username){
    char * path = malloc(sizeof(char) * (256));
    snprintf(path,256,"users/%s.txt",username); 

    FILE * user = fopen(path,"w");
    free(path);

    return user;
}
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
FILE * get_user_files(char * username){
    char * path = malloc(sizeof(char) * (256));
    snprintf(path,256,"users/%s.txt",username); 

    FILE * user = fopen(path,"r");
    free(path);

    return user;
}


void print_user_file(char * username){
    FILE * user = get_user_files(username);
    char * linha = malloc(sizeof(char)*256);
    char * usuario = malloc(sizeof(char) * 256);
    double x;
    
    fgets(linha,256,user);
    snprintf(usuario,256, "%s", linha+4);
    usuario[strlen(usuario)-5] = '\0';

    printf("USER: %s\n\nSemana: ", usuario);
    

    fgets(linha,256,user);
    fgets(linha,256,user);
    fgets(linha,256,user);

    for(int i = 0;fgets(linha,256,user) != NULL && i <7; i++)
    printf("%d ",atoi(linha));
    

    printf("\n\n[Disciplinas]\n");

    fgets(linha,256,user);
    fgets(linha,256,user);

    while(fgets(linha,256,user) != NULL){
        snprintf(usuario,256,"%s",linha);
        usuario[strlen(usuario)-1] = '\0';
        printf("%20s  ", usuario);


        fgets(linha,256,user);
        snprintf(usuario,256,"%s",linha);
        usuario[strlen(usuario)-1] = '\0';
        printf("%s  ", usuario);

        fgets(linha,256,user);
        snprintf(usuario,256,"%s",linha);
        x = strtod(usuario,NULL);
        printf("%.2fh\n", x);
        fgets(linha,256,user);

    }



    free(linha);
    free(usuario);
    fclose(user);
}

void set_user_file(char * username, int * quantidade_de_tempo_disponivel, char ** disciplinas, char ** date, double * horas, int quantidade_disciplinas){
    FILE * user = create_user_file(username);

    fprintf(user,"=== %s ===\n\n", username);
    fprintf(user,"[Disponibilidade]\n──────────────────────\n");


    fprintf(user,"%02dh | Segunda-feira\n",quantidade_de_tempo_disponivel[0]);
    fprintf(user,"%02dh | Terça-feira\n",quantidade_de_tempo_disponivel[1]);
    fprintf(user,"%02dh | Quarta-feirah\n",quantidade_de_tempo_disponivel[2]);
    fprintf(user,"%02dh | Quinta-feira\n",quantidade_de_tempo_disponivel[3]);
    fprintf(user,"%02dh | Sexta-feira\n",quantidade_de_tempo_disponivel[4]);
    fprintf(user,"%02dh | Sábado\n",quantidade_de_tempo_disponivel[5]);
    fprintf(user,"%02dh | Domingo\n──────────────────────\n\n",quantidade_de_tempo_disponivel[6]);

    fprintf(user,"[Disciplinas]\n");
    
    for(int i = 0; i < quantidade_disciplinas; i++){
        fprintf(user,"%s\n",disciplinas[i]);
        fprintf(user,"%s\n",date[i]);
        fprintf(user,"%.2fh\n\n",horas[i]);
    }


    fclose(user);
}
//////////////////////////////////////////////////////////////////////



/*
username
*/