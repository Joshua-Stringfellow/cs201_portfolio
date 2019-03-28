//
// Created by jrstringfellow on 3/15/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataLoader.h"
#include "foodItem.h"
#include "hashtable.h"
#define MAX 256
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


SLL *loadLog();
//https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-9.php
void updateFile(){
        FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[MAX],fname[MAX];
        char newln[MAX], temp[] = "temp.txt";

        printf("\n\n Replace a specific line in a text file with a new text :\n");
        printf("-------------------------------------------------------------\n");
        printf(" Input the file name to be opened( ex. jrstringfellow.log) : ");
        fgets(fname, MAX, stdin);
        fname[strlen(fname) - 1] = '\0';
        fptr1 = fopen(fname, "r");
        if (!fptr1)
        {
            printf("Unable to open the input file!!\n");
            return;
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2)
        {
            printf("Unable to open a temporary file to write!!\n");
            fclose(fptr1);
            return;
        }
        /* get the new line from the user */
        printf(" Input the content of the new line : ");
        fgets(newln, MAX, stdin);
        /* get the line number to delete the specific line */
        printf(" Input the line no you want to replace : ");
        scanf("%d", &lno);
        lno++;
        // copy all contents to the temporary file other except specific line
        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1))
            {
                linectr++;
                if (linectr != lno)
                {
                    fprintf(fptr2, "%s", str);
                }
                else
                {
                    fprintf(fptr2, "%s", newln);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);
        printf(" Replacement did successfully..!! \n");
}