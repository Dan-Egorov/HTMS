#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "text.h"


void size_checker(size_t* size, size_t* cap, void** buf, int type_s){
    if ((*size+1) >= *cap){
        *cap *= 2;
        *buf = realloc(*buf, *cap*type_s);
    }
}


void free_and_close_all(char* buf1, ...){
    /* This function DON'T WORK yet,
    need read about "stdarg.h" */
    va_list ap;
    va_start(ap, buf1);
    while (buf1){

        *buf1++;
    }
    va_end(ap);
}


char* base_info(){
    size_t size = 0, cap = 10;
    char* name = malloc(cap*sizeof(char));
    char ch;

    printf("Input file name: ");
    while ((ch = getchar()) != EOF && ch != '\n'){
        size_checker(&size, &cap, (void**)&name, sizeof(char));
        name[size++] = ch;
        name[size] = '\0';
    }
    return name;
}


char* read(FILE* fl){
    size_t cap_text = 10, size_text = 0;
    char* text = malloc(cap_text*sizeof(char));
    char ch;

    while ((ch = getc(fl)) != EOF){
        size_checker(&size_text, &cap_text, (void**)&text, sizeof(char));
        text[size_text++] = ch;
        text[size_text] = '\0';
    }
    return text;
}


sents_t reed_to_sent(char* text){
    sents_t rez;
    size_t cap_s = 10, size_s = 0;
    rez.mas = malloc(cap_s*sizeof(char*));
    size_t cap = 10, size = 0;
    char* stroke = malloc(cap*sizeof(char));

    for (int i = 0; text[i] != '\0'; i++){
        if (text[i] == '\n' || (text[i+1] == '\0')){
            if (text[i+1] == '\0'){
                size_checker(&size, &cap, (void**)&stroke, sizeof(char));
                stroke[size++] = text[i];
                stroke[size] = '\0';
            }
            size_checker(&size_s, &cap_s, (void**)&rez.mas, sizeof(char*));
            rez.mas[size_s] = malloc(size*sizeof(char));
            strcpy(rez.mas[size_s++], stroke);

            size = 0;
            stroke[0] = '\0';
        }else{
            size_checker(&size, &cap, (void**)&stroke, sizeof(char));
            stroke[size++] = text[i];
            stroke[size] = '\0';
        }
    }

    free(stroke);
    rez.len = size_s;
    return rez;
}


int check_keywords(char* word){
    const char* key_words[] = {"div", "a", "p", NULL};

    for (int i = 0; key_words[i] != NULL; i++){
        if (strcmp(key_words[i], word) == 0) return 1;
    }
    return 0;
}


void Flex(){

}