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

void runLogging(char *filename){
    printLoadingMessage();
    HASHTABLE *temp;
    temp=readFile(filename);
    printf("done.\n");
    int run = 1;
    while (run == 1) {
        char logFile[30];
        printf("Enter your myBama username(in most cases first initial middle initial last name)\n");
        fgets(logFile, 30, stdin);
        printf("Enter the manufacture of your product\n");
        char *string = cleanInput(getMenuChoice());
        printf("Looking up manufacture \"%s\"\n", string);
        SLL *manufactureList = lookupManufacture(temp, string);
        free(string);
        if (manufactureList != NULL) {
            displaySLL(manufactureList, stdout);
        } else {
            printf("The manufacturer requested cannot be found.\n");
        }
        printf("Is your item in the above list? Enter the item number to log it.\n");
        char itemNumber[8];
        fgets(itemNumber, 8, stdin);
        int index = atoi(itemNumber);
        FOODITEM *item = getSLL(manufactureList, index);
        FILE *log = fopen(strcat(logFile, ".log"), "w");
        writeToFile(item,log );
        fclose(log);
        printf("Would you like to add another item? Y/n \n");
        char another[2];
        fgets(another, 2, stdin);
        if (strcmp(another, "n") == 0 || strcmp(another, "N") == 0)
            run = 0;
    }

    freeTable(temp);
}