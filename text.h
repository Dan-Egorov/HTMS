#pragma once
#include <stdio.h>

typedef enum{
    TOKEN_DIV,
    TOKEN_A
}Tokentype;

typedef struct sents
{
    char** mas;
    int len;
    /* data */
}sents_t;


char* read(FILE* fl);
char* base_info();
int check_keywords(char* word);
sents_t* cut_to_strokes(char* text);
