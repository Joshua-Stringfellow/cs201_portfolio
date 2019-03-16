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
}FOODITEM;

FOODITEM* create(char *values[]);
int  delete(int id);
struct foodItem* retrieve(int id);
int update(int id);
#endif //CS201_PORTFOLIO_DATASTRUCTURE_H

