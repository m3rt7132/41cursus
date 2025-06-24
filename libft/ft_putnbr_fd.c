/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:26:54 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:47:01 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Writes an integer to the specified file descriptor.
 * If the integer is negative, it writes a '-' sign before the number.
 * If the integer is the minimum value (-2147483648), it writes it as a
 * string "-2147483648" directly to the file descriptor.
 * @param n The integer to write.
 * @param fd The file descriptor to write to.
 * @return VOID.
 */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	write(fd, &"0123456789"[n % 10], sizeof(char));
}
