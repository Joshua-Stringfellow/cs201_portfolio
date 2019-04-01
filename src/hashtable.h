//
// Created by jrstringfellow on 3/22/19.
//

#include <sys/types.h>
#include "foodItem.h"
#include "sll.h"
#ifndef CS201_PORTFOLIO_HASHTABLE_H
#define CS201_PORTFOLIO_HASHTABLE_H

typedef struct tableItem{
    char *key;
    SLL *manufactureList;
}TABLEITEM;

typedef struct hashtable{
    size_t size;
    int count;
    TABLEITEM **items;

}HASHTABLE;

HASHTABLE *createHashTable(size_t size);
void insertTable(HASHTABLE *, FOODITEM *);
SLL *lookupManufacture(HASHTABLE *, char *);
void freeTableItem(TABLEITEM*);
void freeTable(HASHTABLE *);
#endif //CS201_PORTFOLIO_HASHTABLE_H
