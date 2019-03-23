//
// Created by jrstringfellow on 3/22/19.
//
#include <stdlib.h>
#include <string.h>
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
    newTableItem -> items = newSLL();
    newTableItem -> items -> head = newTableItem -> items-> tail = myItem;

    return newTableItem;
}

int tablePositionEmpty(HASHTABLE *myTable, size_t hashValue){
    if (myTable->items[hashValue] == 0)
        return 1;
    return 0;
}

int isCollision(TABLEITEM * myTableItem, FOODITEM *myItem){
    return strcmp(myTableItem -> key, myItem -> manufacture);
}

void addNewTableItem(HASHTABLE *myTable, size_t  hashValue,FOODITEM *newItem){
    TABLEITEM *newTableItem = createTableItem(newItem);
    myTable -> items[hashValue] = newTableItem;
}

void addManufactureList(HASHTABLE *myTable, size_t hashValue, FOODITEM *newItem){
    FOODITEM *temp = myTable -> items[hashValue] -> items -> tail;
    temp -> next = newItem;
    myTable -> items[hashValue] -> items -> tail = newItem;
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
    else if (! tablePositionEmpty(myTable, hashValue) && !isCollision(myTable->items[hashValue], newItem)){
        addManufactureList(myTable, hashValue, newItem);
    }
    else{
        hashValue++;
        addNewTableItem(myTable, hashValue, newItem);
    }

}