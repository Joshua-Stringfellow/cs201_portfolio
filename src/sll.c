//
// Created by josh on 1/21/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sll.h"

SLL *newSLL() {
    SLL *items = malloc(sizeof(SLL));
    if (items == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    items->head = 0;
    items->tail = 0;
    items->size = 0;
    return items;
}
void insertSLL(SLL *items, FOODITEM *newItem){
    if (items -> size == 0){
        items -> head = newItem;
        items-> tail = newItem;
    }
    else{
        items -> tail -> next = newItem;
        items -> tail = newItem;
    }
        
    items->size++;
}

void *getSLL(SLL *items,int index){
    assert(index >= 0);
    FOODITEM *item = items->head;
    if (index == sizeSLL(items))
        return items->tail;
    for(int i = 1; i<index;i++)
    {
        item = item ->next;
    }
    return item;
}


int sizeSLL(SLL *items){
    return items->size;
}

void displaySLL(SLL *items, FILE *fp){
    if (items!=NULL) {
        FOODITEM *current = items->head;
        int counter = 1;
        while (current != NULL) {
            fprintf(fp, "%d. ",counter);
            displayFoodItem(current, fp, 1);
            current = current->next;
            counter++;
        }
    }
}

void freeSLL(SLL *items){
    FOODITEM * curr= NULL;

    while (items->head != 0)
    {
        curr = items->head;
        items->head = items->head->next;
        free(curr->productName);
        free(curr->manufacture);
        free(curr->unit);
        free(curr->gMl);
        free(curr);
    }
    items->tail=NULL;
    free(items);
}
