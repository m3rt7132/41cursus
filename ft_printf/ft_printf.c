#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
	int		count;
	ssize_t	written;

	va_list args;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			written = handle_formatters(args, *++fmt);
		else
			written = write(1, fmt, 1);
		if (written == -1)
		{
			va_end(args);
			return (-1);
		}
		count += (int)written;
		fmt++;
	}
	va_end(args);
	return (count);
}
