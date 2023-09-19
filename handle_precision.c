#include "main.h"

/**
 * _precision - handles printign precision
 * @format: string
 * @arg_i: arguments to be printed
 * @arg_list: list of arguments
 *
 * Return: Precision
 */

int _precision(const char *format, int *arg_i, va_list arg_list)
{
	int init_val = *arg_i + 1;
	int precision = -1;

	if (format[init_val] != '.')
		return (precision);

	precision = 0;

	for (init_val += 1; format[init_val] != '\0'; init_val++)
	{
		if (is_digit(format[init_val]))
		{
			precision *= 10;
			precision += format[init_val] - '0';
		}
		else if (format[init_val] == '*')
		{
			init_val++;
			precision = va_arg(arg_list, int);
			break;
		}
		else
			break;
	}

	*arg_i = init_val - 1;

	return (precision);
}
