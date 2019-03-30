//
// Created by jrstringfellow on 3/24/19.
//
#include <time.h>
#include "logger.h"



void writeToFile(FOODITEM *myItem, FILE *fp, long int servings){
    displayFoodItem(myItem, fp, servings);
    printf("Item successfully logged\n");
}