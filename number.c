#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>


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
    number(token);
    printf("Not Number!\n");
    return 0;
}