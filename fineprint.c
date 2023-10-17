#include <stdio.h>
#include <stdarg.h>

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
 * handle_c - Handle the 'c' conversion specifier
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
static int handle_c(va_list args)
{
	int c = va_arg(args, int);

	return (print_character(c));
}

/**
 * handle_di - Handle the 'd' and 'i' conversion specifiers
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
static int handle_di(va_list args)
{
	int n = va_arg(args, int);
	int char_count = 0;
	int divisor = 1;
	int digit;

	while (n / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		digit = n / divisor;
		print_character('0' + digit);
		char_count++;
		n %= divisor;
		divisor /= 10;
	}
	return (char_count);
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
		} else
		{
			format++;
			if (*format == 'c')
			{
				char_count += handle_c(args);
			} else if (*format == 'd' || *format == 'i')
			{
				char_count += handle_di(args);
			} else if (*format == '%')
			{
				char_count += print_character('%');
			} else
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
