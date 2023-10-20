#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: A format string with format specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int addition = 0;

if (format == NULL)
{
return (-1);
}

va_start(args, format);
while (*format)
{
if (*format == '%')
{
if (*(format + 1) == '\0')
{
va_end(args);
return (-1);
}
format++;
addition += print_format(*format, args);
}
else
{
addition += write(1, format, 1);
}
format++;
}

va_end(args);
return (addition);
}

/**
 * print_format - Handles printing for format specifiers.
 * @format: The format specifier ('c', 's', or '%').
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */
int print_format(char format, va_list args)
{
int addition = 0;

switch (format)
{
case 'c':
{
char c = va_arg(args, int);
addition += write(1, &c, 1);
break;
}
case 's':
{
char *str = va_arg(args, char*);
int len = 0;
while (str[len] != '\0')
len++;
addition += write(1, str, len);
break;
}
case '%':
addition += write(1, "%", 1);
break;
default:
addition += write(1, &format, 1);
}
return (addition);
}

