//
// Created by jrstringfellow on 3/15/19.
//

#ifndef CS201_PORTFOLIO_DATASTRUCTURE_H
#define CS201_PORTFOLIO_DATASTRUCTURE_H
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

typedef struct foodList{
    FOODITEM *head;
    int size;
}FOODLIST;

FOODITEM *createFoodItem(char *values[]);
int  delete();
FOODITEM *retrieve(int id, FOODLIST *myList);
int update(int id);
#endif //CS201_PORTFOLIO_DATASTRUCTURE_H

