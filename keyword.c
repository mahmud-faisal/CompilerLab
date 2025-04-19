#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

bool isKey(const char* str) {
    const char* keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "main",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

void keyword(const char* token) {
    if (isKey(token)) {
        printf("'%s' is a keyword\n", token);    
        exit(0);
    }
}


int main(){
    char token[100];
    scanf("%s",token);
    keyword(token);
    printf("Not keyword\n");
    return 0;
}