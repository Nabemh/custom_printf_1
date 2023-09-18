#include "main.h"

void _printbuff(char buff[], int *buff_ind);

/**
 * _printf - function that prints characters according to format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
        int i, print = 0, _printchars = 0;
        int flags, width precision, size, buff_ind = 0;
        va_list lst;
        char buff[_BUFFSIZE];

        if (format == NULL)
                return (-1);

        va_start(lst, format);

        for (i = 0; format && format[i] != '\0'; i++)
        {
                if (format[i] != '%')
                {
                        buff[buff_ind++] = format[i];
                        if (buff_ind == _BUFFSIZE)
                                _printbuff(buff, &buff_ind);
                        _printedchars++;
                }
                else
		{
                        _printbuff(buff, &buff_ind);
                        flags = get_flg(formart, &i);
                        width = get_w(format, &i, lst);
                        precision = _precision(format, &i, lst);
                        size = get_sze(format, &i);
                        ++i;
                        print = _printfnc(format, &i, lst, buff, flags, width, precision, size);
                        if (print == -1)
                                return (-1);
                        _printedchars += print;
                }
        }
        _printbuff(buff, &buff_ind);

        va_end(lst);
        return (_printedchars);
}

/**
 * _printbuff - prints the contents of a buffer if it exists
 * @buff: an array of characters
 * @buff_ind: index at which next char is added, represents the length
 */
void _printbuff(char buff[], int *buff_ind)
{
        if (*buff_ind > 0)
                write(1, &buff[0], *buff_ind);
        *buff_ind = 0;
}
