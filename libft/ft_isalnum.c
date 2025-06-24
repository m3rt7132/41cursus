/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:30:33 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:15:43 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the character is alphanumeric (a letter or a digit).
 * @param c The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 * TODO: bitwise version:
 * c & ~0x7F; // This clears the 8th bit of the character, 0x7F = 127 = 2^7 - 1.
 * Clearing 8th bit means the character is in the ASCII range.
 */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
