#include "main.h"
/********PRINT A CHAR*********/

/**
 * _printchar - prints a character
 * @type: a list of arguments
 * @buff: buffer array that hnadles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _printchar(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	char c = va_arg(type, int);

	return (_writechar(c, buff, flags, width, precision, size));
}

/********PRINT A STRING*********/
/**
 * _printstr - prints a string
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _printstr(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(type, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags && F_NEG)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

/********PRINT THE % SIGN*********/
/**
 * _printpcnt - prints percent sign
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of charachters printed
 */
int _printpcnt(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	UNUSED(type);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/********PRINT AN INT*********/
/**
 * _printint - prints integer
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _printint(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	int i = _BUFFSIZE - 2;
	int is_negative = 0;
	long int n = va_arg(type, long int);
	unsigned long int num;

	n = convert_sze_num(n, size);

	if (n == 0)
		buff[i--] = '0';

	buff[_BUFFSIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (_writenum(is_negative, i, buff, flags, width, precision, size));
}
/********PRINT STRING IN ROT13 *********/
/**
 * _rot13string - prints string in rot13
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _rot13string(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	char d;
	char *str;
	unsigned int i, j;
	int count = 0;
	char _in[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char _out[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; _in[j]; j++)
		{
			if (_in[j] == str[i])
			{
				d = _out[j];
				write(1, &d, 1);
				count++;
				break;
			}
		}
		if (!_in[j])
		{
			d = str[i];
			write(1, &d, 1);
			count++;
		}
	}
	return (count);
}
