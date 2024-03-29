#include <stdio.h>
#include "dataLoader.h"
#include "hashtable.h"
#include "userInterface.h"
#include "interfaceController.h"

int main() {
    char *filename= "resources/food_nutrient_db.csv";
    //char *filename= "resources/test.csv";
    char *stop;
    HASHTABLE *dataset = readFile(filename);
    while(1){
        showMenu();
        char *choice =cleanInput(getMenuChoice());
        if (strncmp(choice,"exit",100) == 0){
            free(choice);
            break;
        }
        long int choiceValue = strtol(choice, &stop, 10);
        free(choice);
        switch (choiceValue){
            case 1:
                runLogging(dataset);
                break;

            case 2:
                updateLog(dataset);

            default:
                break;

        }
    }
    freeTable(dataset);
    //free(help);
    return 0;
}