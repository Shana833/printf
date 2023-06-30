#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * _printf - printf function
 * @format: The format string(format specifier)
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	formats format_types[] = {
		{"c", print_char}, {"s", print_string},
		{"d", print_int}, {"i", print_int}, {"%", print_percent}, {NULL, NULL}
	};
	va_list list;
	int i, j, len_of_struct, printed = 0;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	len_of_struct = sizeof(format_types) / sizeof(formats) - 1;
	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
			printed += write(1, &format[i], 1);

		j = 0;
		while (format_types[j].type != NULL)
		{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if ((format[i] >= 7 && format[i] <= 13) || format[i] == 32)
				printed += print_percent(list);
			for (j = 0; j < len_of_struct; j++)
			{
				if (format[i] == *(format_types[j].type))
				{	printed += (format_types[j].func)(list);
					break;
				}
			}
		} j++;
		} i++;
	} va_end(list);
	return (printed);
}
