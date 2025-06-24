/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:17:04 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 14:48:48 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Converts an uppercase letter to its lowercase.
 * If the character is not an uppercase letter, it returns itself.
 * @param c The character to convert.
 * @return The lowercase of the character if it is an uppercase letter,
 * TODO: bitwise version:
 * * c |= 0x20; // This sets 1 the 6th bit of the character, 0x20 = 32 = 2^5.
 * * 01 0 0 0001 (65) -> 01 1 0 0001 (97) // 6. bit is set to 1 means its uppercase
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
