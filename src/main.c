#include <stdio.h>
#include "dataLoader.h"
#include "hashtable.h"
#include "sll.h"
#include "userInterface.h"

int main() {

    printWelcomeMessage();
    if (strcmp(promptUserForHelp(), "help") == 0) {
        printHelpMessage();
    }
    else{
        showMenu();
        char *choice =cleanInput(getMenuChoice());
        int choiceValue = atoi(choice);
        free(choice);
        switch (choiceValue){
            case 1:
                printLoadingMessage();
                HASHTABLE *temp;
                temp=readFile("resources/test.csv");
                printf("done.\n");
                printf("Enter the manufacture of your product\n");
                char *string =cleanInput(getMenuChoice());
                printf("Looking up manufacture \"%s\"\n",string);
                SLL *manufactureList = lookupManufacture(temp, string);
                displaySLL(manufactureList, stdin);
                break;

            default:
                break;

        }



    }

    return 0;
}