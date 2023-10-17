#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A format string with format specifiers.
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
int class = 0;
va_list edu;
if (format == NULL)
return (-4);
va_start(edu, format);
class = print_format(format, edu);
va_end(edu);
return (class);
}

/**
 * print_format - Process the format string and write characters.
 * @format: A format string with format specifiers.
 * @edu: The va_list containing the arguments.
 * Return: The number of characters printed.
 */

int print_format(const char *format, va_list edu)
{
int class = 0;
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
class++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == '%')
{
write(1, format, 1);
class++;
}
else if (*format == 'c')
{
char c;
c = (char) va_arg(edu, int);
write(1, &c, 1);
class++;
}
else if (*format == 's')
{
char *str = va_arg(edu, char*);
int str_len = 0;
while (str[str_len] != '\0')
write(1, str, str_len);
class += str_len;
}
format++;
}
}
va_end(edu);
return (class);
}

