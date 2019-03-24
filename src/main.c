#include <stdio.h>
#include "dataLoader.h"
#include "hashtable.h"
#include "sll.h"
#include "userInterface.h"

int main() {
    char *filename= "resources/test.csv";

    printWelcomeMessage();
    char *help = promptUserForHelp();
    if (strcmp(help, "help") == 0) {
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
                temp=readFile(filename);
                printf("done.\n");
                printf("Enter the manufacture of your product\n");
                char *string =cleanInput(getMenuChoice());
                printf("Looking up manufacture \"%s\"\n",string);
                SLL *manufactureList = lookupManufacture(temp, string);
                free(string);
                displaySLL(manufactureList, stdin);
                freeTable(temp);
                break;

            default:
                break;

        }
    }
    free(help);
    return 0;
}