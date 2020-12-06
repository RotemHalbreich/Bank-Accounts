#include <stdio.h>
#include "myBank.h"
#define ROW 2
#define COLUMN 50
#define FIRSTACC 901
#define LASTACC 950

float accounts[ROW][COLUMN];

//help function: checks if the bank account is open
int is_account_open(int account_number)
{
    int account_index = account_number - FIRSTACC;
    if (account_number < FIRSTACC || account_number > LASTACC)
    {
        return -1;
    }
    if (accounts[0][account_index] == 0)
    {
        return 0;
    }
    return 1;
}

//opens a new bank account
int open_new_account()
{
    for (int i = 0; i < 50; i++)
    {
        if (is_account_open(FIRSTACC + i) == 0)
        {
            accounts[0][i] = 1;
            printf("New account number is: %d\n", (FIRSTACC + i));
            return (FIRSTACC + i);
        }
    }
    return 0;
}

//checks the balance in the bank account
float check_balance(int account_number)
{
    int account_index = account_number - FIRSTACC;

    if (is_account_open(account_number) == 0)
    {
        printf("This account is closed\n");
        return -2;
    }
    else if (is_account_open(account_number) == -1)
    {
        printf("Invalid account number\n");
        return -1;
    }
    else
    {
        return accounts[1][account_index];
    }
}

//deposit an amount to the bank account
void deposit_to_account(int account_number, float deposit)
{
    int account_index = account_number - FIRSTACC;
    if (is_account_open(account_number) == 0)
    {
        printf("This account is closed\n");
        return;
    }
    else if (is_account_open(account_number) == -1)
    {
        printf("Invalid account number\n");
        return;
    }
    else
    {
        accounts[1][account_index] += deposit;
    }
}

//withdraw an amount from the bank account
void withdraw_from_account(int account_number, float withdraw)
{
    int account_index = account_number - FIRSTACC;
    if (is_account_open(account_number) == 0)
    {
        printf("This account is closed\n");
        return;
    }
    else if (is_account_open(account_number) == -1)
    {
        printf("Invalid account number\n");
        return;
    }
    else if (is_account_open(account_number) == 1)
    {
        if (withdraw < 0)
        {
            printf("Cannot withdraw a negative amount\n");
            return;
        }
        if (withdraw < accounts[1][account_index])
        {
            accounts[1][account_index] -= withdraw;
            printf("The new balance of account number %d is %.2lf\n", account_number, accounts[1][account_index]);
        }
        else
        {
            printf("Cannot withdraw more than the balance\n");
        }
    }
}

//closes the bank account
void close_account(int account_number)
{
    int account_index = account_number - FIRSTACC;
    if (is_account_open(account_number) == 0)
    {
        printf("This account is already closed\n");
        return;
    }
    else if (is_account_open(account_number) == -1)
    {
        return;
    }
    else if (is_account_open(account_number) == 1)
    {
        accounts[0][account_index] = 0;
        accounts[1][account_index] = 0;
        printf("Closed account number %d\n", account_number);
    }
}

//adds an interest to the amount:
void add_interest(float interest)
{
    if (interest < 0)
    {
        printf("Invalid interest rate\n");
        return;
    }
    for (int i = 0; i < 50; i++)
    {
        if (is_account_open(FIRSTACC + i) == 1)
        {
            accounts[1][i] = (accounts[1][i] * (interest + 100) / 100);
        }
    }
}

//prints all the bank accounts
void print_all_accounts()
{
    for (int i = 0; i < 50; i++)
    {
        if (is_account_open(FIRSTACC + i) == 1)
        {
            printf("The balance of account %d is: %.2lf\n", (FIRSTACC + i), accounts[1][i]);
        }
    }
}

//closes all the bank accounts
void close_all_accounts()
{
    for (int i = 0; i < 50; i++)
    {
        accounts[0][i] = 0;
    }
}