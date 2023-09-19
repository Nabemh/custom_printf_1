#include "main.h"

/**
 * _size - Checkts the size to cast
 * @format: string
 * @arg_i: arguments to be printed
 *
 * Return: size
 */

int _size(const char *format, int *arg_i)
{
	int init_val = (*arg_i + 1);
	int str_size = 0;

	if (format[init_val] == 'l')
		str_size = S_LONG;
	else if (format[init_val] == 'h')
		str_size = S_SHORT;

	if (str_size == 0)
		*arg_i = init_val - 1;
	else
		*arg_i = init_val;

	return (str_size);
}