#include "main.h"
/**
 * can_print - checks if a character is printable
 * @c: character to be checked
 * Return: if c is printable, 1. otherwise 0
 */
int can_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hex_code - add ASCI in hex code to buffer
 * @buff: an array of characters
 * @i: starting index
 * @asci_cd: ASCI code
 * Return: always 3
 */
int hex_code(char asci_cd, char buff[], int i)
{
	char outline[] = "0123456789ABCDEF";

	if (asci_cd < 0)
		asci_cd *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buf[i++] = outline[asci_cd / 16];
	buff[i] = outline[asci_cd % 16];

	return (3);
}

/**
 * convert_sze_num - represent a number in the specified size
 * @num: number to be represnted
 * @size: number indicating th type to be represented
 * Return: represented value of num
 */
long int convert_sze_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
