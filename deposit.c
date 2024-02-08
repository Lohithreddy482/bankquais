/*
* DEPOSITING THE AMOUNT INTO ACCOUNT

* Description:
* This program is a Bank management system designed to Deposit the Account into Account.

* File: deposit.c
* - It includes necessary function to deposit the amount into account.
*
* Usage:
* - Compile the program using a C compiler (e.g., gcc).
* - Follow the on-screen prompts to Deposit.
*
* Note: This program is for educational purposes and may require additional enhancements
* for real-world use cases such as error handling and persistence.
*/

// "main.h" contains the structure for a bank account and declarations for displayAccount, deposit, and withdraw
#include "main.h"

// Function to perform a deposit to the account
void deposit() {
    int accountNumber,password;
    int amount;
while (1) {
        printf("Enter your account number: ");

        // Try to read an integer as the account number
        if (scanf("%d", &accountNumber) == 1) {
            char c;
            // Check if the character following the integer is a newline
            if (scanf("%c", &c) == 1 && c == '\n') {
                break;  // Exit the loop if a valid integer account number is entered
            } else {
                // Input is not a valid integer
                printf("Invalid input. Enter a valid integer account number.\n");

                // Clear the input buffer
                while (getchar() != '\n');  // Consume characters until newline
            }
        } else {
            // Input is not a valid integer
            printf("Invalid input. Enter a valid integer account number.\n");

            // Clear the input buffer
            while (getchar() != '\n');  // Consume characters until newline
        }
    }

    while (1) {
        printf("Enter your password number: ");

        // Try to read an integer as the password
        if (scanf("%d", &password) == 1) {
            char c;
            // Check if the character following the integer is a newline
            if (scanf("%c", &c) == 1 && c == '\n') {
                break;  // Exit the loop if a valid integer password is entered
            } else {
                // Input is not a valid integer
                printf("Invalid input. Enter a valid integer password.\n");

                // Clear the input buffer
                while (getchar() != '\n');  // Consume characters until newline
            }
        } else {
            // Input is not a valid integer
            printf("Invalid input. Enter a valid integer password.\n");

            // Clear the input buffer
            while (getchar() != '\n');  // Consume characters until newline
        }
    }
    // Declaring a structure to hold loaded account information
    struct BankAccount loadedAccount;
    // Open the file for reading and updating
    FILE *file = fopen("C:/Users/chandrasekar/Downloads/bankquick/balance.txt", "r+");
    if (file == NULL) {
        perror("Error opening file");      //the perror is used to print an error message to the standard error stream
        exit(EXIT_FAILURE);
    }

    // Loop through the file to find the account information
    while (fscanf(file, "%d %f %d", &loadedAccount.accountNumber, &loadedAccount.balance, &loadedAccount.password) == 3){
        if (loadedAccount.accountNumber == accountNumber && loadedAccount.password==password) {
            // Prompt the user to enter the amount to deposit
            while (1) {
                printf("Enter the amount to Deposit: ");

                // Try to read an integer as the withdrawal amount
                if (scanf("%d", &amount) == 1) {
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
            // Perform the deposit and update the balance
            loadedAccount.balance += amount;

            // Move the file pointer to the beginning of the file
            fseek(file,0, SEEK_SET);

            // Write the updated balance back to the file
            fprintf(file, "%d  %.2f %d\n",loadedAccount.accountNumber, loadedAccount.balance,loadedAccount.password);

            // Close the file after updating
            fclose(file);

            // Display a successful deposit message
            printf("Deposit successful. New balance: %.2f\n", loadedAccount.balance);
            return;      // Exit the function after processing the deposit
        }
    }

    // Close the file if the account is not found
    printf("Account not found.\n");

    // Close the file if the account is not found
    fclose(file);
}
