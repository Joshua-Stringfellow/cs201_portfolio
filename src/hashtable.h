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
    SLL *items;
}TABLEITEM;

typedef struct hashtable{
    uint size;
    int count;
    TABLEITEM **items;

}HASHTABLE;

HASHTABLE *createHashTable(uint size);
void insertTable(HASHTABLE *, FOODITEM *);
#endif //CS201_PORTFOLIO_HASHTABLE_H
