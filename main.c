#include <stdio.h>
#include <stdlib.h>
#include "text.h"

int main(){
    char* name;
    char* text;
    size_t size = 0;
    FILE* file;
    char ch;
    sents_t sentenses;

    name = base_info();

    file = fopen(name, "r");
    if (file == NULL){
        printf("Error: file not found\n");
        return 1;
    }

    text = read(file);
    printf("%s\n", text);
    sentenses = reed_to_sent(text);

    printf("%s\n", text);
    for (int i = 0; i < sentenses.len; i++){
        printf("//%s\n", sentenses.mas[i]);
    }
    for (int i = 0; i < sentenses.len; i++) free(sentenses.mas[i]);
    free(sentenses.mas);
    free(name);
    free(text);
    fclose(file);
    return 0;
}
