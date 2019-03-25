//
// Created by josh on 1/21/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sll.h"



SLL *newSLL() {
        SLL *items = malloc(sizeof(SLL));
        assert(items != 0);
        items->head = 0;
        items->tail = 0;
        items->size = 0;
//        manufactureList->display = d;
//        manufactureList->free = f;
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

void *removeSLL(SLL *items,int index){
    assert(sizeSLL(items) > 0 && index >= 0);
    FOODITEM *curr = items->head;
    void *returnValue = curr;

    if (index == 0)
    {
        returnValue = curr;
        if (sizeSLL(items) > 1)
        {
            items->head = curr->next;
            free(curr);
        }
        else
        {
            items->head = 0;
            items-> tail = 0;
            items->size = 0;
            free(curr);
            return returnValue;
        }

    }
    else
    {
        for (int i=0; i < index - 1; i++){
            curr = curr->next;
        }
        returnValue = curr->next;
        if(index == sizeSLL(items) - 1)
        {
            items->tail = curr;
            free(curr->next);
            curr->next=0;
        }
        else
        {
            FOODITEM *removedFOODITEM = curr->next;
            curr->next = removedFOODITEM->next;
        }
    }

    items->size--;
    return returnValue;
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
            printf("\n%d. ID: %d Product Name: %s \n", counter, current->id, current->productName);
            current = current->next;
            counter++;
        }
    }
}

void freeSLL(SLL *items){
    FOODITEM * curr;

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
