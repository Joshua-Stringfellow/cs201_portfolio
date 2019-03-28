//
// Created by jrstringfellow on 3/15/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataLoader.h"
#include "foodItem.h"
#include "hashtable.h"

//Private Functions
void parseString(HASHTABLE*myTable, char *string){
    char delim[] = "~";
    char *values[11];
    char *ptr = strtok(string, delim);
    int c = 0;
    while (ptr != NULL) {
        if (strlen(ptr) ==1)
            ptr="1";
        values[c] = ptr;
        ptr = strtok(NULL, delim);
        c ++;
    }
    //Some of the lines in the database are missing information
    while (c <=10){
        values[c]="";
        c++;
    }
    insertTable(myTable, createFoodItem(values));
    for (int i=0; i<11; i++){
        values[i] = "";
    }
}
//Public Functions
HASHTABLE *readFile(char *databaseFile){
    HASHTABLE *table= createHashTable(1000000);
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(databaseFile, "r");
    if (fp == NULL){
        printf("null pointer");
        return table;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        parseString(table, line);
    }
    fclose(fp);
    return table;
}

