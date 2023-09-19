#include "main.h"

/**
 * _precision - handles printign precision
 * @format: string
 * @arg_i: arguments to be printed
 * @arg_list: list of arguments
 *
 * Return: Precison
 */

int _precision(const char *format, int *arg_i, va_list arg_list)
{
	int init_val = *arg_i + 1;
	int val_precision = -1;

	if (format[init_val] != '.')
		return (val_precision);

	val_precision = 0;

	while (format[init_val] != '\0')
	{
		if (is_digit(format[init_val]))
		{
			val_precision *= 10;
			val_precision += format[init_val] - '0';
			init_val++;
		}
		else if (format[init_val] == '*')
		{
			init_val++;
			val_precision = va_arg(arg_list, int);
			break;
		}
		else
			break;
	}

	*arg_i = init_val - 1;

	return (val_precision);
}
