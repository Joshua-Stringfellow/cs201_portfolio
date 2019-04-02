//
// Created by jrstringfellow on 3/23/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userInterface.h"

void printWelcomeMessage(){
    printf("Welcome to your nutrition logger!\nType \"help\" for instructions or press ENTER to continue\n");
}

void showMenu(){
    printf("Main Menu:\n");
    printf("1.Log your food\n");
    printf("2.Review your log\n");
    printf("3.Some other options\n");
    printf("Type exit to end session\n");
}
char *getMenuChoice(){
    char *string = calloc(100, sizeof(char));
    if (string == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    return fgets(string, 100, stdin);
}
void printLoadingMessage(){
    printf("Loading Database...");
}

char *promptAddAnother(){
    char *another = calloc(2, sizeof(char));
    fgets(another, 2, stdin);
    return another;
}