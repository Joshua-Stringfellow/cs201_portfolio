//
// Created by jrstringfellow on 3/15/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataLoader.h"
#include "foodItem.h"
#include "queue.h"
#include "hashtable.h"

//Private Functions
void parseString(HASHTABLE*myTable, char *string){
    char delim[] = "~";
    char *values[10];
    char *ptr = strtok(string, delim);
    int c = 0;
    while (ptr != NULL) {
        values[c] = ptr;
        ptr = strtok(NULL, delim);
        c ++;
    }
    insertTable(myTable, createFoodItem(values));
}
//Public Functions
HASHTABLE *readFile(){
    QUEUE * temp = newQUEUE();
    HASHTABLE *table= createHashTable(50);
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("resources/test.csv", "r");
    if (fp == NULL){
        printf("null pointer");
        return table;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        parseString(table, line);
    }
    return table;
}