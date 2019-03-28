//
// Created by jrstringfellow on 3/24/19.
//
#include <string.h>
#include <stdlib.h>
#include "interfaceController.h"
#include "userInterface.h"
#include "hashtable.h"
#include "dataLoader.h"
#include "logger.h"

//https://stackoverflow.com/questions/38767967/clear-input-buffer-after-fgets-in-c
char* cleanInput(char *string){
    char *p;
    if(p=strchr(string, '\n')){//check exist newline
        *p = 0;
    } else {
        scanf("%*[^\n]");scanf("%*c");//clear upto newline
    }
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
    return string;
}

void runLogging(char *filename){
    printLoadingMessage();
    HASHTABLE *temp;
    temp=readFile(filename);
    printf("done.\n");
    printf("Enter your myBama username(in most cases first initial middle initial last name)\n");
    char *logFile = cleanInput(getMenuChoice());
    int run = 1;
    while (run == 1) {
        printf("Enter the manufacture of your product\n");
        char *string = cleanInput(getMenuChoice());
        printf("Looking up manufacture \"%s\"\n", string);
        SLL *manufactureList = lookupManufacture(temp, string);
        free(string);
        if (manufactureList != NULL) {
            displaySLL(manufactureList, stdout);
            printf("Is your item in the above list? Enter the item number to log it.\n");
            char *itemNumber=cleanInput(getMenuChoice());
            int index = atoi(itemNumber);
            FOODITEM *item = getSLL(manufactureList, index);
            FILE *log = fopen(strcat(logFile, ".log"), "a");
            if (item!=NULL)
                writeToFile(item, log);
            fclose(log);
        } else {
            printf("The manufacturer requested cannot be found.\n");
        }
        printf("Would you like to add another item? Y/n \n");
        char *another = cleanInput(getMenuChoice());
        if (strncmp(another, "Y", 2) != 0 && strncmp(another, "y", 2) != 0)
            run = 0;
        free(another);
    }

    freeTable(temp);
}