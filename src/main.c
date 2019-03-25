#include <stdio.h>
#include "dataLoader.h"
#include "hashtable.h"cd
#include "sll.h"
#include "userInterface.h"
#include "interfaceController.h"

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
                runLogging(filename);
                break;

            default:
                break;

        }
    }
    free(help);
    return 0;
}