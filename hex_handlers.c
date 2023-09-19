#include "main.h"

/**
 * _hexadecimal - prints an unsigned number in hexadecimal notations
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: Size Specifier
 *
 * Return: Number of chars
 */

int _hexadecimal(va_list type, char buffer[], int flags, int width, int precision, int size)
{
        int n = BUFF_SIZE - 2;
        unsigned long int digit = va_arg(type, unsigned long int);

        digits = convert_size_unsgnd(digits, size);

        if (digits == 0)
                buffer[n--] = '0';

        for (; digits > 0; digits /= 16)
        {
                int hex = digits % 16;
                if (hex < 10)
                        buffer[n--] = '0' + hex;
                else
                        buffer[n--] = 'a' + hex - 10;
        }
        n++;

        write(1, &buffer[n], BUFF_SIZE - n - 1);

        return (BUFF_SIZE - n - 1);
}

/**
 * _hexa_upper - prints an unsigned int in upper hexadecimal notation
  * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: gets the width
 * @precision: Precision specification
 * @size: Size Specifier
 *
 * Return: Number of chars
 */

int _hexa_upper(va_list type, char buffer[], int flags, int width, int precision, int size)
{
        return (print_hexa(type, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

