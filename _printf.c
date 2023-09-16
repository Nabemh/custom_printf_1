#include "main.h"

/**
 * _printf - my printf function
 * @format: Format string
 *
 * Return: number of characters
 */

int _printf(const char *format, ...)
{
	int char_out = 0;
	va_list arg_set;

	if (!format)
		return (-1);

	va_start(arg_set, format);

	while (*format)
	{
		if (*format != '%')
		{
			char_out += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				char_out += write(1, format, 1);
			}
			else if (*format == 's')
			{
				char_out += _string(&format, arg_set);
			}
			else if (*format == 'c')
			{
				char_out += _char(&format, arg_set);
			}
		}
		format++;
	}

	va_end(arg_set);
	return (char_out);
}
