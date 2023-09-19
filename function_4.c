#include "main.h"

/**
 * handle_unsigned - writes an unsigned number
 * @is_neg: indicates if the number is negative
 * @id: index where the number starts in the buffer
 * @buffer: array of characters
 * @flags: flag specifier
 * @width: width specifier
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: number of characters written
 */

int handle_unsigned(int is_neg, int id, char buffer[], int flags, int width, int precision, int size)
{
    int len = _BUFFSIZE - id - 1;
    int n = 0;

    UNUSED(is_neg);
    UNUSED(size);

    if (precision == 0 && id == _BUFFSIZE - 2 && buffer[id] == '0')
        return (0);

    if (precision > 0 && precision < len)
        pd = ' ';
    while (precision > len)
    {
        buffer[--id] = '0';
        len++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        pd = '0';

    if (width > len)
    {
        for (n = 0; n < width - len; n++)
            buffer[n] = pd;

        buffer[n] = '\0';
        if (flags & F_MINUS)
        {
            return (write(1, &buffer[id], len) +
                    write(1, &buffer[0], n));
        }
        else
        {
            return (write(1, &buffer[0], n) +
                    write(1, &buffer[id], len));
        }
    }
    return (write(1, &buffer[id], len));
}
