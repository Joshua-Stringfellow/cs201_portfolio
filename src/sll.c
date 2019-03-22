//
// Created by josh on 1/21/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sll.h"



SLL *newSLL(void (*d)(void *,FILE *fp),void (*f)(void *items)) {
        SLL *items = malloc(sizeof(SLL));
        assert(items != 0);
        items->head = 0;
        items->tail = 0;
        items->size = 0;
        items->display = d;
        items->free = f;
        return items;
}
void insertSLL(SLL *items, FOODITEM *newItem){
    if (items -> size == 0){
        items -> head = items-> tail = newItem;
    }
    else{
        items -> tail -> next = newItem;
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

//void unionSLL(SLL *recipient,SLL *donor){
//
//    if(recipient->head ==0 && recipient->tail ==0)
//    {
//        if(donor->head != 0 && donor->tail != 0)
//        {
//            recipient->head= donor->head;
//            recipient->tail = donor->tail;
//            recipient->size+= donor->size;
//            donor->tail =0; donor->head = 0;
//        }
//    }
//    else if(donor->head != 0 && donor->tail != 0){
//        recipient->tail->next = donor->head;
//        recipient->tail = donor->tail;
//        recipient->size+= donor->size;
//        donor->tail =0; donor->head = 0;
//    }
//    donor->size = 0;
//}

void *getSLL(SLL *items,int index){
    assert(index >= 0);
    FOODITEM *FOODITEM = items->head;
    if (index == sizeSLL(items)-1)
        return items->tail;
    for(int i = 0; i<index;i++)
    {
        FOODITEM = FOODITEM->next;
    }
    return FOODITEM;
}

//void *setSLL(SLL *items,int index,void *value){
//    assert(index >= 0 && index <= sizeSLL(items));
//    FOODITEM *curr = items->head;
//    void * returnvalue=0;
//    if (index == sizeSLL(items)){
//        insertSLL(items,index,value);
//        return NULL;
//    }
//    else if(index == sizeSLL(items)-1){
//        returnvalue=items->tail
//        items->tail->value = value;
//    }
//    else
//    {
//        for(int i=0; i<index; i ++){
//            curr = curr->next;
//        }
//        returnvalue = curr->value;
//        curr->value = value;
//    }
//
//    return returnvalue;
//}

int sizeSLL(SLL *items){
    return items->size;
}

//void displaySLL(SLL *items,FILE *fp){
//    //printf("Beginning Display\n");
//    if(items->head == 0)
//    {
//        fprintf(fp,"{}");
//        return;
//    }
//    FOODITEM *curr = items->head;
//    fprintf(fp,"{");
//    for(int i = 0; i < items->size; i++)
//    {
//        if(i == items->size - 1 )
//        {
//            items->display( curr->value, fp);
//        }
//        else
//        {
//            items->display(curr->value, fp);
//            fprintf(fp,",");
//        }
//        curr = curr->next;
//    }
//    fprintf(fp,"}");
//}
//
//void displayFormatq(SLL *items,FILE *fp){
//    if(items->head == 0)
//    {
//        fprintf(fp,"<>");
//        return;
//    }
//    FOODITEM *curr = items->head;
//    fprintf(fp,"<");
//    for(int i = 0; i < items->size; i++)
//    {
//        if(i == items->size - 1 )
//        {
//            items->display( curr->value, fp);
//        }
//        else
//        {
//            items->display(curr->value, fp);
//            fprintf(fp,",");
//        }
//        curr = curr->next;
//    }
//    fprintf(fp,">");
//}
//void displaySLLdebug(SLL *items,FILE *fp){
//    if (items->size == 0) {
//        fprintf(fp, "head->{},tail->{}");
//    }
//    else {
//        FOODITEM *curr = items->head;
//        fprintf(fp, "head->{");
//        while (curr != 0) {
//            items->display(curr->value, fp);
//                if (curr->next != 0)
//                    fprintf(fp, ",");
//            curr = curr->next;
//    }
//        fprintf(fp,"},tail->{");
//        //printf("Tail Value = %d", *(int*)items->tail->value);
//
//        items->display(items->tail->value, fp);
//        fprintf(fp, "}");
//    }
//
//}
void freeSLL(SLL *items){
    FOODITEM * curr;

    while (items->head != 0)
    {
        curr = items->head;
        items->head = items->head->next;
        if (items->free != 0) {
            items->free(curr->productName);
        }
        free(curr);
    }
    items->tail=NULL;
    free(items);
   }
