#pragma once
#include "Account.h"

class ContribAccount : public Account
{
private:
	int total_constribute;

public:
	ContribAccount(const char* name_in, const int& id_in, const int& balance_in)
		: Account(name_in, id_in, balance_in - balance_in * 0.01)
	{}

	void AddMoney(int money)
	{
		Account::AddMoney(money - money * 0.01);
		total_constribute += money * 0.01;
	}

	void ShowAllData() const
	{
		Account::ShowAllData();
		std::cout << "total_contribution : " << total_constribute << std::endl;
	}
};