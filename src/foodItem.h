//
// Created by jrstringfellow on 3/15/19.
//

#ifndef CS201_PORTFOLIO_DATASTRUCTURE_H
#define CS201_PORTFOLIO_DATASTRUCTURE_H

#include <stdio.h>

typedef struct foodItem{
    int id;
    char *productName;
    char *manufacture;
    double calories;
    double carbs;
    double fat;
    double protein;
    double servingSizeMlG;
    char *gMl;
    double servingSizeUnit;
    char *unit;
    struct foodItem *next;
}FOODITEM;

FOODITEM *createFoodItem(char *values[]);
void displayFoodItem(FOODITEM *,FILE *);
#endif //CS201_PORTFOLIO_DATASTRUCTURE_H

