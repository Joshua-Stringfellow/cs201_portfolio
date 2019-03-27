//
// Created by jrstringfellow on 3/24/19.
//
#include <time.h>
#include "logger.h"



void writeToFile(FOODITEM *myItem, FILE *fp){
    displayFoodItem(myItem, fp);
    printf("Item successfully logged\n");
}