#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
    const char *start;

	start = s;
    while (*s)
        s++;
    return (s - start);
}

ssize_t ft_putstr(const char *s)
{
	const char	*out;

	if (!s)
		out = "(null)";
	else
		out = s;
    return (write(1, out, ft_strlen(s)));
}

static int	countdigit(long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		is_negative;
	long	num;

	num = n;
	is_negative = (num < 0);
	if (is_negative)
		num = -num;
	len = countdigit(num) + is_negative;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len--] = 0;
	if (is_negative)
		ret[0] = '-';
	if (n == 0)
		ret[0] = '0';
	while (num != 0)
	{
		ret[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (ret);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_utoa_base(unsigned long num, const char *base)
{
	char	buffer[21]; // max 64-bit hex + null
	int		base_len = ft_strlen(base);
	int		i = 20;

	buffer[i--] = '\0';
	if (num == 0)
		buffer[i--] = '0';
	while (num > 0)
	{
		buffer[i--] = base[num % base_len];
		num /= base_len;
	}
	return (ft_strdup(&buffer[i + 1]));
}