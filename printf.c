#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * print_format - Prints characters based on the format specifier.
 * @format: The format specifier ('c', 's', or '%').
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */
int print_format(char format, va_list args)
{
int print = 0;
switch (format)
{
case 'c':
{
char c = va_arg(args, int);
print += write(1, &c, 1);
break;
}
case 's':
{
char *str = va_arg(args, char*);
int len = strlen(str);
print += write(1, str, len);
break;
}
case '%':
print += write(1, "%", 1);
break;
default:
print += write(1, &format, 1);
}
return (print);
}

/**
 * _printf - Produces output according to a format.
 * @format: A format string with format specifiers.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
int addition = 0;
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
addition += print_format(*(++format), args);
}
else
{
addition += write(1, format, 1);
}
++format;
}
va_end(args);
return (addition);
}
/**
 * main - Entry point of the program
 *
 * Description: The main function demonstrates the usage of the custom _printf
 * function by printing formatted output.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
n = _printf("Hello, %c, %s, and %%%c\n", 'W', "World", '!');
_printf("Characters printed: %d\n", n);
return (0);
}
