#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

#define UNUSED(x) (void)(x)
#define _BUFFSIZE 1024

/**
 * struct frmt - structure opr
 * @frmt: format
 * @fnc: function associated
 */
struct frmt
{
        char frmt;
        int (*fnc)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct frmt frmt_t - structure opr
 * @frmt: format
 * @frmt_t: function associated
 */

typedef struct frmt frmt_t;

int _printf(const char *format, ...);
va_list (lst, char buff[]);
/*functions*/
int _printchar(va_list type, char buff[]);
int _printstr(va_list type, char buff[]);
int _printpcnt(va_list type, char buff[]);
int _printint(va_list type, char buff[]);
int _printbinary(va_list type, char buff[]);
int _unsigned(va_list type, char buff[]);
int _octal(va_list type, char buff[]);
int _hexadecimal(va_list type, char buff[]);
int _hexa_upper(va_list type, char buff[]);


#endif
