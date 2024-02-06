/*
* Bank Management System

* Description:
* This program is a simple Bank management system designed to manage Account information.
* It allows user to display the Account information, deposit,and to perform withdraw tasks.

* File: main.c
* - This file contains the main function and serves as the entry point for the program.
* - It includes necessary header files, defines constants, and implements the main menu loop.
*
* Usage:
* - Compile the program using a C compiler (e.g., gcc).
* - Follow the on-screen prompts to Deposit, withdraw, Display the account information and exit the program.
*
* Note: This program is for educational purposes and may require additional enhancements
* for real-world use cases such as error handling, data validation, and persistence.
*/

// "main.h" contains the structure for a bank account and declarations for displayAccount, deposit, and withdraw

#include "main.h"
int main(){
    int choice;

    do {
         // Display menu
        printf("1. Display Account Information\n");
        printf("2. Exit\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAccount();   // Call the function to display account information
                break;
            case 2:
                printf("Exiting...\n");   // Call the function to exit from the program
                break;
            case 3:
                deposit();         // Call the function to deposit into the account
                break;
            case 4:
                withdraw();        // Call the function to withdraw from the account
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);
    return 0;
}
