#include "main.h"

/**
 * _hexadecimal - prints an unsigned number in hexadecimal notations
 * @type: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: Size Specifier
 *
 * Return: Number of chars
 */

int _hexadecimal(va_list type, char buffer[], int flags,
		int width, int precision, int size)
{
	return (handle_hex(type, "0123456789abcdef", buffer, flags,
				'x', width, precision, size));
}

/**
 * _hexa_upper - prints an unsigned int in upper hexadecimal notation
  * @type: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: gets the width
 * @precision: specification for precision
 * @size: Size Specifier
 *
 * Return: Number of chars
 */

int _hexa_upper(va_list type, char buffer[], int flags,
		int width, int precision, int size)
{
	return (handle_hex(type, "0123456789ABCDEF", buffer, flags,
				'X', width, precision, size));
}

/** HANDLES PRINTING OF HEX IN BOTH LOWER AND UPPER CASE **/

/**
 * handle_hex - prints hexadecimal numbers in both lower and upper case
 * @type: argument list
 * @map_point: array of values to map to
 * @buffer: buffer array handling print
 * @flags: calculates actice flags
 * @flag_up: Also calculates active flags
 * @width: gets the width
 * @precision: specification for precision
 * @size: size specifier
 *
 * Return: Number of chars
 */

int handle_hex(va_list type, char map_point[], char buffer[],
		int flags, char flag_up, int width, int precision, int size)
{
	int n = _BUFFSIZE - 2;
	unsigned long int digit = va_arg(type, unsigned long int);
	unsigned long int digit2 = digit;

	UNUSED(width);

	digit = convert_sze_num(digit, size);

	if (digit == 0)
		buffer[n++] = '0';
	buffer[_BUFFSIZE - 1] = '\0';

	while (digit > 0)
	{
		buffer[n--] = map_point[digit % 16];
		digit /= 16;
	}

	if (flags & F_HASH && digit2 != 0)
	{
		buffer[n++] = flag_up;
		buffer[n++] = '0';
	}

	n++;

	return (_writenum(0, n, buffer, flags, width, precision, size));
}
