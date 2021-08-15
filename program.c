
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct bank_account_object
{
	char accountID[200];
	char password[200];
	double money;
} ACCOUNT;

typedef struct bank_account_login
{
	char accountID[200];
	char password[200];
} LOGIN;

bool input_account_login(LOGIN* account)
{
	printf("Input accountID: ");
	if(!scanf("%s", account->accountID)) return false;

	printf("Input Password: ");
	if(!scanf("%s", account->password)) return false;

	return true;
}

int bank_accounts_amount(ACCOUNT* accounts)
{
	int length = 0;
	for(length; strlen(accounts[length].accountID); length += 1);
	return length;
}

bool input_starting_action(char* action)
{
	printf("Action: ");
	return (scanf("%s", action) == 1);
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

		break;
	}

	return true;
}

void display_bank_account(ACCOUNT account)
{
	printf("accountID:\t%s\n", account.accountID);
	printf("password:\t%s\n", account.password);
	printf("money:\t\t%.2f\n", account.money);
}

bool input_bank_account(ACCOUNT* account)
{
	printf("Input accountID: ");
	if(!scanf("%s", account->accountID)) return false;

	printf("Input Password: ");
	if(!scanf("%s", account->password)) return false;

	return true;
}

bool create_bank_account(ACCOUNT* account, ACCOUNT* accounts, int amount)
{
	if(!input_bank_account(account)) return false;

	account->money = 0.0;

	return true;
}

bool valid_bank_account(ACCOUNT account, ACCOUNT* accounts, int amount)
{
	for(int index = 0; index < amount; index += 1)
	{
		if(!strcmp(account.accountID, accounts[index].accountID))
		{
			return false;
		}
	}
	return true;
}

bool signup_action_handler(char* accountID, ACCOUNT* accounts, int amount)
{
	ACCOUNT account;
	
	while(!valid_bank_account(account, accounts, amount))
	{
		if(!create_bank_account(&account)) return false;
	}

	accounts[amount] = account;

	strcpy(accountID, accounts[amount].accountID);

	return true;
}

bool start_action_handler(char* accountID, char* action, ACCOUNT* accounts)
{
	int amount = bank_accounts_amount(accounts);
	if(!strcmp(action, "login"))
	{
		if(!login_action_handler(accountID, accounts, amount))
		{
			return false;
		}
	}
	else if(!strcmp(action, "signup"))
	{
		if(!signup_action_handler(accountID, accounts, amount))
		{
			return false;
		}
	}
	else return false;

	return true;
}

bool extract_bank_accounts(ACCOUNT* accounts, char filename[])
{
	FILE* fPointer = fopen(filename, "r");
	if(fPointer == NULL) return false;

	for(int index = 0; fread(&accounts[index], sizeof(ACCOUNT), 1, fPointer); index += 1);

	fclose(fPointer);

	return true;
}

bool store_bank_accounts(ACCOUNT* accounts, int amount, char filename[])
{
	FILE* fPointer = fopen(filename, "w");
	if(fPointer == NULL) return false;

	for(int index = 0; index < amount; index += 1)
	{
		if(!fwrite(&accounts[index], sizeof(ACCOUNT), 1, fPointer))
		{
			return false;
		}
	}

	fclose(fPointer);

	return true;
}

int main(int aAmount, char* arguments[])
{
	char filename[] = "accounts.dat";

	ACCOUNT* accounts = malloc(sizeof(ACCOUNT) * 10);
	if(!extract_bank_accounts(accounts, filename))
	{
		printf("extract error!\n"); return true;
	}

	int amount = 0;

	printf("bank accounts:\n");
	amount = bank_accounts_amount(accounts);
	for(int index = 0; index < amount; index += 1)
	{
		display_bank_account(accounts[index]);
	}

	char* action = malloc(sizeof(char) * 1024);

	if(!input_starting_action(action))
	{
		printf("Error!\n");
	}

	char* accountID = malloc(sizeof(char) * 200);

	if(!start_action_handler(accountID, action, accounts))
	{
		printf("START ERROR!\n");
	}

	printf("accountID: %s\n", accountID);

	free(accountID);

	printf("bank accounts:\n");
	amount = bank_accounts_amount(accounts);
	for(int index = 0; index < amount; index += 1)
	{
		display_bank_account(accounts[index]);
	}

	store_bank_accounts(accounts, amount, filename);
	
	free(action); free(accounts);

	return false;
}

