#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>



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




int main(){
    char token[100];
    operator(token);
    printf("Unidentified Token\n");
    return 0;
}