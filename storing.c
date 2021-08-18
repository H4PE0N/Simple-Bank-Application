
#include "header.h"

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

bool store_bank_history(HISTORY* history, int amount, char filename[])
{
	FILE* fPointer = fopen(filename, "w");
	if(fPointer == NULL) return false;

	for(int index = 0; index < amount; index += 1)
	{
		if(!fwrite(&history[index], sizeof(HISTORY), 1, fPointer))
		{
			return false;
		}
	}

	fclose(fPointer);

	return true;
}

bool extract_bank_history(HISTORY* history, char filename[])
{
	FILE* fPointer = fopen(filename, "r");
	if(fPointer == NULL) return false;

	for(int index = 0; fread(&history[index], sizeof(HISTORY), 1, fPointer); index += 1);

	fclose(fPointer);

	return true;
}