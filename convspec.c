#include <stdio.h>
#include <stdarg.h>

int _printf(char *format, ...)
{
	 va_list args;

    int char_count;
    int i;
    int j;
    char_count = 0;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            putchar(format[i]);
            char_count++;
        } else {
            i++;
            switch (format[i]) {
                case 'c':
                    {
                        int c = va_arg(args, int);
                        putchar(c);
                        char_count++;
                    }
                    break;
                case 's':
                    {
                        char *s = va_arg(args, char *);
                        for (j = 0; s[j] != '\0'; j++) {
                            putchar(s[j]);
                            char_count++;
                        }
                    }
                    break;
                case '%':
                    putchar('%');
                    char_count++;
                    break;
                default:
                    
                    putchar('%');
                    putchar(format[i]);
                    char_count += 2;
                    break;
            }
        }
    }

    va_end(args);
    return char_count;
}
