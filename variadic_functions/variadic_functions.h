#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stddef.h>

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct printer - Struct for choosing the right print function
 * @symbol: format char (c, i, f, s)
 * @print: function that prints the corresponding type
 */
 typedef struct printer{
	char symbol;
	void (*print)(va_list args);
 }printer_t;
 

#endif
