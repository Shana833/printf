#include "main.h"

/**
 * revert_str - reverses a string
 * @str: string to be reversed
 * @len: length of string
 *
 * Return: void
 */

void revert_str(char *str, int len)
{
	int start, end;
	char temp;

	start = 0;
	end = len - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}


/**
 * itos - converts int to str
 * @num: number to be converted
 * @str: string to store num
 *
 * Return: length of string
 */

int itos(int num, char *str)
{
	int i = 0, isNeg = 0;

	if (num == 0)
	{
		str[i] = '0';
		i++;
		str[i] = '\0';

		return (1);
	}

	if (num < 0)
	{
		isNeg = 1;
		num = -num;
	}

	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		i++;
		num /= 10;
	}

	if (isNeg)
	{
		str[i] = '-';
		i++;
	}

	str[i] = '\0';

	revert_str(str, i);

	return (i);
}
