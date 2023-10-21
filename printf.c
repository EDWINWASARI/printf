#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int b, added = 0, printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (b = 0; format && format[b] != '\0'; b++)
	{
		if (format[b] != '%')
		{
			buffer[buff_ind++] = format[b];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &b);
			width = get_width(format, &b, list);
			precision = get_precision(format, &b, list);
			size = get_size(format, &b);
			++b;
			printed = handle_print(format, &b, list, buffer,
				flags, width, precision, size);
			if (added == -1)
				return (-1);
			printed += added;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
