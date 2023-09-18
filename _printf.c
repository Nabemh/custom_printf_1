#include "main.h"

int _printf(const char *format, ...)
{
    int char_out = 0;
    va_list arg_set;
    
    if (!format)
        return (-1);

    va_start(arg_set, format);

    while (*format)
    {
        if (*format != '%')
        {
            _write(1, format, 1);
            char_out++;
        }
        else 
        {
            format++;
            if (*format == '\0')
            break;
            
            if (*format == '%')
            {
                _write(1, format, 1);
                char_out++;
            }

            else if (*format == 's')
            {
                char *s = va_arg(arg_set, char*);
                int _strlen = 0;
                
                while (s[_strlen] != '\0')
                {
                    _strlen++;
                }
                _write(1, s, _strlen);
                char_out = _strlen + char_out;

            }
            else if(*format == 'c')
            {
                char c;
                c = va_arg(arg_set, int);
                _write(1, &c, 1);
                char_out++;
            }
        }

        format++;
    }

    va_end(arg_set);
    return (char_out);

}
int main()
{
    _printf("L\n");
    _printf("%c\n", 'v');
    _printf("%s\n", "strings");
    _printf("%%\n");
    return 0;

}
