#pragma once
#include "Account.h"
#include "CreditAccount.h"
#include "ContribAccount.h"

const int name_len = 20;

class AccountManager
{
private:
	Account* pArray[100];
	int index;

public:
	AccountManager()
		: index(0)
	{}

	void AddAccount(Account* acc)
	{
		pArray[index] = acc;
		index++;
	}

	void printMenu()
	{
		std::cout << "-------Menu-------" << std::endl;
		std::cout << "1. open an account" << std::endl;
		std::cout << "2. deposit" << std::endl;
		std::cout << "3. withdraw" << std::endl;
		std::cout << "4. inquire" << std::endl;
		std::cout << "5. end" << std::endl;
	}

	void openAnAccount()
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int select;
		cout << "select Account type" << endl;
		cout << "1. general" << endl;
		cout << "2. credit" << endl;
		cout << "3. contribution" << endl;

		cin >> select;

		char name[name_len];
		int id;
		int balance;
		cout << "name : ";
		cin >> name;
		cin.ignore(32767, '\n');
		cout << "id : ";
		cin >> id;
		cin.ignore(32767, '\n');
		cout << "balance : ";
		cin >> balance;
		cin.ignore(32767, '\n');

		if (select == 1)
		{
			pArray[index] = new Account(name, id, balance);
			index++;
			cout << "created" << endl;
		}
		else if (select == 2)
		{
			pArray[index] = new CreditAccount(name, id, balance);
			index++;
			cout << "created" << endl;
		}
		else if (select == 3)
		{
			pArray[index] = new ContribAccount(name, id, balance);
			index++;
			cout << "created" << endl;
		}
		
	}

	void deposit()
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int id;
		int money;
		cout << "id : ";
		cin >> id;
		cin.ignore(32767, '\n');
		cout << "money : ";
		cin >> money;
		cin.ignore(32767, '\n');

		for (int i = 0; i < index; ++i)
		{
			if (pArray[i]->getId() == id)
			{
				pArray[i]->AddMoney(money);

				cout << "deposit complete" << endl;

				return;
			}
		}
		cout << "invalid id" << endl;
	}
	void withdraw()
	{
		using std::cout;
		using std::endl;
		using std::cin;

		int id;
		int money;

		cout << "id : ";
		cin >> id;
		cin.ignore(32767, '\n');
		cout << "money : ";
		cin >> money;
		cin.ignore(32767, '\n');

		for (int i = 0; i < index; ++i)
		{
			if (pArray[i]->getId() == id)
			{
				if (pArray[i]->getBalance() < money)
				{
					cout << "not enough money" << endl;
					return;
				}
				else
				{
					pArray[i]->MinMoney(money);
					cout << "withdraw complete" << endl;
					return;
				}
				
			}
		}
		cout << "invalid id" << endl;
	}

	void inquire()
	{
		if (index == 0)
		{
			std::cout << "no account" << std::endl;
		}
		{
			for (int i = 0; i < index; ++i)
			{
				pArray[i]->ShowAllData();
			}
		}
	}
};