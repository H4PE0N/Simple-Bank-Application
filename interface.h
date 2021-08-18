
#ifndef INTERFACE
#define INTERFACE

#include "header.h"

bool input_account_login(LOGIN*);

bool string_input_promt(char*, char[]);

bool value_input_promt(float*, char[]);

bool input_bank_account(ACCOUNT*);

void display_bank_account(ACCOUNT);

void display_history_node(HISTORY);

void display_bank_history(HISTORY*, int);

void display_bank_accounts(ACCOUNT*, int);

void only_account_display(ACCOUNT);

void only_history_display(HISTORY);

#endif