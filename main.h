#ifndef MAIN_H
#define MAIN_H
#include <unistd.h> 
#include <stdio.h>
#include <stdarg.h>

int _strlen(char *s);
int _char(const char **format, va_list list);
int _string(const char **format, va_list list);
int _printf(const char *format, ...);

#endif
