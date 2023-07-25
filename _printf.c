/* _printf.c file */
#include <unistd.h>
#include "main.h"

/**
* _printf - Our own printf function
* @format: The format to print
*
* Return: The number of characters printed
*/
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;

va_start(args, format);

/* loop through the format string */
for (; *format != '\0'; format++)
{
/* check for format specifier */
if (*format == '%')
{
format++;

switch (*format)
{
case 'c': /* char specifier */
{
char c = va_arg(args, int);
write(1, &c, 1);
printed_chars++;
break;
}
case 's': /* string specifier */
{
char *str = va_arg(args, char *);
while (*str)
{
write(1, str++, 1);
printed_chars++;
}
break;
}
case '%': /* percent specifier */
write(1, format, 1);
printed_chars++;
break;
default:
break;
}
}
else /* if not a format specifier, print char as is */
{
write(1, format, 1);
printed_chars++;
}
}

/* cleanup arg list */
va_end(args);

return printed_chars;
}

