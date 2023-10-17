#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_character - Print a character to stdout
 * @c: The character to print
 *
 * Return: 1 for the printed character
 */
static int print_character(int c)
{
	putchar(c);
	return (1);
}

/**
 * print_string - Print a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
static int print_string(const char *str)
{
	int cahr_count;

	int char_count = 0;

	while (*str)
	{
		char_count += print_character(*str);
		str++;
	}
	return (char_count);
}

/**
 * handle_c - Handle the 'c' conversion specifier
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
static int handle_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (print_character(c));
}

/**
 * handle_s - Handle the 's' conversion specifier
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
static int handle_s(va_list args)
{
	char *s = va_arg(args, char *);

	return (print_string(s));
}

/**
 * my_printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int my_printf(const char *format, ...)
{
	va_list args;
	int char_count;

	va_start(args, format);
	char_count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			char_count += print_character(*format);
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char_count += handle_c(args);
			} else if (*format == 's')
			{
				char_count += handle_s(args);


			} else if (*format == '%')
			{
				char_count += print_character('%');

			}
			else
			{
				char_count += print_character('%');
				char_count += print_character(*format);
			}
		}
		format++;
	}
	va_end(args);
	return (char_count);
}
