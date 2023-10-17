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
 * handle_format - Handle the format string and print formatted output
 * @format: The format string
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed (excluding the null byte)
 */

static int handle_format(const char *format, va_list args)
{
	int char_count;

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
				int c = va_arg(args, int);

				char_count += print_character(c);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					char_count += print_character(*s);
					s++;
				}
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
	return (char_count);
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int char_count;

	va_start(args, format);

	char_count = handle_format(format, args);

	va_end(args);

	return (char_count);
}

