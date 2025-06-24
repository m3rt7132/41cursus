/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:51:14 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:29:27 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts an integer to a string representation.
 * This function allocates memory for the string,
 * so it is the caller's responsibility to free it.
 * @param n The integer to convert.
 * @return A pointer to the string representation of the integer,
 * @return or NULL if the allocation fails.
 * * If the integer is 0, it returns "0".
 * * If the integer is negative, it returns a string starting with '-'.
 * ? Example:
 * * - ft_itoa(42) returns "42"
 * * - ft_itoa(-42) returns "-42"
 * * - ft_itoa(0) returns "0"
 * ! Note: The returned string is dynamically allocated,
 * ! so it should be freed by the caller when no longer needed.
 */

#include <stdlib.h>
#include "libft.h"

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
		return ((void *)0);
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
