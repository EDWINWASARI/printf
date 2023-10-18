#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int k, form = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list edu;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(edu, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &k);
			width = get_width(format, &k, edu);
			precision = get_precision(format, &k, edu);
			size = get_size(format, &k);
			++k;
			form = handle_print(format, &k, edu, buffer,
				flags, width, precision, size);
			if (form == -1)
				return (-1);
			printed_chars += form;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(edu);

	return (printed_chars);
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
