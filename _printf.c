#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <main.h>

/**
 * _printf - printf function
 * @format: The format string(format specifier)
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	formats format_types[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	va_list list;
	int i, j, len_of_struct, printed = 0;

	va_start(list, format);
	len_of_struct = sizeof(format_types) / sizeof(formats);
	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed++;
		}
		j = 0;
		while (format_types[j].type != NULL)
		{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; j < len_of_struct; j++)
			{
				if (format[i] == *(format_types[j].type))
				{
					printed += (format_types[j].func)(list);
					break;
				}
			}
		}
		j++;
		}
		i++;
	}
	va_end(list);

	return (printed);
}
