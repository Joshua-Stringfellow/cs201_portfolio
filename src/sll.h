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


extern SLL *newSLL(void (*d)(void *,FILE *),void (*f)(void *));
extern void insertSLL(SLL *items, FOODITEM *newItem);
extern void *removeSLL(SLL *items,int index);
// extern void unionSLL(SLL *recipient,SLL *donor);
extern void *getSLL(SLL *items,int index);
// extern void *setSLL(SLL *items,int index,void *value);
extern int sizeSLL(SLL *items);
extern void displaySLL(SLL *items,FILE *);
extern void displayFormatq(SLL *items,FILE *);
extern void displaySLLdebug(SLL *items,FILE *);
extern void freeSLL(SLL *items);

#endif