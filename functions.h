
#ifndef FUNCTIONS
#define FUNCTIONS

#include "header.h"

int bank_accounts_amount(ACCOUNT*);

int bank_history_amount(HISTORY*);

int bank_account_index(ACCOUNT*, int, char[]);

bool valid_bank_account(ACCOUNT, ACCOUNT*, int);

void append_history_node(HISTORY*, int, HISTORY);

HISTORY create_history_node(char[], char[], char[], int);

#endif