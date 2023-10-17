#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * print_format - That format handles format specifiers
 * @format: The format specifier to be handled
 * @args: The va_list containing list of arguments.
 * Return: Returns the number of characters printed
 */

int print_format(char format, va_list args)
{
int print = 0;
switch (format)
{
case 'c':
print += putchar(va_arg(args, int));
break;
case 's':
print += write(1, va_arg(args, char*), strlen(va_arg(args, char*)));
break;
case '%':
print += write(1, "%", 1);
break;
default:
print += write(1, &format, 1);
}
return (print);
}

/**
 * _printf - contains specifiers to be handled
 * @format: A format string with format specifiers.
 * Handled specifiers: %c, %s, and %%
 * Return: Returns the number of characters printed.
 */

int _printf(const char *format, ...)
{
int addition = 0;
va_list edu;
va_start(edu, format);

while (*format != '\0')
{
if (*format == '%')
{
addition += print_format(*(++format), edu);
}
else
{
addition += write(1, format, 1);
}
++format;
}
va_end(edu);
return (addition);
}
