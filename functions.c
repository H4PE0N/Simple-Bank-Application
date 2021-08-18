
#include "header.h"

int bank_accounts_amount(ACCOUNT* accounts)
{
	int length = 0;
	for(length; strlen(accounts[length].accountID); length += 1);
	return length;
}

int bank_history_amount(HISTORY* history)
{
	int length = 0;
	for(length; strlen(history[length].accountID); length += 1);
	return length;
}

int bank_account_index(ACCOUNT* accounts, int amount, char accountID[])
{
	for(int index = 0; index < amount; index += 1)
	{
		if(!strcmp(accounts[index].accountID, accountID))
		{
			return index;
		}
	}
	return -1;
}

bool valid_bank_account(ACCOUNT account, ACCOUNT* accounts, int amount)
{
	if(strlen(account.accountID) == 0) return false;

	for(int index = 0; index < amount; index += 1)
	{
		if(!strcmp(account.accountID, accounts[index].accountID))
		{
			return false;
		}
	}
	return true;
}

HISTORY create_history_node(char date[], char accountID[], char dealing[], int value)
{
	HISTORY history;

	sprintf(history.date, "%s", date);
	sprintf(history.accountID, "%s", accountID);
	sprintf(history.dealing, "%s", dealing);
	history.value = value;

	return history;
}

void append_history_node(HISTORY* history, int amount, HISTORY hisNode)
{
	history[amount] = hisNode;
}
