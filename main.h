/*
*    Bank management system

*    This C program provides a simple implementation for managing account information.
*    It utilizes structures to Modify Account information and includes functions for depositing and withdrawing the amount.

*	Defining the standard C header files
                -->stdio.h  This header file provides functions for input and output operations, such as printf, scanf, fprintf, fscanf, and others.
                -->string.h   It provides functions for handling strings, such as strlen, strcpy, strcat, strcmp, and more.
                -->stdlib.h   provides general-purpose functions related to memory allocation.

*   Function Prototypes:
		extern void displayAccount();
		extern void deposit();
		extern void withdraw();



    Feel free to modify and extend the program according to specific requirements.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Defining a structure for a bank account
struct BankAccount{
    char name[30];
    int accountNumber;
    float balance;
    int password;
};

extern void displayAccount();
extern void deposit();
extern void withdraw();
