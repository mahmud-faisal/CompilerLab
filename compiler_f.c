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


void identifier(const char* token){
    if (!isKey(token)) {
        bool isValid = true;
        if (!isalpha(token[0]) && token[0] != '_') {
            isValid = false;
        }

        for (int i = 1; token[i] != '\0'; i++) {
            if (!isalnum(token[i]) && token[i] != '_') {
                isValid = false;
                break;
            }
        }
        
        if (isValid) {
            printf("'%s' is an identifier\n", token);
            exit(0);
        }
    }
    
}

void operator(const char* token) {
    const char* operators = "+-*/=<>&|!^?:";
    if (strlen(token) == 1 && strchr(operators, token[0]) != NULL) {
        printf("'%s' is an operator\n", token);
    }
    else if (strlen(token) == 2) {
        if ((token[0] == '+' && token[1] == '+') ||(token[0] == '-' && token[1] == '-') ||(token[0] == '&' && token[1] == '&') ||
            (token[0] == '|' && token[1] == '|') ||(token[0] == '=' && token[1] == '=') ||(token[0] == '!' && token[1] == '=') ||
            (token[0] == '<' && token[1] == '=') ||(token[0] == '>' && token[1] == '=') ||(token[0] == '+' && token[1] == '=') ||
            (token[0] == '-' && token[1] == '=') ||(token[0] == '*' && token[1] == '=') ||(token[0] == '/' && token[1] == '=') ||
            (token[0] == '%' && token[1] == '=')) {

            printf("'%s' is an operator\n", token);
            exit(0);
        }
    }
    
}


void number(const char* token){
    bool isNumber = true;
    bool hasDecimal = false;
        for (int i = 0; token[i] != '\0'; i++) {

        if (!isdigit(token[i])) {
            if (token[i] == '.' && !hasDecimal) {
                hasDecimal = true;
            } else {
                isNumber = false;
                break;
            }
        }
    }
    
    if (isNumber) {
        printf("'%s' is a number\n", token);
        exit(0);
    }
    
}

int main(){
    char token[100];
    scanf("%s",token);
    keyword(token);
    identifier(token);
    number(token);
    operator(token);
    printf("Unidentified Token\n");
    return 0;
}