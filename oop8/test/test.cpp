// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>

using std::cout;
using std::endl;

int main()
{
	int fibonacci[] = { 1, 1, 2, 300, 5, 8, 13, 21, 34,
					55, 89 };

	int max_number = std::numeric_limits<int>::lowest();
	int min_number = std::numeric_limits<int>::max();

	for (int& number : fibonacci)
	{
		max_number = (max_number > number) ? max_number : number;
		min_number = (min_number < number) ? min_number : number;
	}

	cout << "max_number : " << max_number << endl;
	cout << "min_number : " << min_number << endl;

	return 0;
}

