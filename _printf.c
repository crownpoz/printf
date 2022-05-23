#include "main.h"

/**
 *printIdentity - prints special characters
 *@next: character after the %
 *@arg: argument for the identifier
 *Return: the number of characters printed
 *(excluding the null byte used to end output to strings)
 */

int printIdentity(char next, va_list arg)
{
	int functI;

	identifyStruct funct[] = {
	{"c", print_char},
	{"s", print_str},
	{NULL, NULL}
	};

	for (functI = 0; funct[functI].identifier != NULL; functI++)
	{
		if (funct[functI].identifier[0] == next)
			return (funct[functI].printer(arg));
	}
	return (0);
}

/**
 *_printf - mimics printf from stdio
 *description: produces output accordimg to format
 *write output to standard output stream
 *@format: character string composed of zero or more directives
 *
 *Return: the number of characters printed
 *(excluding the null byte used to end output to strings)
 *return -1 for incomplete identifier error
 */

int _printf(const char *format, ...)
{
	unsigned int j;
	int printId = 0;
	int charPrint = 0;
	va_list ap;

	va_start(ap, format);
	if (format == NULL)
		return (-1);

	for (j = 0; format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			_putchar(format[j]);
			charPrint++;
			continue;
		}
		if (format[j + 1] == '%')
		{
			_putchar('%');
			charPrint++;
			j++;
			continue;
		}
		if (format[j + 1] == '\0')
			return (-1);

		printId = printIdentity(format[j + 1], ap);
		if (printId == -1 || printId != 0)
			j++;
		if (printId > 0)
			charPrint += printId;

		if (printId == 0)
		{
			_putchar('%');
			charPrint++;
		}
	}
	va_end(ap);
	return (charPrint);
}
