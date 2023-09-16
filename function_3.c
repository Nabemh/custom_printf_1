/********PRINT BINARY*********/
/**
 * _printbinary - prnts an unsigned number
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */

int _printbinary(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(type, unsigned int);
	m = 2147483648; /*(2 ^ 31)*/
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char b = '0' + a[i];

			write(1, &b, 1);
			count++;
		}
	}
	return (count);
}
/*****PRINT POINTER****/
/**
 * _printptr - prnts value of pointer variable
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _printptr(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	char add_c = 0, pt_add = ' ';
	int ind = _BUFFSIZE - 2, length = 2, pt_add_start = 1;
	unsigned long num_adr;
	char outline[] = "0123456789abcdef";
	void *adr = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (adr == NULL)
		return (write(1, "(nil)", 5));

	buff[_BUFFSIZE - 1] = '\0';
	UNUSED(precision);

	num_adr = (unsigned long)adr;

	while (num_adr > 0)
	{
		buff[ind--] = outline[num_adr % 16];
		num_adr /= 16;
		length++
	}
	if ((flags & F_zero) && !(flags & F_NEG))
		pt_add = '0';
	if (flags & F_POS)
		add_c = '+', length++;
	else if (flags & F_SPACE)
		add_c = ' ', length++;

	ind++;
	/*return (write(1, &buff[i], _BUFFSIZE -i -1));*/
	return (write_ptr(buff, ind, length, width,
		flags, pt_add, add_c, pt_add_start));
}
/*****PRINT POINTER****/
/**
 * _printrev - prints a string in reverse
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _printrev(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char b = str[i];

		write(1, &b, 1);
		count++;
	}
	return (count);
}
/*****PRINT NON-PRINT CHARS****/
/**
 * _print_non_print - prnts ASCII codes in hexa and non-printable chars
 * @type: a list of arguments
 * @buff: buffer array that handles print
 * @flags: get number of active flags
 * @width: get width
 * @precision: precision spec
 * @size: size spec
 * Return: number of characters printed
 */
int _print_non_print(va_list type, char buff[], int flags,
	int width, int precision, int size)
{
	int i = 0, bal_out = 0;
	char *str = va_arg(type, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (can_print(str[i]))
			buff[i + bal_out] = str[i];
		else
			bal_out += hex_code(str[i], buff, i + bal_out);

		i++;
	}
	buff[i + bal_out] = '\0';

	return (write(1, buff, i + bal_out));
}
