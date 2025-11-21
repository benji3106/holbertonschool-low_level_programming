#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

void print_char(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void print_string(va_list args);

/**
 * print_all - Prints anything, followed by a new line.
 * @format: A list of types of arguments passed to the function.
 *
 * c: char
 * i: integer
 * f: float
 * s: char * (if NULL, print (nil))
 */
 void print_all(const char * const format, ...)
 {
	va_list args;
	int i = 0;
	int j;
	char *separator = "";
	printer_t types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (types[j].symbol)
		{
			if (format[i] == types[j].symbol)
			{
				printf("%s", separator);
				types[j].print(args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
 	}

 	printf("\n");

	va_end(args);
}

/**
 * print_char - Prints a char.
 * @args: va_list containing the argument.
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - Prints an int.
 * @args: va_list containing the argument.
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - Prints a float.
 * @args: va_list containing the argument.
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - Prints a string.
 * @args: va_list containing the argument.
 *
 * If the string is NULL, print (nil).
 */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}
