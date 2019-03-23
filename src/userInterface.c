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

char *promptUserForHelp(){
    char *string= calloc(100, sizeof(char));
    return fgets(string, 100, stdin);
}
void printHelpMessage(){
    printf("This is the help menu\n");
}
void showMenu(){
    printf("Main Menu:\n");
    printf("1.Log your food\n");
    printf("2.Review your log\n");
    printf("3.Some other options\n");
}
char *getMenuChoice(){
    char *string = calloc(100, sizeof(char));
    return fgets(string, 100, stdin);
}
void printLoadingMessage(){
    printf("Loading Database...");
}

char* cleanInput(char *string){
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
    return string;
}
