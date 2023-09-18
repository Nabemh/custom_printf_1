#include "main.h"
/**
 * _printfnc - function that prints argument according to its type
 * @fmt: arguments prnted in formatted string
 * @lst: list of arguments printed
 * @ind: index
 * @buff: buffer array to handle print function
 * @flags: claculate active flags
 * @width: determine width
 * @precision: precision spec
 * @size: size spec
 * Return: either 1 or 2
 */
int _printfnc(const char *fmt, int *ind, va_list lst, char buff[],
	int flags, int width, int precision, int size);
{
	int i, undef_len = 0, _printedchars = -1;
	fmt_t fmt_type[] = {
		{'c', _printchar}, {'s', _printstr}, {'d', _printint},
		{'%', _printpcnt}, {'i', _printint}, {'b', _printbinary},
		{'p', _printptr}, {'S', _print_non_print}, {'r', _printrev}, {'\0', NULL}
	};
	for (i = 0; fmt_type[i].fmt != '\0', i++)
		if (fmt[*ind] == fmt_type[i].fmt)
			return (fmt_type[i].fn(lst, buff, flags, width, precision, size));
	if (fmt_type[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		undef_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			undef_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		undef_len += write(1, &fmt[*ind], 1);
		return (undef_len);
	}
	return (_printedchars);
}
