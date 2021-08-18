
#ifndef STORING
#define STORING

#include "header.h"

bool extract_bank_accounts(ACCOUNT*, char[]);

bool extract_bank_history(HISTORY*, char[]);

bool store_bank_accounts(ACCOUNT*, int, char[]);

bool store_bank_history(HISTORY*, int, char[]);

#endif