#ifndef MAIN_H
#define MAIN_H
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

#define UNUSED(x) (void)(x)
#define _BUFFSIZE 1024

#define S_SHORT 1
#define S_LONG 2

#define F_NEG 1
#define F_POS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

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
int _printfnc(const char *frmt, int *i, va_list lst,
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
int _printbinary(va_list type, char buff[], int flags,
	int width, int precision, int size);
int _printptr(va_list type, char buff[], int flag,
	int width, int precision, int size);
int _print_non_print(va_list type, char buff[], int flags,
	int width, int precision, int size);
int _printrev(va_list type, char buff[], int flags,
	int width, int precision, int size);
int _unsigned(va_list type, char buffer[], int flags,
	int width, int precision, int size);
int _octal(va_list type, char buffer[], int flags,
	int width, int precision, int size);
int _hexadecimal(va_list type, char buffer[], int flags,
	int width, int precision, int size);
int _hexa_upper(va_list type, char buffer[], int flags,
	int width, int precision, int size);
int handle_hex(va_list type, char map_point[], char buffer[],
	int flags, char flag_up, int width, int precision, int size);
int _rot13string(va_list type, char buff[], int flags,
	int width, int precision, int size);
int handle_unsigned(int is_neg, int id, char buffer[],
	int flags, int width, int precision, int size);

/*CONV*/
int hex_code(char asci_cd, char buff[], int i);
int can_print(char c);
long int convert_sze_num(long int num, int size);
int is_digit(char c);
long int convert_sze_unsgnd(unsigned long int num, int size);

/*WRITE_GUIDE*/
int _writechar(char c, char buff[], int flags,
	int width, int precision, int size);
int write_ptr(char buff[], int ind, int len,
	int width, int flags, char pad, char c_add, int pad_start);
int _writenum(int is_negative, int ind, char buff[],
	int flags, int width, int precision, int size);
int print_num(int ind, char buff[], int flags,
	int width, int prc, int len, char sp, char add_c);
int _writeunsgnd(int is_negative, int ind, char buff[],
	int flags, int width, int precision, int size);

/*OTHER SPECIFIERS*/
int check_flags(const char *format, int *i);
int check_width(const char *format, int *i, va_list lst);
int _precision(const char *format, int *arg_i, va_list arg_list);
int _size(const char *format, int *arg_i);


#endif
