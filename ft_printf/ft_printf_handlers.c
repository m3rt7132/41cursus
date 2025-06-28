#include "ft_printf.h"

ssize_t	handle_formatters(va_list args, int type)
{
	if (type == 'c')
		return (handle_char(args));
	else if (type == 's')
		return (handle_str(args));
	else if (type == '%')
		return (handle_percent());
	else if (type == 'd' || type == 'i')
		return (handle_int(args));
	else if (type == 'u')
		return (handle_uint(args));
	else if (type == 'x' || type == 'X')
		return (handle_hex(args, type));
	else if (type == 'p')
		return (handle_ptr(args));
	else
		return (-1);
}

ssize_t	handle_percent(void)
{
	return (write(1, "%", 1));
}

ssize_t	handle_char(va_list args)
{
	int	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

ssize_t	handle_str(va_list args)
{
	return (ft_putstr((char *)va_arg(args, char *)));
}

ssize_t	handle_int(va_list args)
{
	char	*str;
	ssize_t	written;

	str = ft_itoa((int)va_arg(args, int));
	if (!str)
		return (-1);
	written = ft_putstr(str);
	free(str);
	return (written);	
}

ssize_t	handle_uint(va_list args)
{
	unsigned int	num;
	char			*str;
	ssize_t			written;

	num = (unsigned int)va_arg(args, unsigned int);
	str = ft_utoa_base(num, "0123456789");
	if (!str)
		return (-1);
	written = ft_putstr(str);
	free(str);
	return (written);
}

ssize_t	handle_hex(va_list args, int type)
{
	unsigned int	num;
	char			*str;
	ssize_t			written;

	num = (unsigned int)va_arg(args, unsigned int);
	if (type == 'x')
		str = ft_utoa_base(num, "0123456789abcdef");
	else
		str = ft_utoa_base(num, "0123456789ABCDEF");
	if (!str)
		return (-1);
	written = ft_putstr(str);
	free(str);
	return (written);
}

ssize_t	handle_ptr(va_list args)
{
	unsigned long	ptr;
	char			*str;
	ssize_t			written0x;
	ssize_t			written;

	ptr = (unsigned long)va_arg(args, void *);
	str = ft_utoa_base(ptr, "0123456789abcdef");
	if (!str)
		return (-1);
	written0x = ft_putstr("0x");
	written = ft_putstr(str);
	free(str);
	if (written0x == -1 || written == -1)
		return (-1);
	return (written0x + written);
}