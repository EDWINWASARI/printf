#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int print_format(char format, va_list args);
int _printf(const char *format, ...);

#endif
