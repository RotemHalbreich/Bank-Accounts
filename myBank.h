#ifndef MYBANK_H

#define MYBANK_H
#include <stdio.h>
#define ROW 2
#define COLUMN 50
extern float account_array[ROW][COLUMN];

int is_account_open(int);               //int = num of account.
int open_new_account();
float check_balance(int);               //int = num of account.
void deposit_to_account(int, float);    //int = num of account, float = amount of deposit.
void withdraw_from_account(int, float); //int = num of account, float = amount of withdrow.
void close_account(int);                //int = num of account.
void add_interest(float);               //float = amount of the interest.
void print_all_accounts();
void close_all_accounts();

#endif