/*
* Bank Management System

* Description:
* This program is a Bank management system designed to manage Account information.
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
* for real-world use cases such as error handling and persistence.
*/

// "main.h" contains the structure for a bank account and declarations for displayAccount, deposit, and withdraw

#include "main.h"
int main() {
    int choice;

        do{
        // Display menu
        printf("Welcome to TSL Bank\n");
        printf("1. Display Account Information\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Exit\n");
        while (1) {
                printf("Enter the choice: ");

                // Try to read an integer as the withdrawal amount
                if (scanf("%d", &choice) == 1) {
                    // Check if the amount is a valid integer
                    char c;
                    if (scanf("%c", &c) == 1 && c == '\n') {
                        // Check if the character following the integer is a newline
                        break;  // Exit the loop if a valid integer amount is entered
                    } else {
                        // Input is not a valid integer
                        printf("Invalid input. Enter a valid integer amount.\n");

                        // Clear the input buffer
                        while (getchar() != '\n');  // Consume characters until newline
                    }
                } else {
                    // Input is not a valid integer
                    printf("Invalid input. Enter a valid integer amount.\n");

                    // Clear the input buffer
                    while (getchar() != '\n');  // Consume characters until newline
                }
                  }

        switch (choice) {
            case 1:
                displayAccount();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice!=4);

    return 0;
}
