/*
* Withdrawing the amount from account

* Description:
* This program is a  Bank management system designed to Withdrawing the amount from account.


* File: Withdraw.c
* - It includes necessary function to Withdrawing the amount from account.
*
* Usage:
* - Compile the program using a C compiler (e.g., gcc).
* - Follow the on-screen prompts to withdraw.
*
* Note: This program is for educational purposes and may require additional enhancements
* for real-world use cases such as error handling and persistence.
*/


// "main.h" contains the structure for a bank account and declarations for displayAccount, deposit, and withdraw
#include "main.h"

// Function to perform a withdrawal from the account
void withdraw() {

    // Get account information from the user
    int accountNumber,password;
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
    int amount;

    // Declare a structure to hold loaded account information
    struct BankAccount loadedAccount;
    // Open the file1 for reading and updating
    FILE *file1 = fopen("C:/Users/chandrasekar/Downloads/bankquick/balance.txt", "r+");
    if (file1 == NULL) {
        perror("Error opening file");           //the perror is used to print an error message to the standard error stream
        exit(EXIT_FAILURE);
    }

    // Loop through the file to find the account information
    while (fscanf(file1, "%d %f %d", &loadedAccount.accountNumber, &loadedAccount.balance, &loadedAccount.password) == 3){
        if (loadedAccount.accountNumber == accountNumber &&loadedAccount.password==password) {
                  while (1) {
                printf("Enter the amount to withdraw: ");

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
        }

            // Perform the withdrawal and update the balance
            if (amount <= loadedAccount.balance) {
                loadedAccount.balance -= amount;

                // Move the file pointer to the beginning of the file
                fseek(file1, 0, SEEK_SET);

                // Write the updated balance back to the file
                fprintf(file1, "%d  %.2f %d\n",loadedAccount.accountNumber, loadedAccount.balance,loadedAccount.password);

                // Close the file after updating
                fclose(file1);

                // Display a successful withdrawal message
                printf("Withdrawal successful. New balance: %.2f\n", loadedAccount.balance);
            }
            else {
                // Display an insufficient funds message if the withdrawal amount is greater than the balance
                printf("Insufficient funds for withdrawal.\n");
            }

            // Exit the function after processing the withdrawal
            return;

    }

    // If the loop completes, the account information was not found in the file
    printf("Account not found.\n");

    // Close the file if the account is not found
    fclose(file1);
}
