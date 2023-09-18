#include "main.h"

/**
 * check_precision - identifies precision for printing
 * @format: formatted string which prints arguments
 * @i: arguments to be printed
 * @lst: list of arguments
 * Return: precision
 */
int check_precision(const char *format, int *i, va_list lst)
{
	int pres_i = *i + 1;
	int precision = -1;

	if (format[pres_i] != '.')
		return (precision);

	precision = 0;

	for (pres_i += 1; format[pres_i] != '\0'; pres_i++)
	{
		if (is_digit(format[pres_i]))
		{
			precision *= 10;
			precision += format[pres_i] - '0';
		}
		else if (format[pres_i] == '*')
		{
			pres_i++;
			precision = va_arg(lst, int);
			break;
		}
		else
			break;
	}
	*i = pres_i - 1;

	return (precision);
}
