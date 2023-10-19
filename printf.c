#include "main.h"

/**
 * print_format - Prints characters based on the format specifier.
 * @format: The format specifier ('c', 's', or '%').
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed, addition
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
int len = strlen(str);
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

/**
 * _printf - Produces output according to a format.
 * @format: A format string with format specifiers.
 * Return: The number of characters printed, addition.
 */
int _printf(const char *format, ...)
{
va_list args;
int addition = 0;
{
if (!format || (format[0] == '%' && format[1] == '\0'))
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
addition += print_format(*(++format), args);
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
