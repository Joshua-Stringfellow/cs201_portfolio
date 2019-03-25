//
// Created by jrstringfellow on 3/23/19.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef CS201_PORTFOLIO_USERINTERFACE_H
#define CS201_PORTFOLIO_USERINTERFACE_H
void printWelcomeMessage();
char *promptUserForHelp();
void printHelpMessage();
void showMenu();
char *getMenuChoice();
void printLoadingMessage();
char *cleanInput(char *);
char *promptAddAnother();
#endif //CS201_PORTFOLIO_USERINTERFACE_H
