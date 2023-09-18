#include "main.h"
/**
 * _printfnc - function that prints argument according to its type
 * @frmt: arguments prnted in formatted string
 * @lst: list of arguments printed
 * @ind: index
 * @buff: buffer array to handle print function
 * @flags: claculate active flags
 * @width: determine width
 * @precision: precision spec
 * @size: size spec
 * Return: either 1 or 2
 */
int _printfnc(const char *frmt, int *ind, va_list lst, char buff[],
	int flags, int width, int precision, int size)
{
	int i, undef_len = 0, _printedchars = -1;
	frmt_t frmt_type[] = {
		{'c', _printchar}, {'s', _printstr}, {'d', _printint},
		{'%', _printpcnt}, {'i', _printint}, {'b', _printbinary},
		{'p', _printptr}, {'S', _print_non_print}, {'r', _printrev}, {'\0', NULL}
	};
	for (i = 0; frmt_type[i].frmt != '\0'; i++)
		if (frmt[*ind] == frmt_type[i].frmt)
			return (frmt_type[i].fnc(lst, buff, flags, width, precision, size));
	if (frmt_type[i].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		undef_len += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			undef_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		undef_len += write(1, &frmt[*ind], 1);
		return (undef_len);
	}
	return (_printedchars);
}
