#ifndef _MAIN_H
#define _MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int print_format(char format, va_list args);
int _printf(const char *format, ...);

#endif
