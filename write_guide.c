#include "main.h"
/**
 * _writechar - prints a string
 * @c: character type
 * @buff: buffer array
 * @flags: calculates catie flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _writechar(char c, char buff[], int flags,
	int width, int precision, int size)
{
	int i = 0;
	char sp = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		sp = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (width > 1)
	{
		buff[_BUFFSIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[_BUFFSIZE - i - 2] = sp;
		if (flags & F_NEG)
			return (write(1, &buff[0], 1)) +
				(write(1, &buff[_BUFFSIZE - i - 1], width - 1));
		else
			return (write(1, &buff[_BUFFSIZE - i - 1], width - 1) +
			write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

/**
 * _writenum - prints a string
 * @is_negative: lis of args
 * @ind: char type
 * @buff: buffer array
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of charcters printed
 */
int _writenum(int is_negative, int ind, char buff[],
	int flags, int width, int precision, int size)
{
	int len = _BUFFSIZE - ind - 1;
	char sp = ' ', add_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_NEG))
		sp = '0';
	if (is_negative)
		add_char = '-';
	else if (flags & F_POS)
		add_char = '+';
	else if (flags & F_SPACE)
		add_char = ' ';

	return (_writenum(ind, buff, flags, width, precision,
			len, sp, add_char));
}
/**
 * write_ptr - prints a memory address
 * @buff: buffer array
 * @ind: index where num starts in buffer
 * @len: length of number
 * @flags: calculates the number of flags
 * @width: get width
 * @pad: character in padding
 * @c_add: additional character
 * @pad_start: index where padding starts
 * Return: number of characters printed
 */
int write_ptr(char buff[], int ind, int len,
	int flags, int width, char pad, char c_add, int pad_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buff[i] = pad;
		buff[i] = '\0';

		if (flags & F_NEG && pad == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';

			if (c_add)
				buff[--ind] = c_add;
			return (write(1, &buff[ind], len) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & F_NEG) && pad == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (c_add)
				buff[--ind] = c_add;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
		}
		else if (!(flags & F_NEG) && pad == '0')
		{
			if (c_add)
				buff[--pad_start] == c_add;
			buff[--ind] = 'x';
			buff[--ind] = '0';
			return (write(1, &buff[pad_start], i - pad_start) +
					write(1, &buff[ind], len - (1 - pad_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (c_add)
		buff[--ind] = c_add;
	return (write(1, &buff[ind], _BUFFSIZE - ind - 1));
}
