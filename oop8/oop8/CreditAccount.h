#pragma once

#include "Account.h"

class CreditAccount : public Account
{
private:
public:
	CreditAccount(const char *name_in, const int& id_in, int& balance_in)
		: Account(name_in, id_in, balance_in += balance_in*0.01)
	{}
	virtual void AddMoney(int money)
	{
		Account::AddMoney(money + money * 0.01);
	}
};