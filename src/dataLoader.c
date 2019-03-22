//
// Created by jrstringfellow on 3/15/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataLoader.h"
#include "foodItem.h"
#include "queue.h"

//Private Functions
void parseString(QUEUE *myQueue, char *string){
    char delim[] = "~";
    char *values[10];
    char *ptr = strtok(string, delim);
    int c = 0;
    while (ptr != NULL) {
        values[c] = ptr;
        ptr = strtok(NULL, delim);
        c ++;
    }
    enqueue(myQueue, createFoodItem(values));
}
//Public Functions
QUEUE *readFile(){
    QUEUE * temp = newQUEUE();
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("resources/test.csv", "r");
    if (fp == NULL){
        printf("null pointer");
        return temp;
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        parseString(temp, line);
    }
    display(peekQUEUE(temp), stdout);
    return temp;
}