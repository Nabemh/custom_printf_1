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

/**
 * write_pointer - writes a memory address
 * @buffer: array of characters
 * @id: index where the number starts in the buffer
 * @len: length of the number
 * @width: width specifier
 * @flags: flags specifier
 * @pd: character representing the padding
 * @new_c: character representing the extra character
 * @pd_srt: index at which padding should start
 *
 * Return: number of written characters.
 */

int _writeptr(char buffer[], int id, int len, int width, int flags, char pd, char new_c, int pd_srt)
{
    int n;

    if (width > len)
    {
        for (n = 3; n < width - len + 3; n++)
            buffer[n] = pd;
        buffer[n] = '\0';
        if (flags & F_MINUS && pd == ' ')
        {
            buffer[--id] = 'x';
            buffer[--id] = '0';
            if (new_c)
                buffer[--id] = new_c;
            return (write(1, &buffer[id], len) +
                    write(1, &buffer[3], n - 3));
        }
        else if (!(flags & F_MINUS) && pd == ' ')
        {
            buffer[--id] = 'x';
            buffer[--id] = '0';
            if (new_c)
                buffer[--id] = new_c;
            return (write(1, &buffer[3], n - 3) +
                    write(1, &buffer[id], len));
        }
        else if (!(flags & F_MINUS) && pd == '0')
        {
            if (new_c)
                buffer[--pd_srt] = new_c;
            buffer[1] = '0';
            buffer[2] = 'x';
            return (write(1, &buffer[pd_srt], n - pd_srt) +
                    write(1, &buffer[id], len - (1 - pd_srt - 2)));
        }
    }
    buffer[--id] = 'x';
    buffer[--id] = '0';
    if (new_c)
        buffer[--id] = new_c;
    return (write(1, &buffer[id], _BUFFSIZE - id - 1));
}

