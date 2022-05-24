#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>


int _putchar(char c);
int print_int(va_list arg);
int print_unsigned(va_list arg);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_str(va_list arg);
int print_percent(void);

/**
 *struct identifyStruct - structure definition of a printTypeStruct
 *@identifier: type
 *@printer: function to print
 */
typedef struct identifyStruct
{
char *identifier;
int (*printer)(va_list);
} identifyStruct;

#endif
