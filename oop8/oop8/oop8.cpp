// oop8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include "AccountManager.h"

enum
{
	OPEN = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	END
};

int main()
{
	using namespace std;

	int choice;
	AccountManager manager;

	while (1)
	{
		manager.printMenu();
		cout << "select 1~5" << endl;
		cin >> choice;
		cin.ignore(32767, '\n');

		switch (choice)
		{
		case OPEN:
			manager.openAnAccount();
			break;
		case DEPOSIT:
			manager.deposit();
			break;
		case WITHDRAW:
			manager.withdraw();
			break;
		case INQUIRE:
			manager.inquire();
			break;
		case END:
			return 0;
		default:
			cout << "wrong , try again" << endl;
			break;
		}
	}
	return 0;
}

