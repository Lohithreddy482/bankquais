// "main.h" contains the structure for a bank account and declarations for displayAccount, deposit, and withdraw

#include "main.h"
// Function to perform a deposit to the account
void deposit() {
    int accountNumber,password;
    float amount;

    // Get account information from the user
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your password number: ");
    scanf("%d", &password);

    // Declare a structure to hold loaded account information
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
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);

            // Perform the deposit and update the balance
            loadedAccount.balance += amount;

            // Move the file pointer to the beginning of the file
            fseek(file,0, SEEK_SET);

            // Write the updated balance back to the file
            fprintf(file, "%d  %.2f %d\n",loadedAccount.accountNumber, loadedAccount.balance,loadedAccount.password);

            // Close the file after updating
            fclose(file);

            // Display a successful deposit message
            printf("Deposit successful. New balance: $%.2f\n", loadedAccount.balance);
            return;      // Exit the function after processing the deposit
        }
    }

    // Close the file if the account is not found
    printf("Account not found.\n");

    // Close the file if the account is not found
    fclose(file);
}
