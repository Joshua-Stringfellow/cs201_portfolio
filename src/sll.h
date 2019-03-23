//
// Created by josh on 1/21/18.
//
#ifndef __SLL_INCLUDED__
#define __SLL_INCLUDED__

#include <stdio.h>
#include "foodItem.h"

typedef struct sll {
    FOODITEM *head;
    FOODITEM *tail;
    int size;
    void (*display)(void *, FILE *);
    void (*free)(void* items);

} SLL;


extern SLL *newSLL();
extern void insertSLL(SLL *items, FOODITEM *newItem);
extern void *removeSLL(SLL *items,int index);
extern void *getSLL(SLL *items,int index);
extern int sizeSLL(SLL *items);
extern void displaySLL(SLL *list, FILE *fp);
extern void freeSLL(SLL *items);

#endif