
#include "header.h"

bool input_account_login(LOGIN* account)
{
	if(!string_input_promt(account->accountID, "Input accountID: "))
		return false;

	if(!string_input_promt(account->password, "Input Password: ")) 
		return false;

	return true;
}

bool string_input_promt(char* action, char promt[])
{
	printf("%s", promt); return scanf("%s", action);
}

bool value_input_promt(float* value, char promt[])
{
	printf("%s", promt); return scanf("%f", value);
}

bool input_bank_account(ACCOUNT* account)
{
	if(!string_input_promt(account->accountID, "Input accountID: "))
		return false;

	if(!string_input_promt(account->password, "Input Password: ")) 
		return false;

	return true;
}

void only_account_display(ACCOUNT account)
{
	printf("=== BANK ACCOUNT INFO ===\n");
	display_bank_account(account);
}

void only_history_display(HISTORY history)
{
	printf("=== BANK HISTORY NODE ===\n");
	display_history_node(history);
}

void display_bank_account(ACCOUNT account)
{
	printf("accountID:\t%s\n", account.accountID);
	printf("password:\t%s\n", account.password);
	printf("money:\t\t%.2f\n", account.money);
}

void display_history_node(HISTORY history)
{
	printf("Date:\t\t%s\n", history.date);
	printf("AccountID:\t%s\n", history.accountID);
	printf("Dealing:\t%s\n", history.dealing);
	printf("Value:\t\t%.2f\n", history.value);
}

void display_bank_history(HISTORY* history, int amount)
{

	printf("=== HISTORY OF DEALINGS ===\n\n");

	for(int index = 0; index < amount; index += 1)
	{
		display_history_node(history[index]);
		printf("\n");
	}
}

void display_bank_accounts(ACCOUNT* accounts, int amount)
{
	printf("=== LIST OF BANK ACCOUNTS ===\n\n");

	for(int index = 0; index < amount; index += 1)
	{
		display_bank_account(accounts[index]);
		printf("\n");
	}
}
