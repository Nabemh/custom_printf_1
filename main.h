#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

#define UNUSED(x) (void)(x)
#define _BUFFSIZE 1024

#define S_SHORT 1
#define S_LONG 2

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
int _printfnc(const char *fmt, int *i, va_list lst,
	char buff[], int flags, int precision, int width, int size);
/*functions*/
int _printchar(va_list type, char buff[], int flags,
	int width, int precision, int size);
int _printstr(va_list type, char buff[], int flags,
	int width, int precision, int size);
int _printpcnt(va_list type, char buff[], int flags,
	int width, int precision, int size);
int _printint(va_list type, char buff[], int flags,
	int width, int precision, int size);
int _printbinary(va_list type, char buff[], int flags
	int width, int preecision, int size);
int _printptr(va_list type, char buff[], int flag,
	int width, int preecision, int size);
int _print_non_print(va_list type, char buff[], int flags,
	int width, int preecision, int size);
int _printrev(va_list type, char buff[], int flags,
	int width, int preecision, int size);
int _rot13string(va_list type, char buff[], int flags,
	int width, int precision, int size);

/*CONV*/
int hex_code(char asci_cd, char buff[], int i);
int can_print(char c);
long int convert_sze_num(long int num, int size);

/*WRITE_GUIDE*/
int _writechar(char c, char buff[], int flags,
	int width, int precision, int size);
int write_ptr(char buff[], int ind, int len,
	int flags, int width, char pad, char c_add, int pad_start);
int _writenum(int is_negative, int ind, char buff[],
	int flags, int width, int precision, int size);
#endif
