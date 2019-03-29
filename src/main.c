#include <stdio.h>
#include "dataLoader.h"
#include "hashtable.h"
#include "sll.h"
#include "userInterface.h"
#include "interfaceController.h"

int main() {
    //char *filename= "resources/food_nutrient_db.csv";
    char *filename= "resources/test.csv";
    printWelcomeMessage();
    char *help = promptUserForHelp();
    if (strcmp(help, "help") == 0) {
        printHelpMessage();
        free(help);
    }
    else{
        char exitStatus[5];
        while(1){
            showMenu();
            char *choice =cleanInput(getMenuChoice());
            if (strcmp(choice,"exit") == 0){
                free(choice);
                break;
            }
            int choiceValue = atoi(choice);
            free(choice);
            switch (choiceValue){
                case 1:
                    runLogging(filename);
                    break;
                case 2:
                    updateLog();

                default:
                    break;

            }
        }
    }
    free(help);
    return 0;
}