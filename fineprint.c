#include <stdio.h>
#include <stdarg.h>

/**
 * custom_printf - Custom printf function to handle base conversions
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int custom_printf(const char *format, ...) {
    
	int char_count;
	va_list args;
	
	va_start(args, format);
	char_count = 0;

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            char_count++;
        } else {
            format++;
            if (*format == 'd' || *format == 'i') {
                int num = va_arg(args, int);
                char_count += printf("%d", num);
            } else if (*format == 'x') {
                unsigned int num = va_arg(args, unsigned int);
                char_count += printf("%x", num);
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                char_count += printf("%s", str);
            } else if (*format == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                char_count++;
            } else if (*format == '%') {
                putchar('%');
                char_count++;
            }
        }
        format++;
    }

    va_end(args);
    return char_count;
}
