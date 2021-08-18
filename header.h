
#ifndef HEADER
#define HEADER

#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <string.h>

typedef struct bank_account_object
{
	char accountID[200];
	char password[200];
	float money;
} ACCOUNT;

typedef struct bank_account_login
{
	char accountID[200];
	char password[200];
} LOGIN;

typedef struct bank_dealing_history
{
	char date[20];
	char accountID[200];
	char dealing[20];
	float value;
} HISTORY;

#define ACCFILE "accounts.dat"
#define HISFILE "history.dat"

#include "storing.h"

#include "program.h"

#include "dealings.h"

#include "interface.h"

#include "functions.h"

#endif