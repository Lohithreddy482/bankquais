// "main.h" contains the structure for a bank account and declarations for displayAccount, deposit, and withdraw
#include "main.h"

// Function to display account information
void displayAccount() {
    int accountNumber,password;
    // Get account information from the user
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your password number: ");
    scanf("%d", &password);

    // Declare a structure to hold loaded account information
    struct BankAccount loadedAccount;
    // Open the file1 for reading and updating
    FILE *file1 = fopen("C:/Users/chandrasekar/Downloads/bankquick/details.txt", "r+");
    if (file1 == NULL) {
        perror("Error opening file");          //the perror is used to print an error message to the standard error stream
        exit(EXIT_FAILURE);
    }
    // Open the file2 for reading and updating
    FILE *file2 = fopen("C:/Users/chandrasekar/Downloads/bankquick/balance.txt", "r+");
    if (file2 == NULL) {
        perror("Error opening file");           //the perror is used to print an error message to the standard error stream
        exit(EXIT_FAILURE);
    }

    // Loop through file1 to find the account information
    while (fscanf(file1, "%s %d %f %d", loadedAccount.name, &loadedAccount.accountNumber, &loadedAccount.balance, &loadedAccount.password) == 4) {
        if (loadedAccount.accountNumber == accountNumber && loadedAccount.password==password) {
            printf("\nAccount Information:\n");
            printf("Name: %s\n", loadedAccount.name);
            printf("Account Number: %d\n", loadedAccount.accountNumber);
            fclose(file1);     // Close the file1 as it's no longer needed for reading

            // Loop through file2 to find the balance information
            while (fscanf(file2, "%d %f %d", &loadedAccount.accountNumber, &loadedAccount.balance, &loadedAccount.password) == 3){
            if (loadedAccount.accountNumber == accountNumber &&loadedAccount.password==password){
                printf("Balance: %f\n",loadedAccount.balance);
                fclose(file2);    // Close the file1 as it's no longer needed for reading
                }
            }
            return;    // Exit the function as the account information has been displayed
        }
    }

    // If the loop completes, the account information was not found in file1
    printf("Account not found.\n");
    fclose(file1);  // Close the file1 as it's no longer needed for reading
}
