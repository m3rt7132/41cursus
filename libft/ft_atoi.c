/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:04:58 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:18:08 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts a string to an integer.
 * It ignores whitespace, handles only 1 (ONE) optional '+' or '-' signs,
 * and converts the string to an integer until a non-digit character is found.
 * If the string starts with a sign, it will return a negative or positive integer accordingly.
 * @param nptr The string to convert.
 * @return The converted integer.
 * @return If the string does not contain any digits, it returns 0.
 * ? Example:
 * * - "42" -> 42
 * * - "   -42" -> -42
 * * - "42abc" -> 42
 */

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		res;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}
