//
// Created by jrstringfellow on 3/15/19.
//

#include <stdlib.h>
#include <string.h>
#include "foodItem.h"

FOODITEM *createFoodItem(char *values[]){
    FOODITEM *newItem = malloc(sizeof(FOODITEM));
    char *stopString="";
    newItem -> id = atoi(values[0]);
    newItem -> productName = strdup(values[1]);
    newItem -> manufacture = strdup(values[2]);
    newItem -> gMl = strdup(values[8]);
    newItem -> unit = strdup(values[10]);
//    newItem -> manufacture = calloc(strlen(values[2]), sizeof(char));
//    newItem -> gMl = calloc(strlen(values[8]), sizeof(char));
//    newItem->unit = calloc(strlen(values[10]), sizeof(char));
//    strcpy(newItem -> productName, values[1]);
//    strcpy(newItem -> manufacture, values[2]);
    newItem -> calories = strtod(values[3], &stopString);
    newItem -> carbs = strtod(values[4], &stopString);
    newItem -> fat = strtod(values[5], &stopString);
    newItem -> protein = strtod(values[6], &stopString);
    newItem -> servingSizeMlG=strtod(values[7],&stopString);
    //strcpy(newItem -> gMl, values[8]);
    newItem -> servingSizeUnit=strtod(values[9], &stopString);
    //strcpy(newItem -> unit,values[10]);
    newItem -> next = NULL;

    return newItem;
}

void display(FOODITEM *myItem, FILE *output){
    fprintf(output, "Id: %d\n", myItem -> id);
}