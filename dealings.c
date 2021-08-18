
#include "header.h"

bool deposit_bank_account(ACCOUNT* account, float value, HISTORY* history, int amount)
{
	if(value < 0) return false;

	account->money += value;

	HISTORY hisNode = create_history_node("yy/mm/dd", account->accountID, "DEPOSIT", value);

	append_history_node(history, amount, hisNode);

	return true;
}

bool withdraw_bank_account(ACCOUNT* account, float value, HISTORY* history, int amount)
{
	if(value < 0) return false;
	if(value > account->money) return false;

	account->money -= value;

	HISTORY hisNode = create_history_node("yy/mm/dd", account->accountID, "WITHDRAW", value);

	display_history_node(hisNode);

	append_history_node(history, amount, hisNode);

	return true;
}

bool delete_bank_account(ACCOUNT* accounts, int amount, char accountID[])
{
	int start = bank_account_index(accounts, amount, accountID);
	if(start == -1) return false;

	for(int index = start; index < amount; index += 1)
	{
		*(accounts + index) = *(accounts + index + 1);
	}
	return true;
}