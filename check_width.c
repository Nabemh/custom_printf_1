#include "main.h"

/**
 * check_width - determines wdith for printing
 * @format: formatted string to print arguments
 * @i: arguments to be printed
 * @lst: list of arguments
 * Return: width
 */
int check_width(const char *format, int *i, va_list lst)
{
	int pres_i;
	int width = 0;

	for (pres_i = *i + 1; format[pres_i] != '\0'; pres_i++)
	{
		if (is_digit(format[pres_i]))
		{
			width *= 10;
			width += format[pres_i] - '0';
		}
		else if (format[pres_i] == '*')
		{
			pres_i++;
			width = va_arg(lst, int);
			break;
		}
		else
			break;
	}
	*i = pres_i - 1;

	return (width);
}
