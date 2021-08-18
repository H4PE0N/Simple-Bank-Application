
#ifndef DEALINGS
#define DEALINGS

#include "header.h"

bool deposit_bank_account(ACCOUNT*, float, HISTORY*, int);

bool withdraw_bank_account(ACCOUNT*, float, HISTORY*, int);

bool delete_bank_account(ACCOUNT*, int, char[]);

#endif