#include "main.h"

/**
 * _char - prints a char
 * @format: format character
 * @list: argument list handler
 *
 * Return: char
 */

int _char(const char **format, va_list list)
{
	char c = va_arg(list, int);

	return (write(1, &c, 1));
}


/**
 * _string - prints a string
 * @format: format string
 * @list: argument list
 *
 * Return: string
 */

int _string(const char **format, va_list list)
{
	char *s = va_arg(list, char *);
	int _strlen = 0;

	while (s[_strlen] != '\0')
	{
		_strlen++;
	}

	return (_write(1, s, _strlen));
}
