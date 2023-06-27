#include "main.h"


/**
 * print_char - prints a character
 * @list: list of arguments
 *
 * Return: number of characters printed
 */

int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);

	return (write(1, &c, sizeof(char)));
}


/**
 * print_string - prints a string
 * @list: list of arguments
 *
 * Return: number of characters printed
 */

int print_string(va_list list)
{
	char *string;
	int len;

	len = 0;
	string = va_arg(list, char *);

	if (string == NULL)
	{
		string = "(null)";
	}

	while (string[len] != '\0')
	{
		len++;
	}

	return (write(1, string, len));
}

/**
 * print_percent - prints the '%'
 *@list: list of arguments
 *
 * Return: number of characters printed
 */

int print_percent(va_list list __attribute__((unused)))
{
	char percent;

	percent = '%';
	/*percent=va_arg(list, int); - removed*/

	return (write(1, &percent, sizeof(char)));
}
