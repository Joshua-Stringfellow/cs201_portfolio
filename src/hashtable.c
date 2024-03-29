//
// Created by jrstringfellow on 3/22/19.
//
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

//private
/* D. J. Bernstein hash function https://codereview.stackexchange.com/questions/85556/simple-string-hashing-algorithm-implementation*/
static size_t hash(const char* cp, size_t size)
{
    size_t hash = 5381;
    while (*cp)
        hash = 33 * hash ^ (unsigned char) *cp++;
    hash = hash % size;
    return hash;
}
/*https://www.tutorialgateway.org/c-program-to-convert-string-to-lowercase/*/
char *lowerString(char* key){
    char *lowerKey = strdup(key);
    for (int i=0; i<strlen(key); i++ ){
        if(lowerKey[i] >= 'A' && lowerKey[i] <= 'Z') {
            lowerKey[i] = lowerKey[i] + 32;
        }
    }
    return lowerKey;
}

TABLEITEM *createTableItem(FOODITEM *myItem){
    char *key = lowerString(myItem->manufacture);
    TABLEITEM *newTableItem = malloc(sizeof(TABLEITEM));
    if (newTableItem == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    newTableItem -> key = key;
    newTableItem -> manufactureList = newSLL();
    insertSLL(newTableItem->manufactureList, myItem);

    return newTableItem;
}

TABLEITEM *createExisitingTableItem(char *key, SLL *list){
    TABLEITEM *newTableItem = malloc(sizeof(TABLEITEM));
    if (newTableItem == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    newTableItem -> key = key;
    newTableItem -> manufactureList = list;

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
    return strncmp(key, manufacture, 100);
}

void addNewTableItem(HASHTABLE *myTable, size_t  hashValue,FOODITEM *newItem){
    TABLEITEM *newTableItem = createTableItem(newItem);
    myTable -> items[hashValue] = newTableItem;
    myTable->count++;
}

void addManufactureList(HASHTABLE *myTable, size_t hashValue, FOODITEM *newItem){
    SLL *list = getTableItem(myTable,hashValue) -> manufactureList;
    insertSLL(list,newItem);
}

void displayManufactureList(SLL *manufactureList){
    displaySLL(manufactureList,stdout);
}

void insertExistingTableItem(HASHTABLE *myTable, char * key, SLL *manufactureList){
    size_t hashValue = hash(key,myTable->size);
    if (tablePositionEmpty(myTable, hashValue)){
        myTable -> items[hashValue] = createExisitingTableItem(key, manufactureList);
    }
    else{
        while (!tablePositionEmpty(myTable, hashValue)) {
            hashValue++;
            if (hashValue >= myTable->size -1)
                hashValue = 0;
        }
        myTable -> items[hashValue] = createExisitingTableItem(key, manufactureList);
    }
}

// adopted from https://github.com/jamesroutley/write-a-hash-table/tree/master/06-resizing
void expandTable(HASHTABLE *oldTable){
    size_t size = oldTable -> size * 2;
    HASHTABLE *newTable = createHashTable(size);
    for (int i= 0; i < oldTable -> size; i++){
        TABLEITEM *item = oldTable -> items[i];
        if (item != NULL){
            insertExistingTableItem(newTable, item->key, item->manufactureList);
            oldTable -> items[i] -> manufactureList = NULL;
            oldTable -> items [i] -> key = NULL;
        }
    }
    TABLEITEM **tmpItems = oldTable -> items;
    oldTable -> items = newTable -> items;
    newTable -> items = tmpItems;

    size_t oldsize = oldTable -> size;
    oldTable -> size = newTable -> size;
    newTable -> size = oldsize;
    freeTable(newTable);
}

//public
HASHTABLE *createHashTable(size_t size){
    HASHTABLE *newTable = malloc(sizeof(HASHTABLE));
    if (newTable == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    newTable -> size = size;
    newTable -> count = 0;
    newTable -> items = calloc(size, sizeof(FOODITEM));
    if (newTable->items == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    return newTable;
}

void insertTable(HASHTABLE *myTable, FOODITEM *newItem){
    char *key = lowerString(newItem->manufacture);
    //size_t hashValue = hash(key, myTable->size);
    //printf("\nHash value: %lu ", hashValue);
    if (myTable->count >= myTable->size/2){
        expandTable(myTable);
    }
    size_t hashValue = hash(key, myTable->size);
    if (tablePositionEmpty(myTable, hashValue)){
      addNewTableItem(myTable, hashValue, newItem);
      //displaySLL(getTableItem(myTable,hashValue) ->manufactureList, stdout);

    }
    else if (! tablePositionEmpty(myTable, hashValue) && ! isCollision(getItemKey(myTable, hashValue), key)){
        addManufactureList(myTable, hashValue, newItem);
        //displaySLL(getTableItem(myTable,hashValue) ->manufactureList, stdout);
    }
    else{
        while (!tablePositionEmpty(myTable, hashValue)) {
            hashValue++;
            if (hashValue >= myTable->size -1)
                hashValue = 0;
        }
        addNewTableItem(myTable, hashValue, newItem);
        //displaySLL(getTableItem(myTable,hashValue) ->manufactureList, stdout);
    }
    free(key);
}

SLL *lookupManufacture(HASHTABLE *mytable, char *manufacture){
    char *key = lowerString(manufacture);
    size_t hashValue = hash(key, mytable->size);
    int isEmpty=tablePositionEmpty(mytable, hashValue);
    if (!isEmpty && !isCollision(getItemKey(mytable, hashValue), key)){
        free(key);
        return getManufactureList(getTableItem(mytable,hashValue));
    }
    else if (isCollision(key, manufacture)){
        while (!isEmpty){
            hashValue++;
            isEmpty = tablePositionEmpty(mytable, hashValue);
            if (isEmpty)
                free(key);
            return NULL;
        }
        free(key);
        return getManufactureList(getTableItem(mytable, hashValue));
    }
    free(key);
    return NULL;
}
void freeTableItem(TABLEITEM *myItem){
    if (myItem -> key != NULL)
        free(myItem->key);
    if (myItem -> manufactureList)
        freeSLL(myItem->manufactureList);
    free(myItem);
}

void freeTable(HASHTABLE *myTable){
    for (int i=0; i < myTable->size; i++){
        if (myTable->items[i] != 0)
            freeTableItem(myTable->items[i]);
    }
    //free(myTable->items);
    free(myTable->items);
    free(myTable);
}