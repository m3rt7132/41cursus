/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:43:51 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:38:16 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Compares two blocks of memory for equality.
 * It compares the first 'n' bytes of the two blocks.
 * @param s1 Pointer to the first block of memory.
 * @param s2 Pointer to the second block of memory.
 * @param n The number of bytes to compare.
 * @return 0 if the blocks are equal, a positive value if the first block is greater,
 * @return a negative value if the second block is greater.
 * * This function is useful for comparing binary data or strings.
 */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	while (i < n)
	{
		if (m1[i] != m2[i])
			return (m1[i] - m2[i]);
		i++;
	}
	return (0);
}
