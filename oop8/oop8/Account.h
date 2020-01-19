#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Account
{
private:
	char* name;
	int id;
	int balance;

public:
	Account(const Account& account)
	{
		name = new char[strlen(account.name) + 1];
		strcpy(name, account.name);
		id = account.id;
		balance = account.balance;
	}

	Account(const char* name_in = "No Name", const int& id_in = 0, const int& balance_in = 0)
	{
		name = new char[strlen(name_in) + 1];
		strcpy(name, name_in);
		id = id_in;
		balance = balance_in;
	}

	~Account()
	{
		delete name;
	}

	char* getName()
	{
		return name;
	}

	int getId() const
	{
		return id;
	}

	int getBalance() const
	{
		return balance;
	}

	virtual void AddMoney(int money)
	{
		balance += money;
	}

	void MinMoney(int money)
	{
		balance -= money;
	}

	virtual void ShowAllData() const
	{
		std::cout << "name : " << name << std::endl;
		std::cout << "id : " << id << std::endl;
		std::cout << "balance : " << balance << std::endl;
	}
};