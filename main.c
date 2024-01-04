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

            case 3:
                deposit();         // Call the function to deposit into the account
                break;
            case 4:
                withdraw();        // Call the function to wiithdraw into the account
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);
    return 0;
}
