#include <stdio.h>
#include "myBank.h"
#define FIRSTACC 901
#define LASTACC 950

int main()
{

    int account_num = 0;
    float deposit = 0;
    float withdraw = 0;
    float interest = 0;
    float balance = 0;
    int flag = 1;

    while (flag) // run while flag == 1
    {
        printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        char action_char;
        scanf(" %c", &action_char);

        switch (action_char)
        {
        case 'O': // Open a new account and deposit your first amount
        {

            printf("Please enter amount for deposit: ");

            if (scanf(" %f", &deposit) == 0)
            {
                printf("Failed to read the amount\n");
                break;
            }
            if (deposit < 0)
            {
                printf("Invalid Amount\n");
                break;
            }
            else
            {
                account_num = open_new_account();
                if (account_num == 0)
                {
                    printf("We're sorry, the bank is full at the moment\n");
                }
                deposit_to_account(account_num, deposit);
            }

            account_num = 0;
            deposit = 0;
            break;
        }

        case 'B': // Check Your balance
        {
            printf("Please enter account number: ");
            if (scanf(" %d", &account_num) == 0)
            {
                printf("Faild to read the account number\n");
                break;
            }

            balance = check_balance(account_num);
            if (balance < 0)
            {
                break;
            }
            printf("The balance of account number %d is %.2f \n", account_num, balance);

            account_num = 0;
            balance = 0;
            break;
        }

        case 'D': // Deposit an amount to your account
        {
            int temp = 0;
            printf("Please enter account number: ");
            if (scanf(" %d", &account_num) == 0)
            {
                printf("Faild to read the account number\n");
                break;
            }
            if (account_num < FIRSTACC || account_num > LASTACC)
            {
                printf("Invalid account number\n");
                break;
            }
            if (is_account_open(account_num) == 0)
            {
                printf("This account is closed\n");
                break;
            }
            printf("Please enter amount to deposit: ");
            if (scanf(" %f", &deposit) == 0)
            {
                printf("Failed to read the amount\n");
                break;
            }
            if (deposit < 0)
            {
                temp = 1;
                printf("Cannot deposit a negative amount\n");
            }
            if (temp != 1)
            {
                deposit_to_account(account_num, deposit);
                printf("Your new balance is: %.2lf \n", check_balance(account_num));
            }
            account_num = 0;
            deposit = 0;
            break;
        }

        case 'W': // Withdraw an amount from your account
        {
            printf("Please enter account number: ");
            if (scanf(" %d", &account_num) == 0)
            {
                printf("Faild to read the account number\n");
                break;
            }
            if (account_num < FIRSTACC || account_num > LASTACC)
            {
                printf("Invalid account number\n");
                break;
            }
            if (is_account_open(account_num) == 0)
            {
                printf("This account is closed\n");
                break;
            }
            printf("Please enter the amount to withdraw: ");
            if (scanf(" %f", &withdraw) == 0)
            {
                printf("Failed to read the amount\n");
                break;
            }
            withdraw_from_account(account_num, withdraw);

            account_num = 0;
            withdraw = 0;
            break;
        }

        case 'C': // Close your bank account
        {
            printf("Please enter account number: ");
            if (scanf(" %d", &account_num) == 0)
            {
                printf("Faild to read the account number\n");
                break;
            }
            close_account(account_num);

            account_num = 0;
            break;
        }

        case 'I': // Interest to all accounts
        {
            printf("Please enter interest rate: ");
            if (scanf(" %f", &interest) == 0)
            {
                printf("Failed to read the interest rate\n");
                break;
            }
            else
                add_interest(interest);

            interest = 0;
            break;
        }

        case 'P': // Print all the bank accounts and their balances
        {
            print_all_accounts();
            break;
        }

        case 'E': // Close all the bank accounts and exit the program
        {
            close_all_accounts();

            flag = 0; // Exit the loop
            break;
        }
        default:
        {
            printf("Invalid transaction type\n");
        }
        }
    }
    return 0;
}