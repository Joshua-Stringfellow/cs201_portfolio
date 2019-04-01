//
// Created by jrstringfellow on 3/24/19.
//
#include <string.h>
#include <stdlib.h>
#include "interfaceController.h"
#include "userInterface.h"
#include "hashtable.h"
#include "dataLoader.h"
#include "logger.h"
#define MAX 256
//https://stackoverflow.com/questions/38767967/clear-input-buffer-after-fgets-in-c
char* cleanInput(char *string){
    char *p;
    if(p=strchr(string, '\n')){//check exist newline
        *p = 0;
    } else {
        scanf("%*[^\n]");scanf("%*c");//clear upto newline
    }
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
    return string;
}

char *getFileName(){
    printf("Enter your myBama username(in most cases first initial middle initial last name)\n");
    char *logFile = strcat(cleanInput(getMenuChoice()),".log");
    return logFile;
}

FOODITEM *updateItem(char *str){
    char delim[2] = "~";
    char *ptr= strtok(str, delim);
    int index = 1;
    int value = 0;
    char *values[11];
    while(ptr != NULL)
    {
        ptr = strtok(NULL, delim);
        index ++;
    }
    return NULL ;
}

//https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-9.php
void updateFile(char *fname){
    FILE *fptr1, *fptr2;
    int linectr = 0;
    char *stop;
    char str[MAX];
    char temp[] = "temp.txt";

    printf("\n\n Update the servings for a specific item in your log :\n");
    printf("-------------------------------------------------------------\n");
    //printf(" Input the file name to be opened( ex. jrstringfellow.log) : ");
    fptr1 = fopen(fname, "r");
    if (!fptr1)
    {
        printf("Unable to open the input file!!\n");
        return;
    }
    fptr2 = fopen(temp, "a");
    if (!fptr2)
    {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr1);
        return;
    }
    /* get the line number to delete the specific line */
    printf(" Input the line no you want to replace : ");
    long int lno = strtol(cleanInput(getMenuChoice()),&stop, 10);
    /* get the new line from the user */
    printf(" Input how many servings you had: ");
    char *newServings = cleanInput(getMenuChoice());
    long int servings = strtol(newServings, &stop, 10);
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
                FOODITEM *update = updateItem(str);
                displayFoodItem(update,stdout,servings);
                //fprintf(fptr2, "%s", newln);
            }
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(fname);
    rename(temp, fname);
    printf(" File updated successfully... \n");
}

//https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-8.php
void deleteLine() {
    int lno, ctr = 0;
    char ch;
    FILE *fptr1, *fptr2;
    char *fname;
    char str[MAX], temp[] = "temp.txt";
    printf("\n\n Delete a specific line from a file :\n");
    printf("-----------------------------------------\n");
    printf(" Input the file name to be opened : ");
    fname = getFileName();
    fptr1 = fopen(fname, "r");
    if (!fptr1) {
        printf(" File not found or unable to open the input file!!\n");
    }
    fptr2 = fopen(temp, "w"); // open the temporary file in write mode
    if (!fptr2) {
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr1);
    }
    printf(" Input the line you want to remove : ");
    scanf("%d", &lno);
    lno++;
    // copy all contents to the temporary file except the specific line
    while (!feof(fptr1)) {
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1)) {
            ctr++;
            /* skip the line at given line number */
            if (ctr != lno) {
                fprintf(fptr2, "%s", str);
            }
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove(fname);        // remove the original file
    rename(temp, fname);
    // rename the temporary file to original name
/*------ Read the file ----------------*/
    fclose(fptr1);
/*------- End of reading ---------------*/
}

//public
void runLogging(HASHTABLE *temp){
    printLoadingMessage();
    //HASHTABLE *temp;
    //temp=readFile(filename);
    printf("done.\n");
    char *logFile = getFileName();
    int run = 1;
    while (run == 1) {
        printf("Enter the manufacture of your product\n");
        char *string = cleanInput(getMenuChoice());
        printf("Looking up manufacture \"%s\"\n", string);
        SLL *manufactureList = lookupManufacture(temp, string);
        free(string);
        if (manufactureList != NULL) {
            displaySLL(manufactureList, stdout);
            printf("Is your item in the above list? Enter the item number to log it.\n");
            char *itemNumber=cleanInput(getMenuChoice());
            char *stop;
            long int index = strtol(itemNumber, &stop, 10);
            long int servings = 1;
            FOODITEM *item = NULL;
            if (index <= manufactureList -> size) {
                item = getSLL(manufactureList, index);
                printf("Enter the number of servings:\n");
                char *servingStr = cleanInput(getMenuChoice());
                servings = strtol(servingStr, &stop, 10);
                //TODO check input error
                free(servingStr);
            }
            else {
                printf("Invalid item number\n");
            }
            FILE *log = fopen(logFile, "a");
            if (item!=NULL)
                writeToFile(item, log, servings);
            fclose(log);
            free(itemNumber);
        } else {
            printf("The manufacturer requested cannot be found.\n");
        }
        printf("Would you like to add another item? Y/n \n");
        char *another = cleanInput(getMenuChoice());
        if (strncmp(another, "Y", 2) != 0 && strncmp(another, "y", 2) != 0)
            run = 0;
        free(another);
    }
    free(logFile);
    freeTable(temp);
}

void updateLog(){
    char *logFile = getFileName();
    updateFile(logFile);
    free(logFile);
}