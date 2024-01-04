// "main.h" contains the structure for a bank account and declarations for displayAccount, deposit, and withdraw
#include "main.h"

// Function to perform a withdrawal from the account
void withdraw() {

    // Get account information from the user
    int accountNumber,password;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your password number: ");
    scanf("%d", &password);
    float amount;

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
            printf("Enter the amount to withdraw: ");   // Prompt the user to enter the amount to withdraw
            scanf("%f", &amount);

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
                printf("Withdrawal successful. New balance: $%.2f\n", loadedAccount.balance);
            }
            else {
                // Display an insufficient funds message if the withdrawal amount is greater than the balance
                printf("Insufficient funds for withdrawal.\n");
            }

            // Exit the function after processing the withdrawal
            return;
        }
    }

    // If the loop completes, the account information was not found in the file
    printf("Account not found.\n");

    // Close the file if the account is not found
    fclose(file1);
}
