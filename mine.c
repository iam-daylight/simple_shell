#include "shell.h"

/**
 * reaction - returns true if shell is interactive mode
 * @intel: struct address
 *
 * Return: 1 if reaction mode, 0 otherwise
 */
int reaction(info_t *intel)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * if_Delim - checks if character is a delimeter
 * @a: the char to check
 * @check: the delimeter string
 * Return: 1 if true, 0 if false
 */
int if_Delim(char a, char *check)
{
	while (*check)
		if (*check++ == a)
			return (1);
	return (0);
}

/**
 *alphabetic - checks for alphabetic character
 *@a: The character to input
 *Return: 1 if a is alphabetic, 0 otherwise
 */

int alphabetic(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *mine- converts a string to an integer
 *@b: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int mine(char *b)
{
	int a, indi = 1, point = 0, out;
	unsigned int answer = 0;

	for (a = 0;  b[a] != '\0' && point != 2; i++)
	{
		if (b[a] == '-')
			indi *= -1;

		if (b[a] >= '0' && b[a] <= '9')
		{
			point = 1;
			answer *= 10;
			answer += (b[a] - '0');
		}
		else if (point == 1)
			point = 2;
	}

	if (indi == -1)
		out = -answer;
	else
		out = answer;

	return (out);
}
