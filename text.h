#pragma once
#include <stdio.h>

typedef enum{
    TOKEN_DIV,
    TOKEN_A,
    TOKEN_P,
    TOKEN_IMG
}Tokentype;


typedef struct sents
{
    char** mas;
    int len;
}sents_t;


char* read(FILE* fl);
char* base_info();
int check_keywords(char* word);
sents_t reed_to_sent(char* text);
void size_checker(size_t* size, size_t* cap, void** buf, int type_s);
