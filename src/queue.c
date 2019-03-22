//
// Created by jrstringfellow on 2/5/18.
//
#include <stdlib.h>
#include "queue.h"
#include "sll.h"
#include "foodItem.h"

QUEUE *newQUEUE()   //constructor
{
    QUEUE *items = malloc(sizeof(QUEUE));
    items->list = newSLL();
//    items->display =d;
//    items->free=f;
    return items;
}
void enqueue(QUEUE *items,FOODITEM *value)      //stores a FoodItem
{
    insertSLL(items->list, value);
}
void *dequeue(QUEUE *items)                 //returns a FoodItem node
{
    void * a =removeSLL(items->list,0);
    return a;
}
void *peekQUEUE(QUEUE *items)               //returns a generic value
{
    return getSLL(items->list,0);
}
int sizeQUEUE(QUEUE *items)
{
    return sizeSLL(items->list);
}


void freeQUEUE(QUEUE *items){
    freeSLL(items->list);
    free(items);
}
