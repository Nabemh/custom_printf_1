#include "main.h"

/**
 * _unsigned - Prints an unsigned number
 * @type: List of arguments
 * @buffer: Buffer array to handle print
 * @width: Gets width
 * @flags: Gets active flags
 * @precision: Precision specification
 * @size: specifies the size
 *
 * Return: Number of chars printed.
 */

int _unsigned(va_list type, char buffer[], int flags,
		int width, int precision, int size)
{
	int n = _BUFFSIZE - 2;
	unsigned long int digits = va_arg(type, unsigned long int);

	digits = convert_sze_num(digits, size);

	if (digits == 0)
		buffer[n--] = '\0';
	for (; digits > 0; digits /= 10)
	{

		buffer[n--] = (digits % 10) + '0';
	}
	n++;

	return (_writenum(0, n, buffer, flags, width, precision, size));
}

/**
 * _octal - prints an unsigned number in octal notation
 * @type: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: Size Specifier
 *
 * Return: Number of chars
 */

int _octal(va_list type, char buffer[], int flags,
		int width, int precision, int size)
{
	int n = _BUFFSIZE - 2;
	unsigned long int digits = va_arg(type, unsigned long int);
	unsigned long int init_digit = digits;

	UNUSED(width);

	digits = convert_sze_num(digits, size);

	if (digits == 0)
		buffer[n--] = '0';

	buffer[_BUFFSIZE - 1] = '\0';

	for (; digits > 0; digits /= 8)
	{
		buffer[n--] = (digits % 8) + '0';
		digits /= 8;
	}

	if (flags & F_HASH && init_digit != 0)
		buffer[n--] = '0';

	n++;

	return (_writenum( n, buffer, flags, width, precision, size));
}
