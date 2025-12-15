#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"


char* base_info(){
    size_t size = 0, cap = 10;
    char* name = malloc(cap*sizeof(char));
    char ch;

    printf("Input file name: ");
    while ((ch = getchar()) != EOF && ch != '\n'){
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
        if ((size_text+1) >= cap_text){
            cap_text *= 2;
            text = realloc(text, cap_text*sizeof(char));
        }

        text[size_text++] = ch;
        text[size_text] = '\0';
    }
    return text;
}


sents_t* cut_to_strokes(char* text){
    for (int i = 0; text[i] != '\0'; i++){
        if (text[i] == '\0') printf("///////%d, %c", i, text[i-1]);
    }
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