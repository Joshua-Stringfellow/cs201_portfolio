//
// Created by jrstringfellow on 3/15/19.
//

#include <stdlib.h>
#include <string.h>
#include "foodItem.h"

FOODITEM *createFoodItem(char *values[]){
    FOODITEM *newItem = malloc(sizeof(FOODITEM));
    char *stopString="";
    newItem -> productName = strdup(values[1]);
    newItem -> manufacture = strdup(values[2]);
    newItem -> gMl = strdup(values[8]);
    newItem -> unit = strdup(values[10]);
    newItem -> servingSizeMlG = strtod(values[7],&stopString);
    newItem -> servingSizeUnit = strtod(values[9], &stopString);
    double percentage = newItem -> servingSizeMlG / 100;

    newItem -> calories = strtod(values[3], &stopString) * percentage;
    newItem -> carbs = strtod(values[4], &stopString) * percentage;
    newItem -> fat = strtod(values[5], &stopString) * percentage;
    newItem -> protein = strtod(values[6], &stopString) * percentage;
    newItem -> next = NULL;

    return newItem;
}

void displayFoodItem(FOODITEM *myItem, FILE *output, long int servings){
    fprintf(output,"ProductName: %s Calories: %.2f Fat: %.2f Carbs: %.2f Protein: %.2f\n", myItem->productName, myItem->calories*servings, myItem->fat*servings, myItem->carbs*servings, myItem->protein*servings);
}