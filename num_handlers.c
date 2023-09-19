#include "main.h"

/**
 * _unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @width: Gets width
 * @precision: Precision specification
 * @size: specifies the size
 *
 * Return: Number of chars printed.
 */

int _unsigned(va_list type, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int digits = va_arg(types, unsigned long int);

	digits = convert_size_unsgnd(digits, size);

	if (digits == 0)
		buffer[i--] = '\0';
	for (; digits > 0; digits /=10)
	{

		buffer[i--] = (digits % 10) + '0';
	}
	i++;

	write(1, &buffer[i], BUFF_SIZE - i - 1);
	return (BUFF_SIZE - i -1);
}

/**
 * _octal - prints an unsigned number in octal notation
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: Size Specifier
 *
 * Return: Number of chars
 */

int _octal(va_list type, char buffer[], int flags, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int digits = va_arg(types, unsigned long int);
	unsigned long int init_digit = digits;

	UNUSED(width);

	digits = convert_size_unsgnd(digits, size);

	if (digits == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE -1] = '\0';

	for (; digits > 0; digits /= 8 )
	{
		buffer[n--] = (digits % 8) + '0';
		digits /= 8;
	}
	
	if (flags & F_HASH && init_digit != 0)
		buffer[n--] = '0';

	n++;
	
	write(1, &buffer[n], BUFF_SIZE - n -1);

	return (BUFF_SIZE - n - 1);
}
