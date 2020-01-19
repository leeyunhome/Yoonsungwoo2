// lineCount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define STOP '.'

int main()
{
	char ch;
	int n_chars = 0;
	int n_lines = 0;
	int n_words = 0;

	bool wordflag = false;
	bool lineflag = false;

	while ((ch = getchar()) != STOP)
	{
		if (!isspace(ch))
		{
			n_chars++;
		}

		if (!isspace(ch) && !lineflag)
		{
			n_lines++;
			lineflag = true;
		}

		if (!isspace(ch) && !wordflag)
		{
			n_words++;
			wordflag = true;
		}

		if (ch == '\n')
		{
			lineflag = false;
		}

		if (isspace(ch))
		{
			wordflag = false;
		}
	}

	printf("Characters : %d, Words : %d, LInes : %d", n_chars, n_words, n_lines);

	return 0;
}
