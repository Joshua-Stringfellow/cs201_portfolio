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
        writeToFile(item, stdout);

        printf("Would you like to add another item? Y/n \n");
//        char *another = promptAddAnother();
//        while(strcmp(another, "y") !=0 || strcmp(another,"n")!=0){
//            another = promptAddAnother();
//        }
        run = 0;
    }

    freeTable(temp);
}