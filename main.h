#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>

/**
 * struct formats - structure
 * @type: format specifier
 * @func: function associated with @type
 */

struct formats
{
	char *type;
	int (*func)(va_list);
};

/**
 * typedef struct formats formats - structure
 * @type: format specifier
 * @func: function associated with @type
 */

typedef struct formats formats;

int _printf(const char *format, ...);

int print_char(va_list list);
int print_string(va_list list);
int print_percent(va_list list);

#endif
