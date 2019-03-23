//
// Created by jrstringfellow on 3/22/19.
//
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

//private
/* D. J. Bernstein hash function https://codereview.stackexchange.com/questions/85556/simple-string-hashing-algorithm-implementation*/
static size_t hash(const char* cp, uint size)
{
    size_t hash = 5381;
    while (*cp)
        hash = 33 * hash ^ (unsigned char) *cp++;
    hash = hash % size;
    return hash;
}

TABLEITEM *createTableItem(FOODITEM *myItem){
    TABLEITEM *newTableItem = malloc(sizeof(TABLEITEM));
    newTableItem -> key = malloc(sizeof (myItem->manufacture));
    strcpy(newTableItem->key, myItem -> manufacture);
    newTableItem -> manufactureList = newSLL();
    newTableItem -> manufactureList -> head = newTableItem -> manufactureList-> tail = myItem;

    return newTableItem;
}
TABLEITEM *getTableItem(HASHTABLE *mytable, size_t hashValue){
    return mytable->items[hashValue];
}

SLL *getManufactureList(TABLEITEM* myItem){
    return myItem->manufactureList;
}

char *getItemKey(HASHTABLE *mytable, size_t hashValue){
    return mytable->items[hashValue]->key;
}
int tablePositionEmpty(HASHTABLE *myTable, size_t hashValue){
    if (myTable->items[hashValue] == 0)
        return 1;
    return 0;
}

int isCollision(char *key, char *manufacture){
    return strcmp(key, manufacture);
}

void addNewTableItem(HASHTABLE *myTable, size_t  hashValue,FOODITEM *newItem){
    TABLEITEM *newTableItem = createTableItem(newItem);
    myTable -> items[hashValue] = newTableItem;
}

void addManufactureList(HASHTABLE *myTable, size_t hashValue, FOODITEM *newItem){
    FOODITEM *temp = myTable -> items[hashValue] -> manufactureList -> tail;
    temp -> next = newItem;
    myTable -> items[hashValue] -> manufactureList -> tail = newItem;
}

void displayManufactureList(SLL *manufactureList){

}
//public
HASHTABLE *createHashTable(uint size){
    HASHTABLE *newTable = malloc(sizeof(HASHTABLE));
    newTable -> size = size;
    newTable -> count = 0;

    newTable ->items = calloc(size, sizeof(FOODITEM));
}

void insertTable(HASHTABLE *myTable, FOODITEM *newItem){
    size_t hashValue =hash(newItem->manufacture, myTable->size);
    printf("\nHash value: %lu ", hashValue);
    if (tablePositionEmpty(myTable, hashValue)){
      addNewTableItem(myTable, hashValue, newItem);
    }
    else if (! tablePositionEmpty(myTable, hashValue) && ! isCollision(getItemKey(myTable, hashValue), newItem->manufacture)){
        addManufactureList(myTable, hashValue, newItem);
    }
    else{
        while (!tablePositionEmpty(myTable, hashValue)) {
            hashValue++;
            if (hashValue >= myTable->size)
                hashValue = 0;
        }
        addNewTableItem(myTable, hashValue, newItem);
    }
    myTable->count++;
}

SLL *lookupManufacture(HASHTABLE *mytable, char *manufacture){
    size_t hashValue = hash(manufacture, mytable->size);
    if (!tablePositionEmpty(mytable, hashValue) && !isCollision(getItemKey(mytable, hashValue), manufacture)){
        displayManufactureList(getManufactureList(getTableItem(mytable,hashValue)));
    }
}