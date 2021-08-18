
#include "header.h"

int main(int argAmount, char* arguments[])
{
	ACCOUNT* accounts = malloc(sizeof(ACCOUNT) * 10);
	HISTORY* history = malloc(sizeof(HISTORY) * 10);

	char* action = malloc(sizeof(char) * 20);
	char* accountID = malloc(sizeof(char) * 200);

	int accAmount, hisAmount;

	if(!extract_bank_accounts(accounts, ACCFILE))
	{
		printf("account extract error!\n");

		free(accounts); free(history); free(accountID); free(action);

		return true;
	}
	
	if(!extract_bank_history(history, HISFILE))
	{
		printf("history extract error!\n");

		free(accounts); free(history); free(accountID); free(action);

		return true;
	}

	accAmount = bank_accounts_amount(accounts);
	hisAmount = bank_history_amount(history);

	if(!string_input_promt(action, "Input starting: "))
	{
		printf("Error when inputting action!\n");
	}
	
	if(!start_action_handler(accountID, action, accounts, accAmount))
	{
		printf("Neither Login or Signup entered!\n");
	}
	else
	{
		accAmount = bank_accounts_amount(accounts);

		if(!bank_account_handler(accounts, accAmount, history, hisAmount, accountID))
		{
			printf("Something did go wrong now!\n");
		}
		else
		{
			printf("Everything went fine!\n");
		}
	}

	accAmount = bank_accounts_amount(accounts);
	hisAmount = bank_history_amount(history);

	store_bank_accounts(accounts, accAmount, ACCFILE);
	store_bank_history(history, hisAmount, HISFILE);

	free(accounts); free(history); free(accountID); free(action);

	return false;
}

bool handle_bank_dealings(char action[], ACCOUNT* accounts, int accAmount, HISTORY* history, int hisAmount, char accountID[])
{
	int index = bank_account_index(accounts, accAmount, accountID);
	ACCOUNT* account = &accounts[index];

	float value = 0.0;

	if(!strcmp(action, "deposit") || !strcmp(action, "withdraw"))
	{
		if(!value_input_promt(&value, "Input value: ")) return false;
	}

	if(!strcmp(action, "deposit"))
	{
		if(!deposit_bank_account(account, value, history, hisAmount))
		{
			return false;
		}
	}
	else if(!strcmp(action, "withdraw"))
	{
		if(!withdraw_bank_account(account, value, history, hisAmount)) 
		{
			return false;
		}
	}
	else if(!strcmp(action, "delete"))
	{
		if(!delete_bank_account(accounts, accAmount, accountID))
		{
			printf("Error when deleting account!\n");

			return false;
		}
		return false;
	}
	else if(!strcmp(action, "history"))
	{
		display_bank_history(history, hisAmount);
	}

	return true;
}

bool bank_account_handler(ACCOUNT* accounts, int accAmount, HISTORY* history, int hisAmount, char accountID[])
{
	int index = bank_account_index(accounts, accAmount, accountID);

	char* action = malloc(sizeof(char) * 20);

	while(strcmp(action, "stop"))
	{
		printf("\e[1;1H\e[2J");

		only_account_display(accounts[index]);

		printf("\n");

		hisAmount = bank_history_amount(history);

		if(!handle_bank_dealings(action, accounts, accAmount, history, hisAmount, accountID))
		{
			free(action);
			return false;
		}

		printf("\n");
		if(!string_input_promt(action, "[+] ACTION: ")) 
		{
			free(action);
			return false;
		}
	}

	free(action);
	return true;
}

bool login_action_handler(char* accountID, ACCOUNT* accounts, int amount)
{
	LOGIN account;

	if(!input_account_login(&account)) return false;
	
	for(int index = 0; index < amount; index += 1)
	{
		bool accountIDValid = !strcmp(accounts[index].accountID, account.accountID);
		bool passwordValid = !strcmp(accounts[index].password, account.password);

		if(!accountIDValid || !passwordValid) continue;
		
		strcpy(accountID, accounts[index].accountID);
		return true;
	}

	return false;
}

bool create_bank_account(ACCOUNT* account, ACCOUNT* accounts, int amount)
{
	if(!input_bank_account(account)) return false;

	account->money = 0.0;

	return true;
}

bool signup_action_handler(char* accountID, ACCOUNT* accounts, int amount)
{
	ACCOUNT account;
	
	while(!valid_bank_account(account, accounts, amount))
	{
		if(!create_bank_account(&account, accounts, amount)) 
			return false;
	}

	accounts[amount] = account;

	strcpy(accountID, account.accountID);

	return true;
}

bool start_action_handler(char* accountID, char action[], ACCOUNT* accounts, int amount)
{
	if(!strcmp(action, "login"))
	{
		return login_action_handler(accountID, accounts, amount);
	}
	
	if(!strcmp(action, "signup"))
	{
		return signup_action_handler(accountID, accounts, amount);
	}

	if(!strcmp(action, "display"))
	{
		display_bank_accounts(accounts, amount);
	}

	return false;
}