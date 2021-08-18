
#ifndef PROGRAM
#define PROGRAM

#include "header.h"

bool login_action_handler(char*, ACCOUNT*, int);

bool create_bank_account(ACCOUNT*, ACCOUNT*, int);

bool signup_action_handler(char*, ACCOUNT*, int);

bool start_action_handler(char*, char[], ACCOUNT*, int);

bool bank_account_handler(ACCOUNT*, int, HISTORY*, int, char[]);

#endif