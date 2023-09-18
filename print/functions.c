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
        int i, length = 0;
        char *str = va_arg(type, char *);

        UNUSED(buff);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        if (str == NULL)
        {
                str == "(null)";
                if (precision >= 6)
                        str = "      ";
        }
        while (str[length] != '\0')
                length++;
        if (precision >= 0 && precision < length)
                length = precision;
        if (width > length)
        {
                if (flags && F_MINUS)
                {
                        write(1, &str[0], length);
                        for (i = width - length; i > 0; i--)
				  write(1, " ", 1);
                        return (width);
                }
                else
                {
                        for (i = width - length; i > 0; i--)
                                write(1, " ", 1);
                        write(1, &str[0], length);
                        return (width);
                }
        }
        return (write(1, str, length));
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
