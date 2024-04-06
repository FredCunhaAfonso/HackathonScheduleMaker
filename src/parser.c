#include "../header/parser.h"
#include <stdlib.h>
#include <stdio.h>


FILE *get_user_files(const char * username){
    char * path = malloc(sizeof(char) * (256));
    snprintf(path,256,"users/%s.txt",username); 

    FILE * user = fopen(path,"r");
    free(path);

    return user;
}

FILE *create_user_files(const char * username){
    char * path = malloc(sizeof(char) * (256));
    snprintf(path,256,"users/%s.txt",username); 

    FILE * user = fopen(path,"w");
    free(path);

    return user;

}