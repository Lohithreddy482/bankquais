//Defining the standard C header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Define a structure for a bank account
struct BankAccount{
    char name[30];
    int accountNumber;
    float balance;
    int password;
};

// Function declarations with the 'extern' keyword
extern void displayAccount();
extern void deposit();
extern void withdraw();
